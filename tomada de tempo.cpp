#include <ctime>

using std::clock; 
using std::clock_t;

#include <iostream>

using std::cin; 
using std::cout;

#include <new>

using std::nothrow;

int main () {
	int tam;

	do { cout << "tam: "; cin >> tam; } while (tam < 1);

	int *v = new(nothrow) int[tam]; 

	if (v == nullptr) return 1;

	clock_t i = clock(); 

	for (int j = 0; j < tam; ++j) v[j] = j*j*j*j;

	clock_t f = clock(); // Tambemm poderia declarar "i" e "f" usando "auto".

	cout << "Tempo de CPU: " << (f-i) / (double) CLOCKS_PER_SEC << " segundos.\n";
	delete[] v;
}
