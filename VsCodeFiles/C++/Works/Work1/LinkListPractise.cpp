#include <iostream>
using namespace std;

typedef int Date;
typedef struct Node{
    struct Node *pioneer;
    Date Nodedate;
    struct Node *pnext;
}Node;
class Circularlinkedlist{
private:
    Node *Head, *Trail;
public:
    Circularlinkedlist();
    bool CreateList(void);
    bool ReverseTravel(void);
    bool TravelList(void);
    bool is_symmetrylist(void);
    bool ReverseList(void);
};
Circularlinkedlist::Circularlinkedlist(){
    Head = new Node;
    Head->pioneer = Head;
    Head->pnext = Head;
    Head->Nodedate = -1;
    Trail = Head;
}
bool Circularlinkedlist::CreateList(void){
    Node *p, *pnew;
    int newdate;
    p = Head;
    while(1){
        cout << "���������ݣ�" << endl;
        cin >> newdate;
        if (newdate == -1){
            break;
        }
        pnew = new Node;
        pnew->Nodedate = newdate;
        pnew->pioneer = p;
        pnew->pnext = Head;
        p->pnext = pnew;
        Head->pioneer = pnew;
        p = pnew;
    }
    Trail = p;
    cout << "����ѭ��˫����ṹ�ɹ���" << endl;
    return true;
}
bool Circularlinkedlist::TravelList(void){
    Node *p;
    p = Head->pnext;
    while(p!=Head){
        cout << p->Nodedate << endl;
        p = p->pnext;
    }
    cout << "����������" << endl;
    return true;
}
bool Circularlinkedlist::ReverseTravel(void){
    Node *p;
    p = Trail;
    do{
        cout << p->Nodedate << endl;
        p = p->pioneer;
    }while(p->pioneer!=Trail);
    return true;
}
bool Circularlinkedlist::is_symmetrylist(void){
    if(Head == Trail){
        cout << "����һ���ձ�" << endl;
        return false;
    }
    Node *p1, *p2;
    p1 = Head->pnext;
    p2 = Trail;
    while(p1!=p2){
        if(p1->Nodedate != p2->Nodedate){
            cout << "����һ���ǶԳƱ�" << endl;
            return false;
        }
        p1 = p1->pnext;
        p2 = p2->pioneer;
    }
    cout << "����һ���ԳƱ�" << endl;
    return true;  
}

bool Circularlinkedlist::ReverseList(void){
    Node *p, *ptemp;
    p = Head;
    do{
        ptemp = p->pnext;
        p->pnext = p->pioneer;
        p->pioneer = ptemp;
        p = p->pioneer;
    }while(p!=Head);
    return true;
}
//��Ȼ������˫ѭ��������������ÿ������ǰ��ָ������ָ�뼴��

int main(void){
    Circularlinkedlist list1;
    list1.CreateList();
    list1.TravelList();
//    list1.ReverseTravel();
//    list1.is_symmetrylist();
    list1.ReverseList();
    list1.TravelList();
    return 0;
}