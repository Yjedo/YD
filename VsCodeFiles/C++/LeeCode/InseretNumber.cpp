//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
//���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//����Լ������������ظ�Ԫ�ء�
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int Max, Min, Mid;
       Max = nums.size() - 1;
       Min = 0;
       int iflag, i;
       while(Min<=Max){
           //ע�⣺һ������<=, ��������!=
           //��Ȼ���ܻ������ѭ��
            Mid = (Max+Min)/2;
           if(target == nums[Mid]){
               return Mid;
           }
           else if(target > nums[Mid]){
               Min = Mid+1;
           }
           else{
               Max = Mid-1;
           }
       }
       return Min;
    }
};
//˼·�����ֲ���
int main(void){
    vector<int> myarray = {3, 5, 7, 9, 10};
    int number1 = 8;
    int number2 = 10;
    Solution ways1;
    cout << ways1.searchInsert(myarray, number1);
    return 0;
}