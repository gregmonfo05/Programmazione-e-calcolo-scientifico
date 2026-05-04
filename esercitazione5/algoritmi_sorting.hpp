#include <vector>
#include <algorithm>
#include <optional>
#include <cmath>

using namespace std;

template<typename T>
bool is_sorted(const vector<T>& vec)
{	
	if (vec.size() == 0){
		return true;
	}
	for (int i=0; i<(vec.size()-1); i++){
		if (vec[i] > vec[i+1]){
			return false;
		}
	}
	return true;
}

template<typename T>
void bubble_sort(vector<T>& vec)
{
	if (vec.size() == 0){
		return;
	}
	for (int i = 0; i<(vec.size()-1); i++){
		for (int j = (vec.size()-1); j>i; j--){
			if (vec[j]<vec[j-1]){
				swap(vec[j], vec[j-1]);
			}
		}
	}
	return;
}

template<typename T>
void insertion_sort(vector<T>& vec)
{
	if (vec.size() == 0){
		return;
	}
	for (int j = 1; j < vec.size(); j++){
		T key = vec[j];
		int i = j-1;
		while (i>=0 && vec[i]>key){
			vec[i+1] = vec[i];
			i--;
		}
		vec[i+1] = key;
	}
	return;
}
			
template<typename T>
void selection_sort(vector<T>& vec)
{
	for (int i = 0; i < (vec.size()-1); i++){
		int min = i;
		for (int j = i+1; j < vec.size(); j++){
			if (vec[j] < vec[min]){
				min = j;
			}
		}
		swap(vec[i], vec[min]);
	}
	return;
}	

void Infinity(vector<string>& vec, size_t i)  // funzioni che serviranno per il merge_sort
{
	vec[i] = string(1000, '\xFF');
}

void Infinity(vector<double>& vec, size_t i)
{
	vec[i] = numeric_limits<double>::max();
}
	

template<typename T>
void merge(vector<T>& vec, size_t p, size_t q, size_t r)
{
	size_t n1 = q-p+1;
	size_t n2 = r-q;
	vector<T> L(n1+1);
	vector<T> R(n2+1);
	for (size_t i=0; i < n1; i++){
		L[i] = vec[p+i];
	}
	for (size_t j=0; j < n2; j++){
		R[j] = vec[q+j+1];
	}
	Infinity(L,n1);    // I can use 2 omonymous functions because C++ chooses the right one.
	Infinity(R,n2); 
	size_t i = 0;
	size_t j = 0;
	for (size_t k = p; k <= r; k++){
		if (L[i] <= R[j]){
			vec[k] = L[i];
			i++;
		}
		else{
			vec[k] = R[j];
			j++;
		}
	}
}

template<typename T>
void merge_sort(vector<T>& vec, size_t p, size_t r)
{
	if (p<r){
		size_t q = (p+r)/2;   // non serve mettere floor perchè è quello che succede di default
		merge_sort(vec,p,q);
		merge_sort(vec,q+1,r);
		merge(vec,p,q,r);
	}
	return;
}

template<typename T>
int partition(vector<T>& vec, int p, int r)
{
	T x = vec[r];   
	int i = p-1;   //qua metto int al posto di size_t perchè parte da -1 
	for (int j = p; j < r; j++){
		if (vec[j] <= x){
			i++;
			swap(vec[i], vec[j]);
		}
	}
	swap(vec[i+1], vec[r]);
	return i+1;
}


template<typename T>
void quick_sort(vector<T>& vec, int p, int r)
{
	if (p<r){
		int q = partition(vec, p, r);
		quick_sort(vec, p, q-1);
		quick_sort(vec, q+1, r);
	}
}

template<typename T>
void insertion_sort_modificato(std::vector<T>& vec, int p, int r) {
    for (int i = p + 1; i <= r; ++i) {
        T key = vec[i];
        int j = i - 1;
        while (j >= p && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

template<typename T>
void optimized_quick_sort(std::vector<T>& vec, int p, int r) {
    if (p < r) {
        int n = r - p + 1;
        if (n < 39) {
            // Se il segmento ha meno di 39 elementi, usa Insertion Sort
            insertion_sort_modificato(vec, p, r);
        } 
        else {
            // Se è più grande, procedi con la partizione
            int q = partition(vec, p, r);
            // Applica la stessa logica ricorsivamente ai sottovettori
			optimized_quick_sort(vec, p, q - 1);
            optimized_quick_sort(vec, q + 1, r);
        }
    }
}


	



	

		

		
	
				
			

				
			
		