#pragma once
#include "FighterInterface.h"
using namespace std;

const int STR_MULT = 6;
const int TAKE_DMG = 4;

class Fighter : public FighterInterface
{
public:
	Fighter(string ftrName, int ftrMaxHP, int ftrStr, int ftrSpd, int ftrMag) {
	    name = ftrName;
	    maxHP = ftrMaxHP;
	    currentHP = ftrMaxHP;
	    strength = ftrStr;
	    speed = ftrSpd;
	    magic = ftrMag;
	}
	~Fighter() {}

	string getName() const;

	int getMaximumHP() const;

	int getCurrentHP() const;

	int getStrength() const;

	int getSpeed() const;

	int getMagic() const;

	virtual int getDamage() = 0; //leaving this virtual because the damage depends on the other stats and is different for each type of ftr.

	virtual void takeDamage(int damage) = 0; //depends on speed stat but is the same calc for each ftr so handle that in Fighter.cpp

	virtual void reset() = 0; //resets some stats that need calculations or need resetting so this stays virtual.

	virtual void regenerate() = 0; //regenerate functions differently for cleric so hand this in the subclasses.

	virtual bool useAbility() = 0; //Abilities are diff for each ftr so handle this in the subclasses.
	
	protected:
	    string name;
	    int maxHP;
	    int currentHP;
	    int strength;
	    int speed;
	    int magic;
	    int damage;
};