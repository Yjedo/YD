//����㷨����ջ�ĺϷ��������
#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

//��ջģ��(�������Ա�)
class Stack{
private:
    int date[MAX];      
    int top;
public:
    Stack();
    bool isEmpty(void);             //�ж�ջ�Ƿ�Ϊ��
    bool isFull(void);              //�ж�ջ�Ƿ�����
    bool pushStack(int newdate);    //��ջ
    bool popStack(void);            //��ջ
    int getTopDate(void);           //��ȡջ��Ԫ��
};

//����ʵ��
Stack::Stack() {
    top = 0;
}

bool Stack::isEmpty(void) {
    return top == 0 ? true : false;
}

bool Stack::isFull(void){
    return top == MAX ? true : false;
}

bool Stack::pushStack(int newdate){
    if (isFull()) {
        cout << "ջ������" << endl;
        return false;
    }
    date[top++] = newdate;
    return true;
}

bool Stack::popStack(void) {
    if (isEmpty()) {
        cout << "��ջΪ�գ�" << endl;
        return false;
    }
    top--;
    return true;
}

int Stack::getTopDate(void) {
    if (isEmpty()) {
        cout << "��ջΪ�գ�" << endl;
        return false;
    }
    return date[top-1];
}
/*******************************************************************************************************************/


//�ж���������Ƿ�Ϸ�(����ջ������)
bool isLegalList(vector<int> enterarray, vector<int> putarray);

int main(void){
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {1, 2, 3, 4, 5};
    if (isLegalList(array1, array2)) {
        cout << "������кϷ���" << endl;
    }
    else {
        cout << "������в��Ϸ�" << endl;
    }
    return 0;
}

//����ʵ��
bool isLegalList(vector<int> enterarray, vector<int> putarray){
    Stack testStack;
    int i = 0, j = 0;
    while (i<enterarray.size() && j<putarray.size()){
        testStack.pushStack(enterarray[i++]);
        while(!testStack.isEmpty()){
            if (testStack.getTopDate() == putarray[j]){
                j++;
                testStack.popStack();
            }
            else {
                break;
            }
        }
    }
    if (testStack.isEmpty()){
        return true;
    }
    else {
        return false;
    }
}