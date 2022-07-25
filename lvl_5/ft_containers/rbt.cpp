#include <iostream>
#include "./red_black_tree/red_black_tree.hpp"


int main(){
    
    try
    {
        ft::RedBlackTree<int> RBT;

        RBT.insert(10);
        RBT.insert(18);
        RBT.insert(7);
        RBT.insert(15);
        RBT.insert(16);
        RBT.insert(30);
        RBT.insert(25);
        RBT.insert(40);
        RBT.insert(60);
        RBT.insert(2);
        RBT.insert(1);
        RBT.insert(70);

        RBT.deleteNode(18);
        RBT.deleteNode(0);
        // ft::RedBlackTree<int>::iterator it;
        // it = RBT.begin();
        // std::cout << *it << std::endl;
        // RBT.erase(1);
        // it = RBT.begin();
        // std::cout << *it << std::endl;
        RBT.printTree(3);


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}