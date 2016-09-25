mkdir -p build
g++ -c say_util.cpp -o build/say_util.o
g++ -c say_hello_func.cpp -o build/say_hello_func.o
#程序 ar 配合参数 -r 创建一个新库 libsay.a 并将命令行中列出的对象文件插入。
#采用这种方法，如果库不存在的话，参数 -r 将创建一个新的库，而如果库存在的话，将用新的模块替换原来的模块。
ar -r build/libsay.a build/say_util.o build/say_hello_func.o
ranlib build/libsay.a
g++ say_hello_main.cpp build/libsay.a -o build/say_hello_main
