#include <iostream>
#include <vector>
#define TARGET 7
using namespace std;

/*
    ���⣺����N��������3����������������ܽ����Ϊ�����飬ʹÿһ�鶼Ϊ7�ı���

    ����Ҫ���ж������ݣ�����һ�����룬��һ�е�һ����������������������˺�ÿ����Ϊһ��
             ǰһ�б�ʾ�������ݵ���������һ����3����x��y��z�ֱ�������������1��2��3�ĸ���

    ���Ҫ�����ÿ�����ݷֱ���������ܷ�����������

    ������
          Ӧ�����ܶ����ϳ�7��
          �Ƚ�2��3��ϣ���Ϻ���4�������
          a.ֻʣ��2
          b.ֻʣ��3
          c.����ǡ�������
          d.ʣ��һ��2�����ɸ�3(��2��3ͬʱʣ�࣬��2��Ȼֻ����һ��)
          ����ÿ�����������Ӧ������
*/
class Solution{
public:
    //����һ�����ݵ������������
    int n = 0;
    void maxGroups(int x, int y, int z, int groups){
        /*
            ...
        */
    }
};

class Group{
public:
    int x;
    int y;
    int z;
    int num;
};

int main(void){
    Solution solution;
    int T;
    cin >> T;
    vector<Group> data(T);
    for(int i = 0; i < T; i++){
        int num, x, y, z;
        cin >> num;
        cin >> x >> y >> z;
        data[i].x = x;
        data[i].y = y;
        data[i].z = z;
        data[i].num = num;
    }

    for(int i = 0; i < T; i++){
        cout << data[i].x << " " << data[i].y << " " <<data[i].z << " " << data[i].num << " : ";
        solution.maxGroups(data[i].x, data[i].y, data[i].z, 0);
        cout << solution.n << endl;
        solution.n = 0;
    }
    return 0;
}