mkdir -p build
g++ -E hello_world.cpp -o build/hello_world.ii
grep -c "" build/hello_world.ii
