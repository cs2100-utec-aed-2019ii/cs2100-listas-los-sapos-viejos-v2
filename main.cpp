#include <iostream>
#include "ForwardList.h"

int main(int argc, char** argv) {

    ForwardList<int> fl;

    fl.push_front(5);

    Node<int>* ptr = fl.pop_front();

    std::cout << ptr->value << std::endl;

    return 0;
}