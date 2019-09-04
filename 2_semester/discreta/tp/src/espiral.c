#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Fun��o que calcula os valores de x,y em O(n)
*/
void espiralOn (const int n, int *x, int *y) {
  int i;

	for(i=0; i<n; i++) {
		if((abs(*x) < abs(*y)) || (*x == *y && *y < 0)) {
			if(*y < 0) {
				(*x)++;
			} else {
				(*x)--;
			}
		} else {
			if(*x >= 0) {
				(*y)++;
			} else {
				(*y)--;
			}
		}
	}
}

/**
 * Fun��o que calcula os valores de x,y em O(n^(1/2))
*/
void espiralORaizN(const int n, int *x, int *y) {
	// Calculo a raiz quadrada de n arredondando para o valor mais pr�ximo
	double raizN = round(sqrt(n));

	// Calculo o quadrado perfeito mais pr�ximo
	int quad = raizN * raizN;

	int i, passos;

	// Calculo a posi��o do quadrado mais pr�ximo
	// Caso seja a raiz seja par o quadrado perfeito tamb�m ser� par e ter� coordenadas x,y no formato -raizN/2
	// Caso seja impar, ter� coordenadas da forma (chao(raizN/2),teto(raizN/2)
	if((int)raizN % 2 == 0) {
		*x = -raizN/2;
		*y = -raizN/2;
	} else {
		*x = floor(raizN/2);
		*y = ceil(raizN/2);
	}

	// Se n � um quadrado perfeito  j� calculei suas coordenadas
	if(n == quad) {
		return;
	}

	// Calculo os passos necess�rios: quantos incrementos/decrementos preciso fazer para sair de raizN e chegar em n
	passos = abs(n-quad);

	// Itero os passos necess�rios, testando se � par ou impar e se n � maior ou menor ao quadradoPerfeito
	for(i=0; i<passos; i++) {
		if(quad % 2 == 0) {
			if(n < quad) {
				(*y)++;
			} else {
				(*x)++;
			}
		} else {
			if(n < quad) {
				(*y)--;
			} else {
				(*x)--;
			}
		}
	}
}

/**
 * Fun��o que calcula os valores de x,y em O(1)
 * S� se diferencia da fun��o espiralRaizN a partir da linha 102
*/
void espiralO1(const int n, int *x, int *y) {
	double raizN = round(sqrt(n));
	int quad = raizN * raizN;
	int passos;

	if((int)raizN % 2 == 0) {
		*x = -raizN/2;
		*y = -raizN/2;
	} else {
		*x = floor(raizN/2);
		*y = ceil(raizN/2);
	}

	if(quad == n) {
		return;
	}

	passos = abs(n-quad);

	// Uma vez que eu j� sei o quanto preciso somar/subtrair em x/y para chegar nas coordenadas de n basta realizar a conta
	if(quad % 2 == 0) {
		if(n < quad) {
			(*y) += passos;
		} else {
			(*x) += passos;
		}
	} else {
		if(n < quad) {
			(*y) -= passos;
		} else {
			(*x) -= passos;
		}
	}
}

int main() {
	int n, x=0, y=0;

	printf("---------------------------------\n");
	printf("|        ESPIRAL QUADRADA       |\n");
	printf("---------------------------------\n\n");

	// Fa�o a leitura do n-�simo ponto
	printf("Digite o ponto que deseja localizar na espiral: ");
	fflush(stdout);
	scanf("%d",&n);

	// Verifica��o para o n�mero ser positivo
	while(n < 0) {
		printf("O ponto deve ser maior ou igual a zero!\n");
		printf("Digite o ponto que deseja localizar na espiral: ");
		fflush(stdout);
		scanf("%d",&n);
	}

	// Chamo a fun��o que calcula x,y em O(n)
	espiralOn(n,&x,&y);
	printf("x,y calculado com complexidade O(n): (%d,%d)\n",x,y);

	// Chamo a fun��o que calcula x,y em O(n^(1/2))
	espiralORaizN(n,&x,&y);
	printf("x,y calculado com complexidade O(n^(1/2)): (%d,%d)\n",x,y);

	// Chamo a fun��o que calcula x,y em O(1)
	espiralO1(n,&x,&y);
	printf("x,y calculado com complexidade O(1): (%d,%d)\n",x,y);

	return 0;
}
