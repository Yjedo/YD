//ʹ��ջ��ģ�����
#include <iostream>
#include <stack>
using namespace std;
class MyQueen{
private:
    stack<int> inStack, outStack;   //��������ջ

    void inTwoOut(){
        while(!inStack.empty()){
            outStack.push(inStack.top());
            inStack.pop();
        }
        //��inStack��Ϊ��ʱ��inStack����ջ��Ԫ�أ�ѹ��outStack
    }
    //�˺�������Ϊ��inStack�е�ȫ��Ԫ��ת�Ƶ�outSatck
public:
    MyQueen(){}

    void push(int x){
        inStack.push(x);
    }

    int pop(){
        if(outStack.empty()){
            inTwoOut();
        }
        int x=outStack.top();
        outStack.pop();
        return x;
    }

    int peek(){
        if(outStack.empty()){
            inTwoOut();
        }
        return outStack.top();
    }

    bool empty(){
        return inStack.empty() && outStack.empty();
    }

};
int main(void){
    return 0;
}