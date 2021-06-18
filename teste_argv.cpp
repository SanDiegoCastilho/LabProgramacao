#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
	cout << "Argumento 1: " << argv[0] << endl;
	cout << "Argumento 2: " << argv[1] << endl;
	cout << "Argumento 3: " << argv[2] << endl;

	int n = atoi(argv[2]);

	cout << n << endl;

	int vetor[n];

	for(int i = 0; i < n; i++){
		vetor[i] = i;
	}

	for (int i = 0; i < n; i++){
		cout << vetor[i] << " ";
	}
}