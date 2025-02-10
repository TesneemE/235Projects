//
//  Character.hpp
//  p1_235
//
//  Created by Tesneem Essa on 8/31/23.
//

#ifndef Character_hpp
#define Character_hpp
#include <iostream>
using namespace std;
enum Race{NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};
class Character{
private:
    string name_;
    Race race_;
    int vitality_;
    int armor_;
    int level_;
    bool enemy_;
public:
    Character();
    Character(string name, string race, int vitality=0, int armor=0, int level=0, bool enemy=false);
    void setName(const string& name);
    string getName() const;
    void setRace(const string& race);
    string getRace() const;
    void setVitality(const int& vitality);
    int getVitality() const;
    void setArmor(const int& armor);
    int getArmor() const;
    void setLevel(const int& level);
    int getLevel() const;
    void setEnemy();
    bool isEnemy() const;
};


#endif /* Character_hpp */
