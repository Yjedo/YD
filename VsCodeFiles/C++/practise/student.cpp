#include<stdio.h>
#include<malloc.h>

void Input(struct student *p,int*toal);//¼��ѧ����Ϣ��
void Output(struct student *p,int*toal);//���¼���ѧ����Ϣ��
void found(struct student *p,int*toal );//����ѧ�Ų�ѯѧ����Ϣ��
void revise(struct student *p,int*toal);//�޸�ĳһѧ�ŵ�ѧ����Ϣ��
void sort(struct student *p,int*toal);//����ƽ��������
void average(struct student *p,int*toal);//����ѧ���ɼ���ƽ��ֵ��
struct student
{
long int ID;
char name[10];
float math_score;
float english_score;
float c_score;
float ave;
}st;//����ṹ�壻

//******************************************************************************************************************

int main(void)
{
	int total;
	int*toal;
	int i=0,str;
	char ch;
	struct student *p;
	p=&st;
	toal=&total;
	printf("************************************************************************************************\n");
	printf("����Ҫ¼�����е�ѧ����Ϣ���ܽ��н���ϵͳ	\n");
	printf("��������Ҫ¼��ѧ����������");
	scanf("%d",&total);
	p=(struct student*)malloc(sizeof(struct student)**toal);
	printf("�ɹ�����ϵͳ��\n");

	//**************************************
	printf("����¼�뿪ʼ\n");
	for(i=0;i<*toal;++i)
	{
		printf("ѧ�ţ�");
			scanf("%d",&p[i].ID);
		printf("������");
			scanf("%s",&(p+i)->name);
		printf("��ѧ�ɼ���");
			scanf("%f",&(p+i)->math_score);
		printf("Ӣ��ɼ���");
			scanf("%f",&(p+i)->english_score);
		printf("C���Գɼ���");
			scanf("%f",&(p+i)->c_score);
			p[i].ave=(p[i].c_score+p[i].english_score+p[i].math_score)/3;
		printf("��%d��ͬѧ¼�����\n",i+1);
		printf("************************************************************************************************\n");
	}
	printf("************************************************************************************************\n");
	ch='a';




	//************************************
		while(ch!='0')
	{
		ch=getchar();

	printf("2.¼��ѧ����Ϣ�鿴\n");
	printf("3.����ѧ�Ų�ѯѧ����Ϣ\n");
	printf("4.�޸�ѧ����Ϣ\n");
	printf("5.��ÿ��ѧ����ƽ���ɼ�\n");
	printf("6.��ѧ���ɼ�����\n");
	printf("7.�˳�\n");
	printf("�����������ֿ����ù���\n");
	printf("************************************************************************************************\n");
	scanf("%d",&str);
	switch(str)
	{
case 2:
		Output(p,toal);
		break;//�鿴�Ѿ�¼�������ѧ��
case 3:
		found(p,toal);
		break;//����ѧ�Ų�ѯѧ����Ϣ
case 4:
		revise(p,toal);
		break;//�޸�ѧ����Ϣ
case 5:
		average(p,toal);
		break;//��ÿ��ѧ����ƽ���ɼ�
case 6:
		sort(p,toal);
		break;//��ѧ���ɼ�����
case 7:
		ch='0';
		break;
	}
	printf("�������������\n");

	}
	printf("ллʹ�ã��ټ���\n");
	getchar();
	getchar();
return 0;
}
void Input(struct student *p,int*toal)//¼��ѧ����Ϣ����
{

	int i;
	printf("����¼�뿪ʼ\n");
	for(i=0;i<*toal;++i)
	{
		printf("ѧ�ţ�");
		scanf("%d",&p[i].ID);
		printf("������");
			scanf("%s",&(p+i)->name);
		printf("��ѧ�ɼ���");
			scanf("%f",&(p+i)->math_score);
		printf("Ӣ��ɼ���");
			scanf("%f",&(p+i)->english_score);
		printf("C���Գɼ���");
			scanf("%f",&(p+i)->c_score);
			p[i].ave=(p[i].c_score+p[i].english_score+p[i].math_score)/3;
		printf("��%d��ͬѧ¼�����\n",i+1);
		printf("ѧ�ţ�%d	������%s	��ѧ�ɼ���%.1f	Ӣ��ɼ�: %.1f	c���Գɼ�:%.1f	ƽ���ɼ���%.1f\n",p[i].ID,(p+i)->name,(p+i)->math_score,(p+i)->english_score,(p+i)->c_score,p[i].ave);
	}

}
void Output(struct student *p,int*toal)//���ѧ����Ϣ����
{
	int i;
printf("������¼��%d��ͬѧ�ĸ�����Ϣ�ͳɼ�\n", *toal);
for(i=0;i<*toal;++i)
{
	printf("ѧ�ţ�%d	������%s	��ѧ�ɼ���%.1f	Ӣ��ɼ�: %.1f	c���Գɼ�:%.1f	ƽ���ɼ���%.1f\n",p[i].ID,(p+i)->name,(p+i)->math_score,(p+i)->english_score,(p+i)->c_score,(((p+i)->math_score+(p+i)->english_score+(p+i)->c_score)/3));
}

}

void found(struct student *p,int*toal )
{
	long int n,h;
	//long int*f;
	int j,count=0;
	//f=&n;

	printf("����������Ҫ��ѯ��ѧ�ţ�\n");
		scanf("%d",&n);
		for(j=0;j<*toal;++j)
		{	h=p[j].ID;
			if(n==h)
			{
				printf("ѧ�ţ�%d	������%s	��ѧ�ɼ���%.1f	Ӣ��ɼ�: %.1f	c���Գɼ� %.1f\n",p[j].ID,p[j].name,p[j].math_score,p[j].english_score,p[j].c_score);
				count++;

			}

		}
		if(count==0)
				printf("û�и�ѧ��!\n");
}

//************************************************************************************
void revise(struct student *p,int*toal)
{
	long int n,h;

	int j,count=0;
	printf("����������Ҫ�޸ĵ�ѧ�ţ�\n");
		scanf("%d",&n);
		for(j=0;j<*toal;++j)
		{
			if(n==p[j].ID)
			{
				printf("ѧ�ţ�%d	������%s	��ѧ�ɼ���%.1f	Ӣ��ɼ�: %.1f	c���Գɼ�:%.1f\n",p[j].ID,p[j].name,p[j].math_score,p[j].english_score,p[j].c_score);
				count++;
				printf("�������޸ĺ��ѧ����Ϣ��\n");
					printf("ѧ�ţ�");
						scanf("%d",&(p+j)->ID);
					printf("������");
						scanf("%s",&(p+j)->name);
					printf("��ѧ�ɼ���");
						scanf("%f",&(p+j)->math_score);
					printf("Ӣ��ɼ���");
						scanf("%f",&(p+j)->english_score);
					printf("C���Գɼ���");
						scanf("%f",&(p+j)->c_score);
			printf("�޸����ݳɹ���\n");
			printf("�޸ĺ�ĳɼ����£�\n");
			printf("ѧ�ţ�%d	������%s	��ѧ�ɼ���%.1f	Ӣ��ɼ�: %.1f	c���Գɼ�:%.1f\n",p[j].ID,(p+j)->name,(p+j)->math_score,(p+j)->english_score,(p+j)->c_score);

			}
			if(count==0)
				printf("û�и�ѧ��!\n");
		}

}
//***********************************************************************************
void sort(struct student *p,int*toal)//����ƽ��������
{
	int i,j,k;
	//Output(&st,toal);
	printf("%dλͬѧ��ƽ�������£�������\n");

	for(i=0;i<*toal;++i)
	{
		for(j=0;j<*toal-i-1;++j)
		{
			if(p[j].ave<=p[j+1].ave)
			{
				st=p[j+1];
				p[j+1]=p[j];
				p[j]=st;
			}
		}

	}

	for(i=0;i<*toal;++i)
{
	printf("��%d��:\n",i+1);
	printf("ѧ�ţ�%d	������%s	��ѧ�ɼ���%.1f	Ӣ��ɼ�: %.1f	c���Գɼ�:%.1f	ƽ���ɼ���%.1f\n",p[i].ID,(p+i)->name,(p+i)->math_score,(p+i)->english_score,(p+i)->c_score,p[i].ave);

}

}
	void average(struct student *p,int*toal)
	{
	int i;
	for(i=0;i<*toal;++i)
	{
		printf("ѧ�ţ�%d	������%s	ƽ��ֵ��%.3f\n",p[i].ID,p[i].name,p[i].ave);
	}

	}
