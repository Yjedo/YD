#include <iostream>
#include "LinearList.h"
#define ERROR -1
//����ʵ��
LinearList::LinearList(vector<int> & array){
    for(int i = 0; i<array.size(); i++){
        date[i] = array[i];
    }
    length = array.size();
}

int LinearList::Search_element(int i){
    if (i>length || i<1){
        cout << "���ҵ�Ԫ�ز����ڻ��±�Խ��" << endl;
        return ERROR;
    }
    cout << date[i-1] << endl;
    return date[i-1];
}

bool LinearList::Inseret_node(int i, int x){
    if (i>length || i<1){
        cout << "�޴˽�㣡" << endl;
        return false;
    }
    for(int j = length-1; j>i-2; j--){
        date[j+1] = date[j];    //�ƶ���i����㼰��֮���Ԫ��
    }
    date[i-1] = x;
    length++;
    cout << "����ɹ���" << endl;
    return true;
}

bool LinearList::Delete_node(int i){
    if (i>length || i<1){
        cout << "�޴˽�㣡" << endl;
        return false;
    }
    for(int j=i; j<length; j++){
        date[j-1] = date[j];    //�ƶ���i+1������֮���Ԫ�ؽ���i��Ԫ�ظ���
    }
    length--;
    cout << "ɾ���ɹ���" << endl;
    return true;
} 

bool LinearList::Add_element(int x){
    int i;
    for(i = 0; i<length; i++){
        if(date[i] < x){
            i++;
        }
        else{
            break;
        }
    }
    for(int j = length-1; j>i-1; j--){
        date[j+1] = date[j];
    }
    date[i] = x;
    length++;
    return true;
}

bool LinearList::Separate_list(LinearList & A, LinearList & B){
    int Aflag=0, Bflag=0;
    for(int i = 0; i<length; i++){
        if(date[i]%2 == 0){     //�ж���ż��
            A.date[Aflag++] = date[i];
        }
        else{
            B.date[Bflag++] = date[i];
        }
    }
    A.length = Aflag;
    B.length = Bflag;    
    return true;
}

bool LinearList::Public_element(LinearList & A, LinearList & B){
    int i=0, j=0, k=0;
    while(i<A.length && j<B.length){
        if(A.date[i] == B.date[j]){
            date[k++] = A.date[i];
            i++;
            j++; 
        }
        else if(A.date[i] > B.date[j]){
            j++;
        }
        else{
            i++;
        }
    }
    length = k;
    return true;
}

bool LinearList::Delete_same_element(void){
    if (length<2){
        cout << "���Ա����ظ�Ԫ�أ�" << endl;
        return false;
    }
    int i = 0, j = 0;
    while(j<length){
        if(date[j] != date[j+1]){   //�Ƚϵ�ǰԪ������֮��Ԫ�صĹ�ϵ
            date[i++] = date[j];
        }
        j++;
    }
    length = i;
    return true;
}

void LinearList::Travellist(void){
    for(int i = 0; i<length; i++){
        cout << date[i] << " ";
    }
    cout << endl;
    return;
}

int LinearList::MidNumber(LinearList & A, LinearList & B){
    int MidNumberFlag = 0;
    int temp;
    int i = 0, j = 0;
    while(MidNumberFlag != A.length){
        if(A.date[i] > B.date[j]){
            temp = B.date[j];
            j++;
            MidNumberFlag++;
        }
        else{
            temp = A.date[i];
            MidNumberFlag++;
            i++;
        }
    } 
    return temp;
}
/*�㷨˼�룺�������ȳ��������е���λ�������������еĳ��Ⱦ�ΪL, ����������������Ϊһ���µ�����
��ô��λ����Ȼ�������еĵ�L��λ�õ����������±�ΪL������ôΪ�˽�ʡ�ռ���ʱ�䣬����MidNumberFlagΪ��λ��λ�ñ�־
temp�洢��ǰ������У���������������һ��������MidNumber = L ʱ��˵��temp��Ϊ�����е���λ��
���ӣ�A = {1, 3, 5}, B = (2, 4, 6), ��ôL=3�� MidNumberFlag��ʼֵΪ0;
�Ƚ�1��2�� 1<2, ��MidNumberFlag+1������1Ϊ������еĵ�MidNumberFlag��Ԫ�أ�(MidNumberFlag��ʱΪ1)
�Ƚ�3��2�� 3>2, ��MidNumberFlag+1������2Ϊ������еĵ�MidNumberFlag��Ԫ�أ�(MidNumberFlag��ʱΪ2)
�Ƚ�3��4, 3<4, ��MidNumberFlag+1������3Ϊ������еĵ�MidNumberFlag��Ԫ��,(MidNumberFlag��ʱΪ3)
���ˣ�����MidNumberFlag = L, ����3��Ϊ�����е���λ��
*/