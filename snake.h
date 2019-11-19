#ifndef SNAKE_H
#define SNAKE_H

# include <iostream>
# include <fstream>

class maze
{
public:
	//usaremos uma matriz atraves ponteiro para ponteiro
	char **labirinto; 

	//dimensões
	int row;
	int col;	

	make_maze(std::ifstream maze); // ou pode ser make_maze(std::ifstream *maze); um pónteiro apontando pro arquivo e eu passo pela main
	//print_maze
	
};


class snake
{

	
};

class player
{

	//find_aple()
	//move()

}
	

#endif