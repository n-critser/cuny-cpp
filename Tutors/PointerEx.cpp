#include <iostream>
#include <cstdlib>
int main(){

  const int iStatic  = 17;

  int *iPtr = new int;
  
  *iPtr = 17;

  int *iPtr2 = iPtr;

  std::cout<< "Address:"<< iPtr << std::endl;
  std::cout<< "value:"<< (*iPtr) << std::endl;
  std::cout<< "Address:"<< iPtr2 << std::endl;
  std::cout<< "value:"<< (*iPtr2) << std::endl;

  std::cout<< "Deleting iPtr"  << std::endl;

  delete iPtr;
  std::cout<< "Address:"<< iPtr << std::endl;
  std::cout<< "value:"<< (*iPtr) << std::endl;
  
  iPtr= NULL;

  std::cout<< "Address:"<< iPtr2 << std::endl;
  std::cout<< "value:"<< (*iPtr2) << std::endl;
  //std::cout<< "Address:"<< iPtr << std::endl;

  return 0;
}
