#include <iostream>

#include "ForwardList.h"

int main(int argc, char** argv) {

    ForwardList<int> fl;

    fl.push_front(6);
    fl.push_front(5);
    fl.push_front(4);
    fl.push_front(3);
    fl.push_front(2);
    fl.push_front(1);

    std::cout << "Front: " << fl.front() << std::endl;
    std::cout << "Back: " << fl.back() << std::endl;
    std::cout << "Size: " << fl.get_size() << std::endl;
    std::cout << "Element at fl[2] = " << fl[2] << std::endl;

    return 0;
}