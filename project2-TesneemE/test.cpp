//
//  test.cpp
//  p2_235
//
//  Created by Tesneem Essa on 9/12/23.
//

#include <iostream>
#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"

int main()
{
    int i;
    Mage defaultMage;
    string mage_name="defaultMage";
    defaultMage.setName(mage_name);
    string mage_race="ELF";
    defaultMage.setRace(mage_race);
    defaultMage.setVitality(5);
    defaultMage.setArmor(3);
    defaultMage.setLevel(2);
    defaultMage.setEnemy();
    defaultMage.setSchool("Necromancy");
    defaultMage.setCastingWeapon("STAFF");
    defaultMage.setIncarnateSummon(false);
    cout<<defaultMage.getName()<<" is a Level "<<defaultMage.getLevel()<<" "<<defaultMage.getRace()<<"."<<"\n"<<"Vitality: "<<defaultMage.getVitality()<<"\n"<<"Armor: "<<defaultMage.getArmor()<<"\n";
    if(defaultMage.isEnemy()==true)
    {
        cout<<"They are an enemy"<<"\n";
    }
    else
    {
        cout<<"They are not an enemy"<<"\n";
    }
    cout<<"School of Magic: "<<defaultMage.getSchool()<<"\n"<<"Casting Weapon: "<<defaultMage.getCastingWeapon()<<"\n";
    if(defaultMage.hasIncarnateSummon()==true)
    {
        cout<<"Summon Incarnate: TRUE"<<"\n";
    }
    else
    {
        cout<<"Summon Incarnate: FALSE"<<"\n";
    }
    cout<<"\n";

    
    Mage spynach("Spynach","ELF",6,4,4,false,"Illusion","Wand",true);
    cout<<spynach.getName()<<" is a Level "<<spynach.getLevel()<<" "<<spynach.getRace()<<"."<<"\n"<<"Vitality: "<<spynach.getVitality()<<"\n"<<"Armor: "<<spynach.getArmor()<<"\n";
    if(spynach.isEnemy()==true)
    {
        cout<<"They are an enemy"<<"\n";
    }
    else
    {
        cout<<"They are not an enemy"<<"\n";
    }
    cout<<"School of Magic: "<<spynach.getSchool()<<"\n"<<"Casting Weapon: "<<spynach.getCastingWeapon()<<"\n";
    if(spynach.hasIncarnateSummon()==true)
    {
        cout<<"Summon Incarnate: TRUE"<<"\n";
    }
    else
    {
        cout<<"Summon Incarnate: FALSE"<<"\n";
    }
    cout<<"\n";
    
    
    Scoundrel defaultScoundrel;
    string scoundrel_name="defaultScoundrel";
    string scoundrel_race="HUMAN";
    defaultScoundrel.setName(scoundrel_name);
    defaultScoundrel.setRace(scoundrel_race);
    defaultScoundrel.setVitality(6);
    defaultScoundrel.setArmor(4);
    defaultScoundrel.setLevel(3);
    defaultScoundrel.setEnemy();
    defaultScoundrel.setDagger("MITHRIL");
    defaultScoundrel.setFaction("Shadowblade");
    defaultScoundrel.setDisguise(false);
    cout<<defaultScoundrel.getName()<<" is a Level "<<defaultScoundrel.getLevel()<<" "<<defaultScoundrel.getRace()<<"."<<"\n"<<"Vitality: "<<defaultScoundrel.getVitality()<<"\n"<<"Armor: "<<defaultScoundrel.getArmor()<<"\n";
    if(defaultScoundrel.isEnemy()==true)
    {
        cout<<"They are an enemy"<<"\n";
    }
    else
    {
        cout<<"They are not an enemy"<<"\n";
    }
    cout<<"Dagger: "<<defaultScoundrel.getDagger()<<"\n"<<"Faction: "<<defaultScoundrel.getFaction()<<"\n";
    if(defaultScoundrel.hasDisguise()==true)
    {
        cout<<"Disguise: TRUE"<<"\n";
    }
    else
    {
        cout<<"Disguise: FALSE"<<"\n";
    }
    cout<<"\n";

    
    Scoundrel flea("flea","DWARF",12,7,5,false,"Adamant","Cutpurse",true);
    cout<<flea.getName()<<" is a Level "<<flea.getLevel()<<" "<<flea.getRace()<<"."<<"\n"<<"Vitality: "<<flea.getVitality()<<"\n"<<"Armor: "<<flea.getArmor()<<"\n";
    if(flea.isEnemy()==true)
    {
        cout<<"They are an enemy"<<"\n";
    }
    else
    {
        cout<<"They are not an enemy"<<"\n";
    }
    cout<<"Dagger: "<<flea.getDagger()<<"\n"<<"Faction: "<<flea.getFaction()<<"\n";
    if(flea.hasDisguise()==true)
    {
        cout<<"Disguise: TRUE"<<"\n";
    }
    else
    {
        cout<<"Disguise: FALSE"<<"\n";
    }
    cout<<"\n";
    

    Ranger defaultRanger;
    string ranger_name="defaultRanger";
    string ranger_race="UNDEAD";
    defaultRanger.setName(ranger_name);
    defaultRanger.setRace(ranger_race);
    defaultRanger.setVitality(8);
    defaultRanger.setArmor(4);
    defaultRanger.setLevel(5);
    defaultRanger.setEnemy();
    defaultRanger.addArrows("wood",5);
    defaultRanger.addAffinity("blood");
    defaultRanger.setCompanion(false);
    cout<<defaultRanger.getName()<<" is a Level "<<defaultRanger.getLevel()<<" "<<defaultRanger.getRace()<<"."<<"\n"<<"Vitality: "<<defaultRanger.getVitality()<<"\n"<<"Armor: "<<defaultRanger.getArmor()<<"\n";
    if(defaultRanger.isEnemy()==true)
    {
        cout<<"They are an enemy"<<"\n";
    }
    else
    {
        cout<<"They are not an enemy"<<"\n";
    }
    cout<<"Vector of Arrows: ";
    vector<Arrows> default_arrows=defaultRanger.getArrows();
    short int default_arrows_size_=default_arrows.size();
    for(i=0;i<default_arrows_size_;i++)
    {
        if(i<default_arrows_size_-1)
        {
            cout<<default_arrows[i].type_<<", "<<default_arrows[i].quantity_<<", ";
        }
        else
        {
            cout<<default_arrows[i].type_<<", "<<default_arrows[i].quantity_<<"\n";
        }
    }
    cout<<"Affinities: ";
    vector<string> default_affinities=defaultRanger.getAffinities();
    short int default_affinities_size_=default_affinities.size();
    for(i=0; i<default_affinities_size_;i++)
    {
        if(i<default_affinities_size_-1)
        {
            cout<<default_affinities[i]<<", ";
        }
        else
        {
            cout<<default_affinities[i]<<"\n";
        }
    }
    cout<<"Animal Companion: ";
    if(defaultRanger.getCompanion()==true)
    {
        cout<<"TRUE"<<"\n";
    }
    else
    {
        cout<<"FALSE"<<"\n";
    }
    cout<<"\n";


    vector<Arrows> arrows;
    Arrows one={"Wood",30};
    Arrows two={"Fire",5};
    Arrows three={"Water",5};
    Arrows four={"Poison",5};
    arrows.push_back(one);
    arrows.push_back(two);
    arrows.push_back(three);
    arrows.push_back(four);
    vector<string> affinities;
    affinities.push_back("Fire");
    affinities.push_back("Poison");
    Ranger marrow={"Marrow","UNDEAD",9,6,5,true,arrows,affinities,true};
    cout<<marrow.getName()<<" is a Level "<<marrow.getLevel()<<" "<<marrow.getRace()<<"."<<"\n"<<"Vitality: "<<marrow.getVitality()<<"\n"<<"Armor: "<<marrow.getArmor()<<"\n";
    if(marrow.isEnemy()==true)
    {
        cout<<"They are an enemy"<<"\n";
    }
    else
    {
        cout<<"They are not an enemy"<<"\n";
    }
    cout<<"Vector of Arrows: ";
    vector<Arrows> marrow_arrows=marrow.getArrows();
    short int arrows_size_=marrow_arrows.size();
    for(i=0;i<arrows_size_;i++)
    {
        if(i<arrows_size_-1)
        {
            cout<<marrow_arrows[i].type_<<", "<<marrow_arrows[i].quantity_<<", ";
        }
        else
        {
            cout<<marrow_arrows[i].type_<<", "<<marrow_arrows[i].quantity_<<"\n";
        }
    }
    cout<<"Affinities: ";
    vector<string> marrow_affinities=marrow.getAffinities();
    short int affinities_size_=marrow_affinities.size();
    for(i=0; i<affinities_size_;i++)
    {
        if(i<affinities_size_-1)
        {
            cout<<marrow_affinities[i]<<", ";
        }
        else
        {
            cout<<marrow_affinities[i]<<"\n";
        }
    }
    cout<<"Animal Companion: ";
    if(marrow.getCompanion()==true)
    {
        cout<<"TRUE"<<"\n";
    }
    else
    {
        cout<<"FALSE"<<"\n";
    }
    cout<<"\n";

    
    Barbarian defaultBarbarian;
    string barbarian_name="defaultBarbarian";
    string barbarian_race="HUMAN";
    defaultBarbarian.setName(barbarian_name);
    defaultBarbarian.setRace(barbarian_race);
    defaultBarbarian.setVitality(10);
    defaultBarbarian.setArmor(5);
    defaultBarbarian.setLevel(5);
    defaultBarbarian.setEnemy();
    defaultBarbarian.setMainWeapon("Axe");
    defaultBarbarian.setEnrage(false);
    cout<<defaultBarbarian.getName()<<" is a Level "<<defaultBarbarian.getLevel()<<" "<<defaultBarbarian.getRace()<<"."<<"\n"<<"Vitality: "<<defaultBarbarian.getVitality()<<"\n"<<"Armor: "<<defaultBarbarian.getArmor()<<"\n";
    if(defaultBarbarian.isEnemy()==true)
    {
        cout<<"They are an enemy"<<"\n";
    }
    else
    {
        cout<<"They are not an enemy"<<"\n";
    }
    cout<<"Main Weapon: "<<defaultBarbarian.getMainWeapon()<<"\n"<<"Offhand Weapon: "<<defaultBarbarian.getSecondaryWeapon()<<"\n";
    if(defaultBarbarian.getEnrage()==true)
    {
        cout<<"Enraged: TRUE"<<"\n";
    }
    else
    {
        cout<<"Enraged: FALSE"<<"\n";
    }
    cout<<"\n";

    
    Barbarian bonk("bonk","HUMAN",11,5,5,true,"Mace","Anothermace",true);
    cout<<bonk.getName()<<" is a Level "<<bonk.getLevel()<<" "<<bonk.getRace()<<"."<<"\n"<<"Vitality: "<<bonk.getVitality()<<"\n"<<"Armor: "<<bonk.getArmor()<<"\n";
    if(bonk.isEnemy()==true)
    {
        cout<<"They are an enemy"<<"\n";
    }
    else
    {
        cout<<"They are not an enemy"<<"\n";
    }
    cout<<"Main Weapon: "<<bonk.getMainWeapon()<<"\n"<<"Offhand Weapon: "<<bonk.getSecondaryWeapon()<<"\n";
    if(bonk.getEnrage()==true)
    {
        cout<<"Enraged: TRUE"<<"\n";
    }
    else
    {
        cout<<"Enraged: FALSE"<<"\n";
    }
    cout<<"\n";
}

