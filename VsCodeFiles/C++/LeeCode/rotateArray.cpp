#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
    eg: ����: nums = [1,2,3,4,5,6,7], k = 3
        ���: [5,6,7,1,2,3,4]
    ����:
        ������ת 1 ��: [7,1,2,3,4,5,6]
        ������ת 2 ��: [6,7,1,2,3,4,5]
        ������ת 3 ��: [5,6,7,1,2,3,4]
    ˼·���ֶη�ת����
*/ 


void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

/**
 * @brief:��������left��right֮���Ԫ��˳��
 **/
void reverseArray(vector<int> &nums, int start, int end){
    while(start < end){
        swap(nums[start++], nums[end--]);
    }
}

void rotateArray(vector<int> &nums, int k){
    int len = nums.size();
    k %= len;
    //��������������
    reverseArray(nums, 0, len-1);
    //������0��k-1֮���Ԫ��
    reverseArray(nums, 0, k-1);
    //������k��len-1֮���Ԫ��
    reverseArray(nums, k, len-1);
}

int main(void){
    vector<int> testArray = {1, 2, 3, 4, 5, 6, 7};
    rotateArray(testArray, 3);
    for(int i = 0; i < testArray.size(); i++){
        cout << testArray[i] << " ";
    }
    return 0;
}
