typedef struct Date{
    char Nodedate;
    int number;
}Date;
//�������
typedef struct Nodex{
    Date NodeDate;
    struct Nodex *pnext;
}OneWayNode;
//����������
typedef struct Nodey{
    Date NodeDate;
    struct Nodey *pnext;
    struct Nodey *pbefore;
}BothWayNode;
//˫��������
class LinkList{
private:
    OneWayNode *HeadNode1;  //��������ͷ���
    BothWayNode *HeadNode2; //˫������ͷ���
    int NumNode;            //�����
    int iflag;              //����������˫������ı�־
public:
    LinkList();                         //��ʼ������
    void Create_OneWay_LinkList();      //������������
    void Create_BothWay_Linklist();     //����˫������
    bool Add_Node(char date, int Beforenumber, int Nextnumber);           //�����½��
    bool Delete_Node(int number);       //ɾ�����
    bool Sort_Link_List();              //�������������
    Date Search_Node(int number);       //���ҽ��
    bool TravelLinkList();              //��������
    bool Delete_LinkList();             //ɾ������
};