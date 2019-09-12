#include <iostream>

#include "ForwardList.h"

int main(int argc, char** argv) {

    ForwardList<int> fl;

    fl.push_front(645);
    fl.push_front(5);
    fl.push_front(87);
    fl.push_front(46);
    fl.push_front(99);

    std::cout << fl << std::endl;

    ForwardListNode<int>* ref = fl.find_node_at(0);

    fl.insert(ref, 2);

    ForwardListNode<int>* ref2 = fl.find_node_at(7);

    fl.erase(ref2);
    fl.reverse();
    std::cout << fl << std::endl;

    return 0;
}