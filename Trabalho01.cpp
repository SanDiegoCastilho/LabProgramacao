#include <iostream>

using namespace std;

int pai(int i){ return (i-1)/2; }

int f_esq(int i){ return 2*i + 1; }

int f_dir(int i){ return 2*i + 2; }

void mostrar_vetor(int* vetor, int tam_vetor){
	for(int i = 0; i < tam_vetor; i++){
		cout << vetor[i] << " ";
	}

	cout << endl;
}

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
	 	cout << "iteração " << i << endl;
		descer(vetor, 0, tam_vetor);
	}
}


int* gerar_instancia(char t_instancia, int tam_vetor){
	int vetor[tam_vetor];

	if(t_instancia == 'C'){
		for(int i = 0; i < tam_vetor; i++){
			vetor[i] = i;
		}

	} else if(t_instancia == 'D'){
		for (int i = tam_vetor; i > 0; i++){
			vetor[i] = i;
		}
	}
	
	cout << "Ok, vetor teste feito" << endl;
	return vetor;
} 

int main(){
	char t_instancia;
	int tam_vetor;
	int* vetor;

	cin >> t_instancia;

	cin >> tam_vetor;

	vetor = gerar_instancia(t_instancia, tam_vetor);

	mostrar_vetor(vetor, 10);

	cout << "Chamar heapsort" << endl;
	heapsort(vetor, 10);

	cout << "heapsort realizado com sucesso!" << endl;
	cout << "Resutado: ";
	mostrar_vetor(vetor, 10);



	return 0;
}

