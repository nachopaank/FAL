

#include <iostream>

using namespace std;


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

(4) An�lisis de la complejidad del algoritmo

*/
int suma_parcial(int enemigos[], int ini, int fin) {
	int result = 0;
	while (ini < fin) {
		result = result + enemigos[ini];
		ini++;
	}
	return result;

}
int divide(int enemigos[], int &ini, int &fin, int &mitad, int &sumaIzq, int &sumaDer) {
	mitad = (fin - ini) / 2;
	sumaIzq = suma_parcial(enemigos, ini, mitad);
	sumaDer = suma_parcial(enemigos, mitad, fin);
	int maxi = max(sumaIzq, sumaDer);
	if (sumaIzq < sumaDer) {
		int miniAux = max(suma_parcial(enemigos, ini, mitad + 1), suma_parcial(enemigos, mitad + 1, fin));
		while (miniAux < maxi) {
			maxi = miniAux;
			mitad++;
			miniAux = max(suma_parcial(enemigos, ini, mitad + 1), suma_parcial(enemigos, mitad + 1, fin));
		}
		sumaIzq = suma_parcial(enemigos, ini, mitad);
		sumaDer = suma_parcial(enemigos, mitad, fin);
	}
	if (sumaDer > sumaIzq) {
		int miniAux = max(suma_parcial(enemigos, ini, mitad - 1), suma_parcial(enemigos, mitad - 1, fin));
		while (miniAux < maxi) {
			maxi = miniAux;
			mitad--;
			miniAux = max(suma_parcial(enemigos, ini, mitad - 1), suma_parcial(enemigos, mitad - 1, fin));
		}
		sumaIzq = suma_parcial(enemigos, ini, mitad);
		sumaDer = suma_parcial(enemigos, mitad, fin);
	}
	return maxi;

}
int min_poder(int enemigos[], int n, int max_duelos) {
	int ini = 0;
	int fin = n;
	int mitad = 0;
	int sumaIzq = 0;
	int sumaDer = 0;
	int min_pod = 0;
	int iniAux = 0;
	int finAux = 0;
	int sumaAux = 0;
	if (max_duelos == 0) {
		return 0;
	}
	if (max_duelos == 1) {
		return suma_parcial(enemigos, ini, fin);
	}
	while (max_duelos > 2) {
		min_pod = divide(enemigos, ini, fin, mitad, sumaIzq, sumaDer);
		if (sumaIzq >= sumaDer) {
			int reserve = ini;
			if (sumaAux > sumaDer) {
				ini = iniAux;		
				fin = finAux;	
				iniAux = reserve;
				finAux = mitad;
				sumaAux = sumaIzq;
			}
			else {
				
				iniAux = mitad;
				finAux = fin;
				sumaAux = sumaDer;
				fin = mitad;
			}
			
		}
		else {
			int reserve = fin;
			if (sumaAux > sumaIzq) {			
				ini = iniAux;
				fin = finAux;	
				iniAux = mitad;
				finAux = reserve;
				sumaAux = sumaDer;
			}
			else {
				iniAux = ini;
				finAux = mitad;
				sumaAux = sumaIzq;
				ini = mitad;
			}
			
		}	
		max_duelos--;
	}
	min_pod = divide(enemigos, ini, fin, mitad, sumaIzq, sumaDer);
	// Punto de entrada al algoritmo: a implementar
	return max(sumaAux,min_pod);
}


const int MAX_ENEMIGOS = 1000;
bool ejecuta_caso() {
	int enemigos[MAX_ENEMIGOS];
	int num_enemigos;
	cin >> num_enemigos;
	if (num_enemigos == -1) {
		return false;
	}
	else {
		int max_torneos;
		cin >> max_torneos;
		for (int i = 0; i < num_enemigos; i++) {
			cin >> enemigos[i];
		}
		cout << min_poder(enemigos, num_enemigos, max_torneos) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}