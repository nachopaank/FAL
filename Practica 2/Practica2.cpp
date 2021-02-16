
#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos



/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  0 < n < tam(a)
  PARATODO i:0 <= i < TMAX: a[i] <= a[i+1]

*/
int menor_moda(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
  num_repeticiones(v,a,n) = #i : 0 <= i < n: a[i] = v
  esta_en(v,a,n) = EXISTE i: 0<=i<n: a[i] = v
  resul = esta_en(resul,a,n) && num_repeticiones(resul,a,n) = min(max i:0<=i<n:num_repeticiones(a[i],a,n))

*/



int menor_moda(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	bool end = true;
	int i = 1;
	int num = a[0];
	int modaC = 1;
	int modaF = 1;
	while (i < n && end) {
		if (a[i] > a[i-1]) {
			modaC = 1;
		}
		else {
			modaC++;
		}
		if (modaC > modaF) {
			modaF = modaC;
			num = a[i];
		}
		if (i + modaF - modaC >= n) {
			end = false;
		}
		i++;
	}
	return num;
}

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema
   El problema depende del tamaño del vector "n". Se ejecuta un bucle de tamaño n menos un numero x dado por el siguiente calculo:
   Si la moda que actualmente se lleva es mayor o igual que el numero de elementos restantes en el vector, es imposible encontrar una moda mejor dadas las condiciones del problema
   Orden de O(n-x)

   Las 5 primeras instrucciones tienes coste constante K0
   Dentro del cuerpo del while en el caso peor se ejecutan una suma 3 instrucciones if y sus correspondientes cuerpos siendo el primer if 1+1, el segundo 1+2 y el tercer if 1+1, quedando
   1+2+3+2 = 8 -> coste constante K1
   El coste queda K0 + Sumatorio de i=0 hasta i=n de i*K1
   A*n + B por lo que la funcion es O(n)

*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

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
			cout << menor_moda(a, n) << endl;
		}
	} while (n != -1);
}