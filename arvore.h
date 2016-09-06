#ifndef ARVORE_H
#define ARVORE_H
typedef struct no {
	int valor, fb;
	struct no *dir;
	struct no *esq;
} NO;


class Arvore
{
	private:
		NO *raiz;
		void insere(NO **pNo, int N);
		void imprimeArvore(NO **pNo);
		int alturaArvore(NO **pNo);
		void calcularFb(NO **pNo);
		void rotacaoSD(NO **pNo);
		void rotacaoSE(NO **pNo);
		void rotacaoDD(NO **pNo);
		void rotacaoDE(NO **pNo);
	public:
		Arvore();
		void insere(int N);
		void imprimeNo(NO **pNo);
		void imprimeArvore();
		int alturaArvore();
		void calcularFb();
		void calcularFbArvore(NO **pNo);
		void calcularFbArvore();
};

#endif
