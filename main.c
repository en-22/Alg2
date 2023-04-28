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
    for(int i = tam - 1; i>=0; i--)
        v[i] = i;
}

void Vetor_Aleatorio(int v[], int tam){
    for(int i = 0; i<tam; i++)
        v[i] = rand();
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
}

void Calcula_Tempo_e_Comp_aleat(int v[], int vaux[], int tam, unsigned int mc[], double mt[]){//Calcula o tempo e o numComp de todos os algortimos para um mesmo vetor
    clock_t start, end;
    double total;
	int numComp;

	start = clock();
	numComp= insertionSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    mc[0]+=numComp;
    mt[0]+=total;
    printf("Insertion \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
    Igualar_Vetores(v, vaux, tam);
    start = clock();
	numComp= mergeSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    mc[1]+=numComp;
    mt[1]+=total;
    printf("Merge \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
    Igualar_Vetores(v, vaux, tam);
    start = clock();
	numComp= selectionSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    mc[2]+=numComp;
    mt[2]+=total;
    printf("Selection \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
    Igualar_Vetores(v, vaux, tam);
	start = clock();
	numComp= quickSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    mc[3]+=numComp;
    mt[3]+=total;
    printf("Quick \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
    Igualar_Vetores(v, vaux, tam);
	start = clock();
	numComp= heapSort(v, tam);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
    mc[4]+=numComp;
    mt[4]+=total;
    printf("Heap \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
}

void Imprime_media(unsigned int mc[], double mt[]){
    printf("\nMédia dos Aleatórios \n");
    
    double total = mt[0]/3;
    unsigned int numComp = mc[0]/3;
    printf("Insertion \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
    
    total = mt[1]/3;
    numComp = mc[1]/3;
    printf("Merge \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);

    total = mt[2]/3;
    numComp = mc[2]/3;
    printf("Selection \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);

    total = mt[3]/3;
    numComp = mc[3]/3;
    printf("Quick \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);

    total = mt[4]/3;
    numComp = mc[4]/3;
    printf("Heap \n");
	printf("Tempo total: %f \n", total);
    printf("numcomp: %d \n", numComp);
}

int main(){
	char nome[MAX_CHAR_NOME];
	int tamVetor = 25000;
    unsigned int media_comparacoes_aleat[5];// 0=Insertion 1=Merge 2=Selection 3=Quick 4=Heap
    for(int i = 0; i<5; i++){
        media_comparacoes_aleat[i] = 0;
    }
    double media_tempo_aleat[5];
    for(int i = 0; i<5; i++){
        media_tempo_aleat[i] = 0;
    }
    srand(time(NULL));

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

    printf("vetores tam= 1000 \n");
    printf("vetor_crescente \n");
    Calcula_Tempo_e_Comp_cresc(vetor_crescente, 1000);
    printf("\nvetor_decrescente \n");
    Calcula_Tempo_e_Comp_decresc(vetor_crescente, 1000);
    printf("\nvetor_aleatorio1 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_a, vetor_a_aux, 1000, media_comparacoes_aleat, media_tempo_aleat);
    printf("\nvetor_aleatorio2 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_b, vetor_b_aux, 1000, media_comparacoes_aleat, media_tempo_aleat);
    printf("\nvetor_aleatorio3\n");
    Calcula_Tempo_e_Comp_aleat(vetor_c, vetor_c_aux, 1000, media_comparacoes_aleat, media_tempo_aleat);
    Imprime_media(media_comparacoes_aleat, media_tempo_aleat);
    
    printf("vetores tam= 5000 \n");
    printf("vetor_crescente \n");
    Calcula_Tempo_e_Comp_cresc(vetor_crescente, 5000);
    printf("\nvetor_decrescente \n");
    Calcula_Tempo_e_Comp_decresc(vetor_crescente, 5000);
    printf("\nvetor_aleatorio1 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_a, vetor_a_aux, 5000, media_comparacoes_aleat, media_tempo_aleat);
    printf("\nvetor_aleatorio2 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_b, vetor_b_aux, 5000, media_comparacoes_aleat, media_tempo_aleat);
    printf("\nvetor_aleatorio3\n");
    Calcula_Tempo_e_Comp_aleat(vetor_c, vetor_c_aux, 5000, media_comparacoes_aleat, media_tempo_aleat);
    Imprime_media(media_comparacoes_aleat, media_tempo_aleat);

    printf("vetores tam= 10000 \n");
    printf("vetor_crescente \n");
    Calcula_Tempo_e_Comp_cresc(vetor_crescente, 10000);
    printf("\nvetor_decrescente \n");
    Calcula_Tempo_e_Comp_decresc(vetor_crescente, 10000);
    printf("\nvetor_aleatorio1 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_a, vetor_a_aux, 10000, media_comparacoes_aleat, media_tempo_aleat);
    printf("\nvetor_aleatorio2 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_b, vetor_b_aux, 10000, media_comparacoes_aleat, media_tempo_aleat);
    printf("\nvetor_aleatorio3\n");
    Calcula_Tempo_e_Comp_aleat(vetor_c, vetor_c_aux, 10000, media_comparacoes_aleat, media_tempo_aleat);
    Imprime_media(media_comparacoes_aleat, media_tempo_aleat);

    printf("vetores tam= 25000 \n");
    printf("vetor_crescente \n");
    Calcula_Tempo_e_Comp_cresc(vetor_crescente, tamVetor);
    printf("\nvetor_decrescente \n");
    Calcula_Tempo_e_Comp_decresc(vetor_crescente, tamVetor);
    printf("\nvetor_aleatorio1 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_a, vetor_a_aux, tamVetor, media_comparacoes_aleat, media_tempo_aleat);
    printf("\nvetor_aleatorio2 \n");
    Calcula_Tempo_e_Comp_aleat(vetor_b, vetor_b_aux, tamVetor, media_comparacoes_aleat, media_tempo_aleat);
    printf("\nvetor_aleatorio3\n");
    Calcula_Tempo_e_Comp_aleat(vetor_c, vetor_c_aux, tamVetor, media_comparacoes_aleat, media_tempo_aleat);

    Imprime_media(media_comparacoes_aleat, media_tempo_aleat);
   
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
