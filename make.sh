W="-Wfatal-errors -Wall -Wextra -Wshadow -Wpedantic"
O="-O3 -flto -march=native -DNDEBUG"
g++ -std=c++11 $W $O -o ./demolito ./src/*.cc -lpthread
strip ./demolito