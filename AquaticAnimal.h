#ifndef AQUATIC_ANIMAL_H
#define AQUATIC_ANIMAL_H

#include <string>


class AquaticAnimal {
protected:
    std::string name;
    int hunger;
    bool hungry = false;
    float health;
    bool sick;
    float sell_price;
    int age;
    std::string art;
public:
    void feed();
    void heal();
    AquaticAnimal(std::string name, std::string art, float sell_price);
    virtual ~AquaticAnimal();
    virtual bool check_environment(float ph_level, float temperature, float volume, bool filltration) const = 0;
    virtual void next_day()  = 0;
    virtual void unique_action() const = 0; // Declare the unique_action method as pure virtual
    std::string getName() const;
    std::string getArt() const;
    float getHunger() const;
    float getHealth() const;
    bool isSick() const;
    float getSellPrice() const;
    float getAge() const;
    virtual AquaticAnimal* clone() const = 0; // Declare the clone method as pure virtual for deep copy
    virtual float getAdjustedSellPrice() const;
    virtual int getMaxAge() const = 0;


};


#endif // AQUATIC_ANIMAL_H
