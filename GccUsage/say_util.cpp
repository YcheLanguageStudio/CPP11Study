#include "say_util.h"
void Say::sayString()
{
    std::cout << string << "\n";
}

//For built-in-library usage
Say librarysay("Library instance of Say");
