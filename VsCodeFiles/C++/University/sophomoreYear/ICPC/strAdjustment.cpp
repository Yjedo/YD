#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    (1) �ַ������� 
���������ַ��� X = x1x2 ... xm �� Y = y1y2 ... yn�����ַ����ڼ���{A, G,C, T}����
��Ҫ�� X �� Y �в���ո񣬵õ��ַ��� X*�� Y*��Ҫ�� 
a) X*�� Y*��ͬ���ĳ��ȣ� 
b) ������Կո�X*=X��Y*=Y�� 
�ٸ����ӣ�X='GATCCGA',Y='GAAAGCAGA',����ո��(�ո���-��ʾ)�����Եõ���һ�ֽ��
�� 
X*=G-A--TCCGA 
Y*=GAAAG-CAGA 
��ȻҲ����������Ľ���� 
X*=GA---TCCGA 
Y*=GAAAG-CAGA. 
��ô�������ǵ������أ�����������ķ������ xi �� yj ����, �÷���:
    xi = yi �÷�Ϊ��2
    xi != yi �÷�Ϊ -1
���һ�� X*(�� Y*)���������Ӵ��� Y*(�� X*)��һ������Ϊ k �Ŀո��Ӵ����룬�÷��� -(4 
+ k). 
���ԣ���һ�ֽ���ĵ÷��� 2 - (4 + 1) + 2 - (4 + 2) - (4 + 1) + 2 - 1 + 2 + 2 = -7��
�ڶ��ֽ���ĵ÷��� 2 + 2 - (4 + 3) - (4 + 1) + 2 - 1 + 2 + 2 = -3�� 
������������Ƕ��ڸ����� X �� Y �ģ��ҳ��÷���ߵ� X*�� Y*��������������ӣ���õ�
����ǣ� 
X*=GA--TCCGA 
Y*=GAAAGCAGA. 
�÷�Ϊ 2+2-(4+2)-1+2-1+2+2=2���������У�m �� n ���Ϊ 500������ X*�� Y*��û���κ�
�����ո��Ƕ���ġ� 
�����ʽ��
��һ��Ϊһ�������������˲��Ե���Ŀ��������ÿ���и���һ�� X �� Y�� 
�����ʽ��
����ÿһ�����룬����÷ֵ����ֵ�� 
����������
3 
ACGGCTTAGATCCGAGAGTTAGTAGTCCTAAGCTTGCA 
AGCTTAGAAAGCAGACACTTGATCCTGACGGCTTGAA 
TTGAGTAGTGTTTTAGTCCTACACGACACATCAAATTCGGACAAGGCCTAGCT 
TTCAAGTCCTACAATGTGTGTCAAATTCGCTTGGCCGAAAGCC 
TTTGGGAACGTGTGTAGACTTCCCCATGCGATGG 
AACACACACGGACTTCATGCTGG 
���������
18 
20 
2

������
��Ŀ����������������Ǹ��������ַ������ֱ�������ַ�������ӿո��ַ���
         ʹ�õ÷־����ܸߣ�
���ֹ�����������
         �����ַ�������һ�����������ģ�k >= 1���Ŀո��Ӵ������-(4 + k)��
         ����ǿո��ַ������������Ƚϣ���ͬ��2��, ��ͬ���-2��
         �Ҳ��ܳ��ֿո��������
�ڴ˹����£�Ӧʹ�ÿո񾡿���������ͬʱ���Ʋ���λ��ʹ�ö����ַ�֮�価�������
*/

class Solution{
public:
    int maxScore(string sx, string sy){

    }

    //��ȡ��ǰ���ַ����ķ���
    int getScore(string sx, string sy){
        for(int i)
    }
};


int main(void){
    int N;
    cin >> N;
    vector<string> xStrings(N);
    vector<string> yStrings(N);
    for(int i = 0; i < N; i++){
        cin >> xStrings[i];
        cin >> yStrings[i];
    }
    Solution solution;
    for(int i = 0; i < N; i++){
        cout << solution.maxScore(xStrings[i], yStrings[i]) << endl;
    }
    return 0;
}