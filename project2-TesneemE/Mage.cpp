//
//  Mage.cpp
//  p2_235
//
//  Created by Tesneem Essa on 9/12/23.
//

#include "Mage.hpp"
    /**
      Default constructor.
      Default-initializes all private members.
      Default character name: "NAMELESS". Booleans are default-initialized to False.
      Default school of magic and weapon: "NONE".
    */
    Mage::Mage()
    {
        Character();
        school_of_magic_="NONE";
        weapon_="NONE";
        can_summon_incarnate_=false;
    }


    //    /**
    //      Parameterized constructor.
    //      @param      : The name of the character (a const string reference)
    //      @param      : The race of the character (a const string reference)
    //      @param      : The character's vitality (an integer). Default to 0
    //      @param      : The character's max armor level (an integer). Default to 0
    //      @param      : The character's level (an integer). Default to 0
    //      @param      : A flag indicating whether the character is an enemy. Default to false.
    //      @param      : The character's school of magic (a const string reference). Valid schools:
    //                    [ELEMENTAL, NECROMANCY, ILLUSION].
    //                    String inputs can be in lowercase, but must be converted to
    //                    uppercase when setting the variable.
    //                    If the school name is invalid, set it to "NONE"
    //      @param      : The character's choice of weapon (a const string reference).
    //                    Valid weapons: [WAND, STAFF]
    //                    String inputs can be in lowercase, but must be converted to
    //                    uppercase when setting the variable.
    //                    If the weapon is invalid, set it to "NONE"
    //      @param      : A flag indicating whether the character is able to summon an
    //                    incarnate. Default to false.
    //      @post       : The private members are set to the values of the corresponding
    //                    parameters.
    //                    REMEMBER: If the school of magic or weapon is not provided or invalid, the
    //                    variables should be set to "NONE".
    //    */
    Mage::Mage(const string& name, const string& race, int vitality, int armor, int level, bool enemy, const string& school_of_magic, const string& casting_weapon,  bool can_summon): Character(name,race)
    {
        setVitality(vitality);
        setArmor(armor);
        setLevel(level);
        if(enemy==true)
        {
            setEnemy();
        }
        bool school_flag=setSchool(school_of_magic);         //if input is invalid for setSchool and setCastingWeapon,
        if(!school_flag)                            // then the default values will be set
        {
            school_of_magic_="NONE";
        }
        bool weapon_flag=setCastingWeapon(casting_weapon);
        if(!weapon_flag)
        {
            weapon_="NONE";
        }
        can_summon_incarnate_=can_summon;
    }
 

    //    /**
    //        @param  :a reference to a string representing the school of magic
    //        @post   : sets the private member variable to the value of the parameter. If
    //                  the provided school of magic is not one of the following: [ELEMENTAL,
    //                  NECROMANCY, NECROMANCY], do nothing and return false.
    //                  String inputs can be in lowercase, but must be converted to
    //                  uppercase when setting the variable.
    //        @return  : true if setting the variable was successful, false otherwise.
    //    **/
    bool Mage::setSchool(const string& school)
    {
        bool set_school=false;
        short int size;
        size=school.length();
        string school_upper="";
        for(int i=0;i<size;i++)
        {
            school_upper+=toupper(school[i]);
        }
        if(school_upper=="ELEMENTAL" || school_upper=="NECROMANCY" || school_upper=="ILLUSION" )
        {
            school_of_magic_=school_upper;
            set_school=true;
        }
       return set_school;
    }
    /**
      @return  : the string indicating the character's school of magic
    **/
    string Mage::getSchool() const
    {
        return school_of_magic_;
    }
    
    
    //    /**
    //        @param  : a reference to a string representing the character's weapon
    //        @post   : sets the private member variable to the value of the parameter.
    //                  String inputs can be in lowercase, but must be converted to
    //                  uppercase when setting the variable.
    //                  If the provided weapon is not one of the following:
    //                  [WAND, STAFF], do nothing and return false.
    //        @return  : true if setting the variable was successful, false otherwise.
    //    **/
    bool Mage::setCastingWeapon(const string& weapon)
    {
        bool set_weapon=false;
        short int size;
        size=weapon.length();
        string weapon_upper="";
        for(int i=0;i<size;i++)
        {
            weapon_upper+=toupper(weapon[i]);
        }
        if(weapon_upper=="WAND" || weapon_upper=="STAFF")
        {
            weapon_=weapon_upper;
            set_weapon=true;
        }
       return set_weapon;
    }


    /**
      @return  : the string indicating the character's weapon
    **/
    string Mage::getCastingWeapon() const
    {
        return weapon_;
    }
    

    //    /**
    //      @param  : a reference to boolean
    //      @post   : sets the private member variable indicating whether the character can
    //                summon an incarnate
    //    **/
    void Mage::setIncarnateSummon(const bool& can_summon)
    {
        can_summon_incarnate_=can_summon;
    }


    /**
      @return  : the summon-incarnate flag
    **/
    bool Mage::hasIncarnateSummon() const
    {
        return can_summon_incarnate_;
    }
