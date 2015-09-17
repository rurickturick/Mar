/***************************************************************/
/*                                                             */
/*            Autor: Ángel Luis Ortiz Folgado                  */
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

//la función PagarVoraz devuelve la solución del problema usando el método voraz. Se usará como cota pesimista en el método de ramificación y poda
// Sólo devuelve el número de monedas necesarias no necesito saber de que tipo.
// M [] es el vector de monedas disponibles, estará ordenado de mayor a menor valor de las monedas y si hay varias de cada tipo aparecerán varias seguidas
// Ej si el vector tiene dos monedas, de 5 una de 3 y tres de 1 sería M = {5,5,3,1,1,1}
//C es la cantidad a pagar y N la longitud del array
//i es el indice del vector a partir del que debo aplicar el algoritmo.
 int PagarVoraz(int M [],int C,int i, int N );

// la fución CotaOp devuelve la cota optimista del metodo de ramificación y poda :
//(el número de monedas usadas hasta el momento) +
 // (el resultado redondeado al alza  de dividir lo que queda por pagar entre el valor de la primera moneda más pequeña a ese valor)   
//C es la cantidad que falta por pagar,N la longitud del array M, k es la moneda del array que estoy considerando en ese momento
// mUsaudas en la cantida de monedas usadas hasta ese momento
 int CotaOp( int M[],int C,int N,int mUsadas,int k);

 // la fución CotaPesimistaIngenua devuelve una cota pesimista "ingenua" para  el metodo de ramificación y poda :
//(el número de monedas usadas hasta el momento) + el número de monedas que quedan por considerar
 // N la longitud del array M, k es la moneda del array que estoy considerando en ese momento
// mUsaudas en la cantida de monedas usadas hasta ese momento
 // C es la cantidad que falta
 int cotaPesimistaIngenua(int M[],int N,int mUsadas,int k,int C);

 // la función PagarRYP devuelve la solución del problema usando el método de Ramificación y Poda
 //  M [] es el vector de monedas disponibles, estará ordenado de mayor a menor valor de las monedas y si hay varias de cada tipo aparecerán varias seguidas
// Ej si el vector tiene dos monedas, de 5 una de 3 y tres de 1 sería M = {5,5,3,1,1,1}
 //C es la cantidad a pagar y N la longitud del array. Sol es donde se devolverá la solución.
 //numNodos devuelve el numero de nodos explorados en la ramificacion y poda
 int PagarRYP( int M[],int C,int N, int Sol[],int& numNodos);
 //hace el método de ramificación y poda pero con cotas ingenuas
 int PagarRYPIngenuo( int M[],int C,int N, int Sol[],int& numNodos);

 //hace el metodo de ramificacion y poda pero solo podando con satisfactibilidad
 int PagarRYPSinPodas(int M[],int C,int N,int Sol[],int &numNodos);

#endif