#include <iostream>
#include "LinearList.h"

//����vector�����Ա�ֵ
LinearList::LinearList(vector<int> & array){
    for(int i = 0; i<array.size(); i++){
        date[i] = array[i];
    }
    length = array.size();
}

//����ʵ��
LinearList & DeleteOrdedAE(LinearList & list){
    int num_flag = 0;           //��¼�±�Ԫ�ظ���
    for(int i=0; i<list.length; i++){
        if(list.date[i] == list.date[i+1]){
            continue;
        }
        else{
            list.date[num_flag++] = list.date[i];
        }
        //����ǰԪ������һ��Ԫ����ȣ���˵����Ԫ���ظ���������Ԫ��
        //��list.date[i]��Ӧ��Ԫ�ز�������һ��Ԫ��ʱ˵����ǰԪ�����Ǵˡ��������ظ����Ա�����һ��Ԫ�ء�
        //���临�Ƶ������Ա���±�Ϊnum_flag��λ��
    }
    list.length = num_flag;
    //�����Ա�ĳ������±�Ԫ�ظ�����ֵ
    //ɾ��Զ���Ա����ظ�Ԫ�غ���±����ɹ�
    return list;
}

LinearList & DeleteAE(LinearList & list){
    static LinearList newlist;
    bool Searchflag;
    newlist.date[newlist.length++] = list.date[0];
    for(int i = 1; i<list.length; i++){
        Searchflag = false;
        for(int j=0; j<newlist.length; j++){
            if(list.date[i] == newlist.date[j]){
                Searchflag = true;
                break;
            }
        }
        if(!Searchflag){
            newlist.date[newlist.length++] = list.date[i];
        }
    }
    return newlist;
}

void PutList(LinearList & list){
    for(int i = 0; i<list.length; i++){
        cout << list.date[i] << " ";
    }
    //�������Ա���Ԫ�ز���֮��ӡ
    cout << endl;
    return;
}

//�ܽ᣺���㷨ʱ�临�Ӷ�ΪO(n);
//���ŵ�Ϊ��û��ͨ���ƶ�����Ԫ����ɾ��Ԫ��
//���Ƕ�Ԫ��������ֵ��ȡһ�������Ա�ͷ��ʼ���ǹ��������޸����Ա��ȣ�

