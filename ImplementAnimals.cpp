#include <cstdlib>
#include "ImplementAnimals.h"
#include "AquaticAnimal.h"
#include <iostream>
#include <random>

//Setting name and sell price for Turtle

Turtle::Turtle(std::string name, std::string art, float sell_price) :
        AquaticAnimal(name, art, sell_price)
{}

// Destructor
Turtle::~Turtle() {}

//Check if Turtle can live in the fish tank.
bool Turtle::check_environment(float ph_level, float temperature, float volume, bool filltration) const {
    if (ph_level < 6.5 || ph_level > 7.5) {
        return false;
    }
    if (temperature < 23.0 || temperature > 27.0) {
        return false;
    }
    if (volume < 100.0) {
        return false;
    }
    if (filltration == 0) {
        return false;
    }
    return true;
}


// Unique action of turtle
void Turtle::crawl() const {
    std::cout << getName() << " crawls on the ground." << std::endl;
}
void Turtle::bask() const {
    std::cout << getName() << " has found a perfect spot to bask, maintaining a healthy shell." << std::endl;
}
// random unique action
void Turtle::unique_action() const {
    int random_action = rand() % 2; // Generates a random number between 0 and 1

    if (random_action == 0) {
        crawl();
    } else {
        bask();
    }
}


Turtle* Turtle::clone() const {
    return new Turtle(*this); // Copy constructor is used here to create a new Turtle object
}

float Turtle::getAdjustedSellPrice() const {
    float health_multiplier = health / 100.0f;
    float age_multiplier = (maxAge - age) / static_cast<float>(maxAge);
    float hunger_multiplier = hungry ? 0.75f : 1.0f;

    return sell_price * health_multiplier * age_multiplier * hunger_multiplier;
}

void Turtle::next_day()  {
    // is hungry?
    if (hunger > 60) {
        hungry = true;
    }

// Increase hunger
    hunger += 5.0;

// Randomly make the animal sick
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int chance_of_sickness = dis(gen);
    if (chance_of_sickness <= 10) { // 10% chance of getting sick
        sick = true;
    }

// Decrease health if animal is hungry or sick
    if (hungry || sick) {
        health -= 10.0;
    }

// Check if animal has died
    if (health <= 0.0) {

        std::cout << getName() << " has passed away." << std::endl;

    }

// Increase age
    age += 1.0;
}



//Setting name and sell price for Fish

Fish::Fish(std::string name, std::string art, float sell_price) :
        AquaticAnimal(name, art, sell_price)
{}
//Destructor
Fish::~Fish() {}

bool Fish::check_environment(float ph_level, float temperature, float volume, bool filltration) const {
    if (ph_level < 6.5 || ph_level > 7.5) {
        return false;
    }
    if (temperature < 20.0 || temperature > 30.0) {
        return false;
    }
    if (volume < 50.0) {
        return false;
    }
    return true;
}





void Fish::swim() const {
    std::cout << getName() << " is swimming through the water gracefully." << std::endl;
}

void Fish::hovering() const {
    std::cout << getName() << " is hovering near the tank surface." << std::endl;
}
Fish* Fish::clone() const {
    return new Fish(*this); // Copy constructor is used here to create a new Fish object
}

void Fish::unique_action() const {
    int random_action = rand() % 2; // Generates a random number between 0 and 1

    if (random_action == 0) {
        swim();
    } else {
        hovering();
    }
}


float Fish::getAdjustedSellPrice() const {
    float health_multiplier = health / 100.0f;
    float age_multiplier = (maxAge - age) / static_cast<float>(maxAge);
    float hunger_multiplier = hungry ? 0.75f : 1.0f;

    return sell_price * health_multiplier * age_multiplier * hunger_multiplier;
}

void Fish::next_day()  {
    // is hungry?
    if (hunger > 60) {
        hungry = true;
    }

// Increase hunger
    hunger += 5.0;// Randomly make the animal sick

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int chance_of_sickness = dis(gen);
    if (chance_of_sickness <= 10) { // 10% chance of getting sick
        sick = true;
    }


// Decrease health if animal is hungry or sick
    if (hungry || sick) {
        health -= 10.0;
    }

// Check if animal has died
    if (health <= 0.0) {

        std::cout << getName() << " has passed away." << std::endl;

    }

// Increase age
    age += 1.0;
}

//Setting name and sell price for Crab

Crab::Crab(std::string name, std::string art, float sell_price) :
        AquaticAnimal(name, art, sell_price)
{}

// Destructor
 Crab::~Crab() {}

//Check if Crab can live in the fish tank.
bool Crab::check_environment(float ph_level, float temperature, float volume, bool filltration) const {
    if (ph_level < 6.5 || ph_level > 7.5) {
        return false;
    }
    if (temperature < 20.0 || temperature > 30.0) {
        return false;
    }
    if (volume < 50.0) {
        return false;
    }
    return true;
}


// Unique action of crab
void Crab::climb_rocks() const {
    std::cout << getName() << " is expertly climbing up the steep rock face in search of a tasty meal" << std::endl;
}
void Crab::burrow() const {
    std::cout << getName() << " is creating a burrow in the sand " << std::endl;
}
// random unique action
void Crab::unique_action() const {
    int random_action = rand() % 2; // Generates a random number between 0 and 1

    if (random_action == 0) {
        climb_rocks();
    } else {
        burrow();
    }
}


Crab* Crab::clone() const {
    return new Crab(*this); // Copy constructor is used here to create a new Crab object
}

float Crab::getAdjustedSellPrice() const {
    float health_multiplier = health / 100.0f;
    float age_multiplier = (maxAge - age) / static_cast<float>(maxAge);
    float hunger_multiplier = hungry ? 0.75f : 1.0f;

    return sell_price * health_multiplier * age_multiplier * hunger_multiplier;
}

void Crab::next_day()  {
    // is hungry?
    if (hunger > 70) {
        hungry = true;
    }

// Increase hunger
    hunger += 5.0;

// Randomly make the animal sick
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int chance_of_sickness = dis(gen);
    if (chance_of_sickness <= 10) { // 10% chance of getting sick
        sick = true;
    }

// Decrease health if animal is hungry or sick
    if (hungry || sick) {
        health -= 10.0;
    }

// Check if animal has died
    if (health <= 0.0) {

        std::cout << getName() << " has passed away." << std::endl;

    }

// Increase age
    age += 1.0;
}



