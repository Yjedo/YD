#include <iostream>
#define MAXLEN 5
using namespace std;

class Queue{
private:
    int date[MAXLEN];
    int front;
    int rear;
public:
    Queue();    //��ʼ������
    bool IsEmpty(void);     //�ж϶����Ƿ�Ϊ��
    bool IsFull(void);      //�ж϶����Ƿ�����
    bool PushDate(int newdate);     //���
    int PopDate(void);              //����
    int GetTopDate(void);           //ȡ��ͷԪ��
    int GetDateNum(void);           //�������Ԫ�ظ���
    bool PutAllDate(void);          //�������������Ԫ��
};

Queue::Queue(){
    front = 0;
    rear =  1;
    cout << "���г�ʼ����ɣ�" << endl;
}

bool Queue::IsEmpty(void){
    if ((front+1)%MAXLEN == rear){
        return true;
    }
    return false;
}

bool Queue::IsFull(void){
    if (rear%MAXLEN == front){
        return true;
    }
    return false;
}

bool Queue::PushDate(int newdate){
    if(IsFull()){
        cout << "����������" << endl;
        return false;
    }
    date[rear] = newdate;
    rear = (rear+1)%MAXLEN;
    return true;
}

int Queue::PopDate(void){
    if (IsEmpty()){
        cout << "����Ϊ�գ�" << endl;
        return false;
    }
    front = (front+1)%MAXLEN;
    return date[front];
}

int Queue::GetTopDate(void){
    return date[front+1];
}

int Queue::GetDateNum(void){
    if (IsEmpty()){
        return 0;
    }
    else return (MAXLEN+(rear-front))%MAXLEN;
}

bool Queue::PutAllDate(void){
    if(IsEmpty()){
        cout << "����Ϊ�գ�" << endl;
        return false;
    }
    int i = front+1;
    cout << "��ʱ�����е������У�" << endl;
    while((i != rear)){
        cout << date[i] <<endl;
        i = (i+1)%MAXLEN;
    }
    return true;
}

bool TestQueue(void){
    Queue testQueue;
    int testNum;
    while(1){
        cout << "���������ݣ�" << endl;
        cin >> testNum;
        if (testNum == 0){
            break;
        }
        else if(testNum%2 == 0){
            testQueue.PopDate();
        }
        else{
            testQueue.PushDate(testNum);
        }
        testQueue.PutAllDate();
    }
    return true;
}                 

int main(void){
    TestQueue();
    return 0;
}