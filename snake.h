#ifndef SNAKE_H
#define SNAKE_H

# include <iostream>
# include <fstream>
# include <string>

class maze
{
private:
	//usaremos uma matriz atraves ponteiro para ponteiro
	char **labirinto; 

	//dimensões
	int row;
	int col;

public:
	read_maze(std::string filepath); // ou pode ser make_maze(string de caminho); um pónteiro apontando pro arquivo e eu passo pela main

	//definindo dimensões
	set_dimensions();

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