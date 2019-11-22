#include "snake.h"
#include <random>

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
            else if ( col == Snakegame::ENTRY ) std::cout << "0";
        }
        std::cout << std::endl;
    }
}

/*bool Snakegame::IsWall(int x, int y)
{
	if(m_maze[x][y] == WALL)
		return true;
}

bool Snakegame::IsApple(int x, int y)
{
	if(m_maze[x][y] == APPLE)
		return true;
}*/

Position Snakegame::GetHead()
{
	return this -> body_snake.front();
}

void Snakegame::rowcol(int r, int c)
{
	linha = r;
	coluna = c;
}

/*void Snakegame::NewApple()// ja sei eu passo a possição atual da apple, apago gero uma nova e pronto
{
  int x;
  //nessa linha estou colocando o intervalo de quanto até quanto eu quero que o varie
  // estou usando n - 4, porque n é um dos lados sendo passado da matriz menos o tamanho do Batleship, para não correr o risco 
  // o risco de "passar" da matriz

  std::random_device rd;
 
  std::mt19937_64 gen(rd());// esse objeto deixa o ramdom mais "pseudo aleatorio possivel"

  std::uniform_int_distribution < unsigned long long > var(0,);

  x = var(gen);

  return x;
	
}*/


