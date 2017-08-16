#include <c++/cstdlib>
#include <c++/ctime>
#include <c++/string>
#include <c++/iostream>

#include "weapon.h"
#include "character.h"
#include "random.h"
#include "ansi.h"

Random* random = new Random();
//Random* random = new Random(1234567890);

Weapon* getRandomWeapon() {
    int result = random->getNumberBetween(0, 2);
    Weapon* weapon;

    if (result == 0) {
        weapon = new Weapon("sword", 1, 3, 0.25);   // damage: 4-12
    } else if (result == 1) {
        weapon = new Weapon("axe", 3, 7, 0.5);      // damage: 6-14
    } else {
        weapon = new Weapon("hammer", 8, 16, 1.0);  // damage: 8-16
    }

    return weapon;
}

void swing(Character *offender, Character *defender) {
    int damage = random->getNumberBetween(offender->weapon->minDamage, offender->weapon->maxDamage) + offender->strength;
    defender->currentHitPoints -= damage;
    std::cout << offender->name << " swings at " << defender->name << " for " << damage << " damage!" << std::endl;

    if (defender->currentHitPoints <= 0) {
        defender->isAlive = false;
        std::cout << defender->name << " has been slain." << std::endl;
    }
}

void attack(Character* offender, Character* defender) {
    auto swingsPerRound = (int)(1 / offender->weapon->speed);
    for (auto i = 0; i < swingsPerRound; ++i) {
        if (!defender->isAlive) break;
        if (random->flipCoin()) {
            swing(offender, defender);
        } else {
            std::cout << offender->name << " swings at " << defender->name << " but misses!" << std::endl;
        }
    }
}

void levelUp(Character* c) {
    int hitPointIncrease = random->getNumberBetween(5, 10);
    std::cout << c->name << " has leveled, gaining " << hitPointIncrease << " HP!" << std::endl;
    c->totalHitPoints += hitPointIncrease;
    c->currentHitPoints = c->totalHitPoints;
    c->strength += 1;
}

int main() {

    std::cout << "---" << std::endl;

    // generate a hero
    Character* hero = new Character("Ryan", getRandomWeapon(), 10, 0);
    std::cout << hero << std::endl;

    // generate the initial monster
    Character* monster = new Character("Orc", getRandomWeapon(), hero->totalHitPoints, hero->strength);
    std::cout << monster << std::endl;

    bool gameIsRunning = true;
    while (gameIsRunning) {

        std::cout << "---" << std::endl;

        if (hero->isAlive && monster->isAlive) {
            // hero swings first
            attack(hero, monster);

            // skip the monster's combat round if it's dead
            if (!monster->isAlive) continue;

            // now the monster swings
            attack(monster, hero);

        } else if (hero->isAlive && !monster->isAlive) {
            // level up the hero
            levelUp(hero);
            std::cout << hero << std::endl;

            // spawn another monster
            monster = new Character("Orc", getRandomWeapon(), hero->totalHitPoints, hero->strength);
            std::cout << monster << std::endl;

        } else if (!hero->isAlive && monster->isAlive) {
            // hero slain
            gameIsRunning = false;

        } else {
            // both monster and hero slain
            gameIsRunning = false;
        }
    }
}
