#include "Robot.h"


int Robot::getDamage() {
    int totalDmg;
    totalDmg = strength + bonusDmg;
    bonusDmg = 0;
    return totalDmg;
}

void Robot::reset() {
    currentHP = maxHP;
    bonusDmg = 0;
    energy = maxEnergy;
}

void Robot::regenerate() {
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

bool Robot::useAbility() { 
    /*Needs work*/
    /*Use pow for the exponent*/
    if (energy >= ROBOT_ABILITY_COST) {
        bonusDmg = ((strength * pow(((double)energy / (double)maxEnergy),SHOCKWAVE_MULT)));
        energy = energy - ROBOT_ABILITY_COST;
    }
}

void Robot::takeDamage(int damage) {
    if (damage - (speed / TAKE_DMG) > 1) {
    currentHP = currentHP - (damage - (speed / TAKE_DMG));
    }
    else {
        currentHP--;
    }
}