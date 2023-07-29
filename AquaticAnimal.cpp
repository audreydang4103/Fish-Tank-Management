#include "AquaticAnimal.h"

//Setting default name, hunger, health, sick, sell price and age

AquaticAnimal::AquaticAnimal(std::string name, std::string art, float sell_price) :
        name(name),
        hunger(40),
        health(100.0),
        sick(false),
        art(art),
        sell_price(sell_price),
        age(0.0)
{}

//A virtual destructor to properly deallocate resources when deleting derived objects through a pointer to the base class

AquaticAnimal::~AquaticAnimal() {}

std::string AquaticAnimal::getName() const {
    return name;
}

std::string AquaticAnimal::getArt() const {
    return art;
}

float AquaticAnimal::getAdjustedSellPrice() const {

}


float AquaticAnimal::getHealth() const {
    return health;
}

bool AquaticAnimal::isSick() const {
    return sick;
}

float AquaticAnimal::getSellPrice() const {
    return sell_price;
}

float AquaticAnimal::getAge() const {
    return age;
}
float AquaticAnimal::getHunger() const{
    return hunger;
}


void AquaticAnimal::feed() {
    if (hunger>=20) {
        hunger -= 20; // Decrese hunger by 20
    } else {
        hunger=0;
    }
}

void AquaticAnimal::heal() {
    health += 20;
    sick = false;
}








