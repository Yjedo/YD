//����Ϊͼ�ķ���ʵ���Լ�������������ʵ��
#include "Graph.h"

//����ͼ�������֣�����Ѱ����Ӧ�������ļ�
Graph::Graph(string & name)
{
   GraphName = name;
}

Graph::~Graph(void) {}

string & Delete_str_space(string & str)
{
   string newstr;
   int j = 0;
   for(int i=0; i<str.size(); i++)
   {
       if (str[i] == ' ')
       {
           continue;
       }
       else
       {
           newstr[j] = str[i];
           j++;
       }
   }
   return newstr;
}
//�����ַ�����ģ����,���Բ��ý������ַ��������ķǿո��ַ�
//���Ƶ��´���

bool Recognize_file(FILE * pfile)
{
    if (!pfile)
    {
        cout << "���ļ���Ч��" << endl;
        return false;
    }
    
}