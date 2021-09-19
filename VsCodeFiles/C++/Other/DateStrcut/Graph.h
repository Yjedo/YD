//���ݽṹ����ͼ�Ĵ洢�������� �Լ������㷨��ʵ��
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
#define MAXVERNUM 1000  //������󶥵���
#define INFINITY 65535  //���������

//ͼ�Ķ�������
typedef struct vertex_date
{
    char date;
}vertex_date;

//ö��ͼ������
typedef enum {UDG, UDN, DG, DN} GraphKind;
//UDG:����ͼ
//UDN:������
//DG:����ͼ
//DN:������
class Graph
{
private:
    string GraphName;                       //ͼ����
    vertex_date Graph_Date;                 //��������
    vector<vector<int>> adjacent_matrix;    //�ڽӾ���
    int verNum;                             //������
    int arcNum;                             //����
    GraphKind graphkind;                    //ͼ����
public:
    Graph(string & name);                                
    ~Graph(void);
    bool Save_graph(void);                  //�洢ͼ
    bool Depth_first_search(void);          //�����������
    bool Breadth_first_search(void);        //�����������
};

//����Ϊ����������ͼ�ṹ��һЩ��������
string & Delete_str_space(string & str);        //ɾ���ַ����еĿո�
bool Recognize_file(FILE *pfile);           //ʶ���ļ�
bool Import_date(FILE *pfile);              //��������


/*
ͼ��һ�����ݽṹ����ڵ����������������ڵ�Ԫ�أ�
�����ڵ�������Ϊ�ߡ�
���㣨Ҳ���ǽڵ㣩vertex
�� edge
·��
����ͼ������֮�������û�з���
����ͼ������֮��������з���
��Ȩͼ�����ϴ���Ȩֵ��Ҳ������
*/