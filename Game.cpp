#include "Game.h"
#include "FishTank.h"
#include <iostream>
#include <fstream>
#include "ImplementAnimals.h"
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>


float ph_level, temperature, volume,filtration;

//set default target_amount, and fish tank environment

Game::Game() : fish_tank(0.0, 0.0, 0.0, false) {
    target_amount = 2500.0;
}


void Game::init_fish_tank() {
    // Input fish tank environment
    std::cout << "Enter the pH level of your fish tank (6.5 - 7.5): ";
    std::cin >> ph_level;
    std::cout << "Enter the temperature of your fish tank in Celsius (20.0 - 30.0): ";
    std::cin >> temperature;
    std::cout << "Enter the volume of your fish tank in liters (greater than 50): ";
    std::cin >> volume;
    std::cout << "Does your fish tank have a filtration system? (1 for yes, 0 for no): ";
    std::cin >> filtration;
    fish_tank = FishTank(temperature, ph_level, volume, filtration);
}

//menu for start game
void Game::start_game() {
    init_fish_tank();
    std::cout << "Your starting budget is: $" << budget << std::endl;
    std::cout << "Your target amount to win is: $" << target_amount << std::endl << std::endl;
    std::cout << "\033[0m"; //default color

    // Initialize available animals
    initialize_available_animals();

    // Filter suitable animals based on the environment
    std::vector<AquaticAnimal*> suitable_animals;
    for (AquaticAnimal* animal : available_animals) {
        if (animal->check_environment(fish_tank.getPHLevel(), fish_tank.getTemperature(), fish_tank.getVolume(), fish_tank.getFiltration())) {
            suitable_animals.push_back(animal);
        }
    }

    // Display suitable animals and their prices
    buy_animal();


    game_loop();
}



void Game::display_suitable_animals(const std::vector<AquaticAnimal*>& suitable_animals) {
    std::cout << "\nList of animals suitable for your tank and their prices:\n\n";
    // Display suitable animals and their prices
    for (size_t i = 0; i < suitable_animals.size(); ++i) {
        const AquaticAnimal* animal = suitable_animals[i];
        std::cout << (i + 1) << ". " << animal->getName() << " - $" << animal->getSellPrice() << std::endl << animal->getArt() << std::endl << std::endl;
    }
}



 // Create list of avaiable animal

void Game::initialize_available_animals() {
    // Add a list of available animals and their prices
    available_animals.push_back(new Fish("Butterfish", "\n          |\\    o\n"
                                         "         |  \\    o\n"
                                         "     |\\ /    .\\ o\n"
                                         "     | |       (\n"
                                         "     |/ \\     /\n"
                                         "         |  /\n"
                                         "          |/", 30.0));

    available_animals.push_back(new Fish("Gold Fish", "\n          _,           _,\n"
                                         "          .' (        .-' /\n"
                                         "        _/..._'.    .'   /\n"
                                         "    .-'`      ` '-./  _.'\n"
                                         "   ( o)           ;= <_\n"
                                         "    '-.,\\\\__ __.-;`\\   '.\n"
                                         "         \\) |`\\ \\)  '.   \\\n"
                                         "            \\_/       '-._\\\n"
                                         "                          `", 15.0));
    available_animals.push_back(new Turtle("Hawksbill Turtle", "\n\n                    __\n"
                                           "         .,-;-;-,. /'_\\\n"
                                           "       _/_/_/_|_\\_\\) /\n"
                                           "     '-<_><_><_><_>=/\\\n"
                                           "     `/_/====/_/-'\\_\\\n"
                                           "        \"\"     \"\"    \"\"", 70.0));

    available_animals.push_back(new Turtle("Box Turtle", "\n\n       _____     ____\n"
                                           "      /      \\  |  o | \n"
                                           "     |        |/ ___\\| \n"
                                           "     |_________/     \n"
                                           "     |_|_| |_|_|", 60.0));
    available_animals.push_back(new Crab("Blue Crab", "                                                                     \n"
                                                      "                                                                                        \n"
                                                      "            ██  ██                      ██  ██                          \n"
                                                      "          ██▒▒██▒▒██                  ██▒▒██▒▒██                        \n"
                                                      "          ██▒▒██▒▒██      ░░          ██▒▒██▒▒██                        \n"
                                                      "          ██▒▒▒▒▒▒██  ░░              ██▒▒▒▒▓▓██                        \n"
                                                      "           ██████                      ██████                          \n"
                                                      "           ██▒▒██                      ██▒▒██                          \n"
                                                      "            ██▒▒██  ██          ██  ██▒▒██                            \n"
                                                      "             ██▒▒██  ██████████  ██▒▒██                              \n"
                                                      "   ██        ██▒▒████▒▒▒▒▒▒▒▒▒▒████▒▒██        ██                    \n"
                                                      "   ████        ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██        ████                    \n"
                                                      "   ██▒▒████    ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██    ████▒▒██                    \n"
                                                      "    ██▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▓▓▒▒██                      \n"
                                                      "     ██▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██                        \n"
                                                      "         ██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██████                          \n"
                                                      "             ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                              \n"
                                                      "           ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████                            \n"
                                                      "         ██▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██                          \n"
                                                      "      ██▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▒▒▒▒██                        \n"
                                                      "      ██████    ████▒▒▒▒▒▒▒▒▒▒████    ██████                        \n"
                                                      "      ██      ██▒▒▒▒██████████▒▒▒▒██      ██                        \n"
                                                      "              ██▒▒██          ██▒▒██                                \n"
                                                      "              ████              ████                                \n"
                                                      "              ██                  ██       ",75));
    available_animals.push_back(new Crab("Dungeness Crab","                                          \n"
                                                     "         ▒▒▒▒▒▒▒▒        ▒▒▒▒▒▒▒▒         \n"
                                                     "       ▒▒▒▒▒▒                ▒▒▒▒▒▒       \n"
                                                     "       ▒▒▒▒▒▒▒▒▒▒        ▒▒▒▒▒▒▒▒▒▒       \n"
                                                     "     ▒▒▒▒▒▒▒▒▒▒            ▒▒▒▒▒▒▒▒▒▒     \n"
                                                     "     ▒▒▒▒      ██        ██      ▒▒▒▒     \n"
                                                     "     ▒▒▒▒    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒     \n"
                                                     "     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒     \n"
                                                     "       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒      \n"
                                                     "           ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒          \n"
                                                     "       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒      \n"
                                                     "     ▒▒▒▒    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒   \n"
                                                     "           ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒         \n"
                                                     "         ▒▒▒▒    ▒▒▒▒▒▒▒▒    ▒▒▒▒       \n",45));
}



Game::Game(float ph_level, float temperature, float volume, bool filtration, float target_amount) :
        fish_tank(temperature, ph_level, volume, filtration),

        target_amount(target_amount),
        game_over(false)
{}

//destructor
Game::~Game() {
    for (AquaticAnimal* animal : animals) {
        delete animal;
    }
}


void Game::load_game(const std::string &filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    // Load fish tank data
    float ph_level, temperature, volume;
    in >> ph_level >> temperature >> volume;
    fish_tank = FishTank(temperature, ph_level, volume, filtration);

    // Load budget and target amount
    in >> budget >> target_amount;

    // Load animals
    int num_animals;
    in >> num_animals;
    animals.clear();
    for (int i = 0; i < num_animals; ++i) {
        std::string type, name;
        float buy_price;
        in >> type >> name >> buy_price;

        AquaticAnimal* animal = nullptr;
        if (type == "Fish") {
            animal = new Fish(name, art, buy_price);
        } else if (type == "Turtle") {
            animal = new Turtle(name, art, buy_price);
        }
        if (animal) {
            animals.push_back(animal);
        }
    }
    in.close();

}

void Game::save_game(const std::string &filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    // Save fish tank data
    out << fish_tank.getPHLevel() << " " << fish_tank.getTemperature() << " " << fish_tank.getVolume() << std::endl;

    // Save budget and target amount
    out << budget << " " << target_amount << std::endl;

    // Save animals
    out << animals.size() << std::endl; // Save the total number of animals in the tank
    for (const AquaticAnimal* animal : animals) { // Iterate through each animal in the tank
        std::string type;

        // Determine the animal's type using dynamic_cast, which checks if the object is an instance of a specified class
        if (dynamic_cast<const Fish*>(animal)) {
            type = "Fish";
        } else if (dynamic_cast<const Turtle*>(animal)) {
            type = "Turtle";
        } else if (dynamic_cast<const Crab*>(animal)) {
            type = "Crab";
        }
        out << type << " " << animal->getName() << " " << animal->getSellPrice() << std::endl;
    }
    out.close(); // Close the output file after saving all the animals
}


void Game::next_day() {
    for (AquaticAnimal *animal: animals) {
        animal->next_day();
    }
    // Initialize an iterator for the animals vector

    auto it = animals.begin();

    // Iterate through the animals vector
    while (it != animals.end()) {
        AquaticAnimal *animal = *it;

        // Check if the animal's health is 0 or less, or if the animal's age exceeds its maximum age
        if (animal->getHealth() <= 0 || animal->getAge() > animal->getMaxAge()) {

            // If so, delete the animal and remove it from the animals vector
            delete animal;
            it = animals.erase(it);
        } else { // Otherwise, move on to the next animal
            ++it;
        }
    }

    check_animal_status();
    show_menu();

}


void Game::show_menu() const {
    std::cout << "\033[34m"; // Set the text color to blue
    std::cout << "\nAvailable actions:\n";
    std::cout << "1. Feed an animal\n";
    std::cout << "2. Treat an animal\n";
    std::cout << "3. Sell an animal\n";
    std::cout << "4. Buy a new animal\n";
    std::cout << "5. Save game\n";
    std::cout << "6. Load game\n\n";
    std::cout << "\033[0m"; // Reset the text color to default
    std::cout << "Enter the number of the action you would like to perform: \n";
}


void Game::game_loop() {
    while (!game_over) {

        check_animal_status();
        show_menu();

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Feed an animal
                feed_animal();
                end_day_prompt();
                break;
            case 2:
                // Treat an animal
                treat_animal();
                end_day_prompt();
                break;
            case 3:
                // Sell an animal
                sell_animal();
                end_day_prompt();
                break;
            case 4:
                // Buy a new animal
                buy_animal();
                end_day_prompt();
                break;

            case 5:
                // Save game
            {
                std::string filename;
                std::cout << "Enter the filename to save the game(.txt file): ";
                std::cin >> filename;
                save_game(filename);
            }
                break;
            case 6:
                // Load game
            {
                std::string filename;
                std::cout << "Enter the filename to load the game: ";
                std::cin >> filename;
                load_game(filename);
            }
            default:
                std::cout << "Invalid option. Please try again." << std::endl;


        }
        game_over = check_game_over();
    }
}

void Game::feed_animal() {
    if (animals.empty()) {
        std::cout << "You don't have any animals to feed." << std::endl;
        return;
    }

    std::cout << "List of animals you have:\n";
    for (size_t i = 0; i < animals.size(); ++i) {
        const AquaticAnimal* animal = animals[i];
        std::cout << (i + 1) << ". " << animal->getName() << std::endl;
    }

    int choice;
    while (true) {
        std::cout << "Enter the number of the animal you want to feed: ";
        std::cin >> choice;

        if (choice < 1 || choice > animals.size()) {
            std::cout << "Invalid choice. Please try again." << std::endl;
        } else {
            break;
        }
    }

    AquaticAnimal* selected_animal = animals[choice - 1];
    selected_animal->feed();
    budget -= 10;
    std::cout << selected_animal->getName() << " has been fed." << std::endl;
}

void Game::treat_animal() {
    if (animals.empty()) {
        std::cout << "You don't have any animals to treat." << std::endl;
        return;
    }

    std::cout << "List of animals you have:\n";
    for (size_t i = 0; i < animals.size(); ++i) {
        const AquaticAnimal* animal = animals[i];
        std::cout << (i + 1) << ". " << animal->getName() << std::endl;
    }

    int choice;
    while (true) {
        std::cout << "Enter the number of the animal you want to treat: ";
        std::cin >> choice;

        if (choice < 1 || choice > animals.size()) {
            std::cout << "Invalid choice. Please try again." << std::endl;
        } else {
            break;
        }
    }

    AquaticAnimal* selected_animal = animals[choice - 1];
    if (selected_animal->isSick() || selected_animal->getHealth()<50) {
        selected_animal->heal();
        budget -= 50;
        std::cout << selected_animal->getName() << " has been treated." << std::endl;
    } else {
        std::cout << selected_animal->getName() << " is not sick." << std::endl;
    }
}

void Game::end_day_prompt() {
    std::cout << "Do you want to end the day? (Press 1 for Yes. Press any key for No): ";
    char choice;
    std::cin >> choice;

    if (choice == '1' || choice == 'Y') {
        next_day();
    } else {
        show_menu();
    }
}



// fix the infinite loop error if the user enter non-number input in sell_animal

bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void Game::sell_animal() {
    if (animals.empty()) {
        std::cout << "You don't have any animals to sell." << std::endl;
        return;
    }

    std::cout << "List of animals you have and their sell prices:\n";
    for (size_t i = 0; i < animals.size(); ++i) {
        const AquaticAnimal* animal = animals[i];
        std::cout << (i + 1) << ". " << animal->getName() << " - $" << animal->getAdjustedSellPrice() << std::endl;
    }

    std::string user_input;
    std::cout << "Enter the number of the animal you want to sell: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    std::getline(std::cin, user_input);

    if (is_number(user_input)) {
        int choice = std::stoi(user_input);

        if (choice >= 1 && choice <= animals.size()) {
            AquaticAnimal *selected_animal = animals[choice - 1];
            float adjusted_sell_price = selected_animal->getAdjustedSellPrice();
            budget += adjusted_sell_price;
            std::cout << selected_animal->getName() << " has been sold for $" << adjusted_sell_price << "." << std::endl;

            delete selected_animal;
            animals.erase(animals.begin() + (choice - 1));
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
            return;
        }
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
        return;
    }
}





void Game::buy_animal() {
    // Display suitable animals and their prices
    std::vector<AquaticAnimal *> suitable_animals;
    for (AquaticAnimal *animal: available_animals) {
        if (animal->check_environment(fish_tank.getPHLevel(), fish_tank.getTemperature(), fish_tank.getVolume(), fish_tank.getFiltration())) {
            suitable_animals.push_back(animal);
        }
    }

    if (suitable_animals.empty()) {
        std::cout << "There is not any animal that can survive in this fish tank.\n";
        std::cout << "You are lose. \n" ;

        game_over = true;
    } else {


        display_suitable_animals(suitable_animals);

        int choice;
        std::cout << "Enter the number of the animal you want to buy: ";
        std::cin >> choice;

        if (choice < 1 || choice > suitable_animals.size()) {
            std::cout << "Invalid choice. Please try again." << std::endl;
            return;
        }

        AquaticAnimal *selected_animal = suitable_animals[choice - 1];

        if (budget >= selected_animal->getSellPrice()) {
            budget -= selected_animal->getSellPrice();
            std::string name;

            animals.push_back(selected_animal->clone());
            std::cout << "Congratulations! You have bought a new " << selected_animal->getName() << "." << std::endl;
            std::cout << "Remaining budget: $" << budget << std::endl;
        } else {
            std::cout << "You don't have enough budget to buy this animal." << std::endl;
        }
    }
}

void Game::check_animal_status() {

    std::cout << "The Status of Animals in Your Fish Tank: \n \n";
    if (animals.empty()) {
        std::cout << "There is not any animal that can survive in this fish tank. Please buy a new one.\n";
    } else {
    for (AquaticAnimal* animal : animals) { // Use non-const reference

        std::cout << animal->getName() << " - Health: " << animal->getHealth() << ", Age: " << animal->getAge()
                  << " Hunger: " << animal->getHunger() << std::endl;
        // Display unique actions for each animal
        std::cout << "Action: ";
        animal->unique_action();
        std::cout << std::endl;
        std::cout << "Remaining budget: $" << budget << std::endl;
    }

    }

    }

    bool Game::check_game_over() const {
        if (animals.empty() && budget <= 0) {
            std::cout << "You are lose. \n" ;
            return true;
        }
        if (budget >= target_amount) {
            std::cout << "You are win!!! \n" ;
            return true;
        }
        return false;
    }

