#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

int main() {

    ForwardList<int> fl;

    fl.push_front(1);
    fl.push_front(2);
    fl.push_front(3);
    fl.push_front(4);
    fl.push_front(5);
    fl.push_front(6);

    cout << fl[0] << fl[1] << fl[2] << fl[3] << fl[4] << fl[5] << endl;
    
    return 0;
}