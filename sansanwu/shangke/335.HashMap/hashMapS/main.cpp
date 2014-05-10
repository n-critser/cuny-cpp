/*
  File: main.cpp for 335.HashMap 

  compile with Makefile
 */
#include<cstdlib>
#include<iostream>
#include<string>
#include"Player.h"
#include"sMap.h"

void displayEntry ( std::string key, int value){
        std::cout << "\t" << key
                  <<"\t" <<value << std::endl;
}
//void displayNumbers(sMap<int> & map){
        //map.mapAll(displayEntry);
//}

int main(){


        sMap<Player*> pMap;
        Player* pStart= new Player ("545-666-7676");
        pMap.put( (pStart->get_phone_number()), pStart);
        pMap.mapAll();
        pStart = pMap.get("545-666-7676");
        pStart->update_cohort_id(44);
        pMap.mapAll();

        
        pStart= NULL;
        delete pStart;
               
        return 0;
}
