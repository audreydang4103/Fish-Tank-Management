#include <iostream>
#include "Game.h"
#include <iomanip>

void print_menu() {


    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 "           .               `         /\n"
                 "                            .    ,../...       .\n"
                 "            .                .  /       `\\  /  .\n"
                 "       \\    .        o         < '  )     =<\n"
                 "       /\\  .                    \\ \\      /  \\   .  __\n"
                 "     >=)'>                       `'\\'\"'\"'         /o \\/\n"
                 "       \\/ .    /         o              /,        \\__/\\    .:/\n"
                 "       /   .  /--\\ /         /         <')=<     .      ,,///;,   ,;/\n"
                 "             <o)  =<      . / \\         \\`         .   o:::::::;;///\n"
                 "              \\__/ \\       <')_=<                     >::::::::;;\\\\\\\n"
                 "               \\            \\_/            .            ''\\\\\\\\\\'' ';\\\n"
                 "      (                      \\              .   __\n"
                 "       )                                       <'_><          (\n"
                 "      (          (                ,/..          `              )\n"
                 "       )     (    )             <')   `=<                )    (\n"
                 "      (       )  (               ``\\```                 (      )\n"
                 "_____________(____)______________________________________)____(___________";
    std::cout <<  std::endl << std::endl;


    // print the left spaces, the text, and the right spaces
    std::cout << "\033[35m"; //set magenta color
    std::cout << std::setw(130) << "╔═══════════════════════════════════════╗" << std::setw(20) << "" << std::endl;
    std::cout << std::setw(50) << "  Welcome to Fish Tank Management Game!    " << std::setw(20) << "" << std::endl;
    std::cout << std::setw(130) << "╚═══════════════════════════════════════╝" << std::setw(20) << "" << std::endl;
    std::cout <<  std::endl;

    std::cout << "\033[0m"; //default color
    std::cout << std::setw(35) << "1. Start a new game\n";
    std::cout << std::setw(36) << "2. Load a saved game\n";
    std:: cout << std::setw(23) << "3. Exit\n";
    std::cout <<  std::endl;
    std::cout << "Please enter your choice (1, 2 or 3): ";
}
int main() {
    int choice;
    std::string filename;


    while (true) {
        print_menu();
        std::cin >> choice;
        if (choice == 3) {
            std::cout << "Exiting the game...\n";
            return 0;
        } else {
            {
                Game game;

                switch (choice) {
                    case 1:
                        game.start_game();
                        game.game_loop();
                        break;
                    case 2:
                        std::cout << "Please enter the filename of the saved game: ";
                        std::cin.ignore(); // Ignore any remaining newline characters in the input buffer
                        std::getline(std::cin, filename);
                        game.load_game(filename);
                        game.game_loop(); // Add the game_loop() call here
                        break;
                    default:
                        std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                }
            }

            return 0;
        }
    }
}



