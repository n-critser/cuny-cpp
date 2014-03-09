#include<iostream>
#include<cstdlib>
#include<stdio.h>

int main(){
  int a[2][3][2] = {
    { {2,4}, {7,8}, {3,4} },
    { {2,2}, {2,3}, {3,4} }};
    
  std::cout<< " a:" << a << std::endl;
  std::cout<< " *a:" << a << std::endl;
  std::cout<< " **a:" << **a << std::endl;
  std::cout<< " ***a:" << ***a << std::endl;
  std::cout<< " a+1: " << a+1 << std::endl;
  std::cout<< " *a+1:" << *a+1 << std::endl;
  std::cout<< " **a+1:" << **a+1 << std::endl;
  std::cout<< " ***a+1:" << ***a+1 << std::endl;

  //printf( "%d\n", a); 
  //printf( "%d\n", *a); 
  //printf( "%d\n", **a); 
  //printf( "%d\n", ***a); 
  //printf( "%d\n", a+1); 
  //printf( "%d\n", *a+1); 
  //printf( "%d\n", **a+1); 
  //printf( "%d\n", ***a+1);
  

  return 0;
}
