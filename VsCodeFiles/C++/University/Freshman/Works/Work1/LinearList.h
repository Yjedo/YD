#include <vector>
#define MAXLEN 100    //�궨�����Ա���Ԫ��������ΪMAXLEN(100)
using namespace std;
//�������Ա���
class LinearList{
public:
    LinearList() { length=0; };     //��ʼ�����Ա���Ϊ0;
    LinearList(vector<int> & array);
    int date[MAXLEN];
    int length;
};

//���ú�������
LinearList & DeleteOrdedAE(LinearList & list);                          //ɾ���������Ա��е��ظ�Ԫ��
LinearList & DeleteAE(LinearList & list);
LinearList & IntersectSet(LinearList & A_list, LinearList & B_list);    //��������(����)
LinearList & UnionSet(LinearList & A_list, LinearList & B_list);        //��������(����)
LinearList & MinusSet(LinearList & A_list, LinearList & B_list);        //��������(����)
LinearList & ordered_IntersectSet(LinearList & A_list, LinearList & B_list);    //��������(����)
LinearList & ordered_UnionSet(LinearList & A_list, LinearList & B_list);        //��������(����)
LinearList & ordered_MinusSet(LinearList & A_list, LinearList & B_list);        //��������(����)
void PutList(LinearList & list);                                        //��ӡ���Ա��Ԫ��