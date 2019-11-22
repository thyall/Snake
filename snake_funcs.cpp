#include "snake.h"

Maze::Maze( const vector< vector<int> > & input_matrix )
    : m_maze{input_matrix}
{
    // the rows count in matrix.
    int row{0};
    // Locate and store the coordinates of the entry and the exit cells.
    for ( const auto line : m_maze )
    {
        auto pos_entry = std::find( line.begin(), line.end(), APPLE );
        if ( pos_entry != line.end() ) { // Found?
            m_entry.col = std::distance( line.begin(), pos_entry );
            m_entry.row = row;
        }
        auto pos_apple = std::find( line.begin(), line.end(), APPLE );
        if ( pos_apple != line.end() ) { // Found?
            m_apple.col = std::distance( line.begin(), pos_apple );
            m_apple.row = row;
        }
        // Increase row count.
        row++;
    }
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
            else if ( col == Maze::APPLE )  std::cout << "a";
            else if ( col == Maze::PATH )  std::cout << "•";
            else if ( col == Maze::ENTRY ) std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void Snake::SnakeWalk();

bool Snake::eatApple();
