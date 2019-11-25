#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <fstream>

#define MAX_ROW 100
#define MAX_COL 100
#define MIN_ROW 1
#define MIN_COL 1

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
/*!
 * Represents a (prefect) maze.
 *
 * Internally a maze is represented as a 2D matrix of numbers
 * corresponding to `cells`.
 *
 * A cell might be either be empty, a wall, an empty cell that
 * is part of the solution, the entry point, or the exit point.
 *
 * This class also provides methods to read information from the maze,
 * and methods to mark empty cells as part of the path (solution of)
 * inside the maze.
 */

class Snakegame {

    private:
        vector< vector<int> > m_maze; //!< para armazenar o labirinto
        //vector<int> caminho; //!< criando o vetor para armezenar a cobra
        Position m_entry; //!< Location of the entry cell.
        Position m_apple;  //!< Location of the apple cell.
        //vector<direcao> passos;//!< lista para armazenar o caminho correto
        int linha, coluna;

    public:
        /// Types of cell inside the maze.
        vector<direcao> passos;
        enum cell_type : int {
            FREE=0,  //!< A free empty cell.
            WALL=1,  //!< A wall inside the maze.
            ENTRY=2, //!< A cell marking the maze's entry point.
            APPLE=3,  //!< A cell marking the maze's apple point.
            PATH=4, //! right path
            VISITED = 5   //!< A cell that has been marked as part of the path that leads from the maze's entry point to the maze's apple point.
        };

        /// Basic constructor. Receives a matrix corresponding to the maze.
        Snakegame( const vector< vector<int> > & );

        //receives row and col
        bool GetRowCol(int aux1, int aux2);//

        /// Return the location (coordinate) of the snake's entry.
        inline Position SnakeHead(void) const
        { return m_entry; }

        /// Return the location (coordinate) of the maze's apple.
        inline Position apple(void) const
        {return m_apple; }

        //return if the next location is wall
        bool IsWall(int x, int y);

         //return true if the next coordante is a apple
        bool IsApple(int x, int y); 

        /// Prints a maze representation on the standard output.
        void print(void) const;

        //return the coordantes of the way till the apple
        bool FindApple(int row, int col);

        //return a new position for apple
        void NewApple();

        //move the snake
        void MoveSnake(direcao aux);

        void printpassos();

        int GetPosSnake(char aux);

        //bool IsBlock(Position a, direcao b);

        //passando quantidade de linhas e colunas
        void rowcol(int r, int c);
};
#endif
