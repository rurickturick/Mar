/***************************************************************/
/*                                                             */
/*            Autor: �ngel Luis Ortiz Folgado                  */
/*                                                             */
/***************************************************************/
#ifndef Pagar
#define Pagar
using namespace std;
struct nodo
{
    int *sol;
    int k ;  // indica el nivel del arbol explorado
    int cantidadFalta;
    int monedasUsadas;
    int CosteOpt; //prioridad es lo que realiza la poda
	
};
//necesaria para usar la cola de prioridad
class CompareNodo {
public:
    bool operator()(nodo& n1, nodo& n2)
    {
		if (n1.CosteOpt > n2.CosteOpt) return true;
		else  return false;
    }
};

//la funci�n PagarVoraz devuelve la soluci�n del problema usando el m�todo voraz. Se usar� como cota pesimista en el m�todo de ramificaci�n y poda
// S�lo devuelve el n�mero de monedas necesarias no necesito saber de que tipo.
// M [] es el vector de monedas disponibles, estar� ordenado de mayor a menor valor de las monedas y si hay varias de cada tipo aparecer�n varias seguidas
// Ej si el vector tiene dos monedas, de 5 una de 3 y tres de 1 ser�a M = {5,5,3,1,1,1}
//C es la cantidad a pagar y N la longitud del array
//i es el indice del vector a partir del que debo aplicar el algoritmo.
 int PagarVoraz(int M [],int C,int i, int N );

// la fuci�n CotaOp devuelve la cota optimista del metodo de ramificaci�n y poda :
//(el n�mero de monedas usadas hasta el momento) +
 // (el resultado redondeado al alza  de dividir lo que queda por pagar entre el valor de la primera moneda m�s peque�a a ese valor)   
//C es la cantidad que falta por pagar,N la longitud del array M, k es la moneda del array que estoy considerando en ese momento
// mUsaudas en la cantida de monedas usadas hasta ese momento
 int CotaOp( int M[],int C,int N,int mUsadas,int k);

 // la fuci�n CotaPesimistaIngenua devuelve una cota pesimista "ingenua" para  el metodo de ramificaci�n y poda :
//(el n�mero de monedas usadas hasta el momento) + el n�mero de monedas que quedan por considerar
 // N la longitud del array M, k es la moneda del array que estoy considerando en ese momento
// mUsaudas en la cantida de monedas usadas hasta ese momento
 // C es la cantidad que falta
 int cotaPesimistaIngenua(int M[],int N,int mUsadas,int k,int C);

 // la funci�n PagarRYP devuelve la soluci�n del problema usando el m�todo de Ramificaci�n y Poda
 //  M [] es el vector de monedas disponibles, estar� ordenado de mayor a menor valor de las monedas y si hay varias de cada tipo aparecer�n varias seguidas
// Ej si el vector tiene dos monedas, de 5 una de 3 y tres de 1 ser�a M = {5,5,3,1,1,1}
 //C es la cantidad a pagar y N la longitud del array. Sol es donde se devolver� la soluci�n.
 //numNodos devuelve el numero de nodos explorados en la ramificacion y poda
 int PagarRYP( int M[],int C,int N, int Sol[],int& numNodos);
 //hace el m�todo de ramificaci�n y poda pero con cotas ingenuas
 int PagarRYPIngenuo( int M[],int C,int N, int Sol[],int& numNodos);

 //hace el metodo de ramificacion y poda pero solo podando con satisfactibilidad
 int PagarRYPSinPodas(int M[],int C,int N,int Sol[],int &numNodos);

#endif