//������������ʵ�֣�����
#include <iostream>
using namespace std;
typedef char Date;
//����
struct TreeNode{
    Date treedate;
    int ltag;       //ǰ����־
    int rtag;       //��̱�־
    struct TreeNode *plchild;   //��������ltagΪ1ʱ��Ϊǰ����
    struct TreeNode *prchild;   //��������rtagΪ1ʱ��Ϊ��̣�
};

typedef struct TreeNode TreeNode;

enum Thread{link, thread};      //ö��������ʶ��ֵ

//�����������Ľ��
class ThreadBinaryTree{
private:
    TreeNode *headNode;     //ͷ���
    TreeNode *BaseNode;     //�����
    TreeNode *preNode;      //����ָ��ǰ����ǰ��(����)
public:
    ThreadBinaryTree();                     //��ʼ����
    TreeNode *GetBaseNode();                //��ȡ�����
    void CreateTree(TreeNode *&Node);       //����������
    void TravelTree(TreeNode *Node);        //�������������(�ǵݹ�)
    void ThreadingTree(TreeNode *&Node);    //������������
    void ImproveThrTree(TreeNode *&Node);   //�Ľ�����������,������ͷ���
};

ThreadBinaryTree::ThreadBinaryTree(){
    BaseNode = NULL;
    preNode = NULL;
}

TreeNode* ThreadBinaryTree::GetBaseNode(){
    return BaseNode;
}

void ThreadBinaryTree::CreateTree(TreeNode *&Node){
   char chDate;
   cin >> chDate;
   if (chDate == '#'){
       return;
   }
   Node = new TreeNode;
   Node->treedate = chDate;
   Node->plchild = NULL;
   Node->prchild = NULL;
   Node->ltag = 0;
   Node->rtag = 0;
   CreateTree(Node->plchild);
   CreateTree(Node->prchild);
}

void ThreadBinaryTree::ThreadingTree(TreeNode *&Node){
    if (Node){
        ThreadingTree(Node->plchild);   //������������
        if (!Node->plchild){
            //�����ǰ����������Ϊ��,����plchildָ��ǰ���ǰ��
            Node->ltag = 1;
            Node->plchild = preNode;
        }
        if(!preNode->prchild){
            //�����ǰ����ǰһ������������Ϊ�գ�������prchildָ��ǰ���
            preNode->rtag = 1;
            preNode->prchild = Node;
        }
        preNode = Node;
        ThreadingTree(Node->prchild);   //������������
    }
}

void ThreadBinaryTree::ImproveThrTree(TreeNode *&Node){
    //��ʼ��ͷ���
    headNode = new TreeNode;    
    headNode->ltag = 0;
    headNode->rtag = 1;
    
    //��ͷ�������ڵ㣬��������ĵ�һ����㣬���һ����㣬��������
    if (!Node) {
        headNode->plchild = headNode;
        headNode->prchild = headNode;
    }
    else {
        preNode = headNode;
        headNode->plchild = Node;
        ThreadingTree(Node);
        preNode->rtag = 1;
        preNode->prchild = headNode;
        headNode->prchild = preNode;
    }

    //������㸳ֵ
    BaseNode = Node;
}

void ThreadBinaryTree::TravelTree(TreeNode *Node){
    TreeNode *tempNode = Node;
    while(tempNode != headNode){

        while(tempNode->ltag != 1){
            //������ǰ���ĵ�һ�����(����)
            tempNode = tempNode->plchild;
        }
        cout << tempNode->treedate << endl;

        //������̽��
        //�����̽��Ҳ�к�̽�㣬���ɰ��˷����
        //ֱ���޺�̽��Ϊֹ
        while(tempNode->rtag == 1 && tempNode->prchild != headNode){
            tempNode = tempNode->prchild;
            cout << tempNode->treedate << endl;
        }

        //���޺�̽�㣬���������������ĵ�һ�����
        tempNode = tempNode->prchild;
    }
}

int main(void){
    ThreadBinaryTree testTree;
    TreeNode *p = testTree.GetBaseNode();
    testTree.CreateTree(p);
    testTree.ImproveThrTree(p);
    testTree.TravelTree(testTree.GetBaseNode());
    return 0;
}
