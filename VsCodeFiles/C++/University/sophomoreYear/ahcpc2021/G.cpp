#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <map>
using namespace std;

/*
    ���⣺����һ�� n ���ڵ������������д��ڱߣ�a,b)(b,c)(c,d)��a,b,c,d ������ͬ��
            ���� a �� d ֮��û�бߣ���ô������һ����(a,d)������������������ߣ�
    ���룺��һ��һ������ N�������� N-1 �У���ʾ����ÿһ���ߡ� 
            1 <= N <= 2��10^5
    ��������һ�У���ʾ�𰸡�

    ��������������ͨ�׵�����������Ϊ����һ������ͼ��Ѱ������2������a, b������֮��û�б�����,
          �Ҵ�a��b���辭���������㣻ÿ��������һ�Զ��㼴������֮�����һ���±�
        (ע�⣺��ӵ��±���֮��������н���������)�������Ӷ������ߣ�
    ˼·������˼·�ܼ򵥣���������˳���𼴿ɣ����岽��Ϊ��
            1.�������빹������ͼ�������ڽӱ�ķ�ʽ��֮���Բ������ڽӾ���������2*10^5�����㣬��Ҫ2*10^5 * 2*10^5��С�ľ���
              �ռ临�Ӷȹ���
            2.�ֱ��ÿ������������������������������ͼ���ҵ������Ըö���Ϊ�����㣬·������Ϊ4��·���������յ�����ʼ��
              ֮��Ĺ�ϵ�����жϣ�Ȼ������жϽ�������Ƿ�����±ߡ�
            3.������maxEdgeNum  
    ���㷨ʱ�临�Ӷ�ΪO(n)��O(n^2)֮�䣬����ĸ��Ӷ��������йأ�ԭ����������ֱ��ÿ����������Ըö���Ϊ��ʼ��ĺϷ�
    ·���м�����ͬʱ�ݹ���Ƚ�Ϊ4����������ǵݹ�����ж�ʱ�����һ���յ���ڽӵ㡣

*/

class Solution{
public:
    //�������
    int maxEdgeNum  = 0;
    vector<int> treeFlag;
    map<int, int> edgeMap;

    /**
     *@param index ��ǰ��������
     *@param floor �ݹ����
     *@param initIndex ��ʼ���� 
     */
    void DFS(vector<list<int>> &tree, int index, int floor, int initIndex){
        if(floor == 4){
           //��������ĸ�����ʱ���ж�������ʼ��֮���Ƿ��б�
           bool flag = true;
           for(int i : tree[index]){
               if (i == initIndex ){
                   //�����бߣ���˵���˱߲������
                   flag = false;
                   break;
               }
            }
            if (flag){
                //���ֿ���ӱ�
                maxEdgeNum++;
                tree[index].push_back(initIndex);
                tree[initIndex].push_back(index);
            }
            return;
        }
        //�����ѷ��ʱ��
        treeFlag[index] = 1;
    
        for(int i : tree[index]){
            if (treeFlag[i] == 0){
                //�����ڶ����������
                DFS(tree, i, floor+1, initIndex);       
            }
        }
        //����ǰ�����÷��ʱ��
        treeFlag[index] = 0;
       
    }
};

int main(void){
    int N;
    cin >> N;
    //��Ƕ����Ƿ񱻷���
    vector<int> treeFlag(N+1);
    //���ٿռ�
    vector<list<int>> tree(N+1);
    list<int> temp;
    for(int i = 0; i < N+1; i++){
        tree[i] = temp;
    }

    int m, n;
    for(int i = 1; i < N; i++){
        //�����ڽӱ���ͼ
        cin >> m >> n;
        tree[m].push_back(n);
        tree[n].push_back(m);
    }

    Solution solution;
    solution.treeFlag = treeFlag;

    for(int i = 1; i < N+1; i++){
        solution.DFS(tree, i, 1, i);
    }

    cout << solution.maxEdgeNum;
    return 0;
}