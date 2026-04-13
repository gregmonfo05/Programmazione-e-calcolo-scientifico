#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>
#include "randfiller.h"
#include "algoritmi_sorting.hpp"
#include "timecounter.h"


using namespace std;

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main(){
	const int N = 12;       // numero di vettori di cui calcola il tempo con le quattro funzioni.
	vector<double> tempi_bubble_sort(N);    
	vector<double> tempi_insertion_sort(N);
	vector<double> tempi_selection_sort(N);
	vector<double> tempi_cpp_sort(N);
	int indice = 0;
	for (int n = 4; n <= 8192; n *= 2){
		randfiller rf;
		vector<double> v;
		v.resize(n);
		rf.fill(v, -100.0, 100.0);
		vector<double> v_bubble = v;       //creo 4 copie perchè altrimenti ordino il vettore iniziale la prima volta e non ho più quello originale a disposizione
		vector<double> v_insertion = v;
		vector<double> v_selection = v;
		vector<double> v_sort = v; 
		timecounter tc1;
		tc1.tic();
		bubble_sort(v_bubble);
		double time_bubble = tc1.toc();
		tempi_bubble_sort[indice] = time_bubble;
		timecounter tc2;
		tc2.tic();
		insertion_sort(v_insertion);
		double time_insertion = tc2.toc();
		tempi_insertion_sort[indice] = time_insertion;
		timecounter tc3;
		tc3.tic();
		selection_sort(v_selection);
		double time_selection = tc3.toc();
		tempi_selection_sort[indice] = time_selection;
		timecounter tc4;
		tc4.tic();
		sort(v_sort.begin(),v_sort.end());
		double time_sort = tc4.toc();
		tempi_cpp_sort[indice] = time_sort;
		cout << "Dimensione del vettore: " << n << "\n";
		// print_vector(v);
		cout << "Bubble sort: " << time_bubble << " s, Insertion sort: " << time_insertion << " s, Selection sort: " << time_selection << " s, Function sort: " << time_sort << " s" << "\n";
		indice++;
	}
	cout << "\n";
	cout << "Tempi Bubble sort: ";
	print_vector(tempi_bubble_sort);
	cout << "Tempi Insertion sort: ";
	print_vector(tempi_insertion_sort);
	cout << "Tempi Selection sort: ";
	print_vector(tempi_selection_sort);
	cout << "Tempi Funzione sort: ";
	print_vector(tempi_cpp_sort);
	return 0;
}

	
		
		
		
		
		
		
		
		
		
		
		