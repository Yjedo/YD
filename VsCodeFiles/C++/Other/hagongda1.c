/*��дһ�����򣬽�һ���ַ���s2���뵽�ַ���s1�У�����ʼ����λ��Ϊn��
**�����ʽҪ��"%d"  ʹ��gets()�����ַ���s1��s2  
��ʾ��Ϣ��"main string:" "sub string:" "site of beginning:(<=%d)"
**�����ʽҪ��"After instert:%s\n" 
��������ʾ�����£�
main string:hello,world!
sub string:c 
site of beginning:(<=12)6
After instert:hello,cworld!*/
#include <stdio.h>

int main(void)
{
    int n, i, j;

    int num1, num2;

    char str1[100], str2[100];

    printf("main string:");

    gets(str1);

    printf("sub string:");

    gets(str2);

    printf("site of beginning:(<=12)");

    scanf("%d", &n);

    for(i=0;str1[i]!='\0';i++)
    {
        ;
    }

    num1=i;

    for(i=0;str2[i]!='\0';i++)
    {
        ;
    }

    num2=i;

    for(i=num1;i>=n;i--)
    {
        str1[i+num2]=str1[i];
    }

    for(i=n, j=0;i<=n+num2-1;i++, j++)
    {
        str1[i]=str2[j];
    }

    printf("After instert:%s\n", str1);

    return 0;


}