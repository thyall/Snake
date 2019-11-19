# include <iostream>
# include <fstream>
# include "snake.h"

void make_maze(std::ifstream maze)
{
	//recebendo as dimensões pela primeira linha do arquivo .dat
	maze >> row >> col;

	//aqui estou alocando a primeira dimensão Y
	//é utilizado o '++'' para ter uma dimensão a mais que a solicitada para não ocorrer erros com as bordas
	jogo = new char*[++row];

	//nesse for eu estou alocando a outra dimensão X para cada ponteira ja alocado assim criando uma matriz de ponteiros
	for (int i = 0; i < ++row; ++i)
	{
	    jogo[i] = new char[++col];
	}	    
}