#pragma once
#include "Fighter.h"

class Archer : public Fighter
{
public: 
    Archer(string archName, int archHP, int archStr, int archSpd, 
    int archMag):Fighter(archName, archHP, archStr, archSpd, archMag){
        startSpeed = speed;
    }
    ~Archer() {}

    int getDamage();
    
    void reset();
    
    void regenerate();
    
    bool useAbility();
    
    void takeDamage(int damage);
    
protected:
    int startSpeed;
};