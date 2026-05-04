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
		optimized_quick_sort(vd, 0, vd.size()-1);
		bool ordinato = is_sorted(vd);
		if (!ordinato){
			return EXIT_FAILURE;
		}
	}
	vector<string> players = {"Messi", "Cristiano Ronaldo", "Pelè", "Maradona", "Cruyff", "Ronaldo il fenomeno", "Di Stefano", "Romario", "Iniesta", "Maldini"};
	optimized_quick_sort(players,0,players.size()-1);     // eseguo il test su una stringa
	bool ordinato = is_sorted(players);
	if (!ordinato){
		return EXIT_FAILURE;
	}
	print_vector(players);       // se la stringa viene stampata sul terminale significa che il test complessivo è andato a buon fine
	return EXIT_SUCCESS;
}