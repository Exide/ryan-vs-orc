#ifndef RYAN_VS_ORC_WEAPON_H
#define RYAN_VS_ORC_WEAPON_H

#include <c++/string>

struct Weapon {
    std::string name;
    int minDamage;
    int maxDamage;
    float speed; // % of round used for a single swing (0.25 = 25% = 4 swings per round)

    explicit Weapon(std::string name, int minDamage, int maxDamage, float speed)
    : name(name), minDamage(minDamage), maxDamage(maxDamage), speed(speed) {};
};

#endif //RYAN_VS_ORC_WEAPON_H
