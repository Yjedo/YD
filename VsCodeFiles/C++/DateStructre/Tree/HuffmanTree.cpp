#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <string>
using namespace std;

/*
·����
��һ�����У���һ���ڵ����µ���һ�����֮���ͨ·
��Ϊ·����ͨ·�з�֧����Ŀ��Ϊ·�����ȡ�

��������Ȩ·������(WPL)��
�����������n��Ҷ�ӽڵ㣬��ôÿ��Ҷ�ӽڵ㵽���ڵ��·�����ȳ���
����Ҷ�ӽ�������Ȩֵ�ĺͼ�Ϊ�������Ĵ�Ȩ·�����ȡ�

�����������ɸ�����ӵ�й̶�Ȩֵ��Ҷ�ӽڵ㹹�����һ�ö�����
�˶�������WPLֵ��С
*/
class HuffmanTree{
private:
    int weight;             //Ȩֵ
    string HuffmanCode;     //����������
    HuffmanTree *lchild;
    HuffmanTree *rchild;
public:
    HuffmanTree(int the_weight, HuffmanTree *left = NULL, HuffmanTree *right = NULL);   //�Թ����������������ݸ�ֵ
    HuffmanTree*  CreateHFTree(int *w, int w_size);    //�����������ݵõ�һ�ù��������ĸ����
    int GetWeight(void);                                //���ؽ��Ȩֵ
    void GetHFCode(HuffmanTree *node, string & s);                  //��ȡ����������
    void PrintHFCode(HuffmanTree *node);
};

HuffmanTree::HuffmanTree(int the_weight, HuffmanTree *left, HuffmanTree *right){
    weight = the_weight;
    lchild = left;
    rchild = right;
}

int HuffmanTree::GetWeight(void){
    return weight;
}

void HuffmanTree::GetHFCode(HuffmanTree *node, string & s){
    if(node != NULL){
        node->HuffmanCode = s;
        if (node->lchild != NULL)
        GetHFCode(node->lchild, s.append("0"));
        if (node->rchild != NULL)
        GetHFCode(node->rchild, s.append("1"));
        s.pop_back();
    }
}

void HuffmanTree::PrintHFCode(HuffmanTree *node){
    if (node != NULL){
        cout << node->HuffmanCode << endl;
        cout << node->lchild->HuffmanCode << endl;
        cout << node->rchild->HuffmanCode << endl;
        // PrintHFCode(node->lchild);
        // PrintHFCode(node->rchild);
    }    
}

//�Զ������ȶ������ȼ�(ȨֵС������)
struct cmp{
    bool operator() (HuffmanTree* node1, HuffmanTree* node2){
		return node1->GetWeight()>node2->GetWeight();
	}
};

HuffmanTree* HuffmanTree::CreateHFTree(int *w, int w_size){
    //�������ȶ���
    priority_queue<HuffmanTree*, vector<HuffmanTree*>, cmp> Q;
    //����1��Ԫ������   ����2����������     ����3�����ȼ��趨
    for(int i = 0; i < w_size; i++){
       HuffmanTree *t =  new HuffmanTree(w[i]);
       Q.push(t);
    }
    while(Q.size() != 1){
        HuffmanTree* left = Q.top();
	    Q.pop();
		HuffmanTree* right = Q.top();
		Q.pop();
		HuffmanTree* root = new HuffmanTree(left->GetWeight()+right->GetWeight(), left, right);
        Q.push(root);
    }
    HuffmanTree *root = Q.top();
	Q.pop();
	return root;		
}

int main(void){
    int array[10] = {1, 4};
    static string str = "0";
    HuffmanTree test(0);
    HuffmanTree *hft = test.CreateHFTree(array, 2);
    test.GetHFCode(hft, str);
    test.PrintHFCode(hft);
    return 0;
}

