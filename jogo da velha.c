#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tabuleiro2(char tab[3][3])
{
	system("cls");
	printf("\t\t     :     :    \n");
	printf("\t\t %c   : %c   : %c \n",tab[0][0], tab[0][1], tab[0][2]);
	printf("\t\t::::::::::::::::\n");
	printf("\t\t     :     :    \n");
	printf("\t\t %c   : %c   : %c \n",tab[1][0], tab[1][1], tab[1][2]);
	printf("\t\t::::::::::::::::\n");
	printf("\t\t     :     :    \n");
	printf("\t\t %c   : %c   : %c\n",tab[2][0], tab[2][1], tab[2][2]);
}

int campeao (char tabuleiro[3][3])
{
	int jogadas;
	//Definindo um ganhador X
		if(tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X')
		{
			jogadas = 12;
		}
		if(tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X')
		{
			jogadas = 12;
		}
		if(tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X')
		{
			jogadas = 12;
		}
		if(tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X')
		{
			jogadas = 12;
		}
		if(tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X')
		{
			jogadas = 12;
		}
		if(tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X')
		{
			jogadas = 12;
		}
		if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X')
		{
			jogadas = 12;
		}
		if(tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X')
		{
			jogadas = 12;
		}
		

	//Definindo um ganhador O
		if(tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O')
		{
			jogadas = 23;
		}
		if(tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O')
		{
			jogadas = 23;
		}
		if(tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O')
		{
			jogadas = 23;
		}
		if(tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O')
		{
			jogadas = 23;
		}
		if(tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O')
		{
			jogadas = 23;
		}
		if(tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O')
		{
			jogadas = 23;
		}
		if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O')
		{
			jogadas = 23;
		}
		if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O')
		{
			jogadas = 23;
		}

		return jogadas;
}

int main()
{
	char tabuleiro[3][3];
	char XO;
	int i,j,lin=0,col=0, jogadas, turno=0, op, X=0, O=0, partidas=0; // variáveis: tabuleiro, e opção (x ou o)

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tDigite enter para comecar\n");
	getchar();
	system("cls");

	do
	{
		partidas++;
		jogadas=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				tabuleiro[i][j] = ' ';
			}
		}
		
		do
		{
			tabuleiro2(tabuleiro);

			if(turno%2 == 0)
			{
				printf("\nE a vez de X!\n");
			}
			else
			{
				printf("\nE a vez de O!\n");
			}

			printf("\n\nDigite a linha: ");
			scanf("%d",&lin);

			printf("\n\nDigite a coluna: ");
			scanf("%d",&col);

			if(lin > 3 || lin < 1 || col > 3 || col<1)
			{
				printf("\nValores inválidos: ");
				lin=0;
				col=0;
			}
			else if(tabuleiro[lin-1][col-1] != ' ')
			{
				lin=0;
				col=0;
			}
			else
			{
				if(turno%2 == 0)
				{
		
					XO = 'X';
				}
				else
				{
					XO = 'O';
				}
				turno++;
				jogadas++;
				tabuleiro[lin-1][col-1]=XO;
			}
			jogadas=campeao(tabuleiro);
		}while(jogadas<9);
		
		tabuleiro2(tabuleiro);
		if(jogadas==9)
		{
			printf("DEU VELHA\n\n");
		}
		if(jogadas==12)
		{
			X++;
			printf("CAMPEAO X\n\n");
		}
		if(jogadas==23)
		{
			O++;
			printf("CAMPEAO O\n\n");
		}
		printf("Continuar - 1\n\nTerminar - 2\n");
		scanf("%d",&op);		
	}while(op==1);
	printf("A quantidade de partidas jogadas foi: %d\n",partidas);
	printf("O jogador 1 (X) venceu %d partidas\n", X);
	printf("O jogador 2 (O) venceu %d partidas\n", O);
	float XP,OP;
	XP=((partidas/100)*X);
	OP=((partidas/100)*O);
	printf("A porcetagem de vitorias de X foi %d\n", XP);
	printf("A porcetagem de vitorias de O foi %d\n", OP);
}
