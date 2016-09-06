#include "arvore.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//construtor vazio
Arvore::Arvore(){
	raiz = 0;
	cout << "Arvore criada" << endl;
}

//inserção completa
void Arvore::insere(NO **pNo, int N){
	if(*pNo == 0){
		*pNo = (NO*)malloc(sizeof(NO));
		(*pNo)->esq = 0;
		(*pNo)->dir = 0;
		(*pNo)->fb = 0;
		(*pNo)->valor = N;
	}
	else{
		if(N<(*pNo)->valor)
			insere(&(*pNo)->esq, N);
		if(N>(*pNo)->valor)
			insere(&(*pNo)->dir, N);
	}
}

//inserção simplificada
void Arvore::insere(int N){
	insere(&raiz, N);
}

//imprimir nó especifico
void Arvore::imprimeNo(NO **pNo){
	cout << (*pNo)->valor;
}

//impressão da árvore completa
void Arvore::imprimeArvore(NO **pNo){
	if((*pNo)->esq!=0){
		imprimeArvore(&(*pNo)->esq);
	}
	//imprime na tela o valor armazenado no nó.
	cout << (*pNo)->valor <<endl;
	if((*pNo)->dir!=0){
		imprimeArvore(&(*pNo)->dir);
	}
}

//impressão da árvore completa
void Arvore::imprimeArvore(){
	imprimeArvore(&raiz);
}

//altura da árvore completa
int Arvore::alturaArvore(NO **pNo){
	int e, d;
	if (*pNo == 0)
		return -1;
	e = alturaArvore(&(*pNo)->esq);
	d = alturaArvore(&(*pNo)->dir);
	if (e > d)
		return e+1;
	else
		return d+1;
}

//altura da árvore simplificada
int Arvore::alturaArvore(){
	return alturaArvore(&raiz);
}

//calcular fator de balanceamento de um no especifico
void Arvore::calcularFb(NO **pNo){
	int he, hd;
	if(*pNo!=0){
		he = alturaArvore(&(*pNo)->esq);
		hd = alturaArvore(&(*pNo)->dir);
		(*pNo)->fb = he-hd;
	}
}

//Calacula o fator de balanceamento de toda a subarvore apartir do pNo
void Arvore::calcularFbArvore(NO **pNo){
	int he, hd;
	if((*pNo)->esq!=0)
		calcularFbArvore(&(*pNo)->esq);
	he = alturaArvore(&(*pNo)->esq);
	hd = alturaArvore(&(*pNo)->dir);
	(*pNo)->fb = he-hd;
	if((*pNo)->dir!=0)
		calcularFbArvore(&(*pNo)->dir);
}

//Calcula o fator de balanceamento de toda a arvore
void Arvore::calcularFbArvore(){
	calcularFbArvore(&raiz);
}

//Rotação simples a direita
void Arvore::rotacaoSD(NO **pNo){
	NO *temp = (*pNo)->esq;
	(*pNo)->esq = temp->dir;
	temp->dir = *pNo;
}

//Rotação simples a esquerda
void Arvore::rotacaoSE(NO **pNo){
	NO *temp = (*pNo)->dir;
	(*pNo)->dir = temp->esq;
	temp->esq = *pNo;
}
