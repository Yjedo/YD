/*����һ�� 32 λ���з������� x ������ x ��ÿλ�ϵ����ַ�ת��Ľ����
�����ת���������� 32 λ���з��������ķ�Χ?[?2^31,? 2^31?? 1] ���ͷ��� 0��*/
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int sum=0;
        while(x!=0){
            sum=sum*10+x%10;
            x/=10;
        }
        if(sum<-2147483648 || sum>2147483647){
            sum=0;
        }
        return sum;
    }
};
int main(void){
    Solution ways1;
    int x;
    x=-123;
    cout << ways1.reverse(x);
    return 0;
}