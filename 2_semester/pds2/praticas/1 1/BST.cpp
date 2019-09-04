#include "BST.hpp"

// Cria um no definindo suas ramifica��es a esquerda e direita como nulo
No* criarNo(int dado) {
	No* auxiliar = new No;
	auxiliar->dado = dado;
	auxiliar->esq = nullptr;
	auxiliar->dir = nullptr;
	return auxiliar;
}

// Recebe um no e um dado
// Como se trata de uma �rvore de pesquisa, precisa verificar se o dado � menor ou maior do que o que presente no no
void inserirNoAuxiliar(No* no, int dado) {
	if (dado < no->dado) {
		if (no->esq == nullptr) {
			no->esq = criarNo(dado);
		} else {
			inserirNoAuxiliar(no->esq, dado);
		}
	} else if (dado > no->dado) {
		if (no->dir == nullptr) {
			no->dir = criarNo(dado);
		} else {
			inserirNoAuxiliar(no->dir, dado);
		}
	}
}

// Fun��o para inserir um n� na arvore.
// Recebe um dado, caso a arvore n�o esteja vazia, chama uma fun��o auxiliar de inser��o, caso contr�rio simplesmente cria o no.
void Arvore::inserirNo(int dado) {
	if (raiz != nullptr) {
		inserirNoAuxiliar(raiz, dado);
	} else {
		raiz = criarNo(dado);
	}
}

// Ordenar que n�o ordena efetivamente mas mostra
void ordenar(No* no) {
	if(no == nullptr)
		return;

	ordenar(no->esq);
	cout << no->dado << " ";
	ordenar(no->dir);
}

// Mostrar que n�o mostra (?)
void Arvore::mostrar() {
	ordenar(raiz);
	cout << endl;
}
