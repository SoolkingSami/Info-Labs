#include <iostream>
#include "StackLinkedList.h"

int main() {
    auto st = StackLinkedList();

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    std::cout << st.pop() << std::endl;
    std::cout << st.pop() << std::endl;

    st.push(5);
    st.push(6);

    std::cout << st.pop() << std::endl;

    return 0;
}
