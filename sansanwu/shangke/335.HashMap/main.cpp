/*
  File: main.cpp for 335.HashMap 

  compile with Makefile
 */
#include<cstdlib>
#include<iostream>
#include<string>
#include"sMap.h"

int main(){
        sMap<int> map1;
        map1.put("hello",3);
        std::cout << map1.get("hello") << std::endl;


        return 0;
}
