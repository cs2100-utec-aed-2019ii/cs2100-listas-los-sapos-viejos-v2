#include <iostream>

#include "ForwardList.h"

int main(int argc, char** argv) {

    ForwardList<int> fl;

    fl << 1;
    fl << 1;
    fl << 1;
    fl << 1;
    fl << 1;
    fl << 1;

    fl.drop(1);

    std::cout << fl << std::endl;

    return 0;
}