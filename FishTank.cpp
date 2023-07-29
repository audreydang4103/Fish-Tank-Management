#include "FishTank.h"


FishTank::FishTank(float temperature, float ph_level, float volume, bool filtration) : temperature(temperature), ph_level(ph_level), volume(volume), filtration(filtration) {}

float FishTank::getTemperature() const { return temperature; }
float FishTank::getPHLevel() const { return ph_level; }
float FishTank::getVolume() const { return volume; }

bool FishTank::getFiltration() const {
    return filtration;
}




