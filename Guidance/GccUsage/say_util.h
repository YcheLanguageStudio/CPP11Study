#include <iostream>
extern void sayhello(void);

class Say {
private:
  char *string;

public:
  Say(char *str) { string = str; }
  void sayOther(const char *str) {
    std::cout << str << " from \"" << string << "\"" << std::endl;
  }
  void sayString(void);
};
