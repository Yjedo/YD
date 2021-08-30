#include <iostream>
#include <queue>
#include <string>
#define MAXLEN 100
using namespace std;

typedef struct TreeNode{
    char date;
    TreeNode *pleft;
    TreeNode *pright;
}TreeNode;
/***********************/
string s[100];
int num = 0;
//����·����Ϣ
/***********************/
static int iflag = 0;
//��¼���ʽ�����
/***********************/

//��˳���洢�Ķ�����
//����һ����㣬��data = -1, ��ý��Ϊ��;
typedef struct ArrayTreeNode{
    char date;
    int pleft;
    int right;
}ArrayTreeNode;

class ArrayTree{
public:
    int nodeNum = 0;
    ArrayTreeNode binaryTree[100];
    ArrayTree(char *s, int index);
};

ArrayTree::ArrayTree(char s[], int index){
    for(int i = 1; i < index; i++){
        cout << s[i];
        binaryTree[i].date = s[i];
        binaryTree[i].pleft = i*2;
        binaryTree[i].right = i*2 + 1;
        nodeNum++;
    }
}

class BinaryTree{
private:
    TreeNode *baseNode;
    queue<TreeNode*> myqueue;
public:
    BinaryTree();
    BinaryTree(TreeNode *node);
    void CreateSonTree(TreeNode **childTree, FILE *pf);     //��������
    void CreateTree(void);                                  //������
    void PreorderTraversal(TreeNode *node);     //�������
    void InorderTaversal(TreeNode *node);       //�������
    void PostorderTraversal(TreeNode *node);    //�������
    void LevelTraversal2(TreeNode *node);                         //�������(���ڶ���)
    void PutDateAndLevel(TreeNode *node, int level = 1);          //����������������������Ӧ�Ĳ���������
    int GetTreeHeight(TreeNode *node);                            //��������߶�
    int GetNodeNum(TreeNode *node);                               //�������������
    void GetLeafNode(TreeNode *node);                             //���������Ҷ�ӽڵ����
    void GetTwoDegreeNode(TreeNode *node);                        //���������Ϊ���Ľ�����
    void GetDateLevel(TreeNode *node, char nodeDate, int level, bool &flag);  //��������ΪnodeDate�Ľ����
    void GetNodeFamilyDate(TreeNode *node, char nodeDate);        //��ȡ���ļ�ͥ��Ա��Ϣ
    void SwopLR(TreeNode *node);                                  //����������ÿ���������Һ��ӽ���ֵ                                 
    TreeNode * GetBaseNode(void);                                 //���ظ����
};

BinaryTree::BinaryTree(){
    baseNode = NULL;
}

BinaryTree::BinaryTree(TreeNode *node){
    baseNode = node;
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

void BinaryTree::InorderTaversal(TreeNode *node){
    if (node!=NULL){
        PreorderTraversal(node->pleft);
        cout << node->date << endl;
        PreorderTraversal(node->pright);
    }
}

void BinaryTree::PostorderTraversal(TreeNode *node){
    if (node!=NULL){
        PreorderTraversal(node->pleft);
        PreorderTraversal(node->pright);
        cout << node->date << endl;
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

static int leavNodeNum = 0; 
void BinaryTree::GetLeafNode(TreeNode *node){
    if (node != NULL){
        if (node->pleft == NULL && node->pright == NULL){
            leavNodeNum++;
        }
        GetLeafNode(node->pleft);
        GetLeafNode(node->pright);
    }
}

static int twoDegreeNodeNum = 0;
void BinaryTree::GetTwoDegreeNode(TreeNode *node){
    if (node != NULL){
        if (node->pleft != NULL && node->pright != NULL){
            twoDegreeNodeNum++;
        }
        GetTwoDegreeNode(node->pleft);
        GetTwoDegreeNode(node->pright);
    }
}

void BinaryTree::GetDateLevel(TreeNode *node, char nodeDate, int level, bool &flag){
    if (node != NULL){
        if (node->date == nodeDate){
            cout << "��Ԫ�������еĲ��Ϊ��" << level+1 << endl;
            flag = true;
        }
        GetDateLevel(node->pleft, nodeDate, level+1, flag);
        GetDateLevel(node->pright, nodeDate, level+1, flag);
    }
}

void BinaryTree::LevelTraversal2(TreeNode *node){
    TreeNode *p = node;
    if (p){
        myqueue.push(p);
    }
    while(!myqueue.empty()){
        p = myqueue.front();
        myqueue.pop();
        cout << p->date << endl;
        if (p->pleft){
            myqueue.push(p->pleft);
        }
        if (p->pright){
            myqueue.push(p->pright);
        }
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

void BinaryTree::SwopLR(TreeNode *node){
    if (node != NULL){
        SwopLR(node->pleft);
        SwopLR(node->pright);
        TreeNode *ptemp;
        ptemp = node->pleft;
        node->pleft = node->pright;
        node->pright = ptemp;
    }
}

void TurnArray(TreeNode **node , ArrayTree *a_node, int index){
    if (index <= a_node->nodeNum){
        int left = a_node->binaryTree[index].pleft;
        int right = a_node->binaryTree[index].right;
        *node = new TreeNode;
        (*node)->date = a_node->binaryTree[index].date;
        (*node)->pleft =NULL;
        (*node)->pright = NULL;
        if (a_node->binaryTree[left].date != '#')
        TurnArray(&((*node)->pleft), a_node, left);
        if (a_node->binaryTree[right].date != '#')
        TurnArray(&((*node)->pright), a_node, right);
    }
}

void Menu(void){
    cout << "<1>��ӡ�������������ֱ�����" << endl;
    cout << "<2>����㷨�������������������и�����ֵ��������Ӧ�Ĳ����" << endl;
    cout << "<3>��������ĸ߶�" << endl;
    cout << "<4>��������Ľ����" << endl;
    cout << "<5>���������Ҷ�ӽ����" << endl;
    cout << "<6>��������Ķ�Ϊ2�Ľ����" << endl;
    cout << "<7>��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��" <<
            "������ʱ������Ӧ��ʾ��Ϣ�����ֵܽ��ͺ��ӽ�㣬" <<
            "����ʱҪ��ȷָ�������ֵܡ����ӡ����ֵܻ��Һ���" << endl;
    cout << "<8>��������һ��Ԫ��x�����������еĲ�Ρ�������ʱ������Ӧ��ʾ��Ϣ" << endl;
    cout << "<9>����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ����������Ҫ��չΪ��ȫ����������" << endl;
    cout << "<10>������������ÿ���������Һ���ָ���ֵ����������������Ϊ����������������Ϊ��������" << endl;
    cout << "<11>�������������" << endl;
    cout << "(����-1�˳�����)" << endl;
}

int main(void){
    char s[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '#', '#', '#', '#', '#', '#', '#', '#'};
    BinaryTree myTree;
    bool flag = false;
    ArrayTree *myArrayTree = new ArrayTree(s, 16);
    TreeNode *node;
    TurnArray(&node, myArrayTree, 1);
    BinaryTree testTree(node);
    myTree.CreateTree();
    while(1){
        Menu();
        int testNum;
        cout << "��������ţ�" << endl;
        cin >> testNum;
        switch (testNum){
            case 1: cout << "���������" << endl;
                    myTree.PreorderTraversal(myTree.GetBaseNode());
                    cout << "�������:" << endl;
                    myTree.InorderTaversal(myTree.GetBaseNode());
                    cout << "�������:" << endl;
                    myTree.PostorderTraversal(myTree.GetBaseNode());
                    system("pause");
                    break;
            case 2: myTree.PutDateAndLevel(myTree.GetBaseNode());
                    system("pause");
                    break;
            case 3: cout << "�˶������ĸ߶�Ϊ��" << myTree.GetTreeHeight(myTree.GetBaseNode()) << endl;
                    system("pause");
                    break;
            case 4: cout << "�˶������Ľ�����Ϊ��" << myTree.GetNodeNum(myTree.GetBaseNode()) << endl;
                    system("pause");
                    break;
            case 5: myTree.GetLeafNode(myTree.GetBaseNode());
                    cout << "��������Ҷ�ӽ�����Ϊ��" << leavNodeNum << endl;
                    system("pause");
                    break;
            case 6: myTree.GetTwoDegreeNode(myTree.GetBaseNode());
                    cout << "�˶�������Ϊ2�Ľ�����Ϊ��" << twoDegreeNodeNum << endl;
                    system("pause");
                    break;
            case 7: char element;
                    cout << "��������Ҫ���ҵ�Ԫ�أ�";
                    cin >> element;
                    myTree.GetNodeFamilyDate(myTree.GetBaseNode(), element);
                    system("pause");
                    break;
            case 8: char date;
                    cout << "��������Ҫ���ҵ�Ԫ�أ�";
                    cin >> date;
                    myTree.GetDateLevel(myTree.GetBaseNode(), date, 0, flag);
                    if (!flag){
                        cout << "�˶��������޴�Ԫ��" << endl;
                    }
                    system("pause");
                    break;
            case 9: testTree.PreorderTraversal(testTree.GetBaseNode());
                    system("pause");
                    break;
            case 10:cout << "�������������ڵ����Һ��ӽ��ָ��ǰ(�������)��" << endl;
                    myTree.PreorderTraversal(myTree.GetBaseNode());
                    myTree.SwopLR(myTree.GetBaseNode());
                    cout << "�������������ڵ����Һ��ӽ��ָ���(�������):" << endl;
                    myTree.PreorderTraversal(myTree.GetBaseNode());
                    system("pause");
                    break;
            case 11:myTree.LevelTraversal2(myTree.GetBaseNode());
                    system("pause");
                    break;
            default:
                    return -1;
        }
        system("cls");

    }
    return 0;
}
