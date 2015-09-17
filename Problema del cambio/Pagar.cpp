/***************************************************************/
/*                                                             */
/*            Autor: Ángel Luis Ortiz Folgado                  */
/*                                                             */
/***************************************************************/

# include "Pagar.h"
#include <math.h>
#include <queue>

 int PagarVoraz(int M [],int C,int i,int N){
	 int monedas =0;  // guarda el número de monedas que vamos a usar
	 int j=i+1; 
	 while (j<N && C > 0){
		 if(C-M[j]>=0){
			 C-=M[j];
			 monedas++;
		 }
		 j++;
	 }
  return monedas;
}

 int CotaOp( int M[],int C,int N,int mUsadas,int k){
	 int monedas;
	 int i=k+1;
	if (i>N && C !=0) monedas = INT_MAX;
	 else{
	   while(i<N && M[i]>C){
		 i++;
	   }
	   monedas=mUsadas+(ceil((float)C/M[i]));
	 }
	 return monedas;
   
 }

 int cotaPesimistaIngenua(int M[],int N,int mUsadas,int k,int C){
	 int monedas;
	 if(k>= N-1 && C!=0) monedas = INT_MAX;
	 else
	 {
       monedas= mUsadas + (N-k);
	 }
	
	 return monedas;
 }

 int PagarRYP(int M[],int C,int N,int Sol[],int &numNodos){ 
	 numNodos=0;
	 nodo X,Y,X1;
	 priority_queue<nodo, vector<nodo>, CompareNodo> pq;
	 pq.empty();
	 int NumMonedasMejor; 
	 Y.k=-1;
	 Y.cantidadFalta=C;
	 Y.monedasUsadas=0;
	 Y.CosteOpt=CotaOp(M,Y.cantidadFalta,N,Y.monedasUsadas,Y.k);
	 Y.sol= new int [N];
	 for (int i=0;i<N;i++) 
		 Y.sol[i]=0;
	 pq.push(Y);
	 NumMonedasMejor=PagarVoraz(M,C,0,N);
	 while(!pq.empty() && (pq.top().CosteOpt <= NumMonedasMejor) ){
		 numNodos++;
		 Y=pq.top();
		 pq.pop();
		 X.k=Y.k+1;
		 X.sol=new int [N];
		
		  for(int i=0;i<N;i++) 
			  X.sol[i]=Y.sol[i];
		
		 if( Y.cantidadFalta-M[X.k]>=0){ // hijo izq coger el valor
			
			 X.sol[X.k]=1;
			 X.monedasUsadas=Y.monedasUsadas+1;
			 X.cantidadFalta=Y.cantidadFalta-M[X.k];
			 X.CosteOpt=CotaOp(M,X.cantidadFalta,N,X.monedasUsadas,X.k);
		 
		     if(X.CosteOpt <=NumMonedasMejor){
			    if((X.k == N)){ 
				  
					for(int i=0;i<N;i++) Sol[i]=X.sol[i];
				   NumMonedasMejor=X.monedasUsadas;
			    }
			    else pq.push(X);
		     }
	     }
	
		  //hijo derecho no coger solucion
		 
		 
		    X1.k=Y.k+1;
		    X1.sol=new int [N];
		 
		    for(int i=0;i<N;i++) 
			   X1.sol[i]=Y.sol[i];
			 X1.monedasUsadas=Y.monedasUsadas;
			 X1.cantidadFalta=Y.cantidadFalta;
			 X1.CosteOpt=CotaOp(M,X1.cantidadFalta,N,X1.monedasUsadas,X1.k);
			 if(X1.CosteOpt <= NumMonedasMejor){
				 if((X1.k == N)){ 
				   
					for(int i=0;i<N;i++) 
						Sol[i]=X1.sol[i];
				   NumMonedasMejor=X1.monedasUsadas;
			    }
				 else {
					 pq.push(X1);
					 int pes= X1.monedasUsadas + PagarVoraz(M,X1.cantidadFalta ,X1.k,N); 
					NumMonedasMejor=min(NumMonedasMejor,pes);
				 }
			 }
		 
		

		 delete []Y.sol; 
   }

 return NumMonedasMejor;
}
 //****************************************************************************************************************/
 int PagarRYPIngenuo(int M[],int C,int N,int Sol[],int &numNodos){ 
	 numNodos=0;
	 nodo X,Y,X1;
	 priority_queue<nodo, vector<nodo>, CompareNodo> pq;
	 pq.empty();
	 int NumMonedasMejor; 
	 Y.k=-1;
	 Y.cantidadFalta=C;
	 Y.monedasUsadas=0;
	 Y.CosteOpt=Y.monedasUsadas;
	 Y.sol= new int [N];
	 for (int i=0;i<N;i++) 
		 Y.sol[i]=0;
	 pq.push(Y);
	 NumMonedasMejor=cotaPesimistaIngenua(M,N,Y.monedasUsadas,Y.k,Y.cantidadFalta);
	 while(!pq.empty() && (pq.top().CosteOpt <= NumMonedasMejor) ){
		 numNodos++;
		 Y=pq.top();
		 pq.pop();
		 X.k=Y.k+1;
		 X.sol=new int [N];
		
		  for(int i=0;i<N;i++) 
			  X.sol[i]=Y.sol[i];
		 
		 if( Y.cantidadFalta-M[X.k]>=0){ // hijo izq coger el valor
			 
			 X.sol[X.k]=1;
			 X.monedasUsadas=Y.monedasUsadas+1;
			 X.cantidadFalta=Y.cantidadFalta-M[X.k];
			 X.CosteOpt=X.monedasUsadas;
			
		     if( X.CosteOpt <=NumMonedasMejor){
			    if((X.k == N) && (X.cantidadFalta == 0)){ 
				  
					for(int i=0;i<N;i++) Sol[i]=X.sol[i];
				   NumMonedasMejor=X.monedasUsadas;
			    }
			    else if(X.k<N) pq.push(X);
		     }
	     }
	
		  //hijo derecho no coger solucion
		 
		 
		    X1.k=Y.k+1;
		    X1.sol=new int [N];
		 
		    for(int i=0;i<N;i++) 
			   X1.sol[i]=Y.sol[i];
			 X1.monedasUsadas=Y.monedasUsadas;
			 X1.cantidadFalta=Y.cantidadFalta;
			 X1.CosteOpt=X1.monedasUsadas;
			 if(X1.CosteOpt <= NumMonedasMejor){
				 if((X1.k == N)&& (X1.cantidadFalta==0)){ 
				  
					for(int i=0;i<N;i++) 
						Sol[i]=X1.sol[i];
				   NumMonedasMejor=X1.monedasUsadas;
			    }
				 else if(X1.k<N){
					 pq.push(X1);
					 int pes=cotaPesimistaIngenua(M,N,X1.monedasUsadas,X1.k,X1.cantidadFalta);
					NumMonedasMejor=min(NumMonedasMejor,pes);
				 }
			 }
		 
		

		 delete []Y.sol; 
   }

 return NumMonedasMejor;
}

/*********************************************************************************************/
 int PagarRYPSinPodas(int M[],int C,int N,int Sol[],int &numNodos){ 
	 numNodos=0;
	 nodo X,Y,X1;
	 priority_queue<nodo, vector<nodo>, CompareNodo> pq;
	 pq.empty();
	 int NumMonedasMejor; 
	 Y.k=-1;
	 Y.cantidadFalta=C;
	 Y.monedasUsadas=0;
	 
	 Y.sol= new int [N];
	 for (int i=0;i<N;i++) 
		 Y.sol[i]=0;
	 pq.push(Y);
	 NumMonedasMejor=INT_MAX;
	 while(!pq.empty() ){
		 numNodos++;
		 Y=pq.top();
		 pq.pop();
		 X.k=Y.k+1;
		 X.sol=new int [N];
		
		  for(int i=0;i<N;i++) 
			  X.sol[i]=Y.sol[i];
		
		 if( Y.cantidadFalta-M[X.k]>=0){ // hijo izq coger el valor
			
			 X.sol[X.k]=1;
			 X.monedasUsadas=Y.monedasUsadas+1;
			 X.cantidadFalta=Y.cantidadFalta-M[X.k];
			
		 if(X.k == N){
			  if(X.monedasUsadas <=NumMonedasMejor && (X.cantidadFalta == 0) ){
			
					for(int i=0;i<N;i++) Sol[i]=X.sol[i];
				   NumMonedasMejor=X.monedasUsadas;
			    }
		 }
	    else  pq.push(X);
			
	     }
	
		  //hijo derecho no coger solucion
		 
		
		    X1.k=Y.k+1;
		    X1.sol=new int [N];
		 
		    for(int i=0;i<N;i++) 
			   X1.sol[i]=Y.sol[i];
			 X1.monedasUsadas=Y.monedasUsadas;
			 X1.cantidadFalta=Y.cantidadFalta;
			
			 if(X1.k==N){
			   if(X1.monedasUsadas <=NumMonedasMejor && (X1.cantidadFalta==0) ){
				
				 
					for(int i=0;i<N;i++) 
						Sol[i]=X1.sol[i];
				   NumMonedasMejor=X1.monedasUsadas;
			    }
			  }
		    else  pq.push(X1);
					
				 
			 
		 
		

		 delete []Y.sol; 
   }

 return NumMonedasMejor;
}