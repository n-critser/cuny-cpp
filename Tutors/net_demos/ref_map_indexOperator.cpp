/* From cpp-reference
   http://www.cplusplus.com/reference/map/map/operator[]
   // accessing mapped values

 */

#include <iostream>
#include <map>
#include <string>

int main ()
{
  std::map<char,std::string> mymap;

  mymap['a']="first";
  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  mymap['b']="bisfirst";
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  mymap['c']=mymap['b']+ "but in c";
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  mymap['a']= "secondA";
  std::cout << "mymap['a'] is " << mymap['a'] << '\n';

  // REFERENCING A MAP KEY CREATES THAT KEY WITH A BLANK VALUE!
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

  return 0;
}
