#include "snake.h"

Snakegame::Snakegame( const vector< vector<int> > & input_matrix )
    : m_maze{input_matrix}
{
    // the rows count in matrix.
    int row{0};
    // Locate and store the coordinates of the entry and the exit cells.
    for ( const auto line : m_maze )
    {
        auto pos_entry = std::find( line.begin(), line.end(), ENTRY );
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
void Snakegame::print() const
{
    // For each row of the maze.
    for ( const auto& row : m_maze )
    {
        // For each col of the maze.
        for ( const auto& col : row )
        {
            // Determine whith type of cell we have here.
            if ( col == WALL )             std::cout << "#";
            else if ( col == Snakegame::FREE )  std::cout << " ";
            else if ( col == Snakegame::APPLE )  std::cout << "@";
            else if ( col == Snakegame::PATH )  std::cout << "•";
            else if ( col == Snakegame::ENTRY ) std::cout << "O";
        }
        std::cout << std::endl;
    }
}

//void Snake::SnakeWalk();

//bool Snake::eatApple();
