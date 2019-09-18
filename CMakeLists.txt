cmake_minimum_required(VERSION 3.14)
project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(Node.h List.h DoublyLinkedList main.cpp ForwardList.h DoubleList.h CircularList.h DoubleCircularList.h Iterator.h)