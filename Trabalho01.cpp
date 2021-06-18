/*
---------------------------------------------------------------------------------------------------------------

	Trabalho 01 - Laboratório de Programação

	Aluno: Francisco San Diego de Sousa Castilho - 397377

	Compilar usando: g++ -Wall -Wextra -std=c++17 Trabalho01.cpp -o teste.exe

	Informações: Todas as funções estão implementadas no mesmo arquivo, todas indicadas por blocos de comentários
	como esse.

---------------------------------------------------------------------------------------------------------------
*/

/*
---------------------------------------------------------------------------------------------------------------
										[Imports necessários]

	iostream: Biblioteca de fluxo de entrada e saída c++
	cstdlib: 
---------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;



int pai(int i){ return (i-1)/2; }

int f_esq(int i){ return 2*i + 1; }

int f_dir(int i){ return 2*i + 2; }


void descer(int* vetor, int indice_atual, int tam_vetor){

	int maior = indice_atual;

	 if(f_esq(indice_atual) < tam_vetor && vetor[f_esq(indice_atual)] > vetor[maior]){
	 	maior = f_esq(indice_atual);

	 } 

	 if(f_dir(indice_atual) < tam_vetor && vetor[f_dir(indice_atual)] > vetor[maior]){
	 	maior = f_dir(indice_atual);
	 }

	 if(maior != indice_atual){
	 	int aux = vetor[indice_atual];
	 	vetor[indice_atual] = vetor[maior];
	 	vetor[maior] = aux;
	 	descer(vetor, maior, tam_vetor);
	 }

}

void construir_heap(int* vetor, int tam_vetor){

	for(int i = tam_vetor -1; i >= 0; i--){
		descer(vetor, i, tam_vetor);
	}	
}

void heapsort(int* vetor, int tam_vetor){
	construir_heap(vetor, tam_vetor);

	for(int i = tam_vetor - 1; i >= 0; i--){
		int maior = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = maior;
		tam_vetor = tam_vetor - 1;
		descer(vetor, 0, tam_vetor);
	}
}

void mostrar_instancias(int** vetor, int tam_vetor_principal, int tam_vetor_interno){
	for(int i = 0; i < tam_vetor_principal; i++){

		cout << "[ ";

		for (int j = 0; j < tam_vetor_interno; j++){
			cout << " " << vetor[i][j] << " ";
		}

		cout << "]" << endl;
	}

	cout << endl;
}

void gerar_instancias(int** instancias, int qtd_instancias, int tam_vetor, char* t_instancia){


	for(int i = 0; i < qtd_instancias; i++){
		instancias[i] = new int[tam_vetor];
	}

	if(t_instancia[0] == 'C'){
		for(int i = 0; i < qtd_instancias; i++){
			for (int j = 0; j < tam_vetor; j++){
				
				instancias[i][j] = j;
			}
		}

	} else if(t_instancia[0] == 'D'){
		for(int i = 0; i < qtd_instancias; i++){
			for (int j = 0; j < tam_vetor; j++){
				
				instancias[i][j] = tam_vetor - j;
			}
		}

	}else if(t_instancia[0] == 'A'){
		int min = 0;
		int max = tam_vetor;
		random_device dar_semente; 
		mt19937 gerador( dar_semente() );
		uniform_int_distribution<int> distribuicao(min,max);

		for(int i = 0; i < qtd_instancias; i++){
			for (int j = tam_vetor - 1; j >= 0; j--){
				
				instancias[i][j] = distribuicao(gerador);
			}
		}

	}else{
		cout << "Algum erro aconteceu" << endl;

	}

	cout << "Ok, vetor teste feito" << endl;
} 


int main(int argc, char** argv){
	char* t_instancia;
	int tam_vetor;
	int qtd_instancias;

	t_instancia = argv[argc - 3];
	tam_vetor = atoi(argv[argc - 2]);
	qtd_instancias = atoi(argv[argc - 1]);

	cout << "Tipo instância: " << t_instancia << endl;
	cout << "Tamanho do vetor: " << tam_vetor << endl;
	cout << "Qauntidade de instancias: " << qtd_instancias << endl;

	int** instancias = new int*[qtd_instancias];

	gerar_instancias(instancias, qtd_instancias, tam_vetor, t_instancia);

	//mostrar_instancias(instancias, qtd_instancias, tam_vetor);

	cout << "Chamar heapsort" << endl;
	clock_t i = clock();
	for (int i = 0; i < qtd_instancias; i++){
		heapsort(instancias[i], tam_vetor);
	}
	clock_t f = clock();
	cout << "Tempo de CPU: " << (f-i) / (double) CLOCKS_PER_SEC << " segundos.\n";

	cout << "heapsort realizado com sucesso!" << endl;
	cout << "Resutado: ";
	//mostrar_instancias(instancias, qtd_instancias, tam_vetor);

}

