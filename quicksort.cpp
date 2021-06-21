#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;

int pivo(int inicio, int fim, char c){
	if(c == 'A'){
		random_device dar_semente; 
		mt19937 gerador( dar_semente() );
		uniform_int_distribution<int> distribuicao(inicio, fim);

		return distribuicao(gerador);

	}else if(c == 'F'){
		return fim;

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

	cout << "pivo:: " << p << endl;
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

	cout << "Chamar Quicksort (Pivo: primeiro)" << endl;
	// clock_t i_quicksort2 = clock();
	// for (int i = 0; i < qtd_instancias; i++){
		// quicksort(instancias[i], 0, tam_vetor, 'I');

	int vetor[5] = {9, 2, 65, 0 ,0};


	// particao(vetor, 0, 4, 'I');
	// for (int i = 0; i < 5; i++){
	// 	cout << vetor[i] << " " ;
	// }
	// cout << endl;

	// particao(vetor, 0, 3, 'I');
	// for (int i = 0; i < 5; i++){
	// 	cout << vetor[i] << " " ;
	// }
	// cout << endl;

	// particao(vetor, 0, 2, 'I');
	// for (int i = 0; i < 5; i++){
	// 	cout << vetor[i] << " " ;
	// }
	// cout << endl;

	// particao(vetor, 0, 1, 'I');
	// for (int i = 0; i < 5; i++){
	// 	cout << vetor[i] << " " ;
	// }
	// cout << endl;

	// particao(vetor, 0, 0, 'I');
	// for (int i = 0; i < 5; i++){
	// 	cout << vetor[i] << " " ;
	// }
	// cout << endl;
	


	quicksort(vetor, 0, 4, 'A');
	for (int i = 0; i < 5; i++){
		cout << vetor[i] << " " ;
	}

	// }
	// }
	// clock_t f_quicksort2 = clock();
	// cout << "Tempo de CPU para quicksort: " << (f_quicksort2 - i_quicksort2) / (double) CLOCKS_PER_SEC << " segundos.\n";
	cout << endl;

	//mostrar_instancias(instancias, qtd_instancias, tam_vetor);
	// verifica_ordenacao(instancias, qtd_instancias, tam_vetor);


	return 0;
}