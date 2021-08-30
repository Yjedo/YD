struct TreeNode
{
    char date;
    struct TreeNode *plchild;
    struct TreeNode *prchild;
};
typedef struct TreeNode TreeNode;
class Tree
{
private:
    TreeNode *BaseNode;             //���ڵ�
    int Node_number;                //�ڵ���
    int Treeheight;                 //���ĸ߶�
public:
    Tree();                         //��ʼ����
    void VisitTree(TreeNode *pnode);//�������Ľ�㷽ʽ
    void CreateSonTree(TreeNode *pchild, int iflag);    //��������
    void CreateTree();                                  //������
    void TravelTree(TreeNode *pnode);                   //������
    TreeNode * GetBasenode();                           //��ȡ���ڵ�
    int Getnumber();                                    //��ȡ���Ľ����
    int Getheightleft(TreeNode *pnode);                                    //��ȡ�������ĸ߶�
    int Getheightright(TreeNode *pnode);                                   //��ȡ�������ĸ߶�
    int Getheight(TreeNode *pnode);                                        //��ȡ���ĸ߶�
};