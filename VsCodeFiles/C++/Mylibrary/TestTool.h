#include <iostream>

/*
���˳������:
    array   ��̬����������
    vector  ��̬����������
    deque   ˫�˶���
    forward_list    ������
    list    ˫����
����Ԫ��    
*/
template<typename T>
void printContainer(T t){
     for (auto element : t) {
        std::cout << ' ' << element;
    }
    std::cout << "\n";
}
