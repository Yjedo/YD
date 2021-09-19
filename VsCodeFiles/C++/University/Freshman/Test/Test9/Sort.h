#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

//��ӡ����Ԫ��
void PrintArray(vector<int> array){
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

//��ȡһ��һ�����ȵ��������
vector<int> getArray(){
    vector<int> array;
    srand(time(NULL));
    for(long i = 0; i < 100000; i++){
        array.push_back(rand());
    }
    return array;
}

//����
int Pow(int a, int n){
    if (n <= 0){
        return 1;
    }
    else{
        return a * pow(a, n-1);
    }
}

//��ӡһ�������ո�
void PrintSpace(int n){
    for(int i = 0; i < Pow(2, n); i++){
        cout << "   ";
    }
}

//��ӡ������洢�Ķ������ṹ
void PrintTree(vector<int> array){
    int length = array.size()-1;
    int i = 1;
    int height;
    while(length > pow(2, i) - 1){
        i++;
    }
    height = i;
    int n = i;

    vector<int> temparray;
    queue<int> intQueue;
    intQueue.push(1);
    while(!intQueue.empty()){
        PrintSpace(n-1);
        while(!intQueue.empty()){
            cout << array[intQueue.front()];
            if (array[intQueue.front()] <= 9){
                cout << "**";
            } else if(array[intQueue.front()] <= 99){
                cout << "*";
            }
            for(int i = 0; i < Pow(2, n)-1; i++){
                cout << "   ";
            }

            if (Pow(2, n)-1 == 0){
                cout << "  ";
            }
            int lc = intQueue.front() * 2;
            int rc = lc + 1;
            if (lc <= length)
            temparray.push_back(lc);
            if (rc <= length)
            temparray.push_back(rc);
            intQueue.pop();
        }

        cout << endl;

        for(int i = 0; i < temparray.size(); i++){
            intQueue.push(temparray[i]);
        }

        while(!temparray.empty()){
            temparray.pop_back();
        }
        n--;
    }
}

//��������
void QuicklySort(vector<int> &array, int left, int right){
    if (left > right){
        return;
    }
    int l = left;
    int r = right;
    int mid = array[l];

    while(l < r){
        while(l < r && array[r] >= mid){
            r--;
        }
        array[l] = array[r];
        while(l < r && array[l] <= mid){
            l++;
        }
        array[r] = array[l];
    }
    array[l] = mid;
    PrintArray(array);
    QuicklySort(array, left, l-1);
    QuicklySort(array, l+1, right);
}

//���������ʽ
void SpecialQuicklySort(vector<int> &array, int left, int right){
    if (left > right){
        return;
    }
    int l = left;
    int r = right;
    int mid = array[l];

    while(l < r){
        while(l < r && array[r]%3 >= mid%3){
            r--;
        }
        array[l] = array[r];
        while(l < r && array[l]%3 <= mid%3){
            l++;
        }
        array[r] = array[l];
    }
    array[l] = mid;
    QuicklySort(array, left, l-1);
    QuicklySort(array, l+1, right);
}

//ϣ������
void ShellSort(vector<int> &array){
    int arrayLength = array.size();
    int d = arrayLength / 2;
    while(d > 0){
        for(int i = d; i < arrayLength; i++){
            //���ڰ��������ֵ�ÿһ�����У�Ĭ��ÿ�����е�һ��Ԫ��Ϊ����,�ӵڶ���Ԫ�ؿ�ʼ�����������в���
            for(int j = i; j-d > -1 && array[j] < array[j-d]; j -= d){
                //���ִ�����Ԫ�ص�ǰһ��Ԫ�ش�����������֮����λ�ã�ֱ���ҵ����ʲ���λ��
                int temp = array[j];
                array[j] = array[j-d];
                array[j-d] = temp;
            }
        }
        cout << "����Ϊ" << d << "ʱ�����������£�" << endl;
            int k = 0;
            while(k < d){
                cout << "��" << k+1 << "��:" << endl; 
                for(int t = k; t < array.size(); t += d){
                    cout << array[t] << " ";
                }
                cout << endl;
                k++;
            }
        cout << "��ʱȫ�������������£�" << endl;
        PrintArray(array);
        d /= 2;
    }
}

//ɸѡ��
void sift(vector<int> &array, int m, int n){
    int temp = array[m];
    int i = m;
    int j = i * 2;
    while(1){
        //jָ���ӽ���нϴ��һ��
        if (j < n && array[j] < array[j+1]){
            j += 1;
        }

        //��temp���������ӽڵ㣬��i��ָλ�ü�tempӦ����λ��
        if (j > n || temp >= array[j]){
            array[i] = temp;
            break;
        } 
        else{
            array[i] = array[j];
            i = j;
            j *= 2;
        }

    }

}

//������
void HeapSort(vector<int> &array){
    cout << "ԭ���ݣ�" << endl;
    PrintTree(array);
    for(int i = (array.size()-1)/2; i > 0; i--){
        sift(array, i, array.size()-1);
    }

    cout << "��ʼ�ѣ�" << endl;
    PrintTree(array);

    cout << "�����������:" << endl;
    for(int j = array.size()-1; j > 1; j--){
        //�����
        int temp = array[1];
        array[1] = array[j];
        array[j] = temp;
        cout << "�����" << temp << "�Ժ�Ķѣ�" << endl;
        PrintTree(array);
        //���������������Ѳ�����ѵ����ԣ����ع�
        sift(array, 1, j-1);
        cout << "�ع���Ķѣ�" << endl;
        PrintTree(array);
    }
}

//����ѡ������
const int null = 999;
void TreeSelectSort(vector<int> &array){
   vector<int> tree;
   int length = array.size();
   int height = 0;

    //�����Դ���������Ϊ���һ������������ĸ߶�
   while(length > Pow(2, height) - 1){
       height++;
   }

   height += 1;

   //�������������(��λ��null����)
   int i = 0;
   //�����ϲ�
   while(i < Pow(2, height-1)){
       tree.push_back(null);
       i++;
   }
   //�Դ���������������һ��
   while(!array.empty()){
       tree.push_back(array[array.size()-1]);
       array.pop_back();
   }
    //�������һ��ȱ�ٵ�Ԫ��
   while(tree.size() < Pow(2, height)){
       tree.push_back(null);
   }

    cout << "����������£�" << endl;
    while(array.size() != length){
        int n = height;
        while(n != 1){
            for(int i = Pow(2, n-1); i < Pow(2, n); i += 2){
                tree[i/2] = tree[i] < tree[i+1] ? tree[i] :tree[i+1];
            }
            n--;
        }
        PrintTree(tree);
        cout << endl;
        for(int i = Pow(2, height-1); i < Pow(2, height); i++){
            if (tree[i] == tree[1]){
                array.push_back(tree[i]);
                tree[i] = null;
            }
        }
    }   
}

void RadixSort(vector<int> &array){
    vector<vector<int>> panel;
    int length = array.size();

    while(panel.size() < 10){
        vector<int> temp;
        panel.push_back(temp);
    }

    int n = 1;
    while(n < 1000){
        for(int i = 0; i < length; i++){
            panel[array[i]/n%10].push_back(array[i]);
        }

        int k = 0;

        for(int j = 0; j < 10; j++){
            while(!panel[j].empty()){
                array[k++] = panel[j][panel[j].size()-1];
                panel[j].pop_back();
            }
        }

        switch(n){
            case 1 :cout << "����λ������������£�" << endl; break;
            case 10 :cout << "��λʮλ������������£�" << endl; break;
            case 100 :cout << "����λ������������£�" << endl; break;
        }

        PrintArray(array);

        n *= 10;       
    }
}