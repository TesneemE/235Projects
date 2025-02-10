//
//  main.cpp
//  main
//
//  Created by Tes Essa on 9/2/23.
//

#include "Character.hpp"
#include <cctype>
int main()
{
    Character me;
    string name="TE12s";
    me.setName(name);
    cout<<me.getName()<<"\n";
    Character test;
    cout<<test.getName()<<"\n";
    Character again("Hel2d","ELF",-4,5,-7,false);
    cout<<again.getName()<<"\n";
    cout<<again.getRace()<<"\n";
    cout<<again.getVitality()<<"\n";
    cout<<again.getArmor()<<"\n";
    cout<<again.getLevel()<<"\n";
    cout<<again.isEnemy()<<"\n";
    again.setEnemy();
    cout<<again.isEnemy()<<"\n";
}
