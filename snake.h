#ifndef SNAKE_H
#define SNAKE_H

/// Represents a location within the maze, as a coordinate pair (row,col).
struct Position {
    int row, col; //!< public members.
    /// Constructor.
    Position(int r=0, int c=0) : row{r}, col{c} { /* empty */ }
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
class Maze {

    private:
        vector< vector<int> > m_maze; //!< The maze stored a 2D matrix.
        Position m_entry; //!< Location of the entry cell.
        Position m_exit;  //!< Location of the exit cell.

    public:
        /// Types of cell inside the maze.
        enum cell_type : int {
            FREE=0,  //!< A free empty cell.
            WALL=1,  //!< A wall inside the maze.
            ENTRY=2, //!< A cell marking the maze's entry point.
            EXIT=3,  //!< A cell marking the maze's exit point.
            PATH=4   //!< A cell that has been marked as part of the path that leads from the maze's entry point to the maze's exit point.
        };

        /// Basic constructor. Receives a matrix corresponding to the maze.
        Maze( const vector< vector<int> > & );

        /// Return the location (coordinate) of the maze's entry cell.
        inline Position entry(void) const
        { return m_entry; }

        /// Return the location (coordinate) of the maze's exit cell.
        inline Position exit(void) const
        {return m_exit; }

        /// Prints a maze representation on the standard output.
        void print(void) const;
};

#endif