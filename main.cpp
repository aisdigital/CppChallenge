// Challenge C++ AISDigital

#include <iostream>

#include "Challenge.h"
#include "IOStorage.h"


int main(int argc, const char * argv[])
{
    std::cout << "Challenge C++" << std::endl;
    Challenge challenge(new IOStorage());

    challenge.Execute();

    return 0;
}


