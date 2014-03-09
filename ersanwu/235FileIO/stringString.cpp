#include <iostream>
#include <string>
#include <sstream>

int main(){
  std::string myText("some-text-to-tokenize");
  std::string nextText("hello,my,name,is,939393");
  std::istringstream iss(myText);
  std::istringstream str(nextText);
  std::string token;
  std::string split;
  while(getline(str, split, ','))
    {
      std::cout << split  << std::endl;
    }
}
