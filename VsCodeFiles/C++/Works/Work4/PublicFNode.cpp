#include <iostream>
using namespace std;

int PublicFNode(int i, int j);

int main(void){
    int i = 8, j = 9;
    cout << "���Ϊ" << i << "����Ϊ" << j << "������������Ƚ����Ϊ" << PublicFNode(i, j) << endl;
    return 0;
}

int PublicFNode(int i, int j){
    while(i != j){
        if (i>j){
            i /= 2;
        }
        else {
            j /= 2;
        }
    }
    return i;
}