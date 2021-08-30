//���ҵ���������k�����ݣ� �ҵ���ӡ�����ݣ�������true, ���򷵻�false
//˼·��final_flag��¼�������һ������λ��
//      search_flag[i][1]��¼�����ҵ�����
//      ��ôsearch_flag[final_flag - k + 1][1] ��Ϊ��Ҫ��������
//ȱ�㣺�˷Ѵ����ռ䣿
#include <iostream>
#include <vector>
using namespace std;

//��װ���������������
typedef int Date;
typedef struct Node{
    Date Nodedate;
    struct Node *pnext;
}Node;

class LinkList{
private:
    Node *Head;
public:
    LinkList();
    LinkList(Node *ptemp);
    void Createlist(void);              //����ʽ������������
    bool Travellist(void);
    Node * ReturnHead(void);
    Node * ReturnTail(void);
    bool Head_AddNode(Date add_date);   //ͷ�巨����½ڵ�
    bool Tail_AddNode(Date add_date);   //β������½��
    bool Rear_InsertNode(Date frontdate, Date interset_date);//��������֮������½ڵ�(����������ֵ)
    bool Front_InsertNode(Date reardate, Date interset_date);  //��������֮ǰ�����½��(����������ֵ)
    bool SearchNode_Number(int number);        //����Ų��ҽ��(ͷ���Ϊ��0����㣬�Դ�����)
    bool SearchNode_Date(Date search_date);  //��ֵ����
    bool DeleteNode_Number(int number);        //�����ɾ�����
    bool DeleteNode_Date(Date search_date);  //��ֵɾ�����
    bool DaleteList(void);              //ɾ������
};

//��������ʵ�֣�δ���ԣ�������
/**********************************************************************************************/
//��ʼ���ձ�
LinkList::LinkList(Node * ptemp){
    Head = ptemp;
}

//��ʼ��ͷ���Ϊ��
LinkList::LinkList(){
    Head = NULL;
}

//��������
void LinkList::Createlist(void){
    Node *p1, *p2;
    p1 = new Node;
    p1->pnext = NULL;
    Head = p1;
    do{
        Date newdate;
        cout << "Please input your date:" << endl;
        cin >> newdate;
        if (newdate==-1){
            break;
        }
        p2 = new Node;
        p2->Nodedate = newdate;
        p2->pnext = NULL;
        p1->pnext = p2;
        p1 = p2;
    }while(1);
    return;
}

//��������������
bool LinkList::Travellist(void){
    if (Head==NULL || Head->pnext==NULL){
        cout << "������Ϊ�ջ�δ������" << endl;
        return false;
    }
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        cout << p->Nodedate << endl;
        p = p->pnext;
    }
    return true;
}

//����ͷ���
Node * LinkList::ReturnHead(void){
    return Head;
}

//����β���
Node * LinkList::ReturnTail(void){
    if (Head==NULL || Head->pnext==NULL){
        cout << "������Ϊ�ջ�δ������" << endl;
        return NULL;
    }
    Node *p;
    p = Head->pnext;
    while(p->pnext != NULL){
        p = p->pnext;
    }
    return p;
}

//ͷ�巨����½��
bool LinkList::Head_AddNode(Date add_date){
    if(Head==NULL){
        cout << "������δ������" << endl;
        return false; 
    }
    Node *p, *newNode;
    newNode = new Node;
    p = Head->pnext;
    newNode->Nodedate = add_date;
    Head->pnext = newNode;
    newNode->pnext = p;
    cout << "��ӽ��ɹ���ͷ�壩" << endl;
    return false;
}

//β�巨����½��
bool LinkList::Tail_AddNode(Date add_date){
    Node *p;
    p = new Node;
    p->Nodedate = add_date;
    p->pnext = NULL;
    ReturnTail()->pnext = p;
    return false;
}

//�������������½��
bool LinkList::Rear_InsertNode(Date frontdate, Date interset_date){
    if (Head==NULL || Head->pnext==NULL){
        cout << "������Ϊ�ջ�δ������" << endl;
        return false;
    }
    Node *p;
    p = Head->pnext;
    while(p->Nodedate!=frontdate && p->pnext!=NULL){
        p = p->pnext;
    }
    if (p->pnext==NULL){
        cout << "δ�ҵ���Ӧǰ����㣡" << endl;
        return false;
    }
    Node *pnew_node, *pnext_node;
    pnew_node = new Node;
    pnext_node = p->pnext;
    pnew_node->Nodedate = interset_date;
    p->pnext = pnew_node;
    pnew_node->pnext = pnext_node;
    cout << "��ӽ��ɹ�" << endl;
    return true;
}

//��������֮ǰ����½��
bool LinkList::Front_InsertNode(Date reardate, Date interset_date){
    if (Head==NULL || Head->pnext==NULL){
        cout << "������Ϊ�ջ�δ������" << endl;
        return false;
    }
    Node *p;
    p = Head;
    while(p->pnext->Nodedate!=reardate && p->pnext!=NULL){
        p = p->pnext;
    }
    if (p->pnext==NULL){
        cout << "δ�ҵ�ָ��Ԫ�أ�"  << endl;
        return false;
    }
    Node *pnew_node;
    pnew_node = new Node;
    pnew_node->Nodedate = interset_date;
    pnew_node->pnext = p->pnext;
    p->pnext = pnew_node;
    cout << "����ɹ���" << endl;
    return true;
}

//����������������λ�ò��ҽ��
bool LinkList::SearchNode_Number(int number){
    if(number<0){
        cout << "��Ų��Ϸ���"  << endl;
        return false;
    }
    if(number==0){
        cout << "ͷ��㲻�洢���ݣ�" << endl;
        return false;
    }
    int i = 1;
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        if(number == i){
            cout << "�������" << i << "���ڵ�����Ϊ" << p->Nodedate << endl;
            return true;
        }
        else{
            p = p->pnext;
            i++;
        }
    }
    cout << "��ų�����Χ!" << endl;
    return false;
}

//����洢������ֵ�����½��
bool LinkList::SearchNode_Date(Date search_date){
    Node *p;
    int i = 1;
    p = Head->pnext;
    while(p!=NULL){
        if(p->Nodedate == search_date){
            cout << "���������ڴ������" << i << "�����" << endl;
            return true;
        }
        else{
            p = p->pnext;
            i++;
        }
    }
    cout << "δ���ҵ�������ݣ�" << endl;
    return false;
}

//����������������λ��ɾ�����
bool LinkList::DeleteNode_Number(int number){
     if(number<0){
        cout << "��Ų��Ϸ���"  << endl;
        return false;
    }
    if(number==0){
        cout << "ͷ��㲻�洢���ݣ�" << endl;
        return false;
    }
    int i = 1;
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        if(number == i+1){
            Node *ptemp;
            ptemp = p->pnext;
            p->pnext = p->pnext->pnext;
            delete ptemp;
            cout << "��ɾ���������" << i+1 << "�����" << endl;
            return true;
        }
        else{
            p = p->pnext;
        }
    }
    cout << "��ų�����Χ, ɾ��ʧ�ܣ�" << endl;
    return false;
}

//����洢������ֵɾ���½��
bool LinkList::DeleteNode_Date(Date search_date){
    Node *p;
    int i = 1;
    p = Head->pnext;
    while(p!=NULL){
        if(p->pnext->Nodedate == search_date){
            Node *ptemp;
            ptemp = p->pnext;
            p->pnext = ptemp->pnext;
            delete ptemp;
            cout << "��ɾ���洢����" << search_date << "�Ľ��" << endl;
            return true;
        }
        else{
            p = p->pnext;
            i++;
        }
    }
    cout << "δ���ҵ��������, ɾ��ʧ�ܣ�" << endl;
    return false;
}

//ɾ������
bool LinkList::DaleteList(void){
    if (Head==NULL || Head->pnext==NULL){
        cout << "������Ϊ�ջ�δ������" << endl;
        return false;
    }
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        Node *ptemp;
        ptemp = p;
        p = p->pnext;
        delete ptemp;
    }
    cout << "��ɾ����������"  << endl;
    return true;
}

//������������k���ڵ�����
bool Search_k_date1(LinkList & test_linklist, int k);    //��һ��
bool Search_k_date2(LinkList & test_linklist, int k);    //��һ��
//���汾�㷨ʱ�临�Ӷ���ͬ������һ���㷨�ռ����Ĵ�ö�

//�͵���������
bool InversionList(LinkList & test_linklist);

//����ģ�⼯�ϲ���A = A��B�Ĳ���
LinkList & UnionList(LinkList & A, LinkList & B);

//�������������������ϲ�Ϊһ���ݼ����������
LinkList & MergeList(LinkList & A, LinkList & B);

int main(void){
    LinkList mylist1, mylist2;
    mylist1.Createlist();
    Search_k_date2(mylist1, 3);
    return 0;
}

bool Search_k_date1(LinkList & test_linklist, int k){
    Node *ptemp;
    vector<Date> savedate;
    ptemp = test_linklist.ReturnHead()->pnext;
    int i = 0;
    while(ptemp != NULL){
        savedate[i++] = ptemp->Nodedate;
        ptemp = ptemp->pnext;
    }
    if (i<k) {
        return false;
    }
    else {
        cout << savedate[i-k] << endl;
        return true;
    }
}

bool InversionList(LinkList & test_linklist){
    if (test_linklist.ReturnHead()->pnext->pnext == NULL){
        cout << "��������������" << endl;
        return false;
    }
    Node *pfront, *prear, *ptemp;
    pfront = test_linklist.ReturnHead()->pnext;
    prear = pfront->pnext;
    pfront->pnext = NULL;
    ptemp = NULL;
    while(prear!=NULL){
        ptemp = prear->pnext;
        prear->pnext = pfront;
        pfront = prear;
        prear = ptemp;
    }
    test_linklist.ReturnHead()->pnext = pfront;
    cout << "���óɹ���" << endl;
    return true;
}

LinkList & UnionList(LinkList & A, LinkList & B){
    Node *p1, *p2, *ptemp;
    p1 = A.ReturnHead()->pnext;
    p2 = B.ReturnHead()->pnext;
    while(p2!=NULL){
        while(p1!=NULL){
            if (p1->Nodedate == p2->Nodedate){
                break;
            }
            else{
                ptemp = p1; //��ʱָ�����������ǰһ�����
                p1 = p1->pnext;
            }
        }
        if(p1==NULL){
                p1 = new Node;
                p1->Nodedate = p2->Nodedate;
                p1->pnext = NULL;
                ptemp->pnext = p1;
            }
            p1 = A.ReturnHead()->pnext;
            p2 = p2->pnext;
    }
    return A;
}

LinkList & MergeList(LinkList & A, LinkList & B){
    Node *ptemp;
    ptemp = new Node;
    ptemp->pnext = NULL;
    static LinkList newlist(ptemp);
    Node *pa, *pb;
    pa = A.ReturnHead()->pnext;
    pb = B.ReturnHead()->pnext;
    while(pa!=NULL && pb!=NULL){
        if (pa->Nodedate <= pb->Nodedate){
            newlist.Head_AddNode(pa->Nodedate);
            pa = pa->pnext;
        }
        else{
            newlist.Head_AddNode(pb->Nodedate);
            pb = pb->pnext;
        }
    }
    if (pa==NULL){
        ptemp = pb;
    }
    else {
        ptemp = pa;
    }
    while(ptemp!=NULL){
        newlist.Head_AddNode(ptemp->Nodedate);
        ptemp =ptemp->pnext;
    }
    return newlist;    
}

LinkList & UnionForList(LinkList & A, LinkList & B){
    Node *pa, *pb;
    pa = A.ReturnHead()->pnext;
    pb = B.ReturnHead()->pnext;
    Node *p1, *p2, *ptemp;
    p1 = pa;
    p2 = pb;
    ptemp = NULL;
    while(pa!=A.ReturnHead()){
        pa = pa->pnext;
    }
    while(pb!=B.ReturnHead()){
        pb = pb->pnext;
    }
    while(p2!=pb && p1!=pa){
        if (p1->Nodedate == p2->Nodedate){
            ptemp = p2;
            p2 = ptemp->pnext;
            B.DeleteNode_Date(ptemp->Nodedate);
        }
        else if(p1->Nodedate > p2->Nodedate){
            p2 = p2->pnext;
        }
        else{
            p1 = p1->pnext;
        }
    }
    pa = B.ReturnHead();
    pb = A.ReturnHead();
    return A; 
}

bool Search_k_date2(LinkList & test_linklist, int k){
    Node *p1, *p2;
    int iflag = 0;
    p1 = test_linklist.ReturnHead()->pnext;
    p2 = p1;
    while(p1->pnext!=NULL){
        p1 = p1->pnext;
        iflag++;
        if(iflag > k-1){        //��p1��p2λ�����k-1�����ʱ��p2��ʼ�ƶ�
            p2 = p2->pnext;     //��p1�������һ�����ʱ��p2����λ�ü�������k�����
        }
    }
    if (iflag < k){
        cout << "������С��k" << endl;
        return false;
    }
    else{
        cout << p2->Nodedate << endl;
        return true;
    }
}