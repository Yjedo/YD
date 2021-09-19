#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef struct TreeNode{
    char date;
    TreeNode *pleft;
    TreeNode *pright;
}TreeNode;
string s[100];
int num = 0;
class BinaryTree{
private:
    TreeNode *baseNode;
    queue<TreeNode*> myqueue;
public:
    BinaryTree();
    void CreateSonTree(TreeNode **childTree, FILE *pf);     //��������
    void CreateTree(void);                                  //������
    void PreorderTraversal(TreeNode *node);     //�������
    //void InorderTaversal(TreeNode *node);       //�������
    //void PostorderTraversal(TreeNode *node);    //�������
    void LevelTraversal1(TreeNode *node);        //�������(��������)
    void LevelTraversal2(TreeNode *node);        //�������(���ڶ���)
    void PutDateAndLevel(TreeNode *node, int level = 1);       //����������������������Ӧ�Ĳ���������
    int GetTreeHeight(TreeNode *node);          //��������߶�
    int GetNodeNum(TreeNode *node);             //�������������
    void GetNodeFamilyDate(TreeNode *node, char nodeDate);     //��ȡ���ļ�ͥ��Ա��Ϣ
    void GetLeavesPath(TreeNode *node, string & str);                 //����Ҷ�ӽ�㵽���ڵ��·��
    void PutAllPath(TreeNode *node , string & str);                   //������нڵ㵽���ڵ��·��
    TreeNode * GetBaseNode(void);               //���ظ����
};

BinaryTree::BinaryTree(){
    baseNode = NULL;
}

void BinaryTree::CreateSonTree(TreeNode **childTree, FILE *pf){
    char chDate, ch_left_flag, ch_right_flag;
    if(fscanf(pf, "%c %c %c\n", &chDate, &ch_left_flag, &ch_right_flag)==EOF){
        cout << "�ļ��Ѷ�ȡ��ϣ�" << endl;
        return;
    }
    *childTree = new TreeNode;
    (*childTree)->date = chDate;
    (*childTree)->pleft = NULL;
    (*childTree)->pright = NULL;
    if(ch_left_flag != '&')
    CreateSonTree(&(*childTree)->pleft, pf);
    if(ch_left_flag != '&')
    CreateSonTree(&(*childTree)->pright, pf);
}

void BinaryTree::CreateTree(void){
    baseNode = new TreeNode;
    char chDate, ch_left_flag, ch_right_flag;
    FILE *pf;
    if (pf = fopen("TestDate.txt", "r")){
        cout << "�ļ��򿪳ɹ���" << endl;
    }
    fscanf(pf, "%c %c %c\n", &chDate, &ch_left_flag, &ch_right_flag);
    baseNode->date = chDate;
    baseNode->pleft = NULL;
    baseNode->pright = NULL;
    if(ch_left_flag != '&')
    CreateSonTree(&baseNode->pleft, pf);
    if(ch_left_flag != '&')
    CreateSonTree(&baseNode->pright, pf);
    fclose(pf);
}

void BinaryTree::PreorderTraversal(TreeNode *node){
    if (node!=NULL){
        cout << node->date << endl;
        PreorderTraversal(node->pleft);
        PreorderTraversal(node->pright);
    }
}

TreeNode * BinaryTree::GetBaseNode(void){
    return baseNode;
}

int BinaryTree::GetNodeNum(TreeNode *node){
    if (node != NULL ){
        int numLeft, numRight;
        numLeft = GetNodeNum(node->pleft);
        numRight = GetNodeNum(node->pright);
        return 1 + numLeft + numRight;
    }
    else{
        return 0;
    }
}

void BinaryTree::LevelTraversal1(TreeNode *node){
    TreeNode **tempDate = new TreeNode*[GetNodeNum(node)];  //�����ɴ�Ŷ��������нڵ����ݵ�����
    int i = 0, j = 1;
    tempDate[0] = node;
    while(j < GetNodeNum(node)){
        tempDate[j++] = tempDate[i]->pleft;
        tempDate[j++] = tempDate[i]->pright;
        i++;
    }
    for(int k = 0; k < j; k++){
        cout << tempDate[k]->date << endl;
    }
    return;
}

void BinaryTree::LevelTraversal2(TreeNode *node){
    TreeNode *p = node;
    while(p!=NULL){
        cout << p->date << endl;
        myqueue.push(p->pleft);
        myqueue.push(p->pright);
        p = myqueue.front();
        myqueue.pop();
    }
}

void BinaryTree::PutDateAndLevel(TreeNode *node, int level){
    if (node != NULL){
        PutDateAndLevel(node->pleft,level+1);
        cout << "date:" << node->date <<" level:" << level << endl;
        PutDateAndLevel(node->pright,level+1);
    }
}

int BinaryTree::GetTreeHeight(TreeNode *node){
    if(node!=NULL){
        int m, n;
        m = GetTreeHeight(node->pleft);
        n = GetTreeHeight(node->pright);
        return 1+(m>n?m:n);
    }
    else{
        return 0;
    }
}

void BinaryTree::GetNodeFamilyDate(TreeNode *node, char nodeDate){
    if (node != NULL){
        if (nodeDate == baseNode->date){
            cout << "�˽��Ϊ�����, ���޸��ڵ�,���ֵܽ�㣡" << endl;
            if (node->pleft != NULL){
                cout << "������Ϊ" << node->pleft->date << endl;
            }
            else{
                cout << "�˽ڵ������ӣ�" << endl;
            }
            if (node->pright != NULL){
                cout << "���Һ���Ϊ" << node->pright->date << endl;
            }      
            else{
                cout << "�˽�����к��ӣ�" << endl;
            }
            return;  
        }
        else{
            TreeNode *p;
            if (node->pleft->date != nodeDate && node->pright->date != nodeDate){
                GetNodeFamilyDate(node->pleft, nodeDate);
                GetNodeFamilyDate(node->pright, nodeDate);
            }
            else{
                if (node->pleft->date == nodeDate){
                    p = node->pleft;
                    cout << "�˽ڵ㸸�ڵ�Ϊ" << node->date << endl;
                    if (node->pright != NULL)
                    cout << "�˽���ֵܽ�㣨���ֵܣ�Ϊ" << node->pright->date << endl;
                    else cout << "�˽�����ֵܽ��" << endl;
                }
                if (node->pright->date == nodeDate){
                    p = node->pright;
                    cout << "�˽ڵ㸸�ڵ�Ϊ" << node->date << endl;
                    if (node->pleft != NULL)
                    cout << "�˽���ֵܽ�㣨���ֵܣ�Ϊ" << node->pleft->date << endl;
                    else cout << "�˽�����ֵܽ��" << endl;
                }
                if (p->pleft != NULL){
                    cout << "������Ϊ" << p->pleft->date << endl;
                }
                else{
                    cout << "�˽ڵ������ӣ�" << endl;
                }
                if (p->pright != NULL){
                    cout << "���Һ���Ϊ" << p->pright->date << endl;
                }      
                else{
                    cout << "�˽�����Һ��ӣ�" << endl;
                }
                return;
            }    
        }    
    }
}

/*
��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��
������ʱ������Ӧ��ʾ��Ϣ�����ֵܽ��ͺ��ӽ�㣬����ʱҪ��ȷָ�������ֵܡ����ӡ����ֵܻ��Һ��ӡ�
*/

void BinaryTree::GetLeavesPath(TreeNode *node, string & str){
    if(node != NULL){
        str.push_back(node->date);
        if (node->pleft == NULL && node->pright == NULL){
            s[num++] = str;
        }
        //�ҵ�Ҷ�ӽ��ͽ��ѻ�õ�·�����浽s����
        else{
            GetLeavesPath(node->pleft, str);
            GetLeavesPath(node->pright, str);
        }
        //û�ҵ�Ҷ�ӽ��ͼ���Ѱ��
        str.pop_back();
        //������һ��֮ǰ��Ҫ�ѵ�ǰ��·����ɾ��
        return;
    }
}

void BinaryTree::PutAllPath(TreeNode *node , string & str){
    if (node != NULL){
       str.push_back(node->date);
       int i = str.length()-1;
       while(i>0){
           cout << str[i] << "->";
           i--;
       }
       cout << baseNode->date <<endl;
       PutAllPath(node->pleft, str);
       PutAllPath(node->pright, str);
       str.pop_back();
    }
}

int main(void){
    BinaryTree myTree;
    string str;;
    myTree.CreateTree();
    // cout << myTree.GetBaseNode()->date;
    // myTree.PreorderTraversal(myTree.GetBaseNode());
    // myTree.PutDateAndLevel(myTree.GetBaseNode());
    // cout << "���ĸ߶��ǣ�" << myTree.GetTreeHeight(myTree.GetBaseNode()) << endl;;
    // cout << "��һ����" << myTree.GetNodeNum(myTree.GetBaseNode()) << "�����" << endl;
    // cout << "���������";
    // myTree.LevelTraversal(myTree.GetBaseNode());
    // cout << endl;
    // myTree.GetPath(myTree.GetBaseNode(), str);
    // for(int i = 0; i<num; i++){
    //     cout << s[i] << endl;
    // }
    myTree.PutAllPath(myTree.GetBaseNode(), str);
    return 0;
}
