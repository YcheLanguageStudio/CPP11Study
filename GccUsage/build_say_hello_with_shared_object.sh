mkdir -p build
#添加-fpic 这个compiler flag，告诉编译器，
#生成的对象模块采用浮动的（可重定位的）地址。缩微词 pic 代表“位置无关代码”（position independent code）
g++ -c say_util.cpp -fpic -o build/say_util.o
g++ -c say_hello_func.cpp -fpic -o build/say_hello_func.o

g++ -shared build/say_util.o  build/say_hello_func.o -o build/libsay.so
rm build/*.o

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./build/

g++ say_hello_main.cpp build/libsay.so -o build/say_hello_main_with_so
