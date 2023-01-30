#include <iostream>
#include <thread>

#include "SingletonSimple.h"
#include "Computer.h"

OS* OS::osPtr = nullptr;

void ComputerLaunch(std::string s)
{
    Computer* comp = new Computer();
    comp->Os() = OS::GetOs(s);
    std::cout << comp->Os()->Name() << "\n";
}

int main()
{
    /*SingletonSimple* obj1 = SingletonSimple::GetInstance();
    SingletonSimple* obj2 = SingletonSimple::GetInstance();
    SingletonSimple* obj3 = SingletonSimple::GetInstance();

    std::cout << obj1 << "\n";
    std::cout << obj2 << "\n";
    std::cout << obj3 << "\n";*/

    /*
    Computer* computer = new Computer();
    computer->Launch("Linux");

    std::cout << computer->Os()->Name() << "\n";

    computer->Os()->GetOs("Windows 10");
    std::cout << computer->Os()->Name() << "\n";

    computer->Launch("macOs");
    std::cout << computer->Os()->Name() << "\n";
    */

    
    std::thread th2(ComputerLaunch, "Linux");
    std::thread th1(ComputerLaunch, "Windows");

    th1.join();
    th2.join();

    std::cout << "\n";


    
    
}
