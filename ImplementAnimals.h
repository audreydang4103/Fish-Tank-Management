#include "AquaticAnimal.h"

#ifndef UNTITLED3_IMPLEMENTANIMALS_H
#define UNTITLED3_IMPLEMENTANIMALS_H



class Turtle : public AquaticAnimal {
private:
    int maxAge = 100;
public:
    int getMaxAge() const override {
        return maxAge;
    }

    Turtle(std::string name, std::string art, float sell_price);
    ~Turtle() override;
     bool check_environment(float ph_level, float temperature, float volume, bool filltration) const override;
     void next_day()  override;
    void unique_action() const override;
    void crawl() const;
    void bask() const;
    Turtle* clone() const override;
    float getAdjustedSellPrice() const override;


};

class Fish : public AquaticAnimal {
private:
    int maxAge = 75;

public:
    int getMaxAge() const override {
        return maxAge;
    }
    Fish();
    Fish(std::string name, std:: string art, float sell_price);
    ~Fish() override;
    bool check_environment(float ph_level, float temperature, float volume, bool filtration) const override;
    void next_day()  override;
    void unique_action() const override;
    void swim() const;
    void hovering() const;
    Fish* clone() const override;
    float getAdjustedSellPrice() const override;

};


class Crab : public AquaticAnimal {
private:
    int maxAge = 50;

public:
    int getMaxAge() const override {
        return maxAge;
    }
    Crab();
    Crab(std::string name, std:: string art, float sell_price);
    ~Crab() override;
    bool check_environment(float ph_level, float temperature, float volume, bool filtration) const override;
    void next_day()  override;
    void unique_action() const override;
    void climb_rocks() const;
    void burrow() const;
    Crab* clone() const override;
    float getAdjustedSellPrice() const override;

};


#endif //UNTITLED3_IMPLEMENTANIMALS_H
