#include <stdio.h>

//�˺����������0~9����������
void printNumber(int N);

//�˺�����ʹ������printNumber������������С��������������
void printOut(int N);

int main(void)
{
    printOut(456);
    return 0;
}

void printNumber(int N)
{
    if (N > 9 || N < 0)
    {
        printf("�������޷������");
        return;
    }
    else
    {
        printf("%d", N);
    }
}

void printOut(int N){
    if (N < 0)
    {
        printf("-");
        N *= -1;
    }

    if (N > -1 && N < 10)
    {
        printNumber(N);
    }
    else
    {
        printOut(N/10);
        printNumber(N%10);
    }
}

