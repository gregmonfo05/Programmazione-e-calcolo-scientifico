#include <iostream>
#include <vector>
#include "randfiller.h"
#include <random>
#include <algorithm>
#include "algoritmi_sorting.hpp"
#include <string>

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
	for (int i = 1; i <= 100; i++){    // eseguo il test su 100 vettori di dimensioni casuali e riempiti con numeri casuali
		randfiller rs;
		vector<int> dim_vec;
		dim_vec.resize(1);
		rs.fill(dim_vec, 1, 100);     // dimensione casuale da 1 a 100
		randfiller rf;
		vector<double> vd;
		vd.resize(dim_vec[0]);
		rf.fill(vd, -100.0, 100.0);    // riempio il vettore con numeri double casuali da -100 a 100
		int p = 0;
		int r = dim_vec[0]-1;
		quick_sort(vd,p,r);
		bool ordinato = is_sorted(vd);
		if (!ordinato){
			return EXIT_FAILURE;
		}
	}
	vector<string> players = {"Messi", "Cristiano Ronaldo", "Pelè", "Maradona", "Cruyff", "Ronaldo il fenomeno", "Di Stefano", "Romario", "Iniesta", "Maldini"};
	int p = 0;
	int r = ssize(players)-1;    // comando per calcolare la dimensione di una stringa
	quick_sort(players,p,r);     // eseguo il test su una stringa
	bool ordinato = is_sorted(players);
	if (!ordinato){
		return EXIT_FAILURE;
	}
	print_vector(players);       // se la stringa viene stampata sul terminale significa che il test complessivo è andato a buon fine
	return EXIT_SUCCESS;
}