mkdir -p build
g++ -std=c++11 -O3 -D ENABLE_MOVE move_syntax_demo.cpp -o build/move_syntax_demo
g++ -std=c++11 -O3 move_syntax_demo.cpp -o build/copy_syntax_demo