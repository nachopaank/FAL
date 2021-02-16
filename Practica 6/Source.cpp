


// Si se comenta esta definici�n, el programa
// autocomprobar� su funcionamiento comparando
// la implementaci�n realizada con una 
// implementaci�n 'naif' del algoritmo
#include <iostream>

#define DOM_JUDGE

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif 

using namespace std;

typedef unsigned long long t_num;
void func(t_num n, t_num& c, t_num cero, t_num length);
t_num potencial(t_num n);
t_num digito_mas_significativo(t_num n);
/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.



*/

t_num num_singulares_menoresque(t_num n) {
	// Punto de entrada al algoritmo.
	// A implementar
	t_num sig = n;
	t_num length = 1;
	if (n < 10) {
		return n;
	}
	while (sig > 9) {
		sig = sig / 10;
		length = length * 10;
	}
	t_num ns = 0;
	t_num x = 0;
	//n - (sig * length)
	
	t_num num = n - (sig * length);
	t_num all = potencial(num);
	func(num, ns, sig, length / 10);
	x = all - ns;
	sig--;
	
	while (sig > 0) {		
		x = x + all;
		sig--;
	}
	t_num test = 0;
	length = (length-1)/10;
	while (length > 0) {
		t_num test2 = 0;
		test2 = potencial(length)*9;
		test = test + test2;
		length = length / 10;
	}
	return n-x-test;


}
t_num potencial(t_num n) {
	t_num ret = 1;
	t_num sig = n;
	t_num length = 1;
	if (sig < 10) {
		return ret;
	}
	while (sig > 9) {
		sig = sig / 10;
		length = length * 10;
	}
	t_num result = length + potencial(n - (sig * length)) * 9;
	return result;

}
void func(t_num n, t_num& c, t_num cero, t_num length)

{

	if (n < cero && n > 0) {
		c = c+1;
	}
	else if (n<=9 || n==0)
	{

		c = c+0;
	}
	else

	{
		c = c + (9 - digito_mas_significativo(n)) * potencial(length / 10);
		if (digito_mas_significativo(n) >= cero) {
		}
		else {
			c = c + length-1;
			
		}
		func(n - (digito_mas_significativo(n) * length), c, cero, length / 10);
	}

}
t_num digito_mas_significativo(t_num n) {
	while (n > 9) {
		n = n / 10;
	}
	return n;
}
/*
Determina justificadamente la complejidad del algoritmo

(1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

(2) Resoluci�n utilizando los patrones vistos en clase

(3) Determinaci�n justificada de la complejidad del algoritmo final.


*/

#ifndef DOM_JUDGE
unsigned short digito_mas_significativo(t_num n) {
	while (n > 9) {
		n = n / 10;
	}
	return (unsigned short)n;
}
bool es_singular(t_num n) {
	unsigned short msd = digito_mas_significativo(n);
	bool loes = true;
	while (n > 9 && loes) {
		loes = (n % 10 != msd);
		n = n / 10;
	}
	return loes;
}

t_num num_singulares_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (es_singular(i)) {
			num++;
		}
	}
	return num;
}
#endif

#ifdef DOM_JUDGE
bool ejecuta_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_singulares_menoresque(n) << endl;
		return true;
	}
}
#endif

int main() {

#ifndef DOM_JUDGE
	srand(time(NULL));
	for (int i = 1; i < 1000; i++) {
		t_num  n = (t_num)rand();
		if (num_singulares_menoresque_naif(n) != num_singulares_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_singulares_menoresque_naif(n) << "..." << num_singulares_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif
}