
#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "FishTank.h"
#include "AquaticAnimal.h"
#include "ImplementAnimals.h"



class Game {
private:

    FishTank fish_tank;

    std::vector<AquaticAnimal*> suitable_animals;
    std::vector<AquaticAnimal*> animals;
    float budget = 1000.0;
    float target_amount;
    bool game_over;
    std::string name;
    std::string art;
    std::vector<AquaticAnimal*> available_animals;


public:
    Game();
    Game(float ph_level, float temperature, float volume, bool filtration, float target_amount);
    ~Game();
    void init_fish_tank();
    void start_game();
    void load_game(const std::string &filename);
    void save_game(const std::string &filename);
    void next_day();
    void show_menu() const;
    void game_loop();
    bool check_game_over() const;
    void feed_animal();
    void treat_animal();
    void sell_animal();
    void buy_animal();
    void check_animal_status();
    void display_suitable_animals(const std::vector<AquaticAnimal*>& suitable_animals);
    void initialize_available_animals();
    void end_day_prompt();




};

#endif // GAME_H
