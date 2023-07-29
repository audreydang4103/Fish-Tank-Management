#ifndef FISHTANK_H
#define FISHTANK_H

class FishTank {
private:
    float temperature;
    float ph_level;
    float volume;
    bool filtration;

public:
    FishTank(float temperature, float ph_level, float volume, bool filtration);
    float getTemperature() const;
    float getPHLevel() const;
    float getVolume() const;
    bool getFiltration() const;

};

#endif // FISHTANK_H
