#ifndef RYAN_VS_ORC_CHARACTER_H
#define RYAN_VS_ORC_CHARACTER_H

#include <c++/string>
#include "weapon.h"

struct Character {
    std::string name;
    int currentHitPoints = 10;
    int totalHitPoints = 10;
    int armourClass = 10;
    int strength = 0;
    bool isAlive = true;
    Weapon* weapon = nullptr;

    explicit Character(std::string name, Weapon* weapon, int hitPoints, int strength) {
        this->name = name;
        this->weapon = weapon;
        this->currentHitPoints = this->totalHitPoints = hitPoints;
        this->strength = strength;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Character* c) {
        return stream << "Character: " << c->name << " with "
                      << c->currentHitPoints << "/" << c->totalHitPoints << " HP, "
                      << c->armourClass << " AC, "
                      << c->strength << " STR, "
                      << "wielding a " << c->weapon->name;
    }
};

#endif //RYAN_VS_ORC_CHARACTER_H
