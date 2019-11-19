#ifndef SNAKE_H
#define SNAKE_H

# include <iostream>
# include <fstream>
# include <string>

class maze
{
	//usaremos uma matriz atraves ponteiro para ponteiro
	char **labirinto; 

	//dimensões
	int row;
	int col;

public:
	make_maze(string filepath); // ou pode ser make_maze(string de caminho); um pónteiro apontando pro arquivo e eu passo pela main
	//print_maze
	
};


/*class snake
{

	
};

class player
{

	find_aple()
	move()

}*/
	

#endif