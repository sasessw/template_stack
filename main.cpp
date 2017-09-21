#include <iostream>
#include "t_stack.h"



int main() {
    try {
        stack<int> A(12);
        for (int i = 0; i < 15; i++) {
            A.push(12);
        }
        for (int i = 0; i < 14; i++) {
            A.pop();
        }
    }
    catch(char const* e)
    {
        std::cerr << e;
    }
    return 0;
}