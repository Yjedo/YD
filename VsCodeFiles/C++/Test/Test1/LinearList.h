#include <vector>
#define MAXLEN 100    //�궨�����Ա���Ԫ��������ΪMAXLEN(100)
using namespace std;
//�������Ա���
class LinearList{
public:
    LinearList() { length=0; };     //��ʼ�����Ա���Ϊ0;
    LinearList(vector<int> & array);
    void Travellist(void);
    int Search_element(int i);
    bool Inseret_node(int i, int x);
    bool Delete_node(int i);
    bool Add_element(int x);
    bool Separate_list(LinearList & A, LinearList & B);
    bool Public_element(LinearList & A, LinearList & B);
    int MidNumber(LinearList & A, LinearList & B);
    bool Delete_same_element(void);
    int date[MAXLEN];
    int length;
};