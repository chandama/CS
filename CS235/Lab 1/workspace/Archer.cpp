#include "Archer.h"

int Archer::getDamage() {
    return speed;
}

void Archer::reset() {
    currentHP = maxHP;
    speed = startSpeed;
}

void Archer::regenerate() {
    //Regen HP same for all classes
    if ((strength / STR_MULT) < 1) {
        currentHP = currentHP + 1;
    }
    else {
        currentHP = currentHP + (strength / STR_MULT);
    }
    if (currentHP > maxHP) {
            currentHP = maxHP;
        }
}

bool Archer::useAbility() {
    speed = speed + 1;
    return true;
}

void Archer::takeDamage(int damage) {
    if (damage - (speed / TAKE_DMG) > 1) {
    currentHP = currentHP - (damage - (speed / TAKE_DMG));
    }
    else {
        currentHP--;
    }
}