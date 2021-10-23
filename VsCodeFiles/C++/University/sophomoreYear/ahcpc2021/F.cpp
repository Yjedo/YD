#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
���⣺
    ��һ�����޳��ĵ�·����·���Խ��ƿ���һ��ֱ�ߡ���·���� N ��������Ҫά�ޣ�
    �� i �����ֵ�ά�޵�λ���� Vi��Xi ʱ�俪ʼά�ޣ�ֱ�� Yi ʱ��ά�޽������� Q
    ��ά�޹��ˣ��� i �����˵��ϰ��ʱ���� Ai���°�ʱ���� Bi���� Ai ʱ�俪ʼ��
    ����������ά��λ����[Li,Ri]��Χ�ĵ�·��ֱ�� Bi ʱ�����������Ҫ֪������
    �����ϰ��ÿһ�����Ƿ��ڽ���ά�޹��������ܱ�дһ������ش�����

���룺��һ��һ������ N�������� N �У�ÿ���������� Vi,Xi,Yi�� 
     ��һ��һ������ Q�������� Q �У�ÿ���ĸ����� Li,Ri,Ai,Bi�� 
     1 <= N,Vi,Q <= 10^5��1 <= Xi <= Yi <= 10^5 
     1 <= Li <= Ri <= 10^5��1 <= Ai <= Bi <= 10^5  
     
ʾ����
    ���룺
        4 
        5 3 3 
        2 4 5 
        3 1 2 
        5 2 3 
        4 
        2 3 2 2 
        1 4 2 3 
        2 5 2 4 
        3 5 1 5
    �����
        Yes 
        No 
        Yes 
        No

���������һ�������ڹ���ʱ����һֱ�ڹ�������ô˵����ά�������е�����·�ε�ʩ��ʱ�伯��Ӧ������
      ���ϰ�ʱ�伯�ϣ�������ڵ�һ�����ˣ���ά��������2������3����ά������������·�ε�ʩ��ʱ�伯��Ӧ����
      1��2��4, 5;���ù��˵��ϰ�ʱ�伯����2������Ӧ�����yes;
      �������ڵ������������ǡ���ı�ʾʩ��ʱ�伯���빤��ʱ�伯�ϣ����ҵó����ߵĹ�ϵ
      ��Ȼ��ֱ���г�ʱ��㣬�ж������Ƿ�Ϊ���Ӽ��Ĺ�ϵ���Խ�������⣬��ͬʱ��ʱ�临�Ӷ���ռ临�Ӷȹ���
      ��˲��ô˷����ǲ�̫�õġ��ɲ���������������������

*/

class Road{
public:
    int vi;
    int xi;
    int yi;
};

class Worker{
public:
    int li;
    int ri;
    int ai;
    int bi;
};

struct cmp{
    bool operator() (Road& road1, Road& road2){
		if (road1.xi > road2.xi){
            return false;
        } else if (road1.xi == road2.xi){
            return road1.yi > road2.yi;
        } else{
            return true;
        }
	}
};


class Solution{
public:
    /**
     * @brief �ж�һ���������乤��ʱ�����Ƿ�һֱ�ڹ���
     * @param 
     **/
    bool isWorking(vector<Road> &roads, Worker worker){
        //1.ɸѡ�����������ڵ�·
        vector<Road> workRoads;
        for(int i = 0; i < roads.size(); i++){
            if (roads[i].vi >= worker.li && roads[i].vi <= worker.ri){
                workRoads.push_back(roads[i]);
            }
        }

        //2.��·�ΰ�ʩ��ʱ��������кϲ�.��finalRoad������������·��
        vector<Road> finalRoad;
        Road tempRoad = workRoads[0];
        for(int i = 1; i < workRoads.size(); i++){
            if (tempRoad.yi - workRoads[i].xi < -1){
                finalRoad.push_back(tempRoad);
                tempRoad = workRoads[i];
            } else{
                tempRoad.yi = tempRoad.yi > workRoads[i].yi ? tempRoad.yi : workRoads[i].yi;
            }
        }
        finalRoad.push_back(tempRoad);

        //4.��֤���˹���ʱ���Ƿ�����䣬����������û��һֱ����
        for(int i = 0; i < finalRoad.size(); i++){
            // cout << finalRoad[i].xi << "--" << finalRoad[i].yi << "  ";
            if (worker.ai >= finalRoad[i].xi && worker.bi <= finalRoad[i].yi){
                cout << "Yes" << endl;
                return true;
            }
        }

        cout << "No" << endl;
        return false;
    }
};

int main(void){
    Solution solution;
    vector<Road> roads;
    vector<Worker> workers;
    int N, Q;
    int vi, xi, yi;
    int li, ri,ai, bi;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> vi >> xi >> yi;
        Road road;
        road.vi = vi;
        road.xi = xi;
        road.yi = yi;
        roads.push_back(road);
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> li >> ri >> ai >> bi;
        Worker worker;
        worker.li = li;
        worker.ri = ri;
        worker.ai = ai;
        worker.bi = bi;
        workers.push_back(worker);
    }

    //��·�ν�������(����ʼʱ���С��������ʼʱ����ͬ����ȽϽ���ʱ�䣬С����ǰ)
    sort(roads.begin(),roads.end(), cmp());

    for(int i = 0; i < Q; i++){
       solution.isWorking(roads, workers[i]);
    }

    return 0;
}