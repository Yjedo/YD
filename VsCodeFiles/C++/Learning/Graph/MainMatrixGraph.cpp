#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include "MatrixGraph.h"
#define MAXLEN 100

typedef struct Node{
	char data;
	int parent;
}Node;

class Tree{
public:
	Node tree[MAXLEN];
	int numNode = 0;
	void PreTraversal(){
		for(int i = 0; i < numNode; i++){
			cout << "data:" << tree[i].data << "	parent:" <<tree[i].parent << endl; 
		}
	}

	int GetIndex(char data){
		//���߽��������������±�
		for(int i = 0; i < numNode; i++){
			if (tree[i].data == data){
				return i;
			}
		}
		return INF;
	}
};

//ɾ���ַ������ַ�������߿ո�
void strLTrim(char* str)
{
	int i,j;
	int n=0;
	n=strlen(str)+1;
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')  //�ҵ������һ���ǿո�λ��
			break;
	}
	    //�Ե�һ���ǿո��ַ�Ϊ���ַ��ƶ��ַ���
	for(j=0;j<n;j++)
	{
		str[j]=str[i];
		i++;
	}
}

//*************************�������ļ�����ͼ**************************//
//* �������ܣ����ı��ļ������ڽӾ����ʾ��ͼ                        *//
//* ��ڲ���  char fileName[]���ļ���                               *//
//* ���ڲ�����                                                      *//
//* �� �� ֵ��bool��true�����ɹ���false����ʧ��                     *//
//* �� �� ����CreateGrpFromFile(char fileName[])                  *//
//*******************************************************************//
bool CreateGrpFromFile(const char fileName[], Graph &G)
{
	FILE* pFile;      //����˳�����ļ�ָ��
	char str[1000];   //��Ŷ���һ���ı����ַ���
	char strTemp[10]; //�ж��Ƿ�ע����

	cellType  eWeight;     //�ߵ���Ϣ����Ϊ�ߵ�Ȩֵ
	GraphKind GrpType;  //ͼ����ö�ٱ���

	pFile=fopen(fileName,"r");
	if(!pFile)
	{

		printf("�����ļ�%s��ʧ�ܡ�\n",fileName);
		return false;
	}

	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //����ע����
			continue;
		else  //��ע���С��ǿ��У�����ѭ��
			break;
	}

    //ѭ��������str��Ӧ���Ѿ����ļ���ʶ���ж��ļ���ʽ
	if(strstr(str,"Graph")==NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}

	//��ȡͼ�����ͣ���������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else  //�ǿ��У�Ҳ��ע���У���ͼ�����ͱ�ʶ
			break;
	}
    
    //����ͼ������
	if(strstr(str,"UDG"))
		GrpType=UDG;  //����ͼ
	else if(strstr(str,"UDN"))
		GrpType=UDN;  //������
	else if(strstr(str,"DG"))
		GrpType=DG;   //����ͼ
	else if(strstr(str,"DN"))
		GrpType=DN;   //������
	else
	{
		printf("���󣺶�ȡͼ�����ͱ��ʧ�ܣ�\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}

	//��ȡ����Ԫ�أ���str����������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else  //�ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
			break;
	}

    //�������ݷ���ͼ�Ķ�������	
	char* token=strtok(str," ");
	int nNum=1;	
	while(token!=NULL)
	{
		G.Data[nNum]=*token; // atoi(token);	//��������ת��Ϊ��������Ϊ�ַ�����ת��		
        token = strtok( NULL, " ");
		nNum++;
	}
	nNum--;   //������

    //ͼ���ڽӾ����ʼ��
	int nRow=1;  //�������±꣬��1��ʼ
	int nCol=1;  //�������±꣬��1��ʼ
	if(GrpType==UDG || GrpType==DG)
	{
		for(nRow=1;nRow<=nNum;nRow++)
			for(nCol=1;nCol<=nNum;nCol++)
				G.AdjMatrix[nRow][nCol]=0;
	}
	else
	{
		for(nRow=1;nRow<=nNum;nRow++)
			for(nCol=1;nCol<=nNum;nCol++)
				G.AdjMatrix[nRow][nCol]=INF;  //INF��ʾ�����
	}
	
	//ѭ����ȡ�ߵ����ݵ��ڽӾ���

	int edgeNum=0;  //�ߵ�����
	elementType Nf,Ns; //�߻򻡵�2�����ڶ���
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;

		char* token=strtok(str," ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���
		
		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Nf=*token;  //��ȡ�ߵĵ�һ������
		
		token = strtok( NULL, " ");  //��ȡ��һ���Ӵ������ڶ�������
		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}

		Ns=*token;  //��ȡ�ߵĵڶ�������
            //�ӵ�һ�������ȡ�к�		
		for(nRow=1;nRow<=nNum;nRow++)
		{
			if(G.Data[nRow]==Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
           //�ӵڶ��������ȡ�к�		
		for(nCol=1;nCol<=nNum;nCol++)
		{
			if(G.Data[nCol]==Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}

		//���Ϊ������ȡȨֵ
		if(GrpType==UDN || GrpType==DN)
		{
			token = strtok( NULL, " ");  //��ȡ��һ���Ӵ������ߵĸ�����Ϣ����Ϊ�ߵ�Ȩ��
			if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
			{
				printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
				fclose(pFile); //�ر��ļ�
				return false;
			}
			eWeight=atoi(token);  //ȡ�ñߵĸ�����Ϣ
		}
		if(GrpType==UDN || GrpType==DN)  //���Ϊ�����ڽӾ����ж�Ӧ�ı�����Ȩֵ��������Ϊ1
			G.AdjMatrix[nRow][nCol]=eWeight;
		else
			G.AdjMatrix[nRow][nCol]=1;  //atoi(token);	//�ַ���תΪ����

		edgeNum++;   //������1
	}

    G.VerNum=nNum;  //ͼ�Ķ�����
	if(GrpType==UDG || GrpType==UDN)
		G.ArcNum=edgeNum / 2;  //����ͼ�����ı�������ͳ�Ƶ����ֳ�2  
	else
		G.ArcNum=edgeNum;

	G.gKind=GrpType;  //ͼ������

	fclose(pFile); //�ر��ļ�
	return true;
}

void DFS(Graph G, int v){
	visit(G, v);
	for(int i = 1; i <= G.VerNum; i++){
		if (G.AdjMatrix[v][i] >= 1 && G.AdjMatrix[v][i] < INF && !visited[i]){
			DFS(G, i);
		}
	}
}

void BFS(Graph G, int v){
	/*
		����v����ʼ��
	*/
	queue<int> vQueue;
	cout << G.Data[v];
	visited[v] = true;
	vQueue.push(v);
	int temp = v;
	while(!vQueue.empty()){
		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[temp][i] >= 1 && G.AdjMatrix[temp][i] < INF && !visited[i]){
				//���ʵ�ǰ��������ӵ�
				//�������ӵ����
				cout << G.Data[i];
				visited[i] = true;
				vQueue.push(i);
			}
		}
		vQueue.pop();
		temp = vQueue.front();
		//���µ�ǰ���
	}
}

//������ȱ���������
void SpainningTree(Graph G, int v, Tree &T, int parent){
	T.tree[T.numNode].data = G.Data[v];
	T.tree[T.numNode].parent = parent;
	parent = T.numNode++;
	visited[v] = true;
	for(int i = 1; i <= G.VerNum; i++){
		if (G.AdjMatrix[v][i] >= 1 && G.AdjMatrix[v][i] < INF && !visited[i]){
			SpainningTree(G, i, T, parent);
		}
	}
}

/*
	����Ϊ��С��������prim�㷨ʵ��
	������������������븨���������ͣ��Լ����㷨����ʵ��
*/

/*
	����������
	����һ��������洢ͼ�е����б�
	���������±����˱ߵ�һ�˶��㣬v������һ�˶���
	weight����ߵ�Ȩֵ
	weight��ΪINFʱ����˱߲��Ǻ�ѡ��
	��֮������Ϊ��ѡ��
*/
typedef struct Edge{
	int v;	
	int weight;
}Edge; 

//�ж�������֮���Ƿ��б�
bool HasEdge(Graph G, int v1, int v2){
	if (G.AdjMatrix[v1][v2] > 0 && G.AdjMatrix[v1][v2] < INF){
		//���ݰ�������ж�������֮���Ƿ��б�
		return true;
	}
	else{
		return false;
	}
}

//��ȡδѡ����������ѡ���������ұߵ�Ȩֵ��С�Ķ���
int GetMinWightVertex(Graph G, Edge *E, int &parent){
	int minWeight = INF;
	int n = 0;
	for(int i = 1; i <= G.VerNum; i++){
		if (!visited[i] && E[i].weight < minWeight){
			minWeight = E[i].weight;
			n = i;
		}
	}
	// cout << G.Data[n];
	parent = E[n].v;
	//���ڶ���n��˵, ���������У� v�������ĸ��ڵ�
	return n;
}

//��ʼ����ѡ�߼���
void InitEdgeArray(Graph G, Edge *E, int v){
	for(int i = 1; i <= G.VerNum; i++){
		if (HasEdge(G, v, i)){
			//��ĳ������v֮���бߣ�������֮��ı�ת��Ϊ��ѡ��
			E[i].v = v;
			E[i].weight = G.AdjMatrix[v][i];
		}
		else{
			E[i].weight = INF;
		}
	}
}

//���º�ѡ�߼���
void UpdateEdge(Graph G, Edge *E, int v){
	for(int i = 1; i <= G.VerNum; i++){
		if (!visited[i] && HasEdge(G, v, i) && E[i].weight > G.AdjMatrix[v][i]){
			/*
				����º�ѡ��,�����ԭ�к�ѡ��
				��i��v��������ԭ��ѡ����֮��û�бߣ�������º�ѡ��
				��i��v������ͬʱ����ԭ��ѡ����֮��Ҳ�бߣ�����ݱߵ�Ȩֵ��С������С��
			*/
			E[i].v = v;
			E[i].weight = G.AdjMatrix[v][i];
		}
	}
}

void Prim(Graph G,Tree &T, int v){
	Edge edgeArray[MaxVerNum+1];
	int p = -1;	//��ʱ�������洢��ǰ����ĸ��ڵ���ͼ�е�λ��

	//��ʼ���������ĵ�һ�����
	T.tree[T.numNode].data = G.Data[v];
	T.tree[T.numNode++].parent = p;
	visited[v] = true;

	//��ʼ����ѡ�߼���
	InitEdgeArray(G, edgeArray, v);
	int vex = v;

	//�����ѡ������δѡ����
	for(int i = 1; i < G.VerNum; i++){
		//ÿ��ѭ���õ�һ���µ����������㣬��Ϊ�ѳ�ʼ��һ�����
		//����ѭ��G.VerNum-1�μ���
		vex = GetMinWightVertex(G, edgeArray, p);
		// cout << G.Data[vex];
		//���ݺ�ѡ�ߣ���δѡ�������ҳ�����ѡ���������ұ�Ȩֵ��С�Ķ��㣬������ӵ���ѡ������
		T.tree[T.numNode].data = G.Data[vex];
		T.tree[T.numNode++].parent = T.GetIndex(G.Data[p]);
		//ͨ���丸����Ĵ洢�����������丸�ڵ��������������е��±�
		visited[vex] = true;
		UpdateEdge(G, edgeArray, vex); 
		//��Ϊ�������µ���ѡ���㣬��������º�ѡ��
	}
}
/*
	�㷨������
		��������һ����ѡ�߼��ϣ����ݳ������ʼ����ѡ�ߣ�����������Ϊ��ѡ
		�ٸ���ͼ�ж�����Ŀ����ѭ��������ÿ�ζ����ݺ�ѡ���ҵ���һ�����㣬��֮����Ϊ��ѡ
*/

//�ж�ͼ��������֮���Ƿ���·��
bool HasPath(Graph G, int v1, int v2){
	if (G.AdjMatrix[v1][v2] > 0 && G.AdjMatrix[v1][v2] < INF){
		//���v1,v2֮���бߣ���Ȼ������֮����·��
		return true;
	}
	else{
		visited[v1] = true;
	 	for(int i = 1; i <= G.VerNum; i++){
		 	if (G.AdjMatrix[v1][i] > 0 && G.AdjMatrix[v1][i] < INF && !visited[i]){
				 /*
				 	���v1��v2֮��û�бߣ�����v1�����Ķ�����v2�бߣ���v1��v2֮��Ҳ�б�
				 */
				if (HasPath(G, i, v2)){
					return true;
				}
			}
		}
		return false;
	}
}

//�ж�����ͼ�Ƿ���һ���Զ���v0Ϊ������������
//����������ͨͼ�����ڵ����Ϊ0�����������Ϊ1
bool IsTree(Graph G, int v0){
	int *inDegree = new int[G.VerNum + 1];

	//��ʼ�����ж������
	int i = 0;
	inDegree[i++] = 0;
	while(i < G.VerNum+1){
		inDegree[i++] = 0;
	}

	//�������ж������
	for(i = 1; i <= G.VerNum; i++){
		for(int j = 1; i <= G.VerNum; j++){
			if (G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF){
				inDegree[j]++;
			}
		}
	}

	//�����ڵ���Ȳ�Ϊ0��˵����ͼ������������ֱ�ӷ���false
	if (inDegree[v0] != 0){
		return false;
	}
	else{
		for(i = 1; i <= G.VerNum; i++){
			if (i != v0 && inDegree[i] != 1){
				//��ĳ��㲻�Ǹ��ڵ㣬������Ȳ�Ϊ1��Ҳ˵����ͼ����������������false
				return false;
			}
		}
	}

	return true;

}

//KrusKal�㷨(���������С������)
typedef struct K_Edge{
	int v1;	
	int v2;
	int weight;
	bool treeFalg;	//�Ƿ�Ϊ�������ıߵı�־
}K_Edge;
//���ڴ洢�߼�
void KrusKal(Graph G, Tree &T){
	vector<K_Edge> edge;
	int component[MaxVerNum];
	//�洢��ͨ�������
	K_Edge tempEdge;
	//��ͼ�б��Դ˷�ʽ�洢�������Ժ��㷨ʵ��
	for(int i = 1; i <= G.ArcNum; i++){
		for(int j = 1; j <= G.ArcNum; j++){
			tempEdge.weight = G.AdjMatrix[i][j];
			if (tempEdge.weight == INF || tempEdge.weight <= 0){
				continue;
			}
			tempEdge.v1 = i;
			tempEdge.v2 = j;
			tempEdge.treeFalg = false;

			if (edge.empty()){
				edge.push_back(tempEdge);
			}
			else{
				bool tempflag = false;
				for(int k = 0; k < edge.size(); k++){
					//����������ò���������䰴�Ӵ�С��˳���������
					if (tempEdge.weight > edge[k].weight){
						edge.insert(edge.begin()+k, tempEdge);
						tempflag = true;
						break;
					}
				}
				if (!tempflag){
					edge.push_back(tempEdge);
				}

			}
		}
	}
	for(int i = 0; i < edge.size(); i++){
		cout << edge[i].v1 << "		" << edge[i].v2 << "	" << edge[i].weight << endl;
	}

	for(int i = 1; i <=	G.VerNum; i++){
		component[i] = i;
		//��ʼʱ��ÿһ�����㶼��Ϊһ����ͨ��������������
	}

	int num = edge.size()-1;
	while(num > -1){
		//����ѡȡ��С��
		tempEdge = edge[num];
		if (component[tempEdge.v1] != component[tempEdge.v2]){
			//���˱���ͷ�Ķ���������ͨ������Ų�ͬ����˱ߺϷ����޸����γɵ���ͨ�����ı�Ŷ�ΪINF
			component[tempEdge.v1] = INF;
			component[tempEdge.v2] = INF;
			edge[num].treeFalg = true;	//���˱߼�����ѡ��
		}
		num--;
	}

	for(int i = 0; i < edge.size(); i++){
		if (edge[i].treeFalg){
			cout << edge[i].v1 << "		" << edge[i].v2 << "	" << edge[i].weight << endl;
		}
	}
}

/*
	��һ�����㵽���������������·����������Dijkstra�㷨
	˼·:1.��ʼ����㵽�������·������,�б߳���Ϊ�ߵ�Ȩֵ���ޱ�������ΪINF
		   ���������������Ϊ-1���������������ж���״̬����Ϊδ��
		 2.����·������������һ����ⶥ��(δ�ⶥ���У������·��������С�Ķ��㼴Ϊ��һ����ⶥ��)
		 3.��������ⶥ��״̬����Ϊ�ѽ�
		 4.�����뵱ǰ�ѽⶥ����������δ��Ķ��㣬���䵽����·������С�ڵ�ǰ�ѽⶥ�㵽
		    ����·�����ȼ������ǻ���Ȩֵ֮�ͣ������޸���Щ���������������·������
		 5.�ظ�2��3��4ֱ����������ж���
*/		
void DijKstra(Graph &G, int *path, int *dist, int vFirst){
	bool solveFlag[MaxVerNum+1];
	for(int i = 1; i <= G.VerNum; i++){
		solveFlag[i] = false;
		//��ʼʱ�����ж��㶼����Ϊδ��
		if (G.AdjMatrix[vFirst][i] > 0 && G.AdjMatrix[vFirst][i] < INF){
			//���ж�����������������仡��Ȩֵ��Ϊ�䵽�������·������
			//��������������޸�ΪvFirst
			dist[i] = G.AdjMatrix[vFirst][i];
			path[i] = vFirst;
		}
		else {
			dist[i] = INF;
		}
	}

	solveFlag[vFirst] = true;	//�������Ϊ�ѽ�
	path[vFirst] = -1;			//����������������Ϊ-1
	dist[vFirst] = 0;			//������·������Ϊ0

	int vexTemp = vFirst;
	int minDist;
	int num = 1;	

	//������һ����ⶥ��
	while(num < G.VerNum){
		//ÿ��ѭ�����һ��������ѭ��MaxVerNum-1��

		minDist = INF;
		for(int i = 1; i <= G.VerNum; i++){
			//����������
			if (minDist > dist[i] && !solveFlag[i]){
				//cout << G.AdjMatrix[vPre][i] << "	" << endl;
				vexTemp = i;
				minDist = dist[i];
			}
		}

		if (minDist == INF){
			//��δ���
			return;
		}

		solveFlag[vexTemp] = true;
		dist[vexTemp] = minDist;

		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[vexTemp][i] + dist[vexTemp] < dist[i] && !solveFlag[i]){
			/*
				����vexTemp�����������µ�·������С��ԭ��·�����ȣ��轫��·������������������
			*/
			dist[i] = G.AdjMatrix[vexTemp][i] + dist[vexTemp];
			path[i] = vexTemp;
			}
		}

		num++;
	}

	//��ӡ·����·������
	int k, tempPath[MaxVerNum+1];
	for(int i = 1; i <= G.VerNum; i++){
		if (i == vFirst){
			continue;
		}
		k = i;
		cout << "����" << i << "������1��·������Ϊ��" << dist[i] << endl;  
		cout << "·��Ϊ��";
		num = 0;
		while(k != -1){
			tempPath[num++] = k;
			k = path[k];
		}
		for(int j = num-1; j > -1; j--){
			cout << tempPath[j] << " ";
		}
		cout << endl;
	}
}

/*
	���ͼ������������֮������·����������Floyd�㷨
	˼·��1.��ʼ��������ά����path��dist, path�洢·����dist�洢·������
		   ����path[i][j]��ʾ�����i���յ�j��·�����յ�j��ǰ������
		   dist[i][j]��ʾ�����i���յ�j��·�����յ�j��·������
		   �������Ϊ��������i�붥��j֮���л�����iΪj��ǰ����㣬��������ǰ�����Ϊ-1
		   			  ������i�붥��j֮���л����򻡵�Ȩֵ��Ϊ��ʱ���·�����ȣ���������ΪINF
		  2.��������ѭ���������ж������֮���·�������ת��m��(mΪ������i,j�����ⶥ��)���Ƚ��µ�·��������ԭ��
		  	·�����ȣ������µ�·�����ȸ�С�������dist[i][j]��path[i][j];
*/

void Floyd(Graph G, int path[MaxVerNum+1][MaxVerNum+1], int dist[MaxVerNum+1][MaxVerNum+1], int vFirst){
	//��ʼ��
	for(int i = 1; i <= G.VerNum; i++){
		for(int j = 1; j <= G.VerNum; j++){
			if (i != j && G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF){
				dist[i][j] = G.AdjMatrix[i][j];
				path[i][j] = i; 
			}
			else{
				dist[i][j] = INF;
				path[i][j] = -1;
			}
		}
	}

	//�����㷨������ѭ��
	for(int m = 1; m <= G.VerNum; m++){
		for(int i = 1; i <= G.VerNum; i++){
			for(int j = 1; j <= G.VerNum; j++){
				if (i != j && dist[i][m] + dist[m][j] < dist[i][j]){
					dist[i][j] = dist[i][m] + dist[m][j];
					path[i][j] = path[m][j];
				}
			}
		}
	}

	//��ӡ·����·������
	int k;
	int num;
	int tempPath[MaxVerNum+1];
	for(int i = 1; i <= G.VerNum; i++){
		if (i == vFirst){
			continue;
		}
		k = i;
		cout << "����" << vFirst << "������" << i <<"��·������Ϊ��" << dist[vFirst][i] << endl;  
		cout << "·��Ϊ��";
		num = 0;
		while(k != vFirst){
			tempPath[num++] = k;
			k = path[vFirst][k];
		}
		cout << vFirst << " ";
		for(int j = num-1; j > -1; j--){
			cout << tempPath[j] << " ";
		}
		cout << endl;
	}

}

/*	
	�����޻�ͼ���жϡ���������������
	�������У�����һ�������У�������λ����ǰ�Ķ��㵽λ���ں�Ķ�����·����λ���ں�Ķ��㵽λ����ǰ�Ķ���
			 ��·�������֮Ϊ�������У������������еĹ��̳�Ϊ��������
	ʵ��˼·��
		1.��ȡ����ͼ�����ж������ȣ����������Ϊ0�Ķ������ջ��
		2.����ջ��Ԫ�أ���������������С�
		3������Ԫ�ش���Ķ���ĺ�̶������ȼ�һ��������ĳ��������Ϊ0��������ջ
		4.�ظ�2.3��ֱ��ջΪ��Ϊֹ��
		5.�������������������а���ͼ�����ж��㣬���ͼΪ�����޻�ͼ
*/
void TopologicalSort(Graph G, int topologicalStr[MaxVerNum+1]){
	int inDegree[MaxVerNum+1];	//�������ж�������
	stack<int> topologicalVex;  //�������Ϊ0�Ķ���ջ
	cout << G.VerNum << endl;

	//��ȡ���ж������ȣ��������Ϊ0�Ķ�����ջ
	for(int i = 1; i <= G.VerNum; i++){
		int tempInDegree = 0;
		for(int j = 1; j <= G.VerNum; j++){
			cout << j << " " << i << " " << G.AdjMatrix[j][i] << endl;
			if (i != j && G.AdjMatrix[j][i] > 0 && G.AdjMatrix[j][i] < INF){
				//������j������i�кϷ������򶥵�i����ȼ�һ
				tempInDegree++;
			}
		}
		inDegree[i] = tempInDegree;
		cout << "����" << i << "�����Ϊ" << inDegree[i] << endl;
		if (inDegree[i] == 0){
			topologicalVex.push(i);
		}
	}

	int num = 0; //��¼�������еĶ������
	while(!topologicalVex.empty()){
		//��ջ��Ԫ�ش���Ķ��������������
		int vex = topologicalVex.top();
		topologicalVex.pop();
		topologicalStr[num++] = vex;
		cout << "����" << vex << "������������" << endl;

		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[vex][i] > 0 && G.AdjMatrix[vex][i] < INF && inDegree[i] != 0){
				inDegree[i]--;
				if (inDegree[i] == 0){
					topologicalVex.push(i);
				}
			}
		}
	}

	for(int i = 0; i < num; i++){
		cout << topologicalStr[i];
	}

	cout << endl;

	if (num == G.VerNum){
		cout << "����һ�������޻�ͼ��" << endl;
	}
	else{
		cout << "�ⲻ��һ�������޻�ͼ��" << endl;
	}

}

/*
	�ؼ�·����������Դ�㵽����·��
	˼·����ÿ������(�¼�),����������ʱ��������ʱ�䣬
	ͨ��������㷨Ƕ������������ÿ�������������ʱ�䣬
	ͨ��������㷨Ƕ��������������ÿ�����������ʱ�䣬
	���ڹؼ�·�������κ�ʱ�¼���Ӱ�죬����������ʱ��������ʱ����ȵ�
	���㼴Ϊ�ؼ�·���ϵ�һ�����㣬��˼�������ؼ�·��
	ע�⣺�ؼ�·�����ܲ�ֹһ��
*/
typedef struct Accident{
	int shortestTime;
	int longestTime;
}Accident; 

void PrinKeytPath(Graph G, bool flag[MaxVerNum+1], int sourceVex, int meetingVex, vector<int> &path){
	int temp = sourceVex;
	path.push_back(temp);
	if (temp == meetingVex){
		//���Դ�������غϣ����ӡpath(����ʼԴ�㵽����һ��·��)
		for(int i = 0; i < path.size(); i++){
			cout << path[i] << "	";
		}
		cout << endl;
	}
	else{
		//����Ѱ�ҵ�ǰ����ĺ�̶��㵽����·��
		flag[temp] = false;
		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[temp][i] > 0 && G.AdjMatrix[temp][i] < INF && flag[i]){
				PrinKeytPath(G, flag, i, meetingVex, path);
			}	
		}
	}
	path.pop_back();
}

void CriticalPath(Graph &G, int sourceVex, int meetingVex){
	bool CriticalPath[MaxVerNum+1];			//���ͼ���ڹؼ�·���ϵĶ���
	Accident AllVex[MaxVerNum+1];			//�洢���ж�����ʱ�������ʱ��
	int inDegree[MaxVerNum+1];				//�������ж�������
	int outDegree[MaxVerNum+1]; 			//�洢���ж���ĳ���
	stack<int> topologicalVex;  			//�������Ϊ0�Ķ���ջ
	stack<int> opTopologicalVex;			//�������Ϊ0�Ķ���ջ
	AllVex[sourceVex].shortestTime = 0;		//Դ������ʱ���ʼ��Ϊ0
	AllVex[meetingVex].longestTime = 0;		//�����ʱ���ʼ��Ϊ0

	//��ȡ���ж�����������ȣ��������Ϊ0�����Ϊ0�Ķ���ֱ�ѹ����Ӧ
	for(int i = 1; i <= G.VerNum; i++){
		AllVex[i].shortestTime = 0;

		int tempInDegree = 0;
		int tempOutDegree = 0;

		for(int j = 1; j <= G.VerNum; j++){
			if (i != j && G.AdjMatrix[j][i] > 0 && G.AdjMatrix[j][i] < INF){
				//������j������i�кϷ������򶥵�i����ȼ�һ
				tempInDegree++;
			}
			if (i != j && G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF){
				//������i������j�кϷ������򶥵�i�ĳ��ȼ�һ
				tempOutDegree++;
			}

		}
		inDegree[i] = tempInDegree;
		outDegree[i] = tempOutDegree;

		if (inDegree[i] == 0){
			//���������Ϊ0,���������������ջ
			topologicalVex.push(i);
		}
		if (outDegree[i] == 0){
			//���������Ϊ0�������������������ջ
			opTopologicalVex.push(i);
		}
	}

	//�����������������������ʱ��
	while(!topologicalVex.empty()){
		//��ȡ��������ջջ��Ԫ��
		int vex = topologicalVex.top();
		topologicalVex.pop();

		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[vex][i] > 0 && G.AdjMatrix[vex][i] < INF && inDegree[i] != 0){
				//���µ�ǰ����ĺ�̶�������
				inDegree[i]--;

				if (AllVex[vex].shortestTime + G.AdjMatrix[vex][i] > AllVex[i].shortestTime){
					//���µ�ǰ����ĺ�̶�������ʱ��
					AllVex[i].shortestTime = AllVex[vex].shortestTime + G.AdjMatrix[vex][i];
				}

				if (inDegree[i] == 0){
					//��ĳ��̶������Ϊ0������ջ
					topologicalVex.push(i);
				}
			}
		}
	}

	for(int i = 1; i <= G.VerNum; i++){
		//��ʼ�������������ʱ��
		AllVex[i].longestTime = AllVex[meetingVex].shortestTime;
	}

	//�����������������������ʱ��
	while(!opTopologicalVex.empty()){
		//��ȡ����������ջջ��Ԫ��
		int vex = opTopologicalVex.top();
		opTopologicalVex.pop();

		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[i][vex] > 0 && G.AdjMatrix[i][vex] < INF && outDegree[i] != 0){
				//���µ�ǰ�����ǰ������ĳ���
				outDegree[i]--;

				if (AllVex[vex].longestTime - G.AdjMatrix[i][vex] < AllVex[i].longestTime){
					//���µ�ǰ�����ǰ��������·��
					AllVex[i].longestTime = AllVex[vex].longestTime - G.AdjMatrix[i][vex];
				}

				if (outDegree[i] == 0){
					//��ĳǰ���������Ϊ0������ջ
					opTopologicalVex.push(i);
				}
			}
		}
	}

	for(int i = 1; i <= G.VerNum; i++){
		if (AllVex[i].longestTime == AllVex[i].shortestTime){
			//����������ʱ��������ʱ����ȵ��¼�������֮���
			CriticalPath[i] = true;
		}
		else{
			CriticalPath[i] = false;
		}
	}

	vector<int> path;
	PrinKeytPath(G, CriticalPath, sourceVex, meetingVex, path);
	//��ӡ�ؼ�·��
}

int main(void){
	Graph G;
	CreateGrpFromFile("GraphTestData3.txt", G);
	CriticalPath(G, 1, 10);
    return 0;
}