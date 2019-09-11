#include <iostream>
#include "ForwardList.h"

int main(int argc, char** argv) {

    int arr[] = {1, 2, 3, 4, 5};

    ForwardList<int> fl(arr, 5);

    std::cout << "Front: " << fl.front() << std::endl;
    std::cout << "Back: " << fl.back() << std::endl;
    std::cout << "Size: " << fl.get_size() << std::endl;
    std::cout << "Element at fl[2] = " << fl[2] << std::endl;

    std::cout << fl << std::endl;


    ForwardList<int> fl1(fl);

    std::cout << "Front: " << fl1.front() << std::endl;
    std::cout << "Back: " << fl1.back() << std::endl;
    std::cout << "Size: " << fl1.get_size() << std::endl;
    std::cout << "Element at fl[2] = " << fl1[2] << std::endl;

    std::cout << fl1 << std::endl;


    return 0;
}