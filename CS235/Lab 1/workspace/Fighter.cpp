#include "Fighter.h"

string Fighter::getName() const {
    return name;
}

int Fighter::getMaximumHP() const {
    return maxHP;
}

int Fighter::getCurrentHP() const {
    return currentHP;
}

int Fighter::getStrength() const {
    return strength;
}

int Fighter::getSpeed() const {
    return speed;
}

int Fighter::getMagic() const {
    return magic;
}

//int Fighter::getDamage() {}

//void Fighter::takeDamage(int damage) {}
