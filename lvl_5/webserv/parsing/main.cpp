#include "test.hpp"

int main(){
    configFile v;

    std::string t = "h e l lo\t\n";
    int i = t.find_first_of("\n", 2);
    std::cout << i;
}