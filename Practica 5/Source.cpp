

#include <iostream>
using namespace std;

/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.

  *** RESPONDE AQUI AL APARTADO 1
bool interesting(int n, int postSum, int &preSum) return bool
n y postSum son parametros de entrada, preSum es de entrada salida, bool es de salida
n contiene la lista de dígitos que nos quedan por comprobar, (por lo que puedo acceder al digito actual con n%10)
postSum contiene la suma de los digitos ubicados a la derecha del digito actual respecto al número original
preSum contiene la suma de los digitos ubicados a la izquierda del digito actual respecto al número original
bool devuelve si se han cumplido las condiciones del problema a la solucion parcial


(2) An�lisis de casos:

(2.1) Casos base

  *** RESPONDE AQUI AL APARTADO 2.1
  n == 0 -> true (he llegado al final del número)
  n % 10 -> false (por condicion del problema si un dígito es 0 el numero no puede ser interesante)

(2.2) Casos recursivos

  *** RESPONDE AQUI AL APARTADO 2.2
  n > 0 -> se resuelve el problema para (n%10) donde el problema es true si tanto la suma de los digitos a la izquierda o derecha de un dígito es divisible por dicho dígito
  (se pasa por parámetro n/10 y no n%10 para no perder los dígitos a la izquierda del dígito actual)


(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

  *** RESPONDE AQUI AL APARTADO 3
  El algoritmo comienza con el número original, las sumas de los dígitos son = 0 y si el número es mayor que 0
  Si el número que llega a la recursión es 0 quiere decir que ya hemos recorrido todos los dígitos de derecha a izquierda (caso base)
  Si el dígito actual es 0 el problema debe devolver false
  La solución del problema viene dada por la conjuncion de 3 condiciones: que la suma de los digitos a la derecha de actual se puede dividir por el digito (a), 
  que la suma de los digitos a la izquierda de actual se puede dividir por el digito (c) y que estas 2 condiciones se cumplan para todos los dígitos (b)
  Como recorro de derecha a izquierda puedo llevar la cuenta para los dígitos a la derecha, sin embargo para la izquierda no.
  Para obtener la suma de los dígitos a la izquierda tengo que esperar a llegar al caso base donde si puedo acceder a dichos dígitos a la VUELTA de la recursion


*/

bool interesting(unsigned int n, unsigned int postSum,unsigned int &preSum) {
	
	if (n == 0) { return true; }
	if (n % 10 == 0) {
		return false;
	}
	bool a = postSum % (n % 10) == 0;
	bool b = interesting(n / 10, postSum + (n % 10),preSum);
	bool c = preSum % (n % 10) == 0;
	preSum = preSum + (n % 10);
	return a && b && c;
}

bool es_interesante(unsigned int n) {
	unsigned int preS = 0;
	return n > 0 && interesting(n, 0, preS);
}

void ejecuta_caso() {
	unsigned int n;
	cin >> n;
	if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}