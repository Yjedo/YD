#include <iostream>
using namespace std;
void Move(int x, char a, char c);
void Hannuo(int n, char a, char c, char b);
int main(void)
{
    Hannuo(2,'a','b','c');
    return 0;
}
void Move(int x, char a, char c)
{
    cout << x << ":" << a <<"->"<< c << endl;
}
void Hannuo(int n,char a,char b,char c)
{
    if(n>=1)
    {
        Hannuo(n-1,a,c,b);      //����n��Բ���ϵ�n-1��Բ�̽���c�ƶ���b�ϣ�
        Move(n,a,c);            //
        Hannuo(n-1,b,a,c);
    }
}
//��ŵ���ݹ���⣻