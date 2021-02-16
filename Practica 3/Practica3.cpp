#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  0 <= n < tam(a)

*/
int num_chupiguays(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
  resul = #i : 0 <= i < n: (a[i] % (SUMA j : 0 <= j < i: a[j]):j!=0 == 0 || a[i] == 0)



 */


 /*
 DISE�O DEL ALGORITMO:
 -- Especifica cada paso del dise�o en cada apartado indicado

 Paso 1. Variables

 Aparte de los parámentros(a,n,resul), una variable i de control y una variable "suma" que vaya llevando la suma parcial del vector en función de i

 Paso 2. Invariante
	El problema tambien da una solución para el tramo del vector explorado
	num_chupiguays(a,i,n)
	0 <= i <= n
	sum = SUMA(a,i)

 Paso 3. Inicializaci�n
	i = 0
	resul = #i : 0 <= u < i: (a[i] % (SUMA j : 0 <= j < i: a[j]):j!=0 == 0 || a[i] == 0) = 
		  = #i : 0 <= u < 0: (a[i] % (SUMA j : 0 <= j < i: a[j]):j!=0 == 0 || a[i] == 0) = 
		  = #i : false: (a[i] % (SUMA j : 0 <= j < i: a[j]):j!=0 == 0 || a[i] == 0) = 0
	resul = 0
	suma = j : 0 <= j < i: a[i]
		= j : 0 <= j < 0: a[i]
		= j : false:a[i] = 0 
 Paso 4. Condici�n del bucle, y c�digo tras el bucle

	Condición i < n
	Cuando sale del bucle aseguramos i >= n && resul >= 0
	Como i <= n (por invariante), deducimos que  n <= i <= n, entonces i = n
 Paso 5. Cuerpo del bucle
	Dos casos:
	(1) a[i] % suma == 0 (con la excepción de que suma == 0 puesto que no se puede realizar ese cálculo)
	(2) a[i] == 0
	En ambos casos se incrementa resul. Como tras el bucle sabemos que i = n podemos deducir que resul esta acotado de forma 0 <= resul <= n

	Actualizamos incondicionalmente la variable de control
	Actualizamos incondicionalmente suma tal que suma += a[i]


 Paso 6. Justificaci�n de que el algoritmo siempre termina
	Expresion de cota: n-i
	Por el cuerpo del bucle se incrementa i, n-i decrece.
	Por el invariante 0<=i<=n, por lo que el algoritmo termina
	n-i = 0, puesto que tras el bucle i = n

 Paso 7. Complejidad
	Las 3 primeras instrucciones tienen coste constante K0
	Dentro del bucle:
	Si se cumple la condicion se ejecutan 3 instrucciones de coste constante K1
	Si no se cumple se ejecutan 2 instrucciones de coste constante K2
	Podemos acotar el coste de la siguiente forma Ko + K1 n <= T(n) <= Ko + K2 n
	Tanto el caso mejor como el peor es de la forma A*n + B, por lo que la funcion es de orden lineal O(n)
 */


int num_chupiguays(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int i = 0;
	int resul = 0;
	int suma = 0;
	while (i < n) {
		if ((suma != 0 && a[i] % suma == 0) || a[i] == 0) {
			resul++;
		}
		suma = suma + a[i];
		i++;
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
			cout << num_chupiguays(a, n) << endl;
		}
	} while (n != -1);
}