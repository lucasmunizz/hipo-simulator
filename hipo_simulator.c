// Lucas Muniz de Lima - 13728941

/* O processador executa instruções a partir do endereço zero.
 * as instruções DDF e DFF não precisam ser codificadas.
 * as instruções de deslocamento preservam o sinal.
 * a instrução PAR termina o simulador. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MEMSIZE 10000

int M[MEMSIZE]; // representa a memória do HIPO.

void loadM(char *imgFileName)
{
	FILE *fp;
	fp = fopen(imgFileName, "rt");
	int i = 0;
	while (!feof(fp))
	{
		printf("lendo linha %d ", i);
		fscanf(fp, "%d\n", &(M[i]));
		printf("conteúdo: %d ", M[i]);
		++i;
	}
	fclose(fp);
}

void dumpM()
{
	for (int i = 0; i < MEMSIZE; i++)
	{
		printf("(%d,%d)\t", i, M[i]);
	}
}

int accumulator;
int pointerInstruction;	 // ou ai
int mbr;

void executa()
{

	int addressEE;
	int instruction;
	int ii;

	puts("Execução:");

	/* insira seu programa aqui. */
	/* caso crie outras funções, crie neste arquivo (e chame-as aqui ou onde
	 * for conveniente */

	pointerInstruction = 0;

	while (1)
	{						  
		instruction = M[pointerInstruction];
		addressEE = instruction % 100;		   
		ii = (int)instruction / 100; 

		M[30] = 0;

		pointerInstruction++;

		switch (ii) {
		
		case 11: // Copie o conteúdo do endereço EE no acumulador
			accumulator = M[addressEE]; 
			break;
		case 12: // Copie o conteúdo do acumulador no endereço EE.
			M[addressEE] = accumulator;
			break;
		case 21: // Some o conteúdo do endereço addressEE com o conteúdo do acumulador e guarde o resultado no acumulador
			accumulator += M[addressEE];
			break;
		case 22: // Subtraia o conteúdo do endereço EE do conteúdo do acumulador e guarde o resultado no acumulador
			accumulator -= M[addressEE];
			break;
		case 23: // Multiplique o conteúdo do endereço EE com o conteúdo do acumulador e guarde o resultado no acumulador.
			accumulator *= M[addressEE];
			break;
		case 24: // Divide o conteúdo do acumulador pelo conteúdo do endereço EE e guarde o resultado no acumulador.
			accumulator /= M[addressEE];
			break;
		case 25: // [AC] recebe o resto da divisão
			accumulator %= M[addressEE];
			break;
		case 31: // Leia um número e guarde-o no endereço EE. (EE recebe o valor lido)
			printf("Por favor, insira um número: ");
			scanf("%d", &M[addressEE]);
			break;
		case 41: // Imprima o conteúdo do endereço EE.
			printf("%d\n", M[addressEE]);
			break;
		case 50: // Nenhuma operação é efetuada.
			break;
		case 51: // Desvie a execução para o endereço EE, i.e. AI recebe EE.
			pointerInstruction = addressEE;
			break;
		case 52: // Se o conteúdo do acumulador for maior do que zero, desvie a execução para o endereço EE.
			if(accumulator > 0){
				pointerInstruction = addressEE;
			}
			break;
		case 53: // Se o conteúdo do acumulador for maior ou igual a zero, desvie a execução para o endereço EE. 
			if (accumulator >= 0){
				pointerInstruction = addressEE;
			}
		case 54: // Se o conteúdo do acumulador for menor do que zero, desvie a execução para o endereço EE.
			if (accumulator < 0)
				pointerInstruction = addressEE;
			break;
		case 55: // Se o conteúdo do acumulador for menor ou igual a zero, desvie a execução para o endereço EE.
			if (accumulator <= 0){
				pointerInstruction = addressEE;
			}
		case 56: // Se o conteúdo do acumulador for diferente de zero, desvie a execução para o endereço EE.
			if (accumulator != 0){
				pointerInstruction = addressEE;
			}
			break;
		case 57: // Se o conteúdo do acumulador for igual a zero, desvie a execução para o endereço EE.
			if (accumulator == 0){
				pointerInstruction = addressEE;
			}
			break;
		case 58: // Se o conteúdo do acumulador for diferente de infinito, desvie a execução para o endereço EE.
            if (accumulator != INFINITY){
                pointerInstruction = addressEE;
            }
			break;
		case 59: // Se o conteúdo do acumulador for infinito, desvie a execução para o endereço EE.
            if (accumulator == INFINITY){
                pointerInstruction = addressEE;
            }
			break;
		case 61: // Desloque os dígitos do acumulador uma posição à esquerda, desprezando o digito mais significativo.
            accumulator %= 1000000;
            accumulator	*= 10; 
            break;
		case 62: // Desloque os dígitos do acumulador uma posição à direita, desprezando o digito menos significativo.
            accumulator /= 10; 
            break;
		case 70: // Pare a execução do programa. OBS.: Esta instrução deve ser executada para encerrar a execução do programa.0
			printf("Programa encerrado.");
			pointerInstruction = MEMSIZE;
			break;
		default: 
			printf("\nTamanho de memória excedido, posição atual: %d.", pointerInstruction);
			return;
		}
	}
}

void main(int argc, char *argv[])
{
	puts("Hello");
	if (argc > 1)
	{
		/* Um computador frequentemente tem um programa que carrega um
		 * executável na memória. Esse programa é mais complicado que o tipo
		 * de programa que é suficiente para oferecer um entendimento básico
		 * dos conceitos que quero explorar na disciplina. Por isso, a carga de
		 * um programa na memória, neste simulador, é algo feito "por fora"
		 * da simulação.
		 * */
		loadM(argv[1]);
		dumpM();
		executa();
	}
}