/************************************************************/
/*        Autor:    Ángel Luis Ortiz Folgado                */
/*                                                          */
/************************************************************/

#include <iostream>
#include "Pagar.h"

#include <queue>
void mostrarVector(int a [], int l){ 
  for(int i=0;i<l;i++)
      cout << a[i] <<",";  
  cout << '\n' ;
}

void main(){
	int NN;
	
    const int N0=14;
	int V0 [N0] = {50,50,25,25,12,12,10,10,5,5,1,1,1,1};
	int C0=20;  // cantidad a pagar de la primera prueba
	int C1=30;  // cantidad a pagar de la segunda prueba
	int C3=37;  // cantidad a pagar de la tercera prueba
	int V1 [14]; // vector solución



cout << "Primera Prueba" << endl;
cout << "\n"; 
cout << "el vector es: ";
mostrarVector(V0,N0);
cout << "y se busca pagar la cantidad: " << C0 << "\n";
cout << "\n"; 
cout <<"Cota ingenua";
int sol1=PagarRYPIngenuo(V0,C0,N0,V1,NN);
cout << "\n" ;
cout<<"Numero monedas: "<<sol1 <<" Num Nodos: " << NN <<endl;
cout << "Solucion: " << endl;
mostrarVector(V1,N0);
 
cout << "\n"; 
cout << "Cota elaborada"<< endl;

int sol2=PagarRYP(V0,C0,N0,V1,NN);
cout<<"Numero monedas: "<<sol2 <<" Num Nodos: " << NN <<endl;
cout << "Solucion: " << endl;
mostrarVector(V1,N0);


cout << "\n"; 
cout << "Sin Podas"<< endl;
int sol3=PagarRYPSinPodas(V0,C0,N0,V1,NN);
cout<< "Numero monedas: "<< sol3 <<" Num Nodos: " << NN <<endl;
cout << "Solucion: " << endl;
mostrarVector(V1,N0);

cout << "\n"; 
cout << "\n"; 

cout << "Segunda Prueba" << endl;
cout << "\n"; 
cout << "el vector es: ";
mostrarVector(V0,N0);
cout << "y se busca pagar la cantidad: " << C1 << "\n";
cout << "\n"; 
cout <<"Cota ingenua";
 sol1=PagarRYPIngenuo(V0,C1,N0,V1,NN);
cout << "\n" ;
cout<<"Numero monedas: "<<sol1 <<" Num Nodos: " << NN <<endl;
cout << "Solucion: " << endl;
mostrarVector(V1,N0);
 
cout << "\n"; 
cout << "Cota elaborada"<< endl;

 sol2=PagarRYP(V0,C1,N0,V1,NN);
cout<<"Numero monedas: "<<sol2 <<" Num Nodos: " << NN <<endl;
cout << "Solucion: " << endl;
mostrarVector(V1,N0);


cout << "\n"; 
cout << "Sin Podas"<< endl;
 sol3=PagarRYPSinPodas(V0,C1,N0,V1,NN);
cout<< "Numero monedas: "<< sol3 <<" Num Nodos: " << NN <<endl;
cout << "Solucion: " << endl;
mostrarVector(V1,N0);	

cout << "\n"; 
cout << "\n"; 
cout << "Tercera Prueba" << endl;
cout << "\n"; 
cout << "el vector es: ";
mostrarVector(V0,N0);
cout << "y se busca pagar la cantidad: " << C3 << "\n";
cout << "\n"; 
cout <<"Cota ingenua";
 sol1=PagarRYPIngenuo(V0,C3,N0,V1,NN);
cout << "\n" ;
cout<<"Numero monedas: "<<sol1 <<" Num Nodos: " << NN <<endl;
cout << "Solucion: " << endl;
mostrarVector(V1,N0);
 
cout << "\n"; 
cout << "Cota elaborada"<< endl;

 sol2=PagarRYP(V0,C3,N0,V1,NN);
cout<<"Numero monedas: "<<sol2 <<" Num Nodos: " << NN <<endl;
cout << "Solucion: " << endl;
mostrarVector(V1,N0);


cout << "\n"; 
cout << "Sin Podas"<< endl;
 sol3=PagarRYPSinPodas(V0,C3,N0,V1,NN);
cout<< "Numero monedas: "<< sol3 <<" Num Nodos: " << NN <<endl;
cout << "Solucion: " << endl;
mostrarVector(V1,N0);	
getchar();
}



	
