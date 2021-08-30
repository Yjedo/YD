#include "TeachSrc.h"
#include <queue>

static int degree;
void PreorderTraversal(csNode *node);     //�ȸ�����
void PostorderTraversal(csNode *node);    //�������
void LevelTraversal(csNode *node);        //�������
int GetForestHeight(csNode *node);        //��ɭ�ֵĸ߶�
int GetForestNodeNum(csNode *node);       //��ɭ�ֵĽ�����
int GetLeavesNodeNum(csNode *node);       //��ɭ�ֵ�Ҷ�ӽ�����
void GetForestDegree(csNode *node);       //��ɭ�ֵĶ�
void InputForestDateAndLevel(csNode *node , int level = 0);   //���ɭ�ֵĽ����������
void InputGeneralizedListTree(csNode *node);                  //���������ʾ����

void Menu(void){
    cout << "1.�ȸ�����" << endl;
    cout << "2.�������" << endl;
    cout << "3.�������" << endl;
    cout << "4.��ɭ�ָ߶�" << endl;
    cout << "5.��ɭ�ֵĽ�����" << endl;
    cout << "6.��ɭ�ֵ�Ҷ�ӽ�����" << endl;
    cout << "7.��ɭ�ֵĶ�" << endl;
    cout << "8.���ɭ�ֵĽ����������" << endl;
    cout << "9.���������ʾ����" << endl;
    cout << "���븺һ�˳�" << endl;
}

int main(void){
    pTree testTree;
    csNode *csT;
    CreateTreeFromFile("ForestData.txt",testTree);
    createCsTree(csT, testTree);
    while(1){
        Menu();
        int testNum;
        cout << "��������ţ�" << endl;
        cin >> testNum;
        switch(testNum){
            case 1: PreorderTraversal(csT);
                    system("pause");
                    break;
            case 2: PostorderTraversal(csT);
                    system("pause");
                    break;
            case 3: LevelTraversal(csT);
                    system("pause");
                    break;
            case 4: cout << "ɭ�ֵĸ߶��ǣ�" << GetForestHeight(csT) << endl;
                    system("pause");
                    break;
            case 5: cout << "ɭ�ֵĽ������ǣ�" << GetForestNodeNum(csT) << endl;
                    system("pause");
                    break;
            case 6: cout << "ɭ�ֵ�Ҷ�ӽ�����Ϊ��" << GetLeavesNodeNum(csT) << endl;
                    system("pause");
                    break;
            case 7: GetForestDegree(csT);
                    cout << "ɭ�ֵĶ�Ϊ��" << degree <<endl;
                    system("pause");
                    break;
            case 8: InputForestDateAndLevel(csT);
                    system("pause");
                    break;
            case 9: InputGeneralizedListTree(csT);
                    system("pause");
                    break;
            case -1: return 0;
        }
        system("cls");
    }
    return 0;
}

void PreorderTraversal(csNode *node){
    if (node != NULL){
        cout << node->data << endl;
        PreorderTraversal(node->firstChild);
        PreorderTraversal(node->nextSibling);
    }
}

void PostorderTraversal(csNode *node){
   if (node != NULL){
    PostorderTraversal(node->firstChild);
    cout << node->data << endl;
    PostorderTraversal(node->nextSibling);
   }
}

void LevelTraversal(csNode *node){
    if (node != NULL){
        csNode *ptemp = node;
        queue<csNode*> nodeQueue;
        while(ptemp != NULL || !nodeQueue.empty()){
            while(ptemp){
                cout << ptemp->data << endl;
                nodeQueue.push(ptemp->firstChild);
                ptemp = ptemp->nextSibling;
            }
            ptemp = nodeQueue.front();
            nodeQueue.pop();
        }
    }
}

int GetForestHeight(csNode *node){
    if (node != NULL){
        int height, Bheight;
        height = GetForestHeight(node->firstChild) + 1;
        Bheight = GetForestHeight(node->nextSibling);
        return height > Bheight ? height : Bheight;
    }
    else{
        return 0;
    }
}

int GetForestNodeNum(csNode *node){
    if (node != NULL){
        return 1 + GetForestNodeNum(node->firstChild) + GetForestNodeNum(node->nextSibling);
    }
    else{
        return 0;
    }
}

int GetLeavesNodeNum(csNode *node){
    if (node != NULL){
        if (!node->firstChild){
            //����㺢�ӽ��Ϊ�գ�����ΪҶ�ӽ��
            return 1 + GetLeavesNodeNum(node->nextSibling);
        }
        else{
            return GetLeavesNodeNum(node->firstChild) + GetForestNodeNum(node->nextSibling);
            //ɭ�ֵ�Ҷ�ӽ�����������������Ҷ�ӽ�����������ֵܽ����
        }
    }
    else {
        return 0;
    }
}

void GetForestDegree(csNode *node){
    if (node != NULL){
        csNode *ptemp = node;
        int i = 0;
        while(ptemp != NULL){
            i++;
            ptemp = ptemp->nextSibling;
        }
        if (degree < i){
            degree = i;
        }
        GetForestDegree(node->firstChild);
        GetForestDegree(node->nextSibling);
    }
}

void InputForestDateAndLevel(csNode *node , int level){
    if (node != NULL){
        cout << "date:" << node->data << "  level:" << level+1 << endl;
        InputForestDateAndLevel(node->firstChild, level+1);
        //���ӽ��ȵ�ǰ���Ĳ�����һ
        InputForestDateAndLevel(node->nextSibling, level);
        //�ֵܽ���뵱ǰ�����ͬһ��
    }
}

void InputGeneralizedListTree(csNode *node){
    if (node != NULL){
        cout << node->data ;
        if (node->firstChild){
            cout << "(";
        }
        InputGeneralizedListTree(node->firstChild);
        if (node->nextSibling){
             cout << ",";
        }
        else{
            cout << ")";
        }
        InputGeneralizedListTree(node->nextSibling);
    }
}




