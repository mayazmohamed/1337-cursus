#include <iostream>
#include "./red_black_tree/red_black_tree.hpp"


int main(){
    try
    {
        ft::RedBlackTree<int , int> RBT;

        RBT.insert(10, 10);
        RBT.insert(18, 18);
        RBT.insert(7, 7);
        RBT.insert(15, 15);
        RBT.insert(16, 16);
        RBT.insert(30, 30);
        RBT.insert(25, 25);
        RBT.insert(40, 40);
        RBT.insert(60, 60);
        RBT.insert(2, 2);
        RBT.insert(1, 1);
        RBT.insert(70, 70);

        // std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
        RBT.deleteNode(10);
        RBT.deleteNode(18);
        RBT.printTree(3);
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}