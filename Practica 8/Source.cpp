

#include <iostream>
using namespace std;

const unsigned int MAX_CLIENTES = 10; // maximo numero de clientes
  // Representaci�n de la matriz de afinidades
typedef struct {
	unsigned int n_clientes;                              // numero de clientes. 
	unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES];  // la matriz se almacena en las 'n_clientes' primeras filas,
														  // 'n_clientes' primeras columnas	                                                      
} tMatrizAfinidad;


/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

void encontrar_afinidad(const tMatrizAfinidad& as, int n, int parejas[], int mejorParejas[], int n_clientes, int marcas[]);

int n = el cliente actual
int parejas[] = la solucion parcial del problema
int mejorParejas[] = donde almaceno la solucion parcial mas óptima
int n_clientes = cota superior para poder recorrer los arrays y distinguir al ultimo cliente
int marcas[] = para poder comprobar si un cliente ya había sido asignado a otro cliente. =1 si esta asignado en ese momento, =-1 si no esta asignado en ese momento

(2) �C�mo son las soluciones parciales de este problema?

Las soluciones parciales consisten en un vector cuya posición indica el cliente y el valor indica la cantidad de compatibilidad de OTRO cliente hacia el propio.

(3) �Cu�ndo una soluci�n parcial es viable?

Una solución parcial es viable si se cumple:
Supongamos una pareja x,y
Si la compatibilidad de x hacia y no es 0
Si la compatibilidad de y hacia x no es 0
Si x no tenia ya pareja (marcas)
Si y no tenia ya pareja (marcas)
x,y no pueden ser la misma persona

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

Una solucion parcial es final cuando TODOS los clientes tienen pareja y además la suma de la compatibilidad entre todas las parejas es máxima

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

Se marcan los clientes que ya tienen parejas para que no se tengan en cuenta en el futuro y se procede a buscar la solucion parcial del siguiente cliente en la lista.
Si este cliente ya estaba marcado, se pasa al siguiente.
Una vez acaba con la lista se desmarcan los clientes de dicha solucion parcial para poder usarlos en otra solucion parcial potencialmente mejor

(6) An�lisis de casos

(6.1) Caso(s) base

	Se llega al final de la lista de clientes: (en el algoritmo el final se toma como el penúltimo dado que si se ha llegado a una solución parcial viable, el último cliente ya debe tener asignada una pareja válida
	Si el total de compatibilidad generado por la solucion parcial es mayor que el total generado por una solucion anterior, se actualiza la solucion final

(6.2) Caso(s) recursivos
	1. Si mi cliente actual (n) ya tiene pareja, paso al siguiente
	2. En caso contrario, si la asignacion de un cliente a otro x es viable, se añade a la solucion parcial y se de paso al siguiente cliente

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.

Antes de entrar al algoritmo final:
Comprobar que el numero de clientes es par, sino alguien se quedaria sin pareja
Preparar las soluciones parciales y la final, las soluciones son = 0, todavia no hay ninguna pareja.
Preparar las marcas, todas desmarcadas desde el principio (=-1)
Al terminar:
Devuelvo la suma de los elementos de la solución óptima, dada por mejorParejas

*/
bool esMejorParejas(int parejas[], int mejorParejas[], int tam) {
	int sum = 0;
	int sum2 = 0;
	for (int i = 0; i < tam; i++) {
		sum = sum + parejas[i];
		sum2 = sum2 + mejorParejas[i];
	}
	return sum > sum2;
}
void actualizaParejas(int parejas[], int mejorParejas[], int tam) {
	for (int i = 0; i < tam; i++) {
		mejorParejas[i] = parejas[i];
	}

}
int result(int mejorParejas[], int tam) {
	int sum = 0;
	for (int i = 0; i < tam; i++) {
		sum = sum + mejorParejas[i];
	}
	return sum;
}
void initialize(int marcas[], int parejas[], int mejorParejas[],int size) {
	for (int i = 0; i < size; i++) {
		marcas[i] = -1;
		parejas[i] = 0;
		mejorParejas[i] = 0;
	}
}
void encontrar_afinidad(const tMatrizAfinidad& as, int n, int parejas[], int mejorParejas[], int n_clientes, int marcas[]) {
	if (n == n_clientes-1) {
		if (esMejorParejas(parejas, mejorParejas, n_clientes)) {
			actualizaParejas(parejas, mejorParejas, n_clientes);
		}
	}
	else {
		if (marcas[n] == 1) {
			encontrar_afinidad(as, n + 1, parejas, mejorParejas, n_clientes, marcas);
		}
		else {
			for (int j = 0; j < n_clientes; j++) {
				if (as.afinidades[n][j] != 0 && as.afinidades[j][n] != 0 && marcas[n] == -1 && marcas[j] == -1 && n != j) {
					marcas[n] = 1;
					marcas[j] = 1;
					parejas[n] = as.afinidades[n][j];
					parejas[j] = as.afinidades[j][n];
					encontrar_afinidad(as, n + 1, parejas, mejorParejas, n_clientes, marcas);
					marcas[n] = -1;
					marcas[j] = -1;

				}
			}
		}
	}
}
int maxima_afinidad(const tMatrizAfinidad& as) {

	// Punto de entrada al algoritmo: as representa la matriz de afinidades 
	// (ver definici�n de tMatrizAfinidad). Una vez finalizado el algoritmo,
	// deber� devolverse el valor pedido. Pueden definirse todas las 
	// funciones auxiliares que se considere oportuno.
	if (as.n_clientes % 2 != 0) {
		return 0;
	}
	int size = as.n_clientes;
	int marcas[MAX_CLIENTES];
	int parejas[MAX_CLIENTES];
	int mejorParejas[MAX_CLIENTES];
	initialize(marcas, parejas, mejorParejas,size);
	encontrar_afinidad(as, 0, parejas, mejorParejas, size, marcas);
	return result(mejorParejas, size);
}


void ejecuta_caso() {
	tMatrizAfinidad as;
	cin >> as.n_clientes;
	for (unsigned int i = 0; i < as.n_clientes; i++) {
		for (unsigned int j = 0; j < as.n_clientes; j++) {
			cin >> as.afinidades[i][j];
		}
	}
	cout << maxima_afinidad(as) << endl;
}


int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (unsigned int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}