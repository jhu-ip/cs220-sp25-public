#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include "Game.h"

void show_commands() {
	std::cout << "List of commands:" << std::endl;
	std::cout << "\t'?':            show this list of options" << std::endl;
	std::cout << "\t'Q':            quit the game" << std::endl;
	std::cout << "\t'L' <filename>: load a game from the specified file" << std::endl;
	std::cout << "\t                <filename> is the name of the file to read from" <<std::endl;
	std::cout << "\t'S' <filename>: save a game to the specified file" << std::endl;
	std::cout << "\t                <filename> is the name of the file to write to" <<std::endl;
	std::cout << "\t'M' <move>:     try to make the specified move" << std::endl;
	std::cout << "\t                <move> is a four character string giving the" << std::endl;
	std::cout << "\t                column (['A'-'H']), row ('1'-'8') of the start position" << std::endl;
	std::cout << "\t                followed by the column and row of the end position" << std::endl;
}

int main(int argc, char* argv[]) {
	Chess::Game game;

	// Display command options
	show_commands();

	// Keep playing until the game is over
	bool game_over = false;

	while(!game_over) {

		// Display the board
		game.display();

		// Indicate whose turn it is
		if (game.turn_white()) {
			std::cout << "white move" << std::endl;
		} else {
			std::cout << "black move" << std::endl;
		}

        // Indicate current player's material point value
        std::cout << "Material point value: " << game.point_value(game.turn_white()) << std::endl;

		// If the board is in a check-mate state, end the game
		if (game.in_mate(game.turn_white())) {
			std::cout << "Checkmate! Game over." << std::endl;
			game_over = true;
			break;

		// If the board is in a check state, notify the players
     		} else if (game.in_check(game.turn_white())) {
			std::cout << "You are in check!" << std::endl;

		// If the board is in a stalemate state, notify the players
		} else if (game.in_stalemate(game.turn_white())) {
			std::cout << "Stalemate! Game over." << std::endl;
			game_over = true;
			break;
		}

		// Get the next command
		std::string choice;
        //		std::pair<char, char> start , end;
		std::cout << "Next command: ";
		std::cin >> choice;

		// Validate that the command is a single character
		if (choice.length() != 1) {
			std::cerr << "Action specifier must be a single character, but length(" <<
			  choice << ") = " << choice.length() << std::endl;

		} else {
			// Process the different commands
			switch (choice[0]) {
			case '?':
				// Show the commands
				show_commands();
				break;
			case 'Q': case 'q':
				// Quit the game
				game_over = true;
				break;
			case 'L': case 'l': {
				// Load a game from a file
        // TODO: add try catch blocks to handle any file i/o and gmae loading problem
        // exit the program with return code -1 if an exception is caught here
				std::string argument;
				std::cin >> argument;
				std::ifstream ifs;
				ifs.open( argument );
				ifs >> game;
				ifs.close();
				// Check that the game is valid
				assert(game.is_valid_game());
				break;
			}
			case 'S': case 's': {
				// Write a game to a file
				std::string argument;
				std::cin >> argument;
				std::ofstream ofs;
				ofs.open( argument );
				ofs << game;
				ofs.close();
				break;
			}
			case 'M': case 'm': {
				// Make a move
				std::string argument;
				std::cin >> argument;
				// Validate that the move is correctly specified
				if (argument.length() != 4) {
					std::cerr <<
					  "Move specifier must be four characters, but length(" <<
					  argument << " ) = " << argument.length() << std::endl;
				// And make the move
				} else {
          // TODO: add try catch blocks to recover from illegral moves
					game.make_move(std::make_pair(argument[0], argument[1]),
								   std::make_pair(argument[2], argument[3]));
				}
				break;
			}
			default:
				// Unrecognized command
				std::cerr << "Invalid action '" << choice << "'" << std::endl;
			}
		}
	}

	// Write out the state of the game to a file
	if (argc > 1) {
		std::ofstream ofs;
		ofs.open(argv[1]);
		ofs << game;
		ofs.close();
	}

	return 0;
}

