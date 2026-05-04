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
print_vector(const vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void filling_vector(vector<vector<double>>& vector_list, const int& N, const int& i)
{
	vector_list.resize(N);
    for (int j = 1; j < N+1; j++){
		randfiller rf;
		vector<double> v;
		v.resize(i);
		rf.fill(v, -100.0, 100.0);
		vector_list[j-1] = v;
	}
} 

int main(){
	int N = 100;
	vector<double> tempi_bubble_sort(N);    
	vector<double> tempi_insertion_sort(N);
	vector<double> tempi_selection_sort(N);
	vector<double> tempi_cpp_sort(N);
	vector<double> tempi_merge_sort(N);    
	vector<double> tempi_quick_sort(N);
	vector<double> tempi_optimized_quick_sort(N);
	for (int i = 1; i < N+1; i++){
		vector<vector<double>> vector_list;
		filling_vector(vector_list,N,i);
		vector<vector<double>> copia = vector_list;
		timecounter tc1;
		tc1.tic();
		for (int j = 0; j < N; j++){
			bubble_sort(copia[j]);
		}
		double time_bubble = tc1.toc();
		tempi_bubble_sort[i-1] = time_bubble/N;
		copia = vector_list;
		tc1.tic();
		for (int j = 0; j < N; j++){
			insertion_sort(copia[j]);
		}
		double time_insertion = tc1.toc();
		tempi_insertion_sort[i-1] = time_insertion/N;
		copia = vector_list;
		tc1.tic();
		for (int j = 0; j < N; j++){
			selection_sort(copia[j]);
		}
		double time_selection = tc1.toc();
		tempi_selection_sort[i-1] = time_selection/N;
		copia = vector_list;
		tc1.tic();
		for (int j = 0; j < N; j++){
			sort(copia[j].begin(), copia[j].end());
		}
		double time_cpp_sort = tc1.toc();
		tempi_cpp_sort[i-1] = time_cpp_sort/N;
		copia = vector_list;
		tc1.tic();
		for (int j = 0; j < N; j++){
			merge_sort(copia[j], 0, copia[j].size() - 1);
		}
		double time_merge_sort = tc1.toc();
		tempi_merge_sort[i-1] = time_merge_sort/N;
		copia = vector_list;
		tc1.tic();
		for (int j = 0; j < N; j++){
			quick_sort(copia[j], 0, copia[j].size() - 1);
		}
		double time_quick_sort = tc1.toc();
		tempi_quick_sort[i-1] = time_quick_sort/N;
		tc1.tic();
		for (int j = 0; j < N; j++){
			optimized_quick_sort(copia[j],0,copia[j].size()-1);
		}
		double time_optimized_quick_sort = tc1.toc();
		tempi_optimized_quick_sort[i-1] = time_optimized_quick_sort/N;
	}
	for (int i = 0; i < N; i++){
		cout << "Dimensione: " << i+1 << "\n";
		cout << "Bubble sort: " << tempi_bubble_sort[i] << "\n";
		cout << "Insertion sort: " << tempi_insertion_sort[i] << "\n";
		cout << "Selection sort: " << tempi_selection_sort[i] << "\n";
		cout << "Funzione sort: " << tempi_cpp_sort[i] << "\n";
		cout << "Merge sort: " << tempi_merge_sort[i] << "\n";
		cout << "Quick sort: " << tempi_quick_sort[i] << "\n";
		cout << "Optimized Quick sort: " << tempi_optimized_quick_sort[i] << "\n";
	}
	for (int i = 0; i < N; ++i) {
    // 1. Mettiamo tutti i tempi in un array temporaneo per scorrerli facilmente
		double tempi[] = {
        tempi_bubble_sort[i], 
        tempi_insertion_sort[i], 
        tempi_selection_sort[i], 
        tempi_cpp_sort[i], 
        tempi_merge_sort[i], 
        tempi_quick_sort[i],
		tempi_optimized_quick_sort[i]
		};
    
    // 2. Creiamo un array di nomi corrispondenti 
		std::string nomi[] = {
        "Bubble", "Insertion", "Selection", "Funzione sort", "Merge", "Quick", "Optimized Quick"
		};

    // 3. Cerchiamo il minimo e il massimo a mano
		int indice_min = 0;
		int indice_max = 0;

		for (int j = 1; j < 7; ++j) {
			if (tempi[j] < tempi[indice_min]) {
				indice_min = j;
			}
			if (tempi[j] > tempi[indice_max]) {
				indice_max = j;
			}
		}

    // 4. Stampiamo i risultati usando gli indici trovati
		std::cout << "Dimensione " << i+1 << ": "
				  << "Più veloce: " << nomi[indice_min] << " | "
				  << "Più lento: " << nomi[indice_max] << "\n";
	}
	return 0;
}
		