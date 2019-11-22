#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <iostream>
#include <algorithm>

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
 * is part of the solution, the entry point, or the apple point.
 *
 * This class also provides methods to read information from the maze,
 * and methods to mark empty cells as part of the path (solution of)
 * inside the maze.
 */
class Maze {

    private:
        vector< vector<int> > m_maze; //!< The maze stored a 2D matrix.
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
        Maze( const vector< vector<int> > & );

        /// Return the location (coordinate) of the maze's entry cell.
        inline Position entry(void) const
        { return m_entry; }

        /// Return the location (coordinate) of the maze's apple cell.
        inline Position apple(void) const
        {return m_apple; }

        /// Prints a maze representation on the standard output.
        void print(void) const;
};

class Snake
{
private:
        vector<int> caminho; //!< criando o vetor para armezenar a cobra
        Position m_entry_snake; //!entrada da cobra

        //analisando de usar uma fila "queue"
        
public:
    void SnakeWalk();
        //usar o enum ???

    bool eatApple();
        //posivelmente dar um push.back()

    
};

class Player
{
public:
    bool find_apple();

    bool is_apple();

    bool is_wall();  
    
};

class Level// ????
{
public:
    Level();
    ~Level();
    
};

#endif
