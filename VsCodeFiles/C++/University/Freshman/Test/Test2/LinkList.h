#include <iostream>
#include <vector>

//��װ���������������
typedef int Date;
typedef struct Node{
    Date Nodedate;
    struct Node *pnext;
}Node;

class LinkList{
public:
    Node *Head;
    LinkList();                               //δ����״̬
    LinkList(Node *phead);                    //��ʼ��ͷ���
    void Createlist_Head(void);               //1.ͷ�巨����������
    void Createlist_Tail(void);               //2.β�巨����������
    bool DeleteList(void);                    //3.ɾ������
    int Getlength(void);                      //4.��ȡ��������
    bool SearchNode_Number(int number);       //5.����Ų��ҽ��(ͷ���Ϊ��0����㣬�Դ�����)
    bool Front_InsertNode(int number, Date interset_date);  //6.��������֮ǰ�����½��(����������ֵ)
    bool SearchNode_Date(Date search_date);   //7.��ֵ����
    bool DeleteNode_Number(int number);       //8.�����ɾ�����
    bool Insert_date (Date inseret_date);     //9.�ڵ������������в��������ݣ��������������
    bool Separate_list(LinkList & A, LinkList & B);  //10.���������е�����������ż�����ݷֱ�����±�
    bool Public_element(LinkList & A, LinkList & B); //11.���������������е���ͬ���ݷ����±�
    bool Delete_same_element(void);                  //12.ɾ���������������е���ͬԪ��
    bool Union_list(LinkList & newList);             //13.��������ϲ�Ϊһ������ɾ������һ����ͷ��㣬����������м��ϵ�����
    bool Search_k_date2(int k);                      //��չ�����ҵ���������k���������
    bool Travellist(void);                    //��������������
    bool Add_node(Date newdate);              //����½��(β��)
    bool DeleteNode_Date(Date search_date);    //ɾ�����
};