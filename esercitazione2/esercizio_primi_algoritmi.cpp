#include <iostream>
#include <cmath>
using namespace std;

int main() {
	static const int N = 10;
	double array[N] = {1.1, 2.1, 3.4, 5.6, 6.2, 9.8, 10.1, 2.3, 4.5, 1.9};
	double minimo = array[0];
	double massimo = array[0];
	for (int i = 1; i < N; i++){
		minimo = min(minimo, array[i]);
		massimo = max(massimo, array[i]);
	}
	cout << "Il minimo dell'array è: " << minimo << "\n";
	cout << "Il massimo dell'array è: " << massimo << "\n";
	double somma = 0.0;
	for (int i = 0; i < N; i++){
		somma += array[i];
	}
	double media = somma/N;
	double somma_quadrati = 0.0;
	for (int i = 0; i < N; i++){
		somma_quadrati += pow((array[i] - media),2);
	}
	double varianza = somma_quadrati/N;
	double dev_standard = sqrt(varianza);
	cout << "La media degli elementi dell'array è: " << media << "\n";
	cout << "La deviazione standard dell'array è: " << dev_standard << "\n";
	
	return 0;
}
