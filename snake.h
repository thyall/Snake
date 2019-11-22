#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using std::vector;

/// Represents a location within the maze, as a coordinate pair (row,col).
struct Position {
    int row, col; //!< public members.
    /// Constructor.
    Position() : row{0}, col{0} { /* empty */ };

    //para passagem de valores
    Position(int rr, int cc) : row{rr}, col{cc}{ /* empty */ };
};

enum direcao // posso usar pra class snake
{
    up,
    down,
    left,
    right,
};

class Snakegame {

    private:
        vector< vector<int> > m_maze; //!< para armazenar o labirinto
        vector<int> caminho; //!< criando o vetor para armezenar a cobra
        Position m_entry; //!< Location of the entry cell.
        Position m_apple;  //!< Location of the apple cell.

    public:
        /// Types of cell inside the maze.
        enum cell_type : int {
            FREE=0,  //!< A free empty cell.
            WALL=1,  //!< A wall inside the maze.
            ENTRY=2, //!< A cell marking the maze's entry point.
            APPLE=3,  //!< A cell marking the maze's apple point.
            PATH=4   //!< A cell that has been marked as part of the path that leads from the maze's entry point to the maze's apple point.
        };

        /// Basic constructor. Receives a matrix corresponding to the maze.
        Snakegame( const vector< vector<int> > & );

        /// Return the location (coordinate) of the snake's entry.
        inline Position entry(void) const
        { return m_entry; }

        /// Return the location (coordinate) of the maze's apple.
        inline Position apple(void) const
        {return m_apple; }

        //return if the next location is wall
        bool IsWall(); 

        /// Prints a maze representation on the standard output.
        void print(void) const;

        /// return how much lives the snake has
        void lives();
        
        //return the loaction of snakes' head
        void GetHead();

        //return the coordantes of the way till the apple
        bool FindApple();

        //return true if the next coordante is a apple
        bool IsApple();

        //return a new position for apple
        bool NewApple();

        //move the snake
        void MoveSnake();
};


class Level// ????
{
public:
    Level();
    ~Level();
    
};

#endif
