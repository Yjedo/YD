//�����Ա�ģ�⼯��
//��ʵ��һЩ�������
//�����ص㣺һ�����������ظ�Ԫ��, ��Ԫ������
#include "LinearList.h"

//����
LinearList & IntersectSet(LinearList & A_list, LinearList & B_list){
    static LinearList C_list;//���ֲ����Ա��������Ϊ��̬�� �Ա㺯������ʱ�ö���ռ�ڴ治�ᱻ���գ���ͬ
    for(int i =0; i<A_list.length; i++){
        for(int j=0; j<B_list.length; j++){
            if(A_list.date[i]==B_list.date[j]){
                C_list.date[C_list.length] = A_list.date[i];
                C_list.length++;
                break;
            }
        }
    }
    return C_list;
}
//������ʱ�临�Ӷ�ΪO(n^2)

//����
LinearList & UnionSet(LinearList & A_list, LinearList & B_list){
    static LinearList C_list;
    int newElementNum = 0;
    bool Searchflag;
    for(int i=0; i<A_list.length; i++){
        C_list.date[i] = A_list.date[i];
    }
    C_list.length = A_list.length;
    for(int j=0; j<B_list.length; j++){             //˫ѭ�������Ƚ������Ա��е�Ԫ��
        Searchflag = false;
        for(int i =0; i<C_list.length; i++){
            if(B_list.date[j] == C_list.date[i]){                          
                Searchflag = true;                  //�ҵ�������������־��ֵΪtrue
                break;                              //Ȼ���˳�����ѭ��
            }
        }
        if (!Searchflag){
            C_list.date[C_list.length+newElementNum] = B_list.date[j];  //����������־���±�ֵ
            newElementNum++;
        }
    }
    C_list.length += newElementNum;
    return C_list;
}

//������ʱ�临�Ӷ�ΪO(n^2)

//������A-B������ȥA����B�ظ���Ԫ��
LinearList & MinusSet(LinearList & A_list, LinearList & B_list){
    static LinearList C_list;
    bool searchFlag;
    int k = 0;
    for(int i = 0; i<A_list.length; i++){
        searchFlag = false;
        for(int j = 0; j<B_list.length; j++){
            if (A_list.date[i] == B_list.date[j]){
                searchFlag = true;
                break;
            }
        }
        if (!searchFlag){
            C_list.date[k] = A_list.date[i];
            k++;
        }
    }
     return C_list;
}
//������ʱ�临�Ӷ�ΪO(n^2)
/*******************************************************************************
 *˼����ͨ���Ա��������򼯺ϵ�����㷨���ѷ��֣����ǵò��ɱ���Ľ��ж���ѭ��
 * �����д���㷨�����ϸ�ڿ����Ż�����˼�����������Ѳ��˽��ж���ѭ���Ա��������е�Ԫ�أ�
 * ����ÿ��Ԫ�ض����ò�����һ�����е�����Ԫ�رȽ�һ��
 * ����˷���ʱ��
********************************************************************************/

//����Ϊ���򼯺ϵ�����㷨ʵ�֣�
//Ĭ�����򼯺ϰ���С��������

//����
LinearList & ordered_IntersectSet(LinearList & A_list, LinearList & B_list){
    int i = 0, j = 0;
    static LinearList C_list;
    while(i<A_list.length && j<B_list.length){
        if (A_list.date[i] == B_list.date[j]){
            C_list.date[C_list.length++] = A_list.date[i++];
            j++;
        }
        else if(A_list.date[i] > B_list.date[j]){
            j++;
        }
        else{
            i++;
        }
        //��Ϊ��������һ��ѭ�����ɱȽ���������Ԫ��
    }
    return C_list;
}

//����
LinearList & ordered_UnionSet(LinearList & A_list, LinearList & B_list){
      int i = 0, j = 0;
    static LinearList C_list;
    while(i<A_list.length && j<B_list.length){
        if (A_list.date[i] == B_list.date[j]){
            i++;
        }
        else if(A_list.date[i] > B_list.date[j]){
            C_list.date[C_list.length++] = B_list.date[j++];
        }
        else{
            C_list.date[C_list.length++] = A_list.date[i++];
        }
        //��Ϊ��������һ��ѭ�����ɱȽ���������Ԫ��
    }
    if (i==A_list.length){
        for(j; j<B_list.length; j++){
            C_list.date[C_list.length++] = B_list.date[j];
        }
    }
    else if(j == B_list.length){
        for(i; i<A_list.length; i++){
            C_list.date[C_list.length++] = A_list.date[i];
        }
    }
    else {}
    return C_list;
}

//����
LinearList & ordered_MinusSet(LinearList & A_list, LinearList & B_list){
     int i = 0, j = 0;
    static LinearList C_list;
    while(i<A_list.length && j<B_list.length){
        if (A_list.date[i] == B_list.date[j]){
            i++;
            j++;
            continue;
        }
        else if(A_list.date[i] > B_list.date[j]){
           j++;
        }
        else{
            C_list.date[C_list.length++] = A_list.date[i++];
        }
        //��Ϊ��������һ��ѭ�����ɱȽ���������Ԫ��
    }
    if (i == A_list.length){
        ;
    }
    else{
        for (i; i<A_list.length; i++){
             C_list.date[C_list.length++] = A_list.date[i];
        }
    }
    return C_list;
}

//������ʱ�临�ӶȽ�ΪO(n^2)

/**************************************************************
*˼���� ͨ���Ա�����������ļ��ϵ�����㷨�ɷ��֣�����ʱ�临�ӶȲ�༫��
*       ԭ�������򼯺ϲ���Ҫ�����������ϼ��ɵ�֪��Ԫ���Ƿ�����ڴ˼����У�
*       ��Ϊ��������ĳ��λ�÷��ֵ�ǰԪ���Ѿ���Ѱ��Ԫ�ش��ˣ��������Ա���Ԫ���ǰ���������
*       ������Ȼ֮���������Ҳ�����ڸ�Ԫ�أ����������ж�
*       �����򼯺��ж�һ��Ԫ���Ƿ���ڣ�������������������Ա���Ϊ������Զ����֪��
*       ��Ԫ���Ƿ��Ǵ��������Ա�����һ��λ��
***************************************************************/
