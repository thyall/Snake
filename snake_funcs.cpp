# include <iostream>
# include <fstream>
# include <string>
# include "snake.h"

void maze::read_maze(std::string filepath)
{

	//criando um ponteiro apotando com o filepath pasasdo
	ifstream myfile (filepath);

	//recebendo as dimensões pela primeira linha do arquivo .dat
	myfile >> row >> col;

	//passando dimensões e alocando a memoria
	set_dimensions();

	if(myfile.is_open())
	{
		// While there is lines to read from the input file...
	    while( ! myfile.eof())
	    {
	        std::string line; // Stores a line from the input file.
	        std::getline( myfile, line );

	      	for (int i = 0; i < row; ++i)
	      	{
	      		for (int j = 0; j < col; ++j)
	      		{
	      			labirinto[i] = line; // ou line[j];
	      		}
	      	}
		}

		myfile.close();
	}

	else() {return std::cerr << "ERR_FAILED_OPENING_INPUT_FILE."};
}


void maze::set_dimensions()
{
	//aqui estou alocando a primeira dimensão Y
	//é utilizado o '++'' para ter uma dimensão a mais que a solicitada para não ocorrer erros com as bordas
	labirinto = new char*[++row];

	//nesse for eu estou alocando a outra dimensão X para cada ponteira ja alocado assim criando uma matriz de ponteiros
	for (int i = 0; i < ++row; ++i)
	{
	    labirinto[i] = new char[++col];
	}
}

void print_maze()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			std::cout << labirinto[i][j];						
		}
	}	
}

//bool find_aple()
//move()