mkdir -p build
g++ -c hello_world_util.cpp -o build/hello_world_util.o
g++ -c hello_world_main.cpp -o build/hello_world_main.o
#link and generate executable
g++ build/hello_world_util.o build/hello_world_main.o -o build/multiple_file_hello_world0
#remove intermediate files
rm build/hello_world_util.o build/hello_world_main.o
