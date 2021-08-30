//����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//1.�������
class Solution1 {
public:
    string longestPalindrome(string s) {
        int i, j;
        int ileft=0, iright=0;
        int maxlength = 0;
        for(i=0; i<s.size(); i++){
            for(j=i+1; j<s.size(); j++){
                if(isRestr(s,i,j) && j - i + 1> maxlength){
                    ileft = i;
                    iright = j;
                    maxlength = j -i + 1;
                }
            }
        }
        string newstr;
        newstr.assign(s, ileft, iright-ileft+1);
        return newstr;    
    }

    bool isRestr(string s, int a, int b){
        while(s[a]==s[b] && a<=b){
            a++;
            b--;
        }
        if(a>b){
            return true;
        }
        else{
            return false;
        }

    }
};

//��̬�滮
class Solution2 {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//���Ĵ���ʼλ��
        int max=1;//���Ĵ���󳤶�
        vector<vector<int>>  dp(len,vector<int>(len));//�����ά��̬����
        for(int i=0;i<len;i++)//��ʼ��״̬
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l��ʾ�������Ӵ����ȣ�����3��ʾ�ȼ�������Ϊ3���Ӵ�
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//��ֹ�ַ�λ��
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//״̬ת��
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//��ȡ������Ӵ�
    }
};

int main(void){
    string str="ccc";
    Solution1 way;
    cout << way.longestPalindrome(str) << endl;
    return 0;
}