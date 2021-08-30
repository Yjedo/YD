#include <iostream>
#include <algorithm>
#include <vector>
#define MAXLEN 100
using namespace std;
class Stack{
private:
    int date[MAXLEN];
    int top;
public:
    Stack();
    bool push_stack(int newdate);
    int pop_stack(void);
    int get_top_date(void);
    bool is_empty(void);
    bool is_full(void);
    int get_top(void);
};

Stack::Stack() {
    top = 0;
}

bool Stack::push_stack(int newdate){
    if(top == MAXLEN){
        cout << "ջ������" << endl;
        return false;
    }
    date[top++] = newdate;
    return true;
}

int Stack::pop_stack(void){
    if (top == 0){
        cout << "ջΪ�գ�" << endl;
        return -1;
    }
    top--;
    return date[top];
}

int Stack::get_top_date(void){
    return date[top-1];
}

bool Stack::is_empty(void){
    if (top == 0){
        return true;
    }
    return false;
}

bool Stack::is_full(void){
    if (top == MAXLEN){
        return true;
    }
    return false;
}

int Stack::get_top(void){
    return top;
}

bool legal_put_array(vector<int> & input_array, vector<int> & put_array);

int main(void){
    int  input_arrayx[5] = {1,2,3,4,5};
    vector<int> input_array = {1,2,3,4,5};
    vector<int> put_array(5);
    do{
       for(int i = 0; i<5; i++){
            put_array[i] = input_arrayx[i];
        }
        if (legal_put_array(input_array, put_array)){
            for(int j = 0; j<5; j++){
                cout << put_array[j];
            }
            cout << endl;
        }
    }while(next_permutation(input_arrayx, input_arrayx+5));
    return 0;
}

//ģ��������ջ���ջ�Ĺ��̼����ж���������Ƿ�Ϸ�
bool legal_put_array(vector<int> & input_array, vector<int> & put_array){
    Stack stack;
    int i = 0, j = 0;
    while(i<input_array.size()){
        stack.push_stack(input_array[i++]);           
        while(!stack.is_empty()){
            if (stack.get_top_date() == put_array[j]){
            j++;
            stack.pop_stack();
            }
            else{
                break;
            }
        }
        //�ж�ջ��Ԫ�������������е�ǰԪ���Ƿ����
        //����򽫽�ջ��Ԫ�ص�����jָ�����������е���һ��Ԫ��
        //������������ջ
        //����������ȫ����ջ�����˴��жϹ��̹���ջ��Ϊ�գ���˵��������в��Ϸ�
        //��Ϊ�գ���Ϸ�
    }
    if (stack.is_empty()){
        //cout << "�Ϸ���" << endl;
        return true;
    }
    //cout << "���Ϸ���" << endl;
    return false;
}

