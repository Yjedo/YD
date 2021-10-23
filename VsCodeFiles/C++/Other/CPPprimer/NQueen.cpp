#include <iostream>
#include <windows.h>
#include <ctime>
#include <cmath> 
#include <vector>
using namespace std;
bool checkPos(int *map, int n, int level){
    for(int i = 0; i < level; i++){
        //��������Ƿ����Ҫ��
        if (abs(map[i] - map[level]) == abs(i - level) || map[i] - map[level] == 0){
            return false;
        }
    }
    return true;
}

void searchQueen(int *&map, vector<int *> &allIndex, int n, int level){
    if (level == n){
        //�ҵ�һ���������巽��
        for(int i = 0; i < n; i++){
            cout << i << "," << map[i] << " ";
        }
        cout << endl;
        allIndex.push_back(map);
    }
    else{
        while(map[level] < n){
            if (checkPos(map, n, level)){
                //���˲��к���λ�ã���������һ���������
                searchQueen(map, allIndex, n, level+1);
            }
            map[level]++;
        }
        //������һ��ǰ���轫��ǹ���λ�ô�����0
        map[level] = 0;
    }
}

void nQueue(int n){
    vector<int *> allIndex;
    int *map = new int[n];
    int i = 0;

    //��ʼ����ͼ
    for(i; i < n; i++){
        map[i] = 0;
    }

    searchQueen(map, allIndex, n, 0);

    cout << allIndex.size() << endl;

}

int main(void){
    long finish, start; 
    start = GetTickCount();
    nQueue(8);
    finish = GetTickCount();
    cout << finish-start;
    return 0;
}
