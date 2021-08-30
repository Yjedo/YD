/*
��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ���?Z �������С�
���������ַ���Ϊ "PAYPALISHIRING"?����Ϊ 3 ʱ���������£�
P   A   H   N
A P L S I I G
Y   I   R
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"PAHNAPLSIIGYIR"��
����ʵ��������ַ�������ָ�������任�ĺ�����
string convert(string s, int numRows);
���룺s = "PAYPALISHIRING", numRows = 3
�����"PAHNAPLSIIGYIR"
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string str[numRows];
        int n=0,dir=1;
        for(int i=0;i<s.size();++i){
            if(n==numRows-1)dir=-1;
            if(n==0)dir=1;
            str[n]+=s[i];
            n+=dir;
        }
        for(int i=1;i<numRows;++i){
            str[0]+=str[i];
        }
        return str[0];
    }
};
class Solution1 {
public:
    string convert(string s, int numRows) {
        char **chrow, *chline;
        string news;
        chrow = new char* [numRows];
        int line = s.size()/numRows*2;
        for(int i = 0; i<numRows; i++){
            chrow[i] = new char [line];
        }
        for(int i = 0; i<numRows; i++){
            for(int j=0; j<line; j++){
                chrow[i][j] = ' ';
            }
        }
        for(int i; i<s.size(); i++){
            int a, b, c, d, e;
            a = i/(numRows-1);
            d = a*(numRows-1);
            b = d%2;
            c = i%(numRows-1);
            if(!b){
                e = d/2;
                chrow[c][e]=s[i];
            }
            else{
                e = d/2-1;
                chrow[numRows-1+c][e+c];
            }
        }
        int x=0;
        for(int i = 0; i<numRows; i++){
            for(int j=0; j<line; j++){
                if(chrow[i][j]!=' ')
                news[x]= chrow[i][j];
            }
        }
        return news;

    }
};
int main(void){
    Solution way;
    string s="1234567";
    cout << way.convert(s, 3);
    return 0;
}
