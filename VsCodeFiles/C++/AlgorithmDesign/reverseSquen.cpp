#include <iostream>
#include <algorithm>
#include <vector>

/**
 * @brief �ж�һ���ַ����Ƿ�Ϊ�����ַ���
 * */
bool isReverStr(std::string s){
    std::string temps = s;
    std::reverse(s.begin(), s.end());
    return temps == s; 
}

/**
 * @brief ��һ��ʮ����������ת��Ϊ����������������ַ���
 * @param k ����
 **/
std::string turnString(int N, int k){
    std::string str;
    while(N > 0){
        str.push_back(N%k + '0');
        N /= k;
    }
    return str;
}

/**
 * @brief �ҳ�����10����ʮ���ư˽��ƶ���������Ϊ����������С������
 * */

int getMinReveNum(void){
    std::string number, binaryNumber, octalNumber;
    std::string temps1, temps2, temps3;
    //������Ϊ������������һ��Ϊ����
    for(int i = 11;  ;i += 2){
        number = turnString(i, 10);
        binaryNumber = turnString(i, 2);
        octalNumber = turnString(i, 8);
        temps1 = number;
        temps2 = binaryNumber;
        temps3 = octalNumber;
        std::reverse(number.begin(), number.end());
        std::reverse(binaryNumber.begin(), binaryNumber.end());
        std::reverse(octalNumber.begin(), octalNumber.end());
        if(number == temps1 && binaryNumber == temps2 && temps3 == octalNumber){
            std::cout << number << "    " << binaryNumber << "  " << octalNumber << std::endl;
            return i;
        }
    }
    return -1;
}

int main(void){
    //std::cout << getMinReveNum();
    std::string testStr1 = "abcba";
    std::string testStr2 = "abbad";
    std::cout << isReverStr(testStr1) << std::endl;
    std::cout << isReverStr(testStr2) << std::endl;
    return 0;
}

