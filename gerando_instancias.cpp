#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){

	int tamanho_do_vetor = atoi(argv[argc-1]);

	int** instancias = new int*[tamanho_do_vetor];

	for(int i = 0; i < tamanho_do_vetor; i++){
		instancias[i] = new int[tamanho_do_vetor];
	}

	for (int i = 0; i < tamanho_do_vetor; i++){
		for (int j = 0; j < tamanho_do_vetor; j++){
			instancias[i][j] = j;
		}
	}



	for (int i = 0; i < tamanho_do_vetor; i++){

		cout << "[ "; 

		for (int j = 0; j < tamanho_do_vetor; j++){
			cout << instancias[i][j] << " ";
		}

		cout << " ]";
	}

	return 0;
}