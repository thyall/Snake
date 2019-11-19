# include <iostream>
# include <fstream>
# include <string>
# include "snake.h"
void Maze::readmaze(std::ifstream & myfile)
{
	//para pegar caracter por caracter
	char aux;

	//recebendo as dimensões pela primeira linha do arquivo .dat
	myfile >> row >> col;

	//passando dimensões e alocando a memoria
	//aqui estou alocando a primeira dimensão Y
	labirinto = new char*[row];

	//nesse for eu estou alocando a outra dimensão X para cada ponteira ja alocado assim criando uma matriz de ponteiros
	for (int i = 0; i < row; ++i)
	{
	    labirinto[i] = new char[col];
	}

	if(myfile.is_open() && myfile.good())
	{
		// usando get eu consigo pegar carcter por caracter
	    while(!myfile.get(aux))
	    {
	
			//labirinto[i] = line; // ou line[j];
			std::cout << aux;
	
	      	
		}

		myfile.close();
	}

	else
		std::cerr << "ERR_FAILED_OPENING_INPUT_FILE.";
}

void Maze::print() const
{
    // For each row of the maze.
    for ( const auto& row : m_maze )
    {
        // For each col of the maze.
        for ( const auto& col : row )
        {
            // Determine whith type of cell we have here.
            if ( col == WALL )             std::cout << "#";
            else if ( col == Maze::FREE )  std::cout << " ";
            else if ( col == Maze::EXIT )  std::cout << "e";
            else if ( col == Maze::PATH )  std::cout << "•";
            else if ( col == Maze::ENTRY ) std::cout << "x";
        }
        std::cout << std::endl;
    }
}

//bool find_aple()
//move()