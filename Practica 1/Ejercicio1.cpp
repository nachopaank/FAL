

#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habra vectores de mas de un millon de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqui la precondicion de la funcion.
  0<=n<=TMAX
*/
bool divertida(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:

  Q: { resul = (  (PARATODO i:0<=i<n:(SUMA j:0<=j<=i:a[i])>=0) && ( (SUMA i:0<=i<n:a[i])=0 ) ) }

 */




bool divertida(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int suma = 0;
	bool divertida = true;
	for (int i = 0; i < n; i++) {
		suma += a[i];
		if (suma < 0) divertida = false;
	}
	if (suma != 0) divertida = false;
	return divertida;
}

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso
   -- de este algoritmo, indicando claramente cual es el tamano del problema
	En el caso peor la funcion no es divertida por la condicion de que todos sus elementos no suman 0 pero si son positivos a lo largo del recorrido del vector
   Se ejecuta una vez el bucle en funcion de n que es el tamaño del vector
   Por lo que es orden lineal O(N)
*/




/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR! */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	static int a[TMAX];
	int n;
	do {
		lee_vector(a, n);
		if (n >= 0) {
			if (divertida(a, n))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
	} while (n != -1);
}