#include <random>
using std::mt19937; using std::random_device;
using std::uniform_int_distribution;
#include <iostream>
using std::cout;


int main (){
	random_device dar_semente; mt19937 gerador( dar_semente() );
	int n = 5; 
	int min = 100, max = 200;

	uniform_int_distribution<int> distribuicao(min,max);

	cout << n << " numeros aleatorios de " << min << " a " << max << ":\n\n";
	for (int i = 0; i < n; ++i) cout << distribuicao(gerador) << '\n';
}