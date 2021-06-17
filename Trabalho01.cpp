#include <iostream>
#include <cstdlib>

using namespace std;

// Funções auxiliares para o HeapSort

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

void mostrar_vetor(int* vetor, int tam_vetor){
	for(int i = 0; i < tam_vetor; i++){
		cout << vetor[i] << " ";
	}

	cout << endl;
}

void gerar_instancia(int* vetor, char* t_instancia, int tam_vetor){


	if(t_instancia[0] == 'C'){
		for(int i = 0; i < tam_vetor; i++){
			vetor[i] = i;
		}

	} else if(t_instancia[0] == 'D'){
		for (int i = tam_vetor - 1; i >= 0; i--){
			vetor[i] = i;
		}
	}else{
		cout << "Algum erro aconteceu" << endl;
	}

	cout << "Ok, vetor teste feito" << endl;
} 




int main(int argc, char** argv){
	char* t_instancia;
	int tam_vetor;

	t_instancia = argv[argc - 2];
	tam_vetor = atoi(argv[argc - 1]);

	cout << "Tipo instância: " << t_instancia << endl;
	cout << "Tamanho do vetor: " << tam_vetor << endl;

	int vetor[tam_vetor];

	gerar_instancia(vetor, t_instancia, tam_vetor);

	mostrar_vetor(vetor, tam_vetor);

	cout << "Chamar heapsort" << endl;
	heapsort(vetor, tam_vetor);

	cout << "heapsort realizado com sucesso!" << endl;
	cout << "Resutado: ";
	mostrar_vetor(vetor, tam_vetor);
}

