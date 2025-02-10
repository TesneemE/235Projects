//
//  Tavern.cpp
//  p3_235
//
//  Created by Tesneem Essa on 9/24/23.
// Tavern.cpp defines the constructors and private and public function implementation of the Tavern class, which is a sublcass of template class ArrayBag.

#include "Tavern.hpp"
/**
    Default constructor.
    Default-initializes all private members.
*/
Tavern::Tavern()
{
    sum_levels_=0;
    sum_enemies_=0;
    ArrayBag();
    Character();
}


//    /** @param:   A const reference to a Character entering the Tavern
//        @return:  returns true if a Character was successfully added to the tavern (i.e. items_),                 false otherwise
//        @post:    adds Character to the Tavern and updates the level sum and the enemy count
//                  if the character is an enemy.
//     **/
bool Tavern::enterTavern(const Character &character)
{
    return add(character);
}


//
//    /** @param:   A const reference to a Character leaving the Tavern
//        @return:  returns true if a character was successfully removed from the tavern (i.e. items_),               false otherwise
//        @post:    removes the character from the Tavern and updates the level sum and the enemy count
//                  if the character is an enemy.
//     **/
bool Tavern::exitTavern(const Character &character)
{
    return remove(character);
}


/**
    @return:  The integer level count of all the characters currently in the Tavern
 **/
int Tavern::getLevelSum()
{
    sum_levels_=0;  //have to do this b/c operator functions don't add the levels
    for(int i=0;i<item_count_;i++)
    {
        sum_levels_+=items_[i].getLevel();
    }
    return sum_levels_;
}


/**
    @return:  The average level of all the characters in the Tavern
    @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
 **/
int Tavern::calculateAvgLevel()
{
    double sum_levels=getLevelSum();
    double item_count=item_count_;
    return round(sum_levels/item_count);  //rounds to nearest interger
}



/**
    @return:  The integer enemy count of the Tavern
 **/
int Tavern::getEnemyCount()
{
    sum_enemies_=0;         //have to do this b/c operator functions don't add the enemies
    for(int i=0;i<item_count_;i++)
    {
        if(items_[i].isEnemy()==true)
        {
            sum_enemies_+=1;
        }
      
    }
    return sum_enemies_;
}



/**
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
 **/
double Tavern::calculateEnemyPercentage()
{
    double percent;
    double sum_enemies=getEnemyCount();
    double item_count=item_count_;
    percent=(sum_enemies/item_count)*100;
    percent=round(percent * 100.0) / 100.0;  //if x= 33.3333 then x*100= 3333.33 round(x)= 3333.00                                                    round(x)/100=33.33
    return percent;
}



//    /**
//        @param:   A const reference to a string representing a character Race with value in
//                  ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
//        @return:  An integer tally of the number of characters in the Tavern of the given race.
//                  If the argument string does not match one of the expected race values,
//                  the tally is zero. NOTE: no pre-processing of the input string necessary, only                  uppercase input will match.
//     **/
int Tavern::tallyRace(const string& race) const
{
    int frequency = 0;
    int curr_index = 0;       // Current array index
    while (curr_index <item_count_)
    {
       if (items_[curr_index].getRace() == race)
       {
          frequency++;
       }  // end if

       curr_index++;          // Increment to next entry
    }  // end while

    return frequency;
}


/**
@post:      Outputs a report of the characters currently in the tavern in the form:
            "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average             level is: [x] \n[x]% are enemies.\n"
            Note that the average level should be rounded to the NEAREST integer, and the enemy             percentage should be rounded to 2 decimal places.

            Example output:
            Humans: 3
            Elves: 5
            Dwarves: 8
            Lizards: 6
            Undead: 0

            The average level is: 7
            46.67% are enemies.
*/
void Tavern::tavernReport()
{
    cout<<"Humans: "<<tallyRace("HUMAN")<<"\n"<<"Elves: "<<tallyRace("ELF")<<"\n"<<"Dwarves: "<<tallyRace("DWARF")<<"\n"<<"Lizards: "<<tallyRace("LIZARD")<<"\n"<<"Undead: "<<tallyRace("UNDEAD")<<"\n"<<"The average level is:  "<<calculateAvgLevel()<<"\n"<<calculateEnemyPercentage()<<"% are enemies."<<"\n";
}
