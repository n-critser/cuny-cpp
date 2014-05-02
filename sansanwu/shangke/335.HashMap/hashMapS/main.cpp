/*
  File: main.cpp for 335.HashMap 

  compile with Makefile
 */
#include<cstdlib>
#include<iostream>
#include<string>
#include"sMap.h"

void displayEntry ( std::string key, int value){
        std::cout << "\t" << key
                  <<"\t" <<value << std::endl;
}
//void displayNumbers(sMap<int> & map){
        //map.mapAll(displayEntry);
//}

int main(){
        sMap<int> map1;
        map1.put("hello",3);
        std::cout << map1.get("hello") << std::endl;
        map1["fancy"]=10;
        map1.put("dumb",1);
        map1.get("fish");
        //map1.mapAll(displayNumbers);
        map1.mapAll();
        

        return 0;
}
