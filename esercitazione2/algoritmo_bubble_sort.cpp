#include <iostream>
using namespace std;

int main(){
	static const int N = 5;
	int array[N] = {1, 3, 5, 4, 0};
	bool scambio = 1;
	while (scambio){
		scambio = 0;
		for (int i = 0; i < N-1; i++){
			if (array[i] > array[i+1]){
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				scambio = 1;
			}
		}
	}
	for (int i = 0; i < N; i++){
		cout << array[i] << "\n";
	}
	return 0;
}
		
	