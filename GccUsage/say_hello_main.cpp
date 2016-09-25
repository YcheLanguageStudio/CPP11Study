#include "say_util.h"

int main(int argc,char *argv[])
{
    //告诉编译器这个Say类型的变量(symbol) librarysay在其他的编译单元中，可作为全局变量使用
    extern Say librarysay;
    Say localsay = Say("Local instance of Say");
    sayhello();
    librarysay.sayOther("say from library built-in object");
    librarysay.sayString();
    localsay.sayString();
    return(0);
}
