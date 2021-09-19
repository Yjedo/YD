#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE sizeof(Stu)

struct student
{
    int number;

    char name[10];

    float score;

    struct student *pnext;
};

typedef struct student Stu;

Stu * Createlist(void);//��������
void Sortlist(Stu *p);//�������㰴�ؼ���������
void Travellist(Stu *p);//��������

int main(void)
{
    Stu *ps;//����ͷָ��

    ps=Createlist();

    Sortlist(ps);

    Travellist(ps);

    system("pause");

    return 0;
}

Stu* Createlist(void)
{
     Stu *head, *p1, *p2;

     int a;

     char str[10];

     float scr;

     p1=(Stu *)malloc(SIZE);
     if(p1==NULL)
     {
         printf("Failed to allocate memory!");

         exit(-1);
     }

     head=p1;

     head->pnext=p1;

     do
     {
         printf("Please input number:");

         scanf("%d", &a);

         if(a==0)
         {
             break;
         }

         getchar();//�ն�����ȡ�س��ַ����Է���������ʱ������һ���������ͬ��

         printf("Please input name:");

         scanf("%s", str);

         getchar();//�ն�

         printf("please input score:");

         scanf("%f", &scr);

         getchar();//�ն�

         p2=(Stu *)malloc(SIZE);
         if(p2==NULL)
         {
             printf("Failed to allocate memory!");

             exit(-1);
         }

         p2->number=a;

         strcpy(p2->name, str);

         p2->score=scr;

         p2->pnext=NULL;

         p1->pnext=p2;

         p1=p2;
        
     }while(1);

     printf("Create list succesfully!\n");

     return head;
         
}

void Sortlist(Stu *p)
{
    Stu *px, *py, *pt, ps;
    Stu temp, *pa, *pb;

    px=p->pnext;

    if(px==NULL)
    {
        printf("It need' t sort!");

        return;
    }

    for(px;px->pnext!=NULL;px=px->pnext)
    {
        pt=px;
        for(py=px->pnext;py!=NULL;py=py->pnext)
        {
            if(px->score<py->score)
            {
                pt=py;
            }
        }

        if(pt!=px)//��pxָ��Ľ���Ľ�㷢���д���px��㴦score�Ľ��
        {
             ps=*pt;//�м��������ڽ������������

             pa=px->pnext;
             pb=pt->pnext;
             //��������ָ�����

             *pt=*px;

             pt->pnext=pb;//�ָ�pt��ԭָ�����

             *px=ps;

             px->pnext=pa;//�ָ�px��ԭָ�����
        }
    }
}
//����ѡ�����򷨶Ե���������йؼ���������
//����˼�룺�Ƚ�������ŵĹؼ����ݣ���������������������ָ���������������������

void Travellist(Stu *p)
{
    Stu *x;

    x=p->pnext;

    while(x!=NULL)
    {
        printf("Number:%d\t", x->number);
        printf("Name:%s\t", x->name);
        printf("Score:%.2f\n\n", x->score);
        x=x->pnext;
    }
}
//�������⣺vscode������C���Ա�ʶ���д����»���