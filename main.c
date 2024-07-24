#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
void Igualar_Vetores(int v[], int u[], int tam){
    for(int i = 0; i<tam; i++){
        v[i] = u[i];
    }
}

void Vetor_Crescente(int v[], int tam){
    for(int i = 0; i<tam; i++)
        v[i] = i;
}

void Vetor_Decrescente(int v[], int tam){
    int x = 0;
    for(int i = tam - 1; i>=0; i--){
        v[i] = x;
        x++;
    }
}

void Vetor_Aleatorio(int v[], int tam){
    for(int i = 0; i<tam; i++)
        v[i] = rand()%1000;
}

void Calcula_Tempo_e_Comp_cresc(int v[], int tam){//Calcula o tempo e o numComp de todos os algortimos para um mesmo vetor
    clock_t start, end;
    double total;
	int numComp;

	start = clock();
	numComp= insertionSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Insertion \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);

    start = clock();
	numComp= mergeSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Merge \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
    start = clock();
	numComp= selectionSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Selection \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);

	start = clock();
	numComp= quickSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Quick \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
	start = clock();
	numComp= heapSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Heap \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
}

void Calcula_Tempo_e_Comp_decresc(int v[], int tam){//Calcula o tempo e o numComp de todos os algortimos para um mesmo vetor
    clock_t start, end;
    double total;
	int numComp;

	start = clock();
	numComp= insertionSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Insertion \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
       

    Vetor_Decrescente(v, tam);
    start = clock();
	numComp= mergeSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Merge \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
    Vetor_Decrescente(v, tam);
    start = clock();
	numComp= selectionSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Selection \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);

    Vetor_Decrescente(v, tam);
	start = clock();
	numComp= quickSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Quick \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
    Vetor_Decrescente(v, tam);
	start = clock();
	numComp= heapSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Heap \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);

    Vetor_Decrescente(v, tam);
}

void Calcula_Tempo_e_Comp_aleat(int v[], int vaux[], int tam, double t[], unsigned int c[]){//Calcula o tempo e o numComp de todos os algortimos para um mesmo vetor
    clock_t start, end;
    double total;
	int numComp;

	start = clock();
	numComp = insertionSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Insertion \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    t[0]=t[0]+total;
    c[0]=c[0]+numComp;
    

    Igualar_Vetores(v, vaux, tam);
    start = clock();
	numComp= mergeSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Merge \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    t[1]=t[1]+total;
    c[1]=c[1]+numComp;
    

    Igualar_Vetores(v, vaux, tam);
    start = clock();
	numComp= selectionSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Selection \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    t[2]=t[2]+total;
    c[2]=c[2]+numComp;
    

    Igualar_Vetores(v, vaux, tam);
	start = clock();
	numComp= quickSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Quick \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    t[3]=t[3]+total;
    c[3]=c[3]+numComp;
    

    Igualar_Vetores(v, vaux, tam);
	start = clock();
	numComp= heapSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Heap \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    t[4]=t[4]+total;
    c[4]=c[4]+numComp;
    
    Igualar_Vetores(v, vaux, tam);

}

void Print_Organizado(int v[], int vaux[], int tam){//Imprime o vetor aleatório. Cada algoritmo o organiza e o imprime organizado.
    printf("Vetor de tamanho %d:\n", tam);
    for(int i = 0; i<tam; i++)
        printf("%d ", v[i]);
    printf("\n");

	insertionSort(v, tam);
    printf("Insertion \n");
    for(int i = 0; i<tam; i++)
        printf("%d ", v[i]);
    printf("\n");

    Igualar_Vetores(v, vaux, tam);
	mergeSort(v, tam);
    printf("Merge \n");
    for(int i = 0; i<tam; i++)
        printf("%d ", v[i]);
    printf("\n");

    Igualar_Vetores(v, vaux, tam);
	selectionSort(v, tam);
    printf("Selection \n");
    for(int i = 0; i<tam; i++)
        printf("%d ", v[i]);
    printf("\n");

    Igualar_Vetores(v, vaux, tam);
	quickSort(v, tam);
    printf("Quick \n");
    for(int i = 0; i<tam; i++)
        printf("%d ", v[i]);
    printf("\n");

    Igualar_Vetores(v, vaux, tam);
	heapSort(v, tam);
    printf("Heap \n");
    for(int i = 0; i<tam; i++)
        printf("%d ", v[i]);
    printf("\n");

    Igualar_Vetores(v, vaux, tam);
}

void Testar_Buscas(int v[], int tam){
    int i = 999;
    clock_t start, end;
    double total;
	int numComp = 0;
    int index;

    printf("Vetores de tamanho: %d \n", tam);

    start = clock();
    index = buscaBinaria(v, tam, i, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Busca Binária: \n");
    printf("Index de %d: %d \n", i, index);
	printf("Tempo total: %f \n", total);
    printf("Comparações: %d \n", numComp);
    printf("\n");
    numComp = 0;

    start = clock();
    index = buscaSequencial(v, tam, i, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Busca Sequencial: \n");   
    printf("Index de %d: %d \n", i, index);
	printf("Tempo total: %f \n", total);
    printf("Comparações: %d \n", numComp);
    printf("\n");
    numComp = 0;

    i = 50000;

    start = clock();
    index = buscaBinaria(v, tam, i, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Busca Binária: \n");
    printf("Index de %d: %d \n", i, index);
	printf("Tempo total: %f \n", total);
    printf("Comparações: %d \n", numComp);
    printf("\n");
    numComp = 0;

    start = clock();
    index = buscaSequencial(v, tam, i, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Busca Sequencial: \n");  
    printf("Index de %d: %d \n", i, index);
	printf("Tempo total: %f \n", total);
    printf("Comparações: %d \n", numComp);
    printf("\n");
}

void ResetaCompTemp(unsigned int c[], double t[]){
    for(int i = 0; i<5; i++)
        c[i] = 0;
    for(int i = 0; i<5; i++)
        t[i] = 0;
}


int main(){
	char nome[MAX_CHAR_NOME];
	int tamVetor = 10;
    srand(time(NULL));
    unsigned int Comp[5] = {0,0,0,0,0};//guarda a soma do número de comparações dos vetores aleatórios para cada algortimo
    double Temp[5] = {0,0,0,0,0};//guarda a soma do tempo dos vetores aleatórios para cada algortimo

	int* vetor_crescente = malloc(tamVetor * sizeof(int));
	if(vetor_crescente == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
    
    int* vetor_decrescente = malloc(tamVetor * sizeof(int));
	if(vetor_decrescente == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
    
    int* vetor_a = malloc(tamVetor * sizeof(int));
	if(vetor_a == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
    int* vetor_b = malloc(tamVetor * sizeof(int));
	if(vetor_b == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

    int* vetor_c = malloc(tamVetor * sizeof(int));
	if(vetor_c == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

    int* vetor_a_aux = malloc(tamVetor * sizeof(int));
	if(vetor_a == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
    int* vetor_b_aux = malloc(tamVetor * sizeof(int));
	if(vetor_b == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

    int* vetor_c_aux = malloc(tamVetor * sizeof(int));
	if(vetor_c == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

    Vetor_Crescente(vetor_crescente, tamVetor);
    Vetor_Decrescente(vetor_decrescente, tamVetor);
    Vetor_Aleatorio(vetor_a_aux, tamVetor);
    Vetor_Aleatorio(vetor_b_aux, tamVetor);
    Vetor_Aleatorio(vetor_c_aux, tamVetor);
    Igualar_Vetores(vetor_a, vetor_a_aux, tamVetor);
    Igualar_Vetores(vetor_b, vetor_b_aux, tamVetor);
    Igualar_Vetores(vetor_c, vetor_c_aux, tamVetor);

	getNome(nome);
    
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

    
    Print_Organizado(vetor_b, vetor_b_aux, 20);

    for(int i = 1000; i <= tamVetor; i=i*5){
        printf("Vetores de tamanho: %d \n", i);
        printf("Vetor crescente \n");
        Calcula_Tempo_e_Comp_cresc(vetor_crescente, i);
        printf("\nVetor decrescente \n");
        Calcula_Tempo_e_Comp_decresc(vetor_decrescente, i);
        printf("\nVetor aleatorio 1 \n");
        Calcula_Tempo_e_Comp_aleat(vetor_a, vetor_a_aux, i, Temp, Comp);
        printf("\nVetor aleatorio 2 \n");
        Calcula_Tempo_e_Comp_aleat(vetor_b, vetor_b_aux, i, Temp, Comp);
        printf("\nVetor aleatorio 3 \n");
        Calcula_Tempo_e_Comp_aleat(vetor_c, vetor_c_aux, i, Temp, Comp);
        printf("\nMédia numComp aleatórios:\n");
        printf("Insertion: %d \n", Comp[0]/3);
        printf("Merge: %d \n", Comp[1]/3);
        printf("Selection: %d \n", Comp[2]/3);
        printf("Quick: %d \n", Comp[3]/3);
        printf("Heap: %d \n", Comp[4]/3);
        printf("\n");
        printf("Média Tempo aleatórios:\n");
        printf("Insertion: %f \n", Temp[0]/3);
        printf("Merge: %f \n", Temp[1]/3);
        printf("Selection: %f \n", Temp[2]/3);
        printf("Quick: %f \n", Temp[3]/3);
        printf("Heap: %f \n", Temp[4]/3);
        printf("\n\n");
        ResetaCompTemp(Comp, Temp);
    }

    printf("Vetores de tamanho: %d \n", tamVetor);
    printf("Vetor crescente \n");
    Calcula_Tempo_e_Comp_cresc(vetor_crescente, tamVetor);
    printf("\nVetor decrescente \n");
    Calcula_Tempo_e_Comp_decresc(vetor_decrescente, tamVetor);
    printf("\nVetor aleatorio 1 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_a, vetor_a_aux, tamVetor, Temp, Comp);
    printf("\nVetor aleatorio 2 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_b, vetor_b_aux, tamVetor, Temp, Comp);
    printf("\nVetor aleatorio 3 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_c, vetor_c_aux, tamVetor, Temp, Comp);
    printf("\n");
    printf("Média numComp aleatórios:\n");
    printf("Insertion: %d \n", Comp[0]/3);
    printf("Merge: %d \n", Comp[1]/3);
    printf("Selection: %d \n", Comp[2]/3);
    printf("Quick: %d \n", Comp[3]/3);
    printf("Heap: %d \n", Comp[4]/3);
    printf("\n");
    printf("Média Tempo aleatórios:\n");
    printf("Insertion: %f \n", Temp[0]/3);
    printf("Merge: %f \n", Temp[1]/3);
    printf("Selection: %f \n", Temp[2]/3);
    printf("Quick: %f \n", Temp[3]/3);
    printf("Heap: %f \n", Temp[4]/3);
    printf("\n\n");
    
    Testar_Buscas(vetor_crescente, 1000);
    Testar_Buscas(vetor_crescente, 5000);
    Testar_Buscas(vetor_crescente, 25000);
    Testar_Buscas(vetor_crescente, tamVetor);

	free(vetor_crescente);
    free(vetor_decrescente);
    free(vetor_a_aux);
    free(vetor_b_aux);
    free(vetor_c_aux);
    free(vetor_a);
    free(vetor_b);
    free(vetor_c);

	return 0;
}
