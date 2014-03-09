#include <iostream>
#include <string>


int foo (int n){
        //std::cout << "calling foo("<<n<<")"<<std::endl;
        if (n <= 0)
                return 1;
        else {
                //int floor2 = n/2;
                //int by2 = 2 *floor2;
                //      std::cout <<"floor2 =" << floor2 << std::endl;
                //std::cout << "floor2 *2=" << by2<< std::endl;
                return foo(n/2) + foo(n/2) + n;
        }
}

int main(){

        int n = 20;
        int whatfoo = 0;
        for (int i = 0; i <=n; i++){
                whatfoo = foo(i);
                
                std::cout<< "foo("<< i << ") = " << whatfoo <<std::endl;
                std::cout <<"\n"<< std::endl;
        }





        return 0;

}
      
