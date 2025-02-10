//
//  Scoundrel.cpp
//  p2_235
//
//  Created by Tesneem Essa on 9/12/23.
//

#include "Scoundrel.hpp"
    //    /**
    //        Default constructor.
    //        Default-initializes all private members.
    //        Default character name: "NAMELESS". Booleans are default-initialized to False.
    //        Default dagger: WOOD. Default faction: "NONE".
    //    */
    Scoundrel::Scoundrel()
    {
        Character();
        dagger_=WOOD;
        faction_="NONE";
        has_disguise_=false;
    }


    //    /**
    //        Parameterized constructor.
    //        @param      : The name of the character (a const string reference)
    //        @param      : The race of the character (a const string reference)
    //        @param      : The character's vitality (an integer). Default to 0
    //        @param      : The character's max armor level (an integer). Default to 0
    //        @param      : The character's level (an integer). Default to 0
    //        @param      : A flag indicating whether the character is an enemy. Default to false.
    //        @param      : The character's dagger type (a const string reference).
    //                      String inputs can be in lowercase, but must be converted to
    //                      uppercase when setting the dagger enum. Default to WOOD
    //        @param      : The character's Faction (a const string reference).
    //                      Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE]
    //                      String inputs can be in lowercase, but must be converted to
    //                      uppercase when setting the variable. Default to "NONE"
    //        @param      : A flag indicating whether the character has a disguise. Default to false
    //        @post       : The private members are set to the values of the corresponding
    //                      parameters.
    //                     If the dagger type is not provided or invalid, the variable should
    //                      be set to WOOD.
    //                     If the Faction is not provided or invalid, the variable should be
    //                      set to "NONE".
    //    */
    Scoundrel::Scoundrel(const string& name, const string& race, int vitality, int armor, int level, bool enemy, const string& dagger, const string& faction, bool has_disguise): Character(name,race)
    {
        setVitality(vitality);
        setArmor(armor);
        setLevel(level);
        if(enemy==true)
        {
            setEnemy();
        }
        setDagger(dagger);
        bool flag=setFaction(faction);                 //if invalid input is given for faction, then default value is set
        if(!flag)
        {
            faction_="NONE";
        }
        has_disguise_=has_disguise;
    }


    //    /**
    //       @param     : a reference to a string representing the dagger type
    //       @post      : sets the private member variable to the value of the parameter.
    //                    String inputs can be in lowercase, but must be converted to
    //                    uppercase when setting the variable.
    //                    If the dagger type is not valid (i.e, is one of the following:
    //                    [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]),
    //                    the variable should be set to WOOD.
    //    **/
    void Scoundrel::setDagger(const string& dagger)
    {
        short int size;
        size=dagger.length();
        string dagger_upper="";
        for(int i=0;i<size;i++)
        {
            dagger_upper+=toupper(dagger[i]);
        }
        if(dagger_upper=="BRONZE")
           {
              dagger_=BRONZE;
           }
           else if(dagger_upper=="IRON")
           {
               dagger_=IRON;
           }
           else if(dagger_upper=="STEEL")
           {
               dagger_=STEEL;
           }
           else if(dagger_upper=="MITHRIL")
           {
               dagger_=MITHRIL;
           }
           else if(dagger_upper=="ADAMANT")
           {
               dagger_=ADAMANT;
           }
           else if(dagger_upper=="RUNE")
           {
               dagger_=RUNE;
           }
           else
           {
               dagger_=WOOD;
           }
    }


    //    /**
    //      @return     : the string indicating the character's dagger type
    //    **/
    string Scoundrel::getDagger() const
    {
        string dagger_array[7]={"WOOD","BRONZE","IRON","STEEL","MITHRIL","ADAMANT","RUNE"};   //array   contains all the dagger types as strings
        int x=dagger_;                                                             //x is set equal to the int value of the object's dagger_
        string dagger=dagger_array[x];                                               //x is then used to find the string equivalent of that dagger_
        return dagger;
    }


    //    /**
    //        @param    : a reference to a string representing the character's Faction
    //        @post     : sets the private member variable to the value of the parameter.
    //                    String inputs can be in lowercase, but must be converted to
    //                    uppercase when setting the variable.
    //                    If the provided faction is not one of the following:
    //                   [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE],
    //                   do nothing and return false.
    //        @return   : true if setting the variable was successful, false otherwise.
    //    **/
    bool Scoundrel::setFaction(const string& faction)
    {
        bool set_faction=false;
        short int size;
        size=faction.length();
        string faction_upper="";
        for(int i=0;i<size;i++)
        {
            faction_upper+=toupper(faction[i]);
        }
        if(faction_upper=="CUTPURSE"||faction_upper=="SHADOWBLADE"||faction_upper=="SILVERTONGUE" )
        {
            faction_=faction_upper;
            set_faction=true;
        }
        return set_faction;
    }


    /**
      @return  : the string indicating the character's Faction
    **/
    string Scoundrel::getFaction() const
    {
        return faction_;
    }


    //    /**
    //      @param  : a reference to boolean
    //      @post   : sets the private member variable indicating whether the character has a disguise
    //    **/
    void Scoundrel::setDisguise(const bool& has_disguise)
    {
        has_disguise_=has_disguise;
    }


    /**
      @return  : the visual aid flag
    **/
    bool Scoundrel::hasDisguise() const
    {
        return has_disguise_;
    }

