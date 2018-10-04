#pragma once
#include "Fighter.h"
#include <cmath>

const int ENERGY_MULT = 2;
const double SHOCKWAVE_MULT = 4.0;

class Robot : public Fighter
{
public: 
    Robot(string roboName, int roboHP, int roboStr, int roboSpd, 
    int roboMag):Fighter(roboName, roboHP, roboStr, roboSpd, roboMag){
        maxEnergy = magic * ENERGY_MULT;
        energy = maxEnergy;
        bonusDmg = 0;
    }
    ~Robot() {}
    
    int getDamage();
    
    void reset();
    
    void regenerate();
    
    bool useAbility();
    
    void takeDamage(int damage);
    
protected:
    int energy;
    int maxEnergy;
    int bonusDmg;
};