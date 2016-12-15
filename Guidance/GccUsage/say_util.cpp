#include "say_util.h"
void Say::sayString() { std::cout << string << std::endl; }

// For built-in-library usage
Say librarysay("Library instance of Say");
