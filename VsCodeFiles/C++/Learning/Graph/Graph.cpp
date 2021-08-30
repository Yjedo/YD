#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define null 99999
#define MAXLEN 100
using namespace std;

//����ͼ(�ڽӾ����ʾ��)
class MatrixGraph{
private:
    int numVertex;  //������
    int matrix[MAXLEN][MAXLEN];   //�ڽӾ���
    char vertexData[MAXLEN];      //��������
    bool visited[MAXLEN];
public:
    MatrixGraph(const char *fileName);
    void ResetVisit(void);
    //���÷��ʱ�־
    void DFS(int vertex);              
    void BFS(int vertex);
};

MatrixGraph::MatrixGraph(const char *fileName){
    FILE *pf;
    char tempData;
    int number;
    numVertex = 0;
    if (!(pf = fopen(fileName, "r"))){
        cout << "���ļ�ʧ�ܣ�" << endl;
    }

    //��ʼ�����ʱ�־���
    for(int i = 0; i < MAXLEN; i++){
        visited[i] = false;
        for(int j = 0; j < MAXLEN; j++){
            matrix[i][j] = 0;
        }
    }

    while(fscanf(pf, "%c%d ", &tempData, &number) != EOF){
        if (tempData == '#'){
            //�������ݶ�ȡ����
            //���ж�ȡ������
            break;
        }
        cout << tempData << number << endl;
        vertexData[number] = tempData;
        numVertex++;
    }

    int vertex1, vertex2;
    while(fscanf(pf, "%d %d\n", &vertex1, &vertex2) != EOF){
        cout << vertex1 << vertex2 << endl;
        matrix[vertex1][vertex2] = 1;
        matrix[vertex2][vertex1] = 1;
    }
}

void MatrixGraph::DFS(int vertex){
    cout << vertexData[vertex] << endl; //���ʵ�ǰ����
    visited[vertex] = true;             //���·��ʱ�־
    for(int i = 0; i < numVertex; i++){
        if (matrix[i][vertex] == 1 && matrix[vertex][i] == 1 && !visited[i]){
            //Ѱ���뵱ǰ����֮���бߵĶ���
            //�����������������
            DFS(i);
        }
    }
}

void MatrixGraph::BFS(int vertex){
    queue<int> gQueue;
    int w;

    //��ʼ��
    cout << vertexData[vertex];
    visited[vertex] = true;
    gQueue.push(vertex);

    while(!gQueue.empty()){
        w = gQueue.front();
        gQueue.pop();
        for(int i = 0; i < numVertex; i++){
            if (matrix[i][w] == 1 && matrix[w][i] == 1 && !visited[i]){
                //������ǰ����������ٽӵ�
                cout << vertexData[i];
                visited[i] = true;
                gQueue.push(i);
            }
        }
    }
}

//������
class EdgeList{
public:
    int vertex;             //������
    EdgeList *nextEdge;     //��һ����
public:
    EdgeList();
    EdgeList(int v);
    //����±�
    void AddEdge(int newVertex);
};

EdgeList::EdgeList(){
    vertex = null;
    nextEdge = NULL;
}

EdgeList::EdgeList(int v){
    vertex = v;
    nextEdge = NULL;
}

void EdgeList::AddEdge(int newVertex){
    EdgeList *p = this;
    while(p->nextEdge){
        //�������һ����
        p = p->nextEdge;
    }
    EdgeList *newEdge = new EdgeList(newVertex);
    p->nextEdge = newEdge;
}

//����
struct Vectex{
    char data;              //����洢������
    bool visitedFlag;       //����ķ��ʱ�־
    EdgeList *headEdge;     //�������ͷ���(����Ŵ�С�����˳��洢��˶����������������ж�����)
};


//����ͼ(�ڽӱ��ʾ��)
class LinkListGraph{
private:
    vector<struct Vectex> vertex;       //�洢���ж���
    int numVerdex;
public:
    LinkListGraph(const char *fileName);//�����ļ����ݴ�������ͼ
    void BFS(int v);
};

LinkListGraph::LinkListGraph(const char *fileName){
    FILE *pf;

    //��Ϊ��ʱ�������ļ���ȡ����
    char data;          
    //��������
    int number;         
    //������(�����˶����ڶ��������е��±�)
    char linkVerdex;    
    //�洢�ڽӶ���ı��

    numVerdex = 0; 
    //��ʼ��������ͼ�Ķ�������     

    if(!(pf = fopen(fileName, "r"))){
        cout << "���ļ�ʧ�ܣ�" << endl;
    }

    while(fscanf(pf, "%c%d\n", &data, &number) != EOF){
        /*
            ��ָ����ʽ���ļ���ȡ����
            ÿһ�д洢һ������������Ϣ
            ǰ�����ַ��ֱ�Ϊ���������붥���ţ�
            �˺��Կո�ָ���ÿ���ַ�������˶����ڽӵĶ�����
            ��ȡ����#����������˶�����������Ѷ��꣬���ж�ȡ��һ��������Ϣ
        */

        EdgeList *p = new EdgeList;
        //����ǰ���㴴��������

        while(fscanf(pf, "%c ", &linkVerdex) != EOF){
            if (linkVerdex == '#' ){
                break;
            }

            p->AddEdge(linkVerdex-'0');
            //���ڽӵ��Ŵ洢����������
        }

        /*
            ��������ʵ�壬�����������Ϣ����֮�洢����ͼ�Ķ���������
        */
        Vectex v;
        v.data = data;
        v.headEdge = p;
        v.visitedFlag = false;
        vertex.push_back(v);

        numVerdex++;
        //���¶������
    }
}

void LinkListGraph::BFS(int v){
    cout << vertex[v].data << endl;
    //���ʵ�ǰ����
    vertex[v].visitedFlag = true;
    //���µ�ǰ����ķ��ʱ�־
    int temp;
    EdgeList *p = vertex[v].headEdge->nextEdge;
    while(p){
        if (!vertex[p->vertex].visitedFlag){
            //����ǰ����Ĵ��ٽӵ�δ�����ʣ���BFS���ٽӵ�
            BFS(p->vertex);
        }
        p = p->nextEdge;
        //ָ����һ���ڽӵ�
    }
}

int main(void){
    // MatrixGraph
    // MatrixGraph("GraphTestData.txt");
    // MatrixGraph.BFS(0);
    LinkListGraph test("GraphTestData2.txt");
    test.BFS(0);
    return 0;
}