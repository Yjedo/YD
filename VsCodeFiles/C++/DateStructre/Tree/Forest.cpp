#include <iostream>
#define MAXLEN 100
using namespace std;

typedef char date;

//˫�ױ�ʾ�����
typedef struct PForestNode{
    date nodeDate;
    int parent;
}PFNode;

//˫�ױ�ʾ��ɭ��
class PForest{
private:
    PFNode* forest[MAXLEN];
    int num = 0;
public:
    PForest();
    PFNode* GetNode(int i);
    void AddNode(date newNodeDate, int parent, int index);
    int GetNum(void);
};

PFNode* PForest::GetNode(int i){
    return forest[i];
}

/*
newNodeDate:��������½ڵ������
parent:��������½ڵ��ǵĸ��ڵ�
index:��������½����˫�ױ�ʾ��ɭ���е��±�
*/
void PForest::AddNode(date newNodeDate, int parent, int index){
    PFNode *p;
    p->nodeDate = newNodeDate;
    p->parent = parent;
    forest[index] = p;
    num++;  //ÿ���һ���½�㣬��������һ
}

//���ص�ǰɭ���еĽ�����
int PForest::GetNum(void){
    return num;
}

//�����ֵܱ�ʾ�����
typedef struct BCForestNode{
    date nodeDate;
    BCNode *pBrother;
    BCNode *pChild;
}BCNode;

//�����ֵܷ�ɭ��
class BCForest{
private:
    BCNode *baseNode;
public:
    BCForest();
    BCNode* GetBaseNode(void);                                //���ظ����
    int GetNodeNum(BCNode *node);                             //���ؽ�����
    int GetLeavesNodeNum(BCNode *node);                       //����Ҷ�ӽ�����
    void CreateBCForest(BCNode *&node, PForest &pForest, int index);      //����ɭ��
};

BCForest::BCForest(){
    baseNode = NULL;
}

BCNode* BCForest::GetBaseNode(void){
    return baseNode;
}

int BCForest::GetNodeNum(BCNode *node){
    if (node != NULL){
        return 1 + GetNodeNum(node->pChild) + GetNodeNum(node->pBrother);
        /*
        һ��ɭ�ֵĽ�����Ϊ1�����亢�����Ľ��������ֵ����Ľ�����
        */
    }
    else {
        return 0;
    }
}

void BCForest::CreateBCForest(BCNode *&node , PForest &pForest, int index){
    // if (index != -1){
    //     node = new BCNode;
    //     PFNode *ptemp = pForest.GetNode(index);
    //     node->nodeDate = ptemp->nodeDate;
    //     CreateBCForest(node->pChild, pForest, )
    // }
}







/*************************************************************************************/
//���Ժ����ֵܱ�ʾ���洢(��������)��ɭ��ת��Ϊ˫�ױ�ʾ���洢
void TurnFun(BCNode *BCFNode, PForest &PF, int parent = -1){
    if (BCFNode != NULL){
        PF.AddNode(BCFNode->nodeDate, parent, PF.GetNum());
        TurnFun(BCFNode->pChild,PF, PF.GetNum()-1);
        //���ӽ��ĸ��ڵ�Ϊ��ǰ�����˫�ױ�ʾ�������е��±�
        TurnFun(BCFNode->pBrother, PF, parent);
        //�ֵܱ�ʾ���ĸ��ڵ��뵱ǰ���ĸ��ڵ���ͬ
    }
}

//����ɭ�ָ߶�
int GetHeight(BCNode *BCFNode){
    if (BCFNode != NULL){
        int FCHeight = GetHeight(BCFNode->pChild);      //��ȡ�������߶�
        int BHeight = GetHeight(BCFNode->pBrother);     //��ȡ�ֵ������
        return ((1+FCHeight) > BHeight ? (FCHeight+1) : BHeight); 
        /*
        ע�⣺�ֵ����ĸ߶Ȳ������ϵ�ǰ��㣬����������Ҫ
        */
    }
    else{
        return 0;
    }
}

int main(void){
    return 0;
}

/*
void linkedToParent(csNode *&T,pTree &T1,int &f)
{
    //f Ϊ˫�׽����±�
    int f1;
    if(T)
    {
        T1.node[T1.n].data=T->data;
        T1.node[T1.n].parent=f;
        f1=T1.n; //���µ�һ�����ӽ���˫��
        T1.n++; //������� 1
        linkedToParent(T->firstChild,T1,f1); //˫�ױ�Ϊ f1
        linkedToParent(T->nextSibling,T1,f); //˫����Ϊ f 
    } 
}
*/