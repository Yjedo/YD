//����һ����ά���󣬼������Ӿ��η�Χ��Ԫ�ص��ܺͣ����Ӿ�������Ͻ�Ϊ (row1,?col1) �����½�Ϊ (row2,?col2) ��
/*ʾ�������� matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
*/
#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> x;
    NumMatrix(vector<vector<int>> & matrix) {
        x = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        int i, j;
        for(i = row1; i <= row2; i++){
            for(j = col1; j<=col2; j++){
                sum += x[i][j];
            }
        }        
        return sum;
    }
};
int main(void){
    vector<vector<int>> myarray = {{1,2}, {3, 4}, {5, 6}};
    NumMatrix a(myarray);
    int b;
    b = a.sumRegion(0, 0, 1, 1);
    cout << b;
    return 0;
}


