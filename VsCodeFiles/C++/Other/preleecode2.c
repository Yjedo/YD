/*����һ�ֹ��� pattern?��һ���ַ���?str?���ж� str �Ƿ���ѭ��ͬ�Ĺ��ɡ�
�����?��ѭ?ָ��ȫƥ�䣬���磬?pattern?���ÿ����ĸ���ַ���?str?�е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧ���ɡ�*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char pattern[20], str[20][10], s[200];

    int i, j, k, length, n=0;

    printf("Please enter your pattern:");

    gets(pattern);

    printf("Please input your setence:");

    gets(s);

    length=strlen(pattern);

    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==' ')
        {
            n++;
        }
    }

    if(length!=(n+1))//�������ַ����ַ����������������ַ������ʸ�����������
    {
        printf("false");

        exit(0);
    }

    for(i=0;pattern[i]!='\0';i++)
    {
        str[i][0]=pattern[i];
    }

    j=0;

    k=0;

    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
             str[j][1+k]=s[i];

             k++;
        }

        else
        {
            str[j][1+k]='\0';

            j++;

            k=0;
        }
        
    }
//�������ַ�����ÿ���ַ��������ַ�����Ӧλ���ϵĵ����������Ϊ�µ��ַ���
    str[j][k+1]='\0';

    for(i=0;i<length;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(str[i][0]==str[j][0])
            {

                if(strcmp(str[i], str[j])!=0)
                {
                printf("false");

                exit(0);
                }
            }
        }
    }
//������϶��ɵ������ַ����������ַ���ͬ���ַ����������˵�������ַ��������Ϲ���
    printf("ture");

    return 0;
}