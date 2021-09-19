#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

/*
����������
���ص����£���xΪ����������е�һ����㣬
x�ڵ�����ؼ���key��һ�仰�������ӱȸ��ڵ�С��
�Һ��ӱȸ��ڵ�󣬻���һ�����Ծ��ǡ���������������ý������
������ڵ�����������գ��������������н���ֵ��С�����ĸ�����ֵ��
����ڵ�����������գ��������������н���ֵ���������ĸ�����ֵ��
����ڵ����������Ҳ�ֱ�Ϊ�����������
û�м�ֵ��ȵĽڵ㡣
*/

//������ݹ���
typedef struct Node{
    int data;
    Node *pleft;
    Node *pright;
}Node;

//BST��
class BinarySearchTree{
private:
    Node *baseNode;
public:
 BinarySearchTree();
 Node* GetBaseNode(void);
 void SearchNode(int searchElement);
 void InorderTaversal(Node *node);
 void LevelTaversal(Node *node);
 void InsertNode(Node *&node, int newdata);
 void DeleteNode(int deleteElement);
 void CreateBST(vector<int> dataArray); 
};

BinarySearchTree::BinarySearchTree(void){
    baseNode = NULL;
}

Node* BinarySearchTree::GetBaseNode(void){
    return baseNode;
}

void BinarySearchTree::InsertNode(Node *&node, int newdata){
    if (!node){
        node = new Node;
        node->data = newdata;
        node->pleft = NULL;
        node->pright = NULL;
    }
    else{
        if (newdata < node->data){
            InsertNode(node->pleft, newdata);
        }else if (newdata > node->data){
            InsertNode(node->pright, newdata);
        }
        else{
            cout << "����������в��ܴ��ڼ�ֵ��ͬ�Ľ�㡣" << endl;
            return;
        } 
    }
}

void BinarySearchTree::CreateBST(vector<int> dataArray){
    for(int i = 0; i < dataArray.size(); i++){
        InsertNode(baseNode, dataArray[i]);
    }
}

void BinarySearchTree::InorderTaversal(Node* node){
    if (node){
        InorderTaversal(node->pleft);
        cout << node->data << " ";
        InorderTaversal(node->pright);
    }
}

void BinarySearchTree::LevelTaversal(Node *node){
    if (node != NULL){
        queue<Node*> myqueue;
        Node *tempNode;
        if(node){
            myqueue.push(node);
        }
        while(!myqueue.empty()){
            tempNode = myqueue.front();
            myqueue.pop();
            cout << tempNode->data << " ";
            if (tempNode->pleft){
                myqueue.push(tempNode->pleft);
            }
            if (tempNode->pright){
                myqueue.push(tempNode->pright);
            }
        }
        cout << endl;
    }
}

void BinarySearchTree::DeleteNode(int deleteElement){
    Node *deleteNode = baseNode; //��ʼ��ɾ�����Ϊ�����(��ʱ)
    Node *p = NULL;              //��ʱ�������洢deleteNode�ĸ��ڵ�

    //������ɾ�����
    while(deleteNode != NULL){
        if (deleteNode->data == deleteElement){
            //�ҵ����˳�
            break;
        }
        else{
            p = deleteNode;
            if (deleteElement > deleteNode->data){
                deleteNode = deleteNode->pright;
            }
            else{
                 deleteNode = deleteNode->pleft;
            }
        }
    }

    if (deleteNode == NULL){
        //����ʧ�ܣ��˳�
        cout << "�˶������������޴˽�㣬����ʧ�ܣ�" << endl;
        return;
    }

    if (deleteNode->pleft != NULL && deleteNode->pright != NULL){
        //����ɾ�����������ӽڵ㶼��Ϊ��
        //��������ɾ�����ĺ�̽��
        //��֮���Ǵ�ɾ����㣬Ȼ��ɾ��ԭ��̽�㼴��
        Node *next = deleteNode->pright;
        Node *ptemp = deleteNode;
        while(next->pleft != NULL){
            ptemp = next;
            next = next->pleft;
        }
        deleteNode->data = next->data;
        p = ptemp;
        deleteNode = next;
    }

    bool flag = false;
    if (p->pleft == deleteNode){
        flag = true;
    }

    if (deleteNode->pleft != NULL){
        if (flag){
            p->pleft = deleteNode->pleft;
        }
        else{
            p->pright = deleteNode->pleft;
        }
    }
    else{
         if (flag){
            p->pleft = deleteNode->pright;
        }
        else{
            p->pright = deleteNode->pright;
        }
    }
    
    cout << "ɾ���ɹ���" << endl;
}

void BinarySearchTree::SearchNode(int searchElement){
    Node *p = baseNode;
    while(p != NULL){
        if (p->data == searchElement){
            cout << searchElement << " = " << p->data;
            cout << "   ���ҳɹ���" << endl;
            break;
        }
        else if (p->data > searchElement){
            cout << searchElement << " < " << p->data;
            cout << "   ���ҵ�ǰ����������" << endl;
            p = p->pleft;
        }
        else{
            cout << searchElement << " > " << p->data;
            cout << "   ���ҵ�ǰ����������" << endl;
            p = p->pright;
        }  
    }
    if (!p){
        cout << "�޴�Ԫ�أ�����ʧ�ܣ�" << endl;
    }
}

int main(void){
    vector<int> testArray ={5, 3, 7, 2, 4, 8, 9, 6};
    BinarySearchTree testTree;
    testTree.CreateBST(testArray);
    cout << "���������";
    testTree.InorderTaversal(testTree.GetBaseNode());
    cout << "\n���������";
    testTree.LevelTaversal(testTree.GetBaseNode());
    cout << "------------------------------------------\n";
    // testTree.DeleteNode(5);
    // cout << "���������";
    // testTree.InorderTaversal(testTree.GetBaseNode());
    // cout << "\n���������";
    // testTree.LevelTaversal(testTree.GetBaseNode());
    int temp;
    cout << "���������Ԫ�أ�";
    cin >> temp;
    testTree.SearchNode(temp);
    return 0;
}