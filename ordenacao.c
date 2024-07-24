#include "ordenacao.h"

#include <string.h>

void getNome(char nome[]){
	strncpy(nome, "Eloisa Nielsen", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR(){
	return 20221226;
}

void Troca(int v[], int a, int b){
	int x = v[a];
	v[a] = v[b];
	v[b] = x;
}

void IgualaVetores(int v[], int u[], int a, int b){
    int i;
    for(i=0; i<=b-a; i++){
        v[i+a] = u[i];
    }
}

int BS(int x, int v[], int a, int b, int* numComparacoes){
    (*numComparacoes)++;
	if (a > b || x > v[b])
		return -1;
    (*numComparacoes)++;
	if (x == v[b])
		return b;
	return BS(x, v, a, b-1, numComparacoes);
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	return BS(valor, vetor, 0, tam-1, numComparacoes);
}

int BN(int x, int v[], int a, int b, int* numComparacoes){
	if (a > b)
		return -1;
	int m = (a + b)/ 2 ;
    (*numComparacoes)++;
	if (x == v[m])
		return m;
    (*numComparacoes)++;
	if (x < v[m])
		return BN(x, v, a, m-1, numComparacoes);
	return BN(x, v, m+1, b, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	return BN(valor, vetor, 0, tam-1, numComparacoes);
}

int BNinsere(int x, int v[], int a, int b, int* numComparacoes){
	if (a > b)
		return a-1;
	int m = (a + b)/ 2 ;
    (*numComparacoes)++;
	if (x < v[m]){
		return BNinsere(x, v, a, m-1, numComparacoes);
    }
	return BNinsere(x, v, m+1, b, numComparacoes);
}

void Insere(int v[], int a, int b, int* numComparacoes){
	int p = BNinsere(v[b], v, a, b-1, numComparacoes);
	int i = b;
	while(i > p + 1){
		Troca(v, i, i-1);
		i--;
	}
}

void Ordenai(int v[], int a, int b, int* numComparacoes){
	if(a >= b)
		return;
	Ordenai(v, a, b-1, numComparacoes);
	Insere(v, a, b, numComparacoes);
}

int insertionSort(int vetor[], int tam){    
    int numComparacoes = 0;
	Ordenai(vetor, 0, tam-1, &numComparacoes);
    return numComparacoes;
}

int Minimo(int v[], int a, int b, int* numComparacoes){
	if (a == b)
		return a;
	int m = Minimo(v, a, b-1, numComparacoes);
    (*numComparacoes)++;
	if (v[b] < v[m])
		m = b;
	return m;
}
void OrdenaS(int v[], int a, int b, int* numComparacoes){
	if (a >= b)
		return;
	Troca(v, a, Minimo(v, a, b, numComparacoes));
	OrdenaS(v, a+1, b, numComparacoes);
}

int selectionSort(int vetor[], int tam){
    int numComparacoes = 0;
	OrdenaS(vetor, 0, tam-1, &numComparacoes);
    return numComparacoes;
}

void Intercala(int v[], int a, int m, int b, int* numComparacoes){
	int k;
    int u[b+1];
	if (a >= b)
		return;
	int i = a;
	int j = m + 1;
	for(k = 0; k <= b-a; k++){
        (*numComparacoes)++;
		if((j > b) || ((i<=m) && (v[i] <= v[j]))){
			u[k] = v[i];
            i++;
		}
        else
        {
			u[k] = v[j];
			j++;
		}
	}
	IgualaVetores(v, u, a, b);
	return;
}

void OrdenaM(int v[], int a, int b, int* numComparacoes){
	if(a>=b)
        return;
	int m = (a+b)/2;
	OrdenaM(v, a, m,  numComparacoes);
	OrdenaM(v, m+1, b,  numComparacoes);
	Intercala(v, a, m, b, numComparacoes);
}

int mergeSort(int vetor[], int tam){
    int numComparacoes = 0;
	OrdenaM(vetor, 0, tam-1, &numComparacoes);
    return numComparacoes;
}

int Part(int v[], int a, int b, int x, int* numComparacoes){
    int m = a-1;
    for(int i=a; i<=b; i++){
    (*numComparacoes)++;
        if(v[i] <= x)
            Troca(v, ++m, i);
    }
    return m;
}

void Quick(int v[], int a, int b, int* numComparacoes){
    if (a >= b)
        return;
    int m = Part(v, a, b, v[b], numComparacoes);
    Quick(v, a, m-1, numComparacoes);
    Quick(v, m+1, b, numComparacoes);
}

int quickSort(int vetor[], int tam){
    int numComparacoes = 0;
	Quick(vetor, 0 , tam-1, &numComparacoes);
    return numComparacoes;
}

void max_heapify(int v[], int i, int tam, int* numComparacoes){
    int maior = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    (*numComparacoes)++;
    if(esq<tam && v[esq]>v[i])
        maior = esq;
    (*numComparacoes)++;
    if(dir<tam && v[dir]>v[maior])
        maior = dir;
    if(maior != i){
        Troca(v, i, maior);
        max_heapify(v, maior, tam, numComparacoes);
    }   
}

void build_max_Heap(int v[], int tam, int* numComparacoes){
    int i;
    for(i=tam/2 -1; i>=0; i--)
        max_heapify(v, i, tam, numComparacoes);
    for(i=tam - 1; i>=0; i--){
        Troca(v, 0, i);
        max_heapify(v, 0, i, numComparacoes);
    }
}

int heapSort(int vetor[], int tam){
    int numComparacoes = 0;
    build_max_Heap(vetor, tam, &numComparacoes);
    return numComparacoes;
}



