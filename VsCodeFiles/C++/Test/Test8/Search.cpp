#include <iostream>
#include <stack>
#include <vector>
#include <vector>
#include <queue>
using namespace std;

//AVL���
typedef struct AVLNode{
    //����
    int data;
    //ƽ������(�����������߶Ȳ�)
    int balanceIndex;
    struct AVLNode *pleft;
    struct AVLNode *pright;
    
    /**
     * @brief Ĭ�Ͻ�㹹��
     **/
    AVLNode(){
        data = -1;
        balanceIndex = 0;
        pleft = NULL;
        pright = NULL;
    }

}AVLNode;

//AVL��
class AVL{
private:
    //�����
    AVLNode *root;
public:
    //LL����ת(��ĳ�������ӵ��������ϲ������½�㣬���¸ýڵ�ʧ��)
    AVLNode* llTurn(AVLNode *&node, AVLNode *&parent);
    //RR����ת(��ĳ�����Һ��ӵ��������ϲ������½�㣬���¸ýڵ�ʧ��)
    AVLNode* rrTurn(AVLNode *&node, AVLNode *&parent);
    //LR����ת(��ĳ�������ӵ��������ϲ������½�㣬���¸ýڵ�ʧ��)
    AVLNode* lrurn(AVLNode *&node, AVLNode *&parent);
    //RL����ת(��ĳ�����Һ��ӵ��������ϲ������½�㣬���¸ýڵ�ʧ��)
    AVLNode* rlTurn(AVLNode *&node, AVLNode *&parent);
    //������Ԫ��
    AVLNode* insertNode(int newData, AVLNode *&baseNode, stack<AVLNode*> &nodeStack);
    //ɾ�����
    void deleteNode(int deleteElement);
    //�������
    void inorderTravel(AVLNode *baseNode);
    //�������
    void levelTravel(AVLNode *baseNode);
    //����һ��ƽ�������
    void createAVL(vector<int> array);
    //����ƽ������
    void updateBI(AVLNode *node);
    //��ȡ�������߶�
    int getHeight(AVLNode *node);
    //��ȡ�����
    AVLNode* getRoot();
    //��ʼ��AVL��
    AVL(){root = NULL;};
};

/**
 * @param node LL��ʧ����
 * @param parent ʧ���ĸ��ڵ�
 * @return ��ת����ԭʧ���λ�õĽ��
 **/
AVLNode* AVL::llTurn(AVLNode *&node, AVLNode *&parent){
    //LL����ת�õ����½��Ϊʧ��������
    AVLNode *newBaseNode = node->pleft;
    //��ʱ�������洢�½��ԭ�Һ���
    AVLNode *tempNode = newBaseNode->pright;
    //ʧ�����Ϊ�½����µ��Һ���
    newBaseNode->pright = node;
    //�½���ԭ�Һ�����Ϊʧ��������;
    node->pleft = tempNode;

    //�����������������仯�Ľ��
    updateBI(newBaseNode);
    updateBI(newBaseNode->pright);

    if (!parent){
        //��parentΪ��ֱ�ӷ��أ���������
        return newBaseNode;
    }

    //����parent���½��
    if (parent->pleft == node){
        parent->pleft = newBaseNode;
    }
    else{
        parent->pright = newBaseNode;
    }

    return newBaseNode;
}

/**
 * @param node RR��ʧ����
 * @param parent ʧ���ĸ��ڵ�
 * @return ��ת����ԭʧ���λ�õĽ��
 **/
AVLNode* AVL::rrTurn(AVLNode *&node, AVLNode *&parent){
    //RR����ת�õ����½��Ϊʧ�����Һ���
    AVLNode *newBaseNode = node->pright;
    //��ʱ�������洢�½��ԭ����
    AVLNode *tempNode = newBaseNode->pleft;
    //ʧ�����Ϊ�½����µ�����
    newBaseNode->pleft = node;
    //�½���ԭ������Ϊʧ�����Һ���;
    node->pright = tempNode;

    //�����������������仯�Ľ��
    updateBI(newBaseNode);
    updateBI(newBaseNode->pleft);

    if (!parent){
        //��parentΪ��ֱ�ӷ��أ���������
        return newBaseNode;
    }

    //����parent���½��
    if (parent->pleft == node){
        parent->pleft = newBaseNode;
    }
    else{
        parent->pright = newBaseNode;
    }

    return newBaseNode;

}

/**
 * @param node LR��ʧ����
 * @param parent ʧ���ĸ��ڵ�
 * @return ��ת����ԭʧ���λ�õĽ��
 **/
AVLNode* AVL::lrurn(AVLNode *&node, AVLNode* &parent){
    node->pleft = rrTurn(node->pleft, node);
    node = llTurn(node, parent);
    return node;
}

/**
 * @param node RL��ʧ����
 * @param parent ʧ���ĸ��ڵ�
 * @return ��ת����ԭʧ���λ�õĽ��
 **/
AVLNode* AVL::rlTurn(AVLNode *&node, AVLNode* &parent){
    node->pright = llTurn(node->pright, node);
    node = rrTurn(node, parent);
    return node;
}

/**
 * @param �������������仯�Ľ�� 
 **/
void AVL::updateBI(AVLNode *node){
    if (node){
        node->balanceIndex = getHeight(node->pleft) - getHeight(node->pright);
    } 
}

/**
 * @param �Դ˽ڵ���Ϊ���ڵ�Ķ������ĸ߶�
 **/
int AVL::getHeight(AVLNode *node){
    if (node){
        //��ȡ�������߶�
        int leftHeight = getHeight(node->pleft);
        //��ȡ�������߶�
        int rightHeigt = getHeight(node->pright);
        //ȡ�����нϴ�ĸ߶�
        int max = leftHeight > rightHeigt ? leftHeight : rightHeigt;
        //��˶������߶�Ϊmax + 1
        return max + 1;
    }
    else{
        //nodeΪ��
        return 0;
    }
}

/**
 * @brief ɾ��AVL��������ΪdeleteElement�Ľ��
 * @param deleteElemetn ��ɾ����������
 **/
void AVL::deleteNode(int deleteElement){
    //�洢���ʹ��Ľ�㣬�Ա��ҵ����ڵ�����С��ƽ���
    stack<AVLNode *> nodeStack;
    //��ʼ��pΪ�����
    AVLNode *p = root;

    while(p){
        //������ɾ�����
        nodeStack.push(p);
        if (p->data == deleteElement){
            break;
        }
        else if(p->data > deleteElement){
            p = p->pleft;
        }
        else{
            p = p->pright;
        }
    }

    if (!p){
        cout << "�޴�Ԫ�أ�ɾ��ʧ�ܣ�" << endl;
        return;
    }

    if (p->pleft && p->pright){
        //����ɾ��������������Բ�Ϊ��
        AVLNode *min = p->pright;
        while(min->pleft){
            //�����������������ϵ���С���
            nodeStack.push(min);
            min = min->pleft;
        }
        //��������������С������ݸ���p������
        p->data = min->data;
        
        //ɾ��min;
        if (min->pright){
            //��min����������Ϊ�գ������С���min��ǰ��������ӵ�min��������
           if (nodeStack.top() == p){
               //��min��ǰ�����Ϊp,��minӦΪp���Һ���
               p->pright = min->pright;
           }
           else{
               //����ӦΪ��ǰ����������
               AVLNode *temp = nodeStack.top();
               temp->pleft = min->pright;
           }
        }
        else{
            //��min���Һ���Ϊ�գ����Ӧ�ҵ�����Ӧ��ǰ����㣬����ǰ���������ӻ��Һ����ÿ�
            if (nodeStack.top() == p){
               p->pright = NULL;
            }
            else{
               AVLNode *temp = nodeStack.top();
               temp->pleft = NULL;
            }
        }
        //�ͷ�min
        delete min;
    }
    else{
        nodeStack.pop();
        AVLNode *pr = nodeStack.top();
        if (!p->pleft){
            if (pr->pleft == p){
                pr->pleft = p->pright;
            }
            else{
                pr->pright = p->pright;
            }
        }
        else{
            if (pr->pleft == p){
                pr->pleft = p->pleft;
            }
            else{
                pr->pright = p->pleft;
            }
        }
        delete p;
        p = NULL;
    }

    AVLNode *q, *parent;
    while(!nodeStack.empty()){
        q = nodeStack.top();
        nodeStack.pop();
        if (!nodeStack.empty()){
            parent = nodeStack.top();
        }
        else{
            parent = NULL;
        }

        updateBI(q);//����ƽ������
        
        //����ƽ��
        if (q->balanceIndex > 1 && q->pleft->balanceIndex >= 0){
            cout << "ll";
            q = llTurn(q, parent);
        }
        else if (q->balanceIndex > 1 && q->pleft->balanceIndex < 0){
            cout << "lr";
            q = lrurn(q, parent);
        }
        else if (q->balanceIndex < -1 && q->pright->balanceIndex >= 0){
            cout << "rl";
            q = rlTurn(q, parent);
        }
        else if (q->balanceIndex < -1 && q->pright->balanceIndex < 0){
            cout << "rr";
            q = rrTurn(q, parent);
        }
        else {}
    }
}

/**
 * @param ���������ƽ�������
 **/ 
void AVL::inorderTravel(AVLNode *node){
    if (node){
        inorderTravel(node->pleft);
        cout << "���ݣ�" << node->data << " ƽ�����ӣ�" << node->balanceIndex << endl;
        inorderTravel(node->pright);  
    }
}

void AVL::levelTravel(AVLNode *node){
   if (node != NULL){
        queue<AVLNode*> myqueue;
        vector<AVLNode *> tempArray;
        AVLNode *tempNode;
        if(node){
            myqueue.push(node);
        }
        while(!myqueue.empty()){
            while(!myqueue.empty()){
                tempNode = myqueue.front();
                myqueue.pop();
                cout << tempNode->data << "  ";
                if (tempNode->pleft){
                    tempArray.push_back(tempNode->pleft);
                }
                if (tempNode->pright){
                    tempArray.push_back(tempNode->pright);
                }
            }
            cout << endl;
            for(int i = 0; i < tempArray.size(); i++){
                myqueue.push(tempArray[i]);
            }

            while(!tempArray.empty()){
                tempArray.pop_back();
            }
        }
        cout << endl;
    }
}

AVLNode* AVL::getRoot(){
    return root;
}

AVLNode* AVL::insertNode(int newData, AVLNode *&baseNode, stack<AVLNode*> &nodeStack){
    if (!baseNode){
        baseNode = new AVLNode;
        baseNode->data = newData;
    }
    else{
        nodeStack.push(baseNode);
        if (newData < baseNode->data){
            baseNode = insertNode(newData, baseNode->pleft, nodeStack);
        }else if (newData > baseNode->data){
           baseNode = insertNode(newData, baseNode->pright, nodeStack);
        }
        else{
            cout << "ƽ��������в��ܴ��ڼ�ֵ��ͬ�Ľ�㡣" << endl;
            return NULL;
        } 
    }
    
    //��ʱ�������洢��ǰbaseNode�ĸ��ڵ�
    AVLNode *tempNode;
    if (!nodeStack.empty()){
        tempNode = nodeStack.top();
        updateBI(tempNode);
        nodeStack.pop();
    }
    else{
        //��ջΪ��˵����ǰ������Ǹ����
        return baseNode;
    }

    AVLNode *p;
    if(!nodeStack.empty()){
        p = nodeStack.top();
    }
    else{
        p = NULL;
    }

    if (tempNode->balanceIndex > 1 && tempNode->pleft->balanceIndex >= 0){
        cout << "���� ";
        tempNode = llTurn(tempNode, p);
    }
    else if (tempNode->balanceIndex > 1 && tempNode->pleft->balanceIndex < 0){
        cout << "������ ";
        tempNode = lrurn(tempNode, p);
    }
    else if (tempNode->balanceIndex < -1 && tempNode->pright->balanceIndex >= 0){
        cout << "������ ";
        tempNode = rlTurn(tempNode, p);
    }
    else if (tempNode->balanceIndex < -1 && tempNode->pright->balanceIndex < 0){
        cout << "���� ";
        tempNode = rrTurn(tempNode, p);
    }
    else {}

    return tempNode;
}

void AVL::createAVL(vector<int> array){
    cout << "�����飺";
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << "����������"<<endl;
    stack<AVLNode*> nodeStack;
    for(int i = 0; i < array.size(); i++){
        cout << "����" << array[i];
        root = insertNode(array[i], root, nodeStack);
        cout << endl;
    }
}

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
        cout << "���ֲ���λ�ã�����" << newdata << "\n\n";
        node = new Node;
        node->data = newdata;
        node->pleft = NULL;
        node->pright = NULL;
    }
    else{
        if (newdata < node->data){
            cout << "������Ԫ��" << newdata << " < " << "��ǰ���Ԫ��" << node->data << "   �ڴ˽��������Ѱ�Ҳ���λ��\n";
            InsertNode(node->pleft, newdata);
        }else if (newdata > node->data){
            cout << "����Ԫ��" << newdata << " > " << "��ǰ���Ԫ��" << node->data << "   �ڴ˽��������Ѱ�Ҳ���λ��\n";
            InsertNode(node->pright, newdata);
        }
        else{
            cout << "����������в��ܴ��ڼ�ֵ��ͬ�Ľ�㡣" << endl;
            return;
        } 
    }
}

void BinarySearchTree::CreateBST(vector<int> dataArray){
    cout << "������: {";
    for(int i = 0; i < dataArray.size(); i++){
        cout << dataArray[i] << " ";
    }
    cout << "}��������������\n";
    cout << "\n�˶���������Ϊ��" << endl;
    for(int i = 0; i < dataArray.size(); i++){
        InsertNode(baseNode, dataArray[i]);
    }
    cout << "������ɣ�" << endl;
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
        vector<Node *> tempArray;
        Node *tempNode;
        if(node){
            myqueue.push(node);
        }
        while(!myqueue.empty()){
            while(!myqueue.empty()){
                tempNode = myqueue.front();
                myqueue.pop();
                cout << tempNode->data << "  ";
                if (tempNode->pleft){
                    tempArray.push_back(tempNode->pleft);
                }
                if (tempNode->pright){
                    tempArray.push_back(tempNode->pright);
                }
            }
            cout << endl;
            for(int i = 0; i < tempArray.size(); i++){
                myqueue.push(tempArray[i]);
            }

            while(!tempArray.empty()){
                tempArray.pop_back();
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

bool BinarySearch(vector<int> array, int searchData){
    //array��Ԫ�ذ���������
    int high = array.size() - 1;
    int low = 0;
    int mid;
    cout << "��array[0]��array[" << high << "]�в���" << endl;
    while(high >= low){
        mid = (high + low) / 2;
        if (array[mid] == searchData){
            cout << array[mid] << " = " << searchData;
            cout << "���ҳɹ���" << endl;
            return true;
        }
        else if (array[mid] > searchData){
            cout << array[mid] << " > " << searchData;
            cout << "\t��array[" << low << "]��array[" << mid-1 << "]����" << endl;
            high = mid - 1;
        }
        else{
            cout << array[mid] << " < " << searchData;
            cout << "\t��array[" << mid + 1 << "]��array[" << high << "]" << endl;
            low = mid + 1;
        }
    }
    cout << "����ʧ�ܣ�" << endl;
    return false;
}

void test1(vector<int> array){
    cout << "����Ԫ�أ�";
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
    int element;
    char flag = 'Y';
    while(flag == 'Y'){
        cout << "��������Ҫ���ҵ�Ԫ�أ�";
        cin >> element;
        BinarySearch(array, element);
        cout << "�Ƿ����(Y/N): ";
        cin >> flag;
    }
}

void Menu(void){
    cout << "-------------------------------------------\n";
    cout << "1.���ö��ֲ����㷨�����������" << endl;
    cout << "2.��������������" << endl;
    cout << "3.�ڶ����������ֲ��ҽ��" << endl; 
    cout << "4.�ڶ�����������ɾ�����" << endl;
    cout << "5.����һ��ƽ��Ķ���������" << endl;
    cout << "ע������-1�˳�����"<< endl;
    cout << "-------------------------------------------\n";
}

int main(void){
    vector<int> array1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> array2 ={5, 3, 7, 2, 4, 8, 9, 6};
    vector<int> array3 ={1, 3,9, 2, 7, 5, 4};
    vector<int> array4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                          14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    BinarySearchTree bst;
    AVL a;
    int t;
    while(1){
        Menu();
        cout << "��������ţ�";
        cin >> t;
        switch (t)
        {
        case 1:
            test1(array1);
            system("pause");
            break;

        case 2:
           bst.CreateBST(array2);
           bst.InorderTaversal(bst.GetBaseNode());
           cout << endl;
           bst.LevelTaversal(bst.GetBaseNode());
           system("pause");
           break;

        case 3:
            int n;
            bst.CreateBST(array2);
            cout << "������������" << endl;
            bst.LevelTaversal(bst.GetBaseNode());
            cout << "���������Ԫ�أ�";
            cin >> n;
            bst.SearchNode(n);
            system("pause");
            break;
        case 4:
            int x;
            bst.CreateBST(array2);
            cout << "������������" << endl;
            bst.LevelTaversal(bst.GetBaseNode());
            cout << "������Ҫɾ��Ԫ�أ�";
            cin >> x;
            bst.DeleteNode(x);
            cout << "ɾ��Ԫ��" << x << "��Ķ�����������" << endl;
            bst.LevelTaversal(bst.GetBaseNode());
            system("pause");
            break;
        case 5:
            a.createAVL(array4);
            cout << "ƽ�������(����)��" << endl;
            a.inorderTravel(a.getRoot());
            cout << "ƽ�������(����)��" << endl;
            a.levelTravel(a.getRoot());
            system("pause");
            break;
        default:
            return 0;
        }

        system("cls");
    }
}