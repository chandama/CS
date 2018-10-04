#pragma once
#include "FighterInterface.h"
#include "ArenaInterface.h"
#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include <vector>
#include <sstream>

using namespace std;


class Arena : public ArenaInterface
{
private:
	vector<Fighter*> fighterVec;
	
public:
	Arena() {}
	~Arena() {}

	bool addFighter(string info);

	bool removeFighter(string name);

	FighterInterface* getFighter(string name);

	int getSize() const;
};