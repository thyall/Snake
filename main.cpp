/*!
 * Snake
 * Turmna de LP1, 2019.2
 * @date November, 18th.
 * @author Thyall
 */
# include <iostream>
# include <fstream>
# include <string>
# include "snake.h"
# include <vector>

using namespace std;

#define ERR_FAILED_OPENING_INPUT_FILE 0
#define ERR_MISSING_ENTRY_EXIT 1
#define READ_OK 2

int read_file( std::string file_name, vector<vector<int>> &matrix )
{
    // The input file strem.
    std::ifstream ifs { file_name }; // Creating and Opening the stream.
    // Flags that indicates whether the maze has entry and exit.
    bool has_entry{false}, has_exit{false};

    // Check whether we sucessfully open the input file.
    if ( ifs.fail() ) return ERR_FAILED_OPENING_INPUT_FILE;

    // While there is lines to read from the input file...
    while( not ifs.eof() )
    {
        std::string line; // Stores a line from the input file.
        std::getline( ifs, line );
        std::vector<int> temp; // Array to hold the integer representation of one line of a maze.
        // Traverse the string we just read in from the input file.
        for ( const char &elem : line )
        {
            // Teste which type of cell we've got.
            if ( elem == '0' ) // espaço vazio no labirinto.
                temp.push_back(Maze::FREE);

            else if ( elem == '1' ) // parede
                temp.push_back( Maze::WALL );

            else if ( elem == 'm' or elem == 'M' ) // The start.
            {
                temp.push_back(Maze::ENTRY );
                has_entry = true; // Turn on flag to indicate we've found the entry cell.
            }

            else if ( elem == 'e' or elem == 'E' ) // The exit.
            {
                temp.push_back( Maze::EXIT );
                has_exit = true; // Turn on flag to indicate we've found the exit cell.
            }

            else // Found an invalid value in the file.
                std::cerr << "Invalid value!!\n";
        }
        // Store the new line in the maze.
        matrix.push_back( temp );
    }

    // All mazes to be valid must have entry/exit cells.
    if ( not has_entry or not has_exit )
        return ERR_MISSING_ENTRY_EXIT;

    // Closes input file stream.
    ifs.close();

    return READ_OK;
}

int main(int argc, char const *argv[])
{
	/*if ( argc != 2 ) {
        std::cout << ">>> Missing input file!\n"
                  << "    Sintax: maze [inpu_file_name]\n\n";
        return 1;
    }*/

    //Maze teste;

    //ifstream myfile;

    //myfile.open("lab_irregular.dat");

    //teste.readfile(myfile);

    vector<vector<int>> input_matrix;
    auto result = read_file( "lab_irregular.dat", input_matrix );

	// criar tabuleiro

	//receber da linha de comando filepath do arquivo usando string
	//passar para a funcao apenas o caminho
	
	return 0;
}
