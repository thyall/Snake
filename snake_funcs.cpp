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
            if ( col == Snakegame::WALL )       std::cout << "#";
            else if ( col == Snakegame::FREE )  std::cout << " ";
            else if ( col == Snakegame::APPLE )  std::cout << "@";
            else if ( col == Snakegame::PATH )  std::cout << "•";
            else if ( col == Snakegame::ENTRY ) std::cout << "0";
        }
        std::cout << std::endl;
    }
}

bool Snakegame::IsApple(int x, int y)
{
	if(m_maze[x][y] == Snakegame::APPLE)
  {
		return true;
  }

  return false;
}

bool Snakegame::GetRowCol(int aux1, int aux2)
{
  linha = aux1;
  coluna = aux2;

  //testes para saber se as linhas colunas estão coerentes
  if(linha > MAX_ROW or linha < MIN_ROW)
    return false;

  else if(coluna > MAX_COL or coluna < MIN_COL)
    return false;

  else return true;
}

void Snakegame::MoveSnake(direcao aux)
{
  //altera o valor atual no maze e 
  if(aux == up)
  {
    //coloca o asterisco (headsnake) na nova posição
    m_maze[m_entry.row-1][m_entry.col] = Snakegame::ENTRY;

    //alterando antiga posição
    m_maze[m_entry.row][m_entry.col] = Snakegame::FREE;

    m_entry.row = m_entry.row-1;
  }

  else if(aux == down)
  {
    //coloca o asterisco (headsnake) na nova posição
    m_maze[m_entry.row+1][m_entry.col] = Snakegame::ENTRY;

    //alterando antiga posição
    m_maze[m_entry.row][m_entry.col] = Snakegame::FREE;

    m_entry.row = m_entry.row+1;
  }

  else if(aux == right)
  {
    //coloca o asterisco (headsnake) na nova posição
    m_maze[m_entry.row][m_entry.col+1] = Snakegame::ENTRY;

    //alterando antiga posição
    m_maze[m_entry.row][m_entry.col] = Snakegame::FREE;

    m_entry.col = m_entry.col+1;
  }

 else if(aux == right)
 {
    //coloca o asterisco (headsnake) na nova posição
    m_maze[m_entry.row][m_entry.col-1] = Snakegame::ENTRY;

    //alterando antiga posição
    m_maze[m_entry.row][m_entry.col] = Snakegame::FREE;

    m_entry.col = m_entry.col-1;
 }

}

int Snakegame::GetPosSnake(char aux)
{
  if(aux == 'r')
    return m_entry.row;

  else if(aux == 'c')
    return m_entry.col;

  else
    std::cerr << "Invalid parameter!!!" << std::endl;

  return 0;

}
/*!
 * this method try to solve the maze.
 *
 * the main idea behind is backtracking.
 * if we find the apple the function return true
 * but if the cell is WALL ou VISITED the function returns false
 * after we try to find the right way call back 
 * then we try to find the correct path by calling the function again with different coordinates
 * up, down, right and left.
 */

bool Snakegame::FindApple(int row, int col)
{
  if (m_maze[row][col] == APPLE)  
    return true;
  
  if (m_maze[row][col] == WALL or m_maze[row][col] == VISITED )
      return false;

  m_maze[row][col] = VISITED;  
      
  if (FindApple(row, col+1))//right
  {
    passos.push_back(right);//salvando coordenada
    return true;
  }

  if (FindApple(row+1, col))//down
  {
    passos.push_back(down);
    return true;
  }

  if (FindApple(row-1, col))//up
  {
    passos.push_back(up);
    return true;
  }

  if(FindApple(row, col-1))//left
  {
    passos.push_back(left);
    return true;
  }
  m_maze[row][col] = Snakegame::FREE;
  return false;    
}

void Snakegame::printpassos()
{
  auto it1 =  passos.begin();
  auto it2 = passos.end();
  while(it1 != it2)
  {
     std::cout << *it1 << ' ';
     it1++;
  }
}




