/*
��������Ϊ?2n?���������� nums ����������ǽ���Щ���ֳ�?n ��,
���� (a1, b1), (a2, b2), ..., (an, bn) ��ʹ�ô� 1 ��?n �� min(ai, bi) �ܺ����

ege1:���룺nums = [1,4,3,2]
�����4
���ͣ����п��ܵķַ�������Ԫ��˳��Ϊ��
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
��������ܺ�Ϊ 4

ege2:���룺nums = [6,2,6,5,1,2]
�����9
���ͣ����ŵķַ�Ϊ (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int arraynumsairSum(vector<int>& nums) {
        int SIZE = nums.size();
        int i, MaxSum = 0;
        Quicklysort(nums,0,SIZE);
        for(i=0; i<SIZE; i+=2){
            MaxSum += nums[i];
        }
        return MaxSum;
    }
    void Quicklysort(vector<int>& nums,int left, int right){
        int i=left, j=right;
        int mid=nums[i];
        if(left>=right){
        return;
        }
        while(i<j){
            while(nums[j]>=mid&&i<j){
                j--;
            }
            nums[i]=nums[j];
            while(nums[i]<=mid&&i<j){
                i++;
            }
            nums[j]=nums[i];
    }
    nums[i]=mid;
    Quicklysort(nums,left,i-1);
    Quicklysort(nums,i+1,right);
    return;
    }
};
int main(void){
    Solution ways1;
    int MaxSum;
    vector <int> nums = {1, 4, 3, 2};
    MaxSum = ways1.arraynumsairSum(nums);
    cout << "The max sum is " << MaxSum << endl;
    return 0;
}
