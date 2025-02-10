//
//  Ranger.cpp
//  p2_235
//
//  Created by Tesneem Essa on 9/12/23.
//

#include "Ranger.hpp"
    /**
        Default constructor.
        Default-initializes all private members. Default character name: "NAMELESS".
        Booleans are default-initialized to False.
    */
    Ranger::Ranger()
    {
        Character();
        arrows_={};
        affinities_={};
        has_companion_=false;
    }


    //    /**
    //       Parameterized constructor.
    //      @param      : The name of the character (a const string reference)
    //      @param      : The race of the character (a const string reference)
    //      @param      : The character's vitality (an integer). Default to 0
    //      @param      : The character's max armor level (an integer). Default to 0
    //      @param      : The character's level (an integer). Default to 0
    //      @param      : A flag indicating whether the character is an enemy. Default to false
    //      @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
    //                    Lowercase valid arrow types are retained but converted to uppercase.
    //                    Invalid arrows are those with non-positive quantities or invalid types.
    //                    If the vector contains invalid arrows, those arrows are discarded.
    //                    Default to empty vector
    //      @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
    //                    String inputs can be in lowercase, but must be converted to uppercase.
    //                    If the vector contains invalid affinities, those affinities are discarded.
    //                    Default to empty vector
    //      @param      : A flag indicating whether the character is able to recruit an animal companion.
    //                    Default to false
    //      @post       : The private members are set to the values of the corresponding parameters
    //    */
    Ranger::Ranger(const string& name, const string& race, int vitality, int armor, int level, bool enemy, vector<Arrows> arrows, vector<string> affinities, bool has_companion): Character(name,race)
    {
        setVitality(vitality);
        setArmor(armor);
        setLevel(level);
        if(enemy==true)
        {
            setEnemy();
        }
        int i;
        short int arrow_size=arrows.size();         //loop through given vectors and use setter functions on each element
        for(i=0;i<arrow_size;i++)                   //to check if they are valid entries for data member vectors
        {
            addArrows(arrows[i].type_, arrows[i].quantity_);
        }
        short int affinity_size=affinities.size();
        for(i=0;i<affinity_size;i++)
        {
            addAffinity(affinities[i]);
        }
        has_companion_=has_companion;
    }
    /**
      @return     : a vector of the Character's arrows
    **/
    vector<Arrows> Ranger::getArrows() const
    {
        return arrows_;
    }


    //    /**
    //        @param    : a reference to string representing the arrow type
    //        @param    : a reference to an integer quantity
    //        @post     : If the character already has that type of arrow, the quantity in the vector
    //                    is updated. If not, the arrow is added to the vector.
    //                    Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
    //                    Lowercase valid arrow types are retained but converted to uppercase.
    //                    Quantity of arrows must be greater than 0
    //                    Invalid arrows are those with non-positive quantities or invalid types.
    //                    If the arrows are invalid, they are not added.
    //        @return   : True if the arrows were added successfully, false otherwise
    //    **/
    bool Ranger::addArrows(const string& arrow_type, const int& arrow_quantity)
    {
        bool add_arrows=false;
        short int size=arrow_type.length();
        string arrow_upper="";
        int i;
        for(i=0;i<size;i++)
        {
            arrow_upper+=toupper(arrow_type[i]);
        }
        if((arrow_upper=="WOOD" || arrow_upper=="FIRE" || arrow_upper=="WATER"|| arrow_upper=="POISON"|| arrow_upper=="BLOOD") && arrow_quantity>=0 )       //check that type and int are valid entries
        {
            add_arrows=true;
            bool type_found=false;    //to check if already in vector
            short int v_size=arrows_.size();
            for(i=0;i<v_size;i++)     //loop through data member arrows_
            {
                if(arrows_[i].type_==arrow_upper)
                {
                    arrows_[i].quantity_+=arrow_quantity;    //if found in vector, add quantity to existing quantity
                    type_found=true;                         //set type_found to true
                }
            }
            if(!type_found)
            {
                Arrows temp;                                 //if not found create temp struct object to add quantities to
                temp.type_=arrow_upper;
                temp.quantity_=arrow_quantity;
                arrows_.push_back(temp);                     //push temp onto arrows_ vector
            }
        }
        return add_arrows;
    }


    //    /**
    //        @param    : a reference to string representing the arrow type
    //        @post     : If the character has the listed arrow AND enough arrows to fire one,
    //                    the quantity of remaining arrows in the vector is updated.
    //                    Lowercase valid arrow types are accepted but converted to uppercase.
    //                    If firing the last arrow, simply decrement the quantity to 0.
    //        @return   : True if the character had the listed arrow AND enough arrows, False otherwise.
    //    **/
    bool Ranger::fireArrow(const string& arrow_type)
    {
        bool fire_arrow=false;
        short int size=arrow_type.length();
        string arrow_upper="";
        int i;
        for(i=0;i<size;i++)
        {
            arrow_upper+=toupper(arrow_type[i]);
        }
        short int v_size=arrows_.size();
        for(i=0;i<v_size;i++)
        {
            if(arrows_[i].type_==arrow_upper)    //if type is found in arrows_
            {
                if(arrows_[i].quantity_>0)       //if type has enough to fire 1 arrow
                {
                    arrows_[i].quantity_--;      //update arrow quantity for that type by -1
                    fire_arrow=true;
                }
            }
        }
        return fire_arrow;
    }


    //    /**
    //        @param  : a reference to string representing an affinity
    //        @post   : If the affinity does not already exist in the vector, add it to the vector.
    //                  Valid Affinities: [FIRE, WATER, POISON, BLOOD]
    //                  String inputs can be in lowercase, but must be converted to uppercase when
    //                  setting the variable.
    //                  There should be no duplicate affinities.
    //                  If the affinity is invalid, it is NOT added.
    //        @return : True if the affinity was added successfully, false otherwise
    //    **/
    bool Ranger::addAffinity(const string& affinity)
    {
        bool add_affinity=false;
        short int size=affinity.length();
        string affinity_upper="";
        int i;
        for(i=0;i<size;i++)
        {
            affinity_upper+=toupper(affinity[i]);
        }
        if(affinity_upper=="FIRE" || affinity_upper=="WATER"|| affinity_upper=="POISON"|| affinity_upper=="BLOOD" ) //if input is valid
        {
            short int v_size=affinities_.size();
            for(i=0;i<v_size;i++)                  //loop through affinities_ vector
            {
                if(affinities_[i]==affinity_upper) //if already in vector don't add, return false
                {
                    return add_affinity;
                }
            }
            affinities_.push_back(affinity_upper); //if not, add to vector, return true
            add_affinity=true;
        }
        return add_affinity;
    }


    /**
      @return     : a vector of the Character's affinities
    **/
    vector<string> Ranger::getAffinities() const
    {
        return affinities_;
    }


    //    /**
    //        @param    : a reference to a boolean indicating whether the character is able to recruit
    //                    an animal companion
    //        @post     : sets the private member variable to the value of the parameter.
    //    **/
    void Ranger::setCompanion(const bool& has_companion)
    {
        has_companion_=has_companion;
    }


    /**
        @return   : a boolean indicating whether the character is able to recruit an animal companion
    **/
    bool Ranger::getCompanion() const
    {
        return has_companion_;
    }
