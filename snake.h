#ifndef SNAKE_H
#define SNAKE_H

# include <iostream>
# include <fstream>
# include <string>

class Maze
{
private:
	//usaremos uma matriz atraves ponteiro para ponteiro
	char **labirinto; 

	//dimensões
	int row;
	int col;

public:
	/// Types of cell inside the maze.
    enum cell_type : int
    {
        FREE=0,  //!< A free empty cell.
        WALL=1,  //!< A wall inside the maze.
        ENTRY=2, //!< A cell marking the maze's entry point.
        EXIT=3,  //!< A cell marking the maze's exit point.
        PATH=4   //!< A cell that has been marked as part of the path that leads from the maze's entry point to the maze's exit point.
    };

	// Prints a maze representation on the standard output.
    void print(void) const;
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