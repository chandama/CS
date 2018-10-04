#include "Cleric.h"

#define HEALING_LIGHT_MULT 3

int Cleric::getDamage() {
    return magic;
}

void Cleric::reset() {
    currentHP = maxHP;
    mana = maxMana;
}

void Cleric::regenerate() {
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
    //Mana regen for Clerics
    if ((mana / MANA_MULT) < 1) {
        mana = mana + 1;
    }
    else {
        mana = mana + (double)(magic / MANA_MULT);
    }
    if (mana > maxMana) {
        mana = maxMana;
    }
}

bool Cleric::useAbility() {
    if (mana >= CLERIC_ABILITY_COST) {
    currentHP = (currentHP + (magic / HEALING_LIGHT_MULT));
    mana = mana - CLERIC_ABILITY_COST;
        if (currentHP > maxHP) { //After executing ability, check for overheal and fix
            currentHP = maxHP;
        }
        return true;
    }
    else {
        return false;
    }
}

void Cleric::takeDamage(int damage) {
    if ((damage - (speed / TAKE_DMG)) > 1) {
        currentHP = currentHP - (damage - (speed / TAKE_DMG));
    }
    else {
        currentHP--;
    }
}