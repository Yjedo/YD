#include <cstring>
#include "ListGraph.h"

//ɾ���ַ������ַ�������߿ո�
void strLTrim(char* str)
{
	int i,j;
	int n=0;
	n=strlen(str)+1;
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')  //�ҵ������һ���ǿո�λ��
			break;
	}
	    //�Ե�һ���ǿո��ַ�Ϊ���ַ��ƶ��ַ���
	for(j=0;j<n;j++)
	{
		str[j]=str[i];
		i++;
	}
}

//����ͼ
void DestroyGraph(Graph &G)
{
	EdgeNode *p,*u;        //��������ָ��
	int vID;
	for(vID=1; vID<=G.VerNum; vID++)  //ѭ��ɾ��ÿ������ı�����
	{
		p=G.VerList[vID-1].firstEdge;
		G.VerList[vID-1].firstEdge=NULL;
		while(p)           //ѭ��ɾ����ǰ�������еĹ����� 
		{
			u=p->next;    //uָ����һ���߽��
			delete(p);     //ɾ����ǰ�߽��
			p=u;
		}		
	}
	p=NULL;
	u=NULL;
	G.VerNum=-1;  //��ʶͼ�Ѿ�����
}

//****************************�ļ�����ͼ*****************************//
//* �������ܣ����ı��ļ������ڽӱ��ʾ��ͼ                          *//
//* ��ڲ���  char fileName[]���ļ���                               *//
//* ���ڲ�����Graph &G����������ͼ                                  *//
//* �� �� ֵ��bool��true�����ɹ���false����ʧ��                    *//
//* �� �� ����CreateGraphFromFile(char fileName[], Graph &G)        *//
//* ��ע��������ʹ�õ������ļ���ʽ�Աߣ�����ԣ�Ϊ��������          *//
//*******************************************************************//
int CreateGraphFromFile(char fileName[], Graph &G)
{
	FILE* pFile;         //�����ļ�ָ��
	char str[1000];        //��Ŷ���һ���ı����ַ���
	char strTemp[10];      //�ж��Ƿ�ע����
	char* ss; 
  int i=0, j=0;
	int edgeNum=0;        //�ߵ�����
	eInfoType eWeight;     //�ߵ���Ϣ����Ϊ�ߵ�Ȩֵ
	GraphKind graphType;  //ͼ����ö�ٱ���
	pFile=fopen(fileName,"r");
	if(!pFile)
	{
		printf("�����ļ�%s��ʧ�ܡ�\n",fileName);
		return false;
	}
		while(fgets(str,1000,pFile)!=NULL)  //�������к�ע����
	{
		strLTrim(str);     //ɾ���ַ�����߿ո�����һ���Զ��庯��
		if (str[0]=='\n')    //���У�������ȡ��һ��
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)    //����ע����
			continue;
		else                          //��ע���С��ǿ��У�����ѭ��
			break;
	}
  //ѭ��������str��Ӧ���Ѿ���ͼ�ı�ʶGraph���жϱ�ʶ�Ƿ���ȷ
	if(strstr(str,"Graph")==NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile);                //�ر��ļ�
		return false;
	}
	//��ȡͼ�����ͣ��������м�ע����
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);     //ɾ���ַ�����߿ո�����һ���Զ��庯��
		if (str[0]=='\n')    //���У�������ȡ��һ��
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else                       //�ǿ��У�Ҳ��ע���У���ͼ�����ͱ�ʶ
			break;
	}
  //����ͼ������
	if(strstr(str,"UDG"))
		graphType=UDG;    //����ͼ
	else if(strstr(str,"UDN"))
		graphType=UDN;    //������
	else if(strstr(str,"DG"))
		graphType=DG;     //����ͼ
	else if(strstr(str,"DN"))
		graphType=DN;     //������
	else
	{
		printf("���󣺶�ȡͼ�����ͱ��ʧ�ܣ�\n");
		fclose(pFile);       //�ر��ļ�
		return false;
	}
	//��ȡ�������ݵ�str����������
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);     //ɾ���ַ�����߿ո�����һ���Զ��庯��
		if (str[0]=='\n')    //���У�������ȡ��һ��
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else                       //�ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
			break;
	}
	//�������ݷ���ͼ�Ķ�������		
	char* token=strtok(str," ");
	int nNum=0;	
	while(token!=NULL)
	{
		G.VerList[nNum].data=*token;
		G.VerList[nNum].firstEdge=NULL;
      token = strtok( NULL, " ");
		nNum++;
	}
	//ѭ����ȡ�ߣ�����ԣ�����
	int nRow=0;          //�������±�
	int nCol=0;           //�������±�
	EdgeNode* eR;       //������βָ��
	EdgeNode* p;    
	elementType Nf, Ns;   //�߻򻡵�2�����ڶ���
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);     //ɾ���ַ�����߿ո�����һ���Զ��庯��
		if (str[0]=='\n')    //���У�������ȡ��һ��
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;
		char* token=strtok(str," ");     //�Կո�Ϊ�ָ������ָ�һ������
		if(token==NULL)            //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile);            //�ر��ļ�
			return false;
		}
		Nf=*token;                //��ȡ�ߵĵ�һ������
		token = strtok( NULL, " ");   //��ȡ��һ���Ӵ������ڶ�������
		if(token==NULL)          //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile);          //�ر��ļ�
			return false;
		}
		Ns=*token;    //��ȡ�ߵĵڶ�������
                   //�ӵ�һ�������ȡ�к�
		for(nRow=0;nRow<nNum;nRow++)
		{
			if(G.VerList[nRow].data==Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
                    //�ӵڶ��������ȡ�к�
		for(nCol=0;nCol<nNum;nCol++)
		{
			if(G.VerList[nCol].data==Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}
		//���Ϊ������ȡȨֵ
		if(graphType==UDN || graphType==DN)
		{            //��ȡ��һ���Ӵ������ߵĸ�����Ϣ����Ϊ�ߵ�Ȩ��
			token = strtok( NULL, " ");  
			if(token==NULL)    //�ָ�Ϊ�մ���ʧ���˳�
			{
				printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
				fclose(pFile);    //�ر��ļ�
				return false;
			}
			eWeight=atoi(token);  //ȡ�ñߵĸ�����Ϣ����Ȩֵ
		}
		eR=G.VerList[nRow].firstEdge;
		while(eR!=NULL && eR->next!=NULL)
		{
			eR=eR->next;        //���Ʊ�����ָ�룬ֱ��β�ڵ�
		}
		p=new EdgeNode;        //����һ����������
		p->adjVer=nCol+1;       //����ı�ţ���1��ʼ
	    //�ߵĸ�����Ϣ��Ȩֵ��������Ȩͼ����Ȩֵ����ȨͼΪ1
if(graphType==UDN || graphType==DN) 
			p->eInfo=eWeight;
	    else
			p->eInfo=1; 
		p->next=NULL;
		if(G.VerList[nRow].firstEdge==NULL)
		{
			G.VerList[nRow].firstEdge=p;
			eR=p;
		}
		else
		{
			eR->next=p;
			eR=p;       //�µ�βָ��				
		}				
		edgeNum++;     //������1
	}
	G.VerNum=nNum;    //ͼ�Ķ�����
	if(graphType==UDG || graphType==UDN)
		G.ArcNum=edgeNum / 2;   //����ͼ�����ı�������ͳ�Ƶ����ֳ�2  
	else
		G.ArcNum=edgeNum;
	G.gKind=graphType;           //ͼ������
	fclose(pFile);                 //�ر��ļ�
	return true;
}

int main(void){
    return 0;
}