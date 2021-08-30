//ϣ������
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
void ShellSort1(vector<int> & array);   //ϣ��-��������
void ShellSort2(vector<int> & array);   //ϣ��-ð������
void PutArray(vector<int> & array);     //�����������
int main(void){
    vector<int> myarray1 = {-1, 7, 5, 9, 2, 8, 3, 4, 13, 6};
    vector<int> myarray2 = {3, 7, 2, 9, -9, 10, 29, 18, 1, 0};
    cout << myarray1.size() << endl;;
    ShellSort1(myarray1);
    PutArray(myarray1);
    ShellSort2(myarray2);
    PutArray(myarray2);
    return 0;
}
void ShellSort1(vector<int> & array){
    int length = array.size();
    int gap = length / 2;
    int i, j, temp, k;
    k = 0;
   for(gap; gap > 0 ; gap /= 2){                            //�ı�����
       for(i = gap; i<length; i++){                         
           j = i;       
           temp = array[j];                                 //�����������
           if(array[j] < array[j-gap]){
               while(j-gap>=0 && temp < array[j-gap]){      //����������Ѱ�Һ���λ�ò����������
                   array[j] = array[j-gap];                 //���������к��ƣ��ҳ���λ
                   j -= gap;                              
               }
           }
           array[j] = temp;
       }
   }
}

void ShellSort2(vector<int> & array){
    for(int gap = array.size()/2; gap > 0; gap /= 2){
        for(int i = gap; i < array.size(); i++){
            for(int j = i; j - gap >= 0 && array[j] < array[j-gap]; j -= gap){
                int temp = array[j];            //���ý���λ��
                array[j] = array[j-gap];       
                array[j-gap] = temp;
            }
        }
    }
}

void PutArray(vector<int> &array){
    for(int i=0; i<array.size(); i++){
        cout << array[i] << " ";
    }
    cout << "\n";
    return;
}
//ϣ�������ǰѼ�¼���±��һ���������飬��ÿ��ʹ��ֱ�Ӳ��������㷨����
//���������𽥼��٣�ÿ������Ĺؼ���Խ��Խ�࣬���������� 1 ʱ�������ļ�ǡ���ֳ�һ�飬�㷨����ֹ��