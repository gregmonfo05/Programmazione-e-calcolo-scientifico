#include <vector>
#include <algorithm>
#include <optional>

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
				
			

				
			
		