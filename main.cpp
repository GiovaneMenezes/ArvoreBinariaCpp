#include <iostream>
#include "Arvore.h"
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Arvore a1;
	/*a1.insere(10);
	a1.insere(5);
	a1.insere(8);
	a1.insere(3);
	a1.insere(1);
	a1.insere(4);
	a1.insere(15);
	a1.insere(18);
	a1.insere(13);
	a1.insere(11);*/
	
	a1.insere(50);
	a1.insere(20);
	a1.insere(10);
	a1.insere(5);
	a1.insere(1);
	
	a1.calcularFbArvore();
	
	a1.imprimeArvore();
	
	cout << "A altura da arvore e: " << a1.alturaArvore() << endl; 
	
	return 0;
}
