#include <iostream>
#include <random>
	
using namespace std;

void mostrar_vetor(int* vetor, int tam_vetor){
	for(int i = 0; i < tam_vetor; i++){
		cout << vetor[i] << " ";
	}

	cout << endl;
}

//Escolha do pivô: sempre a primeira.
int pivo(int inicio, int fim){
	return inicio;
}

void troca(int* vetor, int i, int j){
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int particao(int* vetor, int inicio, int fim){
	if(inicio != fim){
		int p = pivo(inicio, fim);
		int i = inicio + 1;
		int j = fim;

		while(i < j){
			if (vetor[i] >= vetor[p]){
				
				while(vetor[j] > vetor[p] && j > i){ j = j - 1; }
				troca(vetor, i, j);
			}

			i = i + 1;
		}

		if(i == j){
			troca(vetor, i-1, p);
			return i-1;

		}else{
			troca(vetor, i-2, p);
			return i-2;
		}
	}else{
		cout << "unitário" << endl;

		return inicio;
	}
}

void quicksort(int* vetor, int inicio, int fim){
	
	if(inicio <= fim){

		int part = particao(vetor, inicio, fim);
		quicksort(vetor, inicio, part-1);
		quicksort(vetor, part+1, fim);
		cout << "tudo certo" << endl;
	}
}

int main(){


	int vetor_quicksort[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	mostrar_vetor(vetor_quicksort, 10);
	int i = particao(vetor_quicksort, 0, 9);
	mostrar_vetor(vetor_quicksort, 10);
	quicksort(vetor_quicksort, 0, 9);
	mostrar_vetor(vetor_quicksort, 10);

	cout << "retorno: " << i << endl;

	return 0;
}