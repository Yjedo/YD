/*����һ���������� nums?��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ ����?����?���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣
����԰�����˳�򷵻ش𰸡�*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vx(2);
        int iflag=0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
                for(int j = i+1; j < n; j++){
                    if(nums[j] == target - nums[i]){
                        vx[0] = i;
                        vx[1] = j;
                        iflag = 1;
                        break;
                    }
                
                }
            if(iflag==1){
                break;
            }
        }
        return vx;
    }
};
int main(void){
    vector<int> vy = {-1, -2, -3, -4, -5};
    vector<int> vx(2);
    Solution ways;
    vx = ways.twoSum(vy, -8);
    cout << vx[0] << " " << vx[1];
    return 0;
}
