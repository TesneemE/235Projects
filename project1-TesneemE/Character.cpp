//
//  Character.cpp
//  p1_235
//
//  Created by Tesneem Essa on 8/31/23.
//
#include "Character.hpp"
/**
     Default constructor.
     Default-initializes all private members.
     Default character name: "NAMELESS".
     Booleans are default-initialized to False.
     Default enum value: NONE.
     Default Vitality, Max Armor, and Level: 0.
  */
Character::Character()
{
    name_="NAMELESS";
    race_=NONE;
    vitality_=0;
    armor_=0;
    level_=0;
    enemy_=false;
}
//**
//Parameterized constructor.
//@param      : The name of the character (a string in UPPERCASE)
//@param      : The race of the character (a string)
//@param      : The character's vitality (a non-negative integer) , with default
//              value 0
//@param      : The character's max armor level (a non-negative integer), with
//              default value 0
//@param      : The character's level (non-negative integer), with default value 0
//@param      : A flag indicating whether the character is an enemy, with default
//              value false
//@post       : The private members are set to the values of the corresponding
//              parameters.
//*
Character::Character(string name, string race, int vitality, int armor, int level, bool enemy)
{
    vitality_=0;
    armor_=0;
    level_=0;
    enemy_=false;
    setName(name);
    setRace(race);
    setVitality(vitality);
    setArmor(armor);
    setLevel(level);
    enemy_=enemy;
}
//**
//         @param  : the name of the Character
//         @post   : sets the Character's title to the value of the parameter,
//                   in UPPERCASE. Only alphabetical characters are allowed.
//                   For example, attempting to create a character named
//                   "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
//                 : If the given parameter does not have any valid alphabetical
//                   characters, the character's name should be set to "NAMELESS".
//*/
void Character::setName(const string& name)
{
    short int size;
    size=name.length();
    string upper_name="";
    for(int i=0;i<size;i++)
    {
        if(isalpha(name[i]))
        {
            upper_name+=toupper(name[i]);
        }
    }
    if (upper_name.length()>0)
    {
        name_=upper_name;
    }
    else
    {
        name_="NAMELESS";
    }
}


/**
   @return : the name of the Character
*/
string Character::getName() const
{
    return name_;
}

//**
//    @param  : the race of the Character (a string)
//    @post   : sets the Character's race to the value of the parameter.
//              If the given race was invalid, set race_ to NONE.
//*/

void Character::setRace(const string& race)
{
    if(race=="HUMAN")
    {
        race_=HUMAN;
    }
    else if(race=="ELF")
    {
        race_=ELF;
    }
    else if(race=="DWARF")
    {
        race_=DWARF;
    }
    else if(race=="LIZARD")
    {
        race_=LIZARD;
    }
    else if(race=="UNDEAD")
    {
        race_=UNDEAD;
    }
    else
    {
        race_=NONE;
    }
       
}


/**
   @return : the race of the Character (a string)
*/
string Character::getRace() const
{
    string race_array[6]={"NONE","HUMAN","ELF","DWARF","LIZARD","UNDEAD"};
    int x=race_;
    string r=race_array[x];
    return r;
}


//**
// @param  : an integer vitality
// @pre    : vitality >= 0 : Characters cannot have negative health
// @post   : sets the vitality private member to the value of the parameter
//*/
void Character::setVitality(const int& vitality)
{
    if (vitality>=0)
    {
        vitality_=vitality;
    }
}


/**
   @return : the value stored in vitality_
*/
int Character::getVitality() const
{
    return vitality_;
}

//**
// @param  : an integer armor level
// @pre    : armor >= 0 : Characters cannot have negative armor
// @post   : sets the armor private member to the value of the parameter
//*/
void Character::setArmor(const int& armor)
{
    if (armor>=0)
    {
        armor_=armor;
    }
}
/*
   @return : the value stored in armor_
*/
int Character::getArmor() const
{
    return armor_;
}

//**
// @param  : an integer level
// @pre    : level >= 0 : Characters cannot have a negative
// @post   : sets the level private member to the value of the parameter
//*/
void Character::setLevel(const int& level)
{
    if (level>=0)
    {
        level_=level;
    }
}


/**
   @return : the value stored in level_
*/
int Character::getLevel() const
{
    return level_;
}



/**
@post   : sets the enemy flag to true
*/
void Character::setEnemy()
{
    enemy_=true;
}


/**
 @return true if the character is an enemy, false otherwise

 Note: this is an accessor function and must follow the same convention as all accessor
       functions even if it is not called getEnemy
*/
bool Character::isEnemy() const
{
    return enemy_;
}
