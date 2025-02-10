//
//  Tavern.hpp
//  p3_235
//
//  Created by Tesneem Essa on 9/24/23.
//Tavern.hpp declares the subclass to template class ArrayBag, Tavern, along with its private and public members

#ifndef Tavern_hpp
#define Tavern_hpp
#include <iostream>
#include <cmath>
#include "ArrayBag.hpp"
#include "Character.hpp"
using namespace std;
#include <stdio.h>
class Tavern:public ArrayBag<Character>
{
private:
    int sum_levels_;
    int sum_enemies_;
public:
    /**
        Default constructor.
        Default-initializes all private members.
    */
    Tavern();
    
    
//    /** @param:   A const reference to a Character entering the Tavern
//        @return:  returns true if a Character was successfully added to the tavern (i.e. items_),                 false otherwise
//        @post:    adds Character to the Tavern and updates the level sum and the enemy count
//                  if the character is an enemy.
//     **/
    bool enterTavern(const Character &character);
    
    
//
//    /** @param:   A const reference to a Character leaving the Tavern
//        @return:  returns true if a character was successfully removed from the tavern (i.e. items_),               false otherwise
//        @post:    removes the character from the Tavern and updates the level sum and the enemy count
//                  if the character is an enemy.
//     **/
    bool exitTavern(const Character &character);


    /**
        @return:  The integer level count of all the characters currently in the Tavern
     **/
    int getLevelSum() ;


    /**
        @return:  The average level of all the characters in the Tavern
        @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
     **/
    int calculateAvgLevel() ;


    /**
        @return:  The integer enemy count of the Tavern
     **/
    int getEnemyCount() ;


    /**
        @return:  The percentage (double) of all the enemy characters in the Tavern
        @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
     **/
    double calculateEnemyPercentage() ;



//    /**
//        @param:   A const reference to a string representing a character Race with value in
//                  ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
//        @return:  An integer tally of the number of characters in the Tavern of the given race.
//                  If the argument string does not match one of the expected race values,
//                  the tally is zero. NOTE: no pre-processing of the input string necessary, only                  uppercase input will match.
//     **/

    int tallyRace(const string& race) const;


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
    void tavernReport() ;
    
};
#endif /* Tavern_hpp */

