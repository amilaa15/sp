#include <iostream>
#include "duration.hpp"

int main() {
  // ovdje možete samostalno testirati neke funkcionalnosti. 
  // Napomena: main.cpp se ne pregleda, sva implementacija 
  // ide u duration .cpp i .hpp fileove.

  Duration test1=Duration(3700);
    std::cout << "sati " << test1.getHour() << " minute " << test1.getMinute()<< " sekunde " << test1.getSecond()<<std::endl;

    Duration test2=Duration{10, 20, 30};
    std::cout << "sati " << test2.getHour() << " minute " << test2.getMinute()<< " sekunde " << test2.getSecond()<<std::endl;

    Duration test3;
    test3.setHour(56);
    std::cout << "sati " << test3.getHour() << std::endl;

    Duration test4;
    test4.setHour(30).setMinute(45).setSecond(15);
    std::cout << test4.getHour() << "h " << test4.getMinute() << "m " << test4.getSecond() << "s" << std::endl;

    Duration d1{10, 35, 15};
    Duration d2{10, 30, 15};
    d1==d2; 
    d1!=d2;
    d1>d2;
    d1<d2;        
    d1>=d2;
    d1<=d2;

    Duration d3{20};
    Duration d4{1, 30, 0};
    d3+=d4;
    d3-=d4;
    d3*=d4;
    d3/=d4;
    d3=d3+d4;
    d3=d3-d4;
    d3=d3*d4;

  
  Duraiton d1{1, 2, 3};
  std::cout << (d1 + Duration{3, 2, 1}) << std::endl;
}
