#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Number(int N, int *p, int *q);
/***************************
 * N������������
 * p�������ݸ���λ�ϵ���
 * q��������λ��
***************************/

int main(void)
{
    int n, a[12], Num;

    int i, Sum=0;

    printf("Please input a positive integer:");

    scanf("%d", &n);

    Number(n, a, &Num);

    i=Num-1;

    while(a[i]<=a[i-1]&&i>0)//�жϴ����λ�����λ�Ƿ��ϸ����
    {
        i--;
    }

    if(i==0)//˵���������ݱ���Ϊһ��������
    {
        printf("The biggest increasal integer that less than or equal to %d is %d", n, n);

        exit(0);
    }

    while(a[i]>a[i-1])//�ҵ���һ�����ڵ�λ��һ��λ�ϵ���
    {
        a[i]-=1;//�����ȥ1��

        if(i<Num-1)//�ж����ȥ1���Ƿ��Ծɴ�����ǰһλ�����ı��С����ǰһλ�������ִ�и�ѭ��
        {
            i++;
        }
    }

    i--;//�ҵ���ȥ1�����λ

    for(i--;i>=0;i--)//����λ�������λ�ϵ�������ֵλ9
    {
        a[i]=9;
    }

    for(i=0;i<Num;i++)
    {
        Sum += a[i]*pow(10, i);//���������ĸ���λ�ϵ����������λ������
    }

    printf("The biggest increasal integer that less than or equal to %d is %d", n, Sum);

    return 0;
}
//����ԭ��
void Number(int N, int *p, int *q)
{
    int i=0;

    while(N>0)
    {
        p[i]= N % 10;

        N/=10;

        i++;
    }

    *q = i;
}
//�������ܣ�����һ���Ǹ���N�����һ��С�ڵ��ڸ÷Ǹ������Ҵ����λ�����Ϊ�����ڵ�������Sum
//������1000�����999������1554�����1499������1234�� ���1234.