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
---------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;

/*
---------------------------------------------------------------------------------------------------------------
									[HEAPSORT - FUNÇÕES AUXÍLÁRES]
---------------------------------------------------------------------------------------------------------------
*/
int pai(int i){ return (i-1)/2; }

int f_esq(int i){ return 2*i + 1; }

int f_dir(int i){ return 2*i + 2; }

template <typename T>
void descer(T* vetor, int indice_atual, int tam_vetor){

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

template <typename T>
void construir_heap(T* vetor, int tam_vetor){

	for(int i = tam_vetor -1; i >= 0; i--){
		descer(vetor, i, tam_vetor);
	}	
}


template <typename T>
void heapsort(T* vetor, int tam_vetor){
	construir_heap(vetor, tam_vetor);

	for(int i = tam_vetor - 1; i >= 0; i--){
		int maior = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = maior;
		tam_vetor = tam_vetor - 1;
		descer(vetor, 0, tam_vetor);
	}
}

/*
---------------------------------------------------------------------------------------------------------------
									[FIM - HEAPSORT]
---------------------------------------------------------------------------------------------------------------
*/

/*
---------------------------------------------------------------------------------------------------------------
									[QUICKSORT - INICIO]
---------------------------------------------------------------------------------------------------------------
*/
int pivo(int inicio, int fim, char c){
	if(c == 'A'){
		random_device dar_semente; 
		mt19937 gerador( dar_semente() );
		uniform_int_distribution<int> distribuicao(inicio, fim);

		return distribuicao(gerador);
	}else if(c == 'F'){
		return fim;

	}else if(c == 'M'){

		return (inicio + fim) / 2;
	}else{
		return inicio;
	}
}

template <typename T>
void troca(T* vetor, int i, int j){
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

template <typename T>
int particao(T* vetor, int inicio, int fim, char t_pivo){
	int p = pivo(inicio, fim, t_pivo);

	troca(vetor, inicio, p);
	int i = inicio + 1;
	int j = fim;

	while(i <= j){
		if (vetor[i] > vetor[inicio]){
			while(vetor[j] > vetor[inicio] && j > i) { j--; }
			if (i != j){ troca(vetor, i, j); }	
		}

		i++;
	}

	if(vetor[i-1] < vetor[inicio]){
		troca(vetor, i-1, inicio);
		return i-1;

	}else{
		troca(vetor, i-2, inicio);
		return i-2;
	}
}

template <typename T>
void quicksort(T* vetor, int inicio, int fim, char t_pivo){
	
	if(inicio < fim){

		int part = particao(vetor, inicio, fim, t_pivo);
		quicksort(vetor, inicio, part-1, t_pivo);
		quicksort(vetor, part+1, fim, t_pivo);
	}
}
/*
---------------------------------------------------------------------------------------------------------------
									[QUICKSORT - FIM]
---------------------------------------------------------------------------------------------------------------
*/

/*
---------------------------------------------------------------------------------------------------------------
									[INTROSORT - INICIO]
---------------------------------------------------------------------------------------------------------------
*/

template <typename T>
void introsort_rec(T* vetor, int inicio, int fim, int niveis, char t_pivo){
	if (inicio < fim){
		
		if (niveis == 0){
			heapsort(vetor, fim-inicio);

		}else{
			int p = particao(vetor, inicio, fim, t_pivo);
			introsort_rec(vetor, inicio, p-1, niveis-1, t_pivo);
			introsort_rec(vetor, p+1, fim, niveis-1, t_pivo);
		}

	}
}

template <typename T>
void introsort(T* vetor, int tam_vetor, char t_pivo){
	int niveis = 0;
	int aux = tam_vetor;

	while(aux >= 1 ){
		aux = (aux << 1);
		niveis++;
	}

	introsort_rec(vetor, 0, tam_vetor, niveis, t_pivo);
}

/*
---------------------------------------------------------------------------------------------------------------
									[INTROSORT - FIM]
---------------------------------------------------------------------------------------------------------------
*/



/*
---------------------------------------------------------------------------------------------------------------
									[FUNÇÕES AUXILIARES]
---------------------------------------------------------------------------------------------------------------
*/
template <typename T>
void mostrar_instancias(T** vetor, int tam_vetor_principal, int tam_vetor_interno){
	for(int i = 0; i < tam_vetor_principal; i++){

		cout << "[ ";

		for (int j = 0; j < tam_vetor_interno; j++){
			cout << " " << vetor[i][j] << " ";
		}

		cout << "]" << endl;
	}

	cout << endl;
}

template <typename T>
void gerar_instancias(T** instancias, int qtd_instancias, int tam_vetor, char* t_instancia){


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

template <typename T>
void verifica_ordenacao(T** instancias, int qtd_instancias, int tam_vetor){
	bool aux = true;

	for (int i = 0; i < qtd_instancias; i++){
		for (int j = 1; j < tam_vetor; j++){
			if(instancias[i][j] < instancias[i][j-1] ){ aux = false; }
		}
	}

	if (aux){
		cout << "Todos os vetores foram devidamente ordenados." << endl;

	}else{
		cout << "Os vetores NAO foram ordenados corretamente" << endl;
	}
}


/*
---------------------------------------------------------------------------------------------------------------
									[Função Main]
---------------------------------------------------------------------------------------------------------------
*/
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

	int** instancias2 = instancias;
	int** instancias3 = instancias;
	int** instancias4 = instancias;
	int** instancias5 = instancias;
	int** instancias6 = instancias;

	cout << "Chamar heapsort" << endl;
	clock_t i_heapsort = clock();
	for (int i = 0; i < qtd_instancias; i++){
		heapsort(instancias[i], tam_vetor);
	}

	// ------------------------------- Heapsort -------------------------------------------------------------------
	clock_t f_heapsort = clock();
	verifica_ordenacao(instancias, qtd_instancias, tam_vetor);
	cout << "Tempo de CPU para Heapsort: " << (f_heapsort - i_heapsort) / (double) CLOCKS_PER_SEC << " segundos.\n";
	cout << endl;
	
	// ------------------------------- Quicksort (pivô meio) -------------------------------------------------------------------
	cout << "Chamar Quicksort (Pivo: Meio)" << endl;
	clock_t i_quicksort4 = clock();
	for (int i = 0; i < qtd_instancias; i++){
		quicksort(instancias4[i], 0, tam_vetor, 'M');
	}
	clock_t f_quicksort4 = clock();
	verifica_ordenacao(instancias5, qtd_instancias, tam_vetor);
	cout << "Tempo de CPU para quicksort: " << (f_quicksort4 - i_quicksort4) / (double) CLOCKS_PER_SEC << " segundos.\n";
	cout << endl;
	


	// ------------------------------- Quicksort (Introsort) -------------------------------------------------------------------
	cout << "Chamar introsort" << endl;
	clock_t i_introsort = clock();
	for (int i = 0; i < qtd_instancias; i++){
		introsort(instancias6[i], tam_vetor, 'M');
	}
	clock_t f_introsort = clock();
	verifica_ordenacao(instancias6, qtd_instancias, tam_vetor);
	cout << "Tempo de CPU para introsort: " << (f_introsort-i_introsort) / (double) CLOCKS_PER_SEC << " segundos.\n";

	// ------------------------------- Quicksort (pivô último) -------------------------------------------------------------------
	cout << "Chamar Quicksort (Pivo: ultimo)" << endl;
	clock_t i_quicksort = clock();
	for (int i = 0; i < qtd_instancias; i++){
		quicksort(instancias2[i], 0, tam_vetor, 'F');
	}
	clock_t f_quicksort = clock();
	verifica_ordenacao(instancias2, qtd_instancias, tam_vetor);
	cout << "Tempo de CPU para quicksort: " << (f_quicksort - i_quicksort) / (double) CLOCKS_PER_SEC << " segundos.\n";
	cout << endl;


	// ------------------------------- Quicksort (pivô primeiro) -------------------------------------------------------------------
	cout << "Chamar Quicksort (Pivo: primeiro)" << endl;
	clock_t i_quicksort2 = clock();
	for (int i = 0; i < qtd_instancias; i++){
		quicksort(instancias3[i], 0, tam_vetor, 'I');
	}
	clock_t f_quicksort2 = clock();
	verifica_ordenacao(instancias3, qtd_instancias, tam_vetor);
	cout << "Tempo de CPU para quicksort: " << (f_quicksort2 - i_quicksort2) / (double) CLOCKS_PER_SEC << " segundos.\n";
	cout << endl;


	// ------------------------------- Quicksort (pivô aleatório) -------------------------------------------------------------------
	cout << "Chamar Quicksort (Pivo: Aleatorio)" << endl;
	clock_t i_quicksort3 = clock();
	for (int i = 0; i < qtd_instancias; i++){
		quicksort(instancias4[i], 0, tam_vetor, 'A');
	}
	clock_t f_quicksort3 = clock();
	verifica_ordenacao(instancias4, qtd_instancias, tam_vetor);
	cout << "Tempo de CPU para quicksort: " << (f_quicksort3 - i_quicksort3) / (double) CLOCKS_PER_SEC << " segundos.\n";
	cout << endl;

}

