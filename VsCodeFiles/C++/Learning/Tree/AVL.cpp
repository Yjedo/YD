#include <iostream>
#include <stack>
#include <vector>
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
            //��min����������Ϊ�գ����轫min��ǰ��������ӵ�min��������
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
        cout << "ll";
        tempNode = llTurn(tempNode, p);
    }
    else if (tempNode->balanceIndex > 1 && tempNode->pleft->balanceIndex < 0){
        cout << "lr";
        tempNode = lrurn(tempNode, p);
    }
    else if (tempNode->balanceIndex < -1 && tempNode->pright->balanceIndex >= 0){
        cout << "rl";
        tempNode = rlTurn(tempNode, p);
    }
    else if (tempNode->balanceIndex < -1 && tempNode->pright->balanceIndex < 0){
        cout << "rr";
        tempNode = rrTurn(tempNode, p);
    }
    else {}

    return tempNode;
}


void AVL::createAVL(vector<int> array){
    stack<AVLNode*> nodeStack;
    for(int i = 0; i < array.size(); i++){
        root = insertNode(array[i], root, nodeStack);
    }
}

int main(void){
    AVL T;
    vector<int> array = {3, 1, 2, 4, 7, 5, 9, 11, 8};
    T.createAVL(array);
    T.inorderTravel(T.getRoot());
    cout << "_______________________" << endl;
    T.deleteNode(5);
    T.deleteNode(8);
    T.inorderTravel(T.getRoot());
    return 0;
}