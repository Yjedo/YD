#include <iostream>
#include "Sort.h"
using namespace std;

void Menu(void){
    cout << "1.��������" << endl;
    cout << "2.��������Ԫ��,����3��ģ��С��������" << endl;
    cout << "3.ϣ������" << endl;
    cout << "4.����ѡ������" << endl;
    cout << "5.������" << endl;
    cout << "6.��ʽ��������" << endl;
    cout << "ע���˳�������-1" << endl;
}

int main(void){
    vector<int> array1 = {3, 1, 2, 5, 8, 7, 4, 9, 0};
    vector<int> array2 = {1, 5, 4, 7, 3, 9, 6, 8, 10};
    vector<int> array3 = {3,4,1,8,6, 10, 19};
    vector<int> array4 = {239, 351, 178, 804, 472, 713, 525, 683, 974};
    vector<int> array5 = {23, 1, 45, 8, 9, 0, 34, 4, 7};
    while(1){
        Menu();
        cout << "��������ţ�";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "ԭ���飺" << endl;
            PrintArray(array1);
            cout << "�����������" << endl;
            QuicklySort(array1, 0, array1.size()-1);
            cout << "�����������������飺" << endl;
            PrintArray(array1);
            system("pause");
            break;
        
        case 2:
            cout << "ԭ���飺" << endl;
            PrintArray(array5);
            SpecialQuicklySort(array5, 0, array5.size()-1);
            cout << "�����������������飺" << endl;
            PrintArray(array5);
            system("pause");
            break;
        case 3:
            cout << "ԭ���飺" << endl;
            PrintArray(array2);
            ShellSort(array2);
            cout << "����ϣ�����������飺" << endl;
            PrintArray(array2);
            system("pause");
            break;
        case 4:
            cout << "ԭ���飺" << endl;
            PrintArray(array3);
            TreeSelectSort(array3);
            cout << "��������ѡ�����������飺" << endl;
            PrintArray(array3); 
            system("pause");
            break;

        case 5:
            cout << "ԭ���飺" << endl;
            PrintArray(array3);
            HeapSort(array3);
            cout << "���������������飺" << endl;
            PrintArray(array3); 
            system("pause");
            break;

        case 6:
            cout << "ԭ���飺"<<endl;
            PrintArray(array4);
            RadixSort(array4);
            cout << "������ʽ�������������飺" << endl;
            PrintArray(array4); 
            system("pause");
            break;
        default:
            return -1;
        }

        system("cls");
    }
    return 0;
}