#include "Arena.h"

using namespace std;

bool Arena::addFighter(string info) {
    stringstream ss(info);
        string name, type;
        int maxHP, strength, speed, magic;
        
        if (ss >> name >> type >> maxHP >> strength >> speed >> magic) {
            cout << "addFighter got "<<name<<" "<<type<<" "<<maxHP<<" "<<strength
            <<" "<<speed<<" "<<magic;
            
            for (int i = 0; i < fighterVec.size(); ++i) {
                 if (name == fighterVec.at(i)->getName()) {
                    return false;
                }
            }
           
            if (!ss.eof()) {
                return false;
            }
            
            if (type == "A") {
                cout << "Adding Archer" << endl;
                fighterVec.push_back(new Archer(name, maxHP, strength, speed, magic));
            }
            else if (type == "R") {
                cout << "Adding Robot" << endl;
                fighterVec.push_back(new Robot(name, maxHP, strength, speed, magic));
            }
            else if (type == "C") {
                cout << "Adding Cleric" << endl;
                fighterVec.push_back(new Cleric(name, maxHP, strength, speed, magic));
            }
            else {
                return false; //Not a valid type of fighter
            }
            return true;
        }
        return false; //Invalid input, not enought tokens or wrong input type
}

bool Arena::removeFighter(string name) {
    for (int i = 0; i < fighterVec.size(); ++i) {
        if (fighterVec.at(i)->getName() == name) {
            fighterVec.erase(fighterVec.begin() + i);
            return true;
        }
    }
    return false;
}

FighterInterface* Arena::getFighter(string name) {
    stringstream ss;
        for (Fighter* fp : fighterVec) {
            if (fp->getName() == name) {
                return fp;
            }
        }
        return NULL;
}

int Arena::getSize() const {
    return fighterVec.size();
}