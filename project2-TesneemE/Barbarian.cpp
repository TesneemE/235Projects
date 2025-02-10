//
//  Barbarian.cpp
//  p2_235
//
//  Created by Tesneem Essa on 9/12/23.
//

#include "Barbarian.hpp"
    /**
        Default constructor.
        Default-initializes all private members. Default character name: "NAMELESS".
        Booleans are default-initialized to False.
        Default weapons: "NONE".
    */
    Barbarian::Barbarian()
    {
        Character();
        main_weapon_="NONE";
        secondary_weapon_="NONE";
    }


    //    /**
    //        Parameterized constructor.
    //        @param      : The name of the character (a const string reference)
    //        @param      : The race of the character (a const string reference)
    //        @param      : The character's vitality (an integer). Default to 0
    //        @param      : The character's max armor level (an integer). Default to 0
    //        @param      : The character's level (an integer). Default to 0
    //        @param      : A flag indicating whether the character is an enemy. Default to false
    //        @param      : The character's main weapon (a const string reference).
    //                      String inputs can be in lowercase, but must be converted to uppercase
    //                      when setting the variable. Only alphabetical characters are allowed.
    //                      Default to "NONE"
    //        @param      : The character's offhand weapon (a const string reference).
    //                      String inputs can be in lowercase, but must be converted to uppercase
    //                      when setting the variable. Only alphabetical characters are allowed.
    //                      Default to "NONE"
    //        @param      : A flag indicating whether the character is enraged. Default to false
    //        @post       : The private members are set to the values of the corresponding parameters.
    //                    : If the main and secondary weapons are not provided or invalid, the variables are set to "NONE".
    //    */
    Barbarian::Barbarian(const string& name, const string& race, int vitality, int armor, int level, bool enemy, const string& main_weapon, const string& secondary_weapon, bool enraged):Character(name,race)
    {
        setVitality(vitality);
        setArmor(armor);
        setLevel(level);
        if(enemy==true)
        {
            setEnemy();
        }
        setMainWeapon(main_weapon);
        setSecondaryWeapon(secondary_weapon);
        enraged_=enraged;
    }


    //    /**
    //        @param    : a reference to a string representing the Character's main weapon
    //        @post     : sets the private member variable to the value of the parameter.
    //                    Only alphabetical characters are allowed.
    //                    String inputs can be in lowercase, but must be converted to uppercase when
    //                    setting the variable.
    //                    If the given input is invalid (i.e contains numbers), do nothing and return false
    //        @return   : true if setting the variable was successful, false otherwise.
    //    **/
    bool Barbarian::setMainWeapon(const string& main_weapon)
    {
        bool set_main_weapon=false;
        short int size;
        size=main_weapon.length();
        string main_weapon_upper="";
        int i;
        for(i=0;i<size;i++)
        {
            if(isalpha(main_weapon[i]))      //only allow alphabetical characters
            {
                main_weapon_upper+=toupper(main_weapon[i]);
            }
            else
            {
                return set_main_weapon;
            }
        }
        main_weapon_=main_weapon_upper;
        set_main_weapon=true;
        return set_main_weapon;
    }


    /**
        @return   : a string of the Character's main weapon
    **/
    string Barbarian::getMainWeapon() const
    {
        return main_weapon_;
    }

    //    /**
    //        @param    : a reference to a string representing the Character's secondary weapon
    //        @post     : sets the private member variable to the value of the parameter.
    //                    Only alphabetical characters are allowed.
    //                    String inputs can be in lowercase, but must be converted to uppercase when
    //                    setting the variable.
    //                  : If the given input is invalid (i.e contains numbers), do nothing and return false
    //        @return   : true if setting the variable was successful, false otherwise.
    //    **/
    bool Barbarian::setSecondaryWeapon(const string& secondary_weapon)
    {
        bool set_secondary_weapon=false;
        short int size;
        size=secondary_weapon.length();
        string secondary_weapon_upper="";
        int i;
        for(i=0;i<size;i++)
        {
            if(isalpha(secondary_weapon[i]))  //only allow alphabetical characters
            {
                secondary_weapon_upper+=toupper(secondary_weapon[i]);
            }
            else
            {
                return set_secondary_weapon;
            }
        }
        secondary_weapon_=secondary_weapon_upper;
        set_secondary_weapon=true;
        return set_secondary_weapon;
    }


    /**
       @return    : a string of the Character's secondary weapon
    **/
    string Barbarian::getSecondaryWeapon() const
    {
        return secondary_weapon_;
    }


    //    /**
    //      @param      : a reference to a bool
    //      @post       : sets the private member variable to the value of the parameter.
    //    **/
    void Barbarian::setEnrage(const bool& enraged)
    {
        enraged_=enraged;
    }


    /**
      @return  : a boolean of whether the Character is enraged
    **/
    bool Barbarian::getEnrage() const
    {
        return enraged_;
    }


    /**
      @post   : sets the enraged variable to the opposite of what it was
    **/
    void Barbarian::toggleEnrage()
    {
        if(enraged_==true)
        {
            enraged_=false;
        }
        else
        {
            enraged_=true;
        }
    }

