#include <iostream>
using namespace std;

typedef unsigned long Item;

//�޷��ų�����ջ
class Stack
{
    private:
    enum {Max=10};
    Item items[Max];
    int top;

    public:
    Stack()
    {
        top=0;
    }
    bool isempty();                 //�ж�ջ�Ƿ�Ϊ��
    bool isfull();                  //�ж�ջ�Ƿ�����
    bool push(const Item & item);   //��ջ
    bool pop(Item & item);          //��ջ
    void show();
};

bool Stack::isempty()
{
    if(top==0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Stack::isfull()
{
    if(top==10)
    {
        return true;
    }
    else
    {
       return false;
    }
    
}

bool Stack::push(const Item & item)
{
    if(top<10)
    {
        items[top++]=item;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Stack::pop(Item & item)
{
    if(top>0)
    {
        item = items[top--];
        return true;
    }
    else
    {
        return false;
    }
    
}

void Stack::show()
{
    for(int i=0;i<top;i++)
    {
        cout << items[i] << " " << endl;
    }
}



int main(void)
{
    Stack stack;
    
    if(stack.isempty())
    {
        Item x;
        cin >> x;
        stack.push(x);
        cout << "Pop successfully" << endl;
    }
    else
    {
        cout << "Stack is full!" << endl;
    }

    stack.show();

    return 0;
}