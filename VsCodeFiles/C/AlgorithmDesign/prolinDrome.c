#include <stdio.h>

//��ȡһ������������
void reverseNumber(int N);

int main(void){
    reverseNumber(123);
    return 0;
}

void reverseNumber(int N)
{
    if (N < 0)
    {
        printf("�������ݲ�����Ҫ��");
        return;
    }

    int tempNum = 0;
    int n = N;
    while(N > 0)
    {
        tempNum = tempNum*10 + N % 10;
        N /= 10;
    }

    if (n == tempNum){
        printf("����һ����������\n");

    }
    else{
        printf("�ⲻ��һ����������\n");
    }
}