

#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  k > 0
  0 < n <= tam(a)
  PARATODO i:0<=i<n: 0 < a[i] <= k
*/

int llena_mochila(const int a[], int n, int k);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

  resul = max i,j:0<=i<=j<n && nproductos(a,i,j,k): (j-i)+1
  nproductos(a,i,j,k) =  (SUMA u: i <= u <= j) < k
 */


 /*
 DISE�O DEL ALGORITMO:

 Paso 1. Variables
 Ademas de lo parámetros a,n,k y resul, una variable i de control y una variable "suma" que lleve la suma parcial

 Paso 2. Invariante
 a,n y k no son modificados durante la ejecucion del problema
 llena_mochila(a,n,k) && 0 <= i <= n && 0 <= suma <= (sum x: 0 <= x <= n: a[x]) && 0 <= resul <= i

 Paso 3. Inicializaci�n
 i = 0
 sum = 0
 resul = 0

 Paso 4. Condici�n del bucle, y c�digo tras el bucle.
 i < n
 Cuando sale del bucle aseguramos i >= n && resul >= 0
 Como i <= n (por invariante), deducimos que  n <= i <= n, entonces i = n

 Paso 5. Cuerpo del bucle
 Incondicionalmente actualizo suma, sumandole el correspondiente contenido del elemento del vector
 2 casos:
	la suma no supera la capacidad de la mochila (suma <= k) -> resul++
	la suma supera la capacidad de la mochila (suma > k) -> suma -= a[i-resul]
 Actualizamos incondicionalmente la variable de control
 Paso 6. Justificaci�n de que el algoritmo siempre termina.
 Cota: n - i
 Por el cuerpo del bucle se incrementa i, n-i decrece.
 Por el invariante 0<=i<=n, por lo que el algoritmo termina
 n-i = 0, puesto que tras el bucle i = n

 Paso 7. Complejidad:
 Las 2 primeras instrucciones tienen coste constante K0
 Dentro del bucle: Se ejecuta una instruccion de coste constante + una instruccion de coste constante K1 si se cumple la condicion o una instruccion de coste constante K2 en caso contrario
 Podemos acotarlo de forma K0 + (1+K1)*n <= T(n) <= K0 + (1+K2)*n
 Ambos casos son de la forma A*n + B por lo que el coste es de orden lineal O(n)

 */

int llena_mochila(const int a[], int n, int k) {
	// A IMPLEMENTAR
	int suma = 0;
	int resul = 0;
	for (int i = 0; i < n; i++) {
		suma += a[i];
		if (suma <= k) {
			resul++;
		}
		else {
			suma -= a[i-resul];
		}
	}
	return resul;
}

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
			int k;
			cin >> k;
			cout << llena_mochila(a, n, k) << endl;
		}
	} while (n != -1);
}