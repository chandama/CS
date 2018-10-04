#pragma once
#include "Fighter.h"

const int MANA_MULT = 5;

class Cleric : public Fighter
{
public: 
    Cleric(string clericName, int clericHP, int clrStr, int clrSpd, 
    int clrMag):Fighter(clericName, clericHP, clrStr, clrSpd, clrMag){
        maxMana = magic * MANA_MULT;
        mana = maxMana;
    }
    ~Cleric() {}

    int getDamage();
    
    void reset();
    
    void regenerate();
    
    bool useAbility();
    
    void takeDamage(int damage);
    
protected:
    int mana;
    int maxMana;
};
