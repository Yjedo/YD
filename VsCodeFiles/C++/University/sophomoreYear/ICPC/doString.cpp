#include <string>
#include <iostream>
using namespace std;
//�����ļӼ��˳���ȡģ����
string ADD_INT(string str1, string str2);
string MULTIPLY_INT(string str1, string str2);
string MINUS_INT(string str1, string str2);
string DIVID_INT(string str1, string str2, int z);
string DIV_INT(string str1, string str2);
string MOD_INT(string str1, string str2);
//�Ƚ����������Ĵ�С
int comp(string str1, string str2);
int comp(string str1, string str2)
{
    if (str1.length() > str2.length()) //���ȳ����������ڳ���С������
        return 1;
    else if (str1.length() < str2.length())
        return -1;
    else
        return str1.compare(str2); //��������ȣ���ͷ��β��λ�Ƚϣ�compare ��������ȷ��� 0�����ڷ��� 1��С�ڷ��أ�1
}
//�����ӷ�
string ADD_INT(string str1, string str2)
{
    //����������
    int b = 1;
    string str;
    if (str1[0] == '-')
        if (str2[0] == '-')
        {
            b = -1;
            str = ADD_INT(str1.erase(0, 1), str2.erase(0, 1));
        }
        else
            str = MINUS_INT(str2, str1.erase(0, 1));
    else
    {
        if (str2[0] == '-')
            str = MINUS_INT(str1, str2.erase(0, 1));
        else
        {
            //�������������룬���Ȳ���ʱ���ڶ̵�����ǰ�� 0 ���볤��
            int l1 = str1.length(), l2 = str2.length();
            if (l1 < l2)
                for (int i = 1; i <= l2 - l1; i++)
                    str1 = "0" + str1;
            else
                for (int i = 1; i <= l1 - l2; i++)
                    str2 = "0" + str2;
            //��λ����λ��
            int int1 = 0, int2 = 0; //Int2 ��¼��λ
            for (int i = str1.length() - 1; i >= 0; i--)
            {
                int1 = (int(str1[i]) - 48 + int(str2[i]) - 48 + int2) % 10;
                int2 = (int(str1[i]) - 48 + int(str2[i]) - 48) / 10;
                str = char(int1 + 48) + str;
            }
            if (int2 != 0)
                str = char(int2 + 48) + str;
        }
    }
    //����������
    if ((b == -1) && (str[0] != '0'))
        str = "-" + str;
    return str;
}
//��������
string MINUS_INT(string str1, string str2)
{
    string str;
    //������ţ��еĿ���ת���ɼӷ�
    int b = 1;
    if (str2[0] == '-')
        str = ADD_INT(str1, str2.erase(0, 1));
    else
    {
        if (comp(str1, str2) == 0)
            return "0";
        if (comp(str1, str2) < 0)
        {
            swap(str1, str2);
            b = -1;
        }
        //��λ����λ��
        int tempint = str1.length() - str2.length(), i;
        for (i = str2.length() - 1; i >= 0; i--)
        {
            if (str1[i + tempint] < str2[i])
            {
                str1[i + tempint - 1] = char(int(str1[i + tempint - 1]) - 1);
                str = char(str1[i + tempint] - str2[i] + 58) + str;
            }
            else
                str = char(str1[i + tempint] - str2[i] + 48) + str;
        }
        for (i = tempint - 1; i >= 0; i--)
            str = str1[i] + str;
    }
    //ȥ�������ͷ�϶���� 0
    str.erase(0, str.find_first_not_of('0'));
    if (str.empty())
        str = "0";
    //��������Ϸ���
    if ((b == -1) && (str[0] != '0'))
        str = "-" + str;
    return str;
}
//�����ĳ˷�
string MULTIPLY_INT(string str1, string str2)
{
    string str;
    //�������λ
    int b = 1;
    if (str1[0] == '-')
    {
        str1 = str1.erase(0, 1);
        b = b * -1;
    }
    if (str2[0] == '-')
    {
        str2 = str2.erase(0, 1);
        b = b * -1;
    }
    //��λʵ���ֹ��˷�
    for (int i = str2.length() - 1; i >= 0; i--)
    {
        int int1 = 0, int2 = 0, int3 = int(str2[i]) - 48;
        string tempstr;
        if (int3 != 0)
        {
            int j;
            for (j = 1; j <= int(str2.length() - 1 - i); j++)
                tempstr = "0" + tempstr;
            for (j = str1.length() - 1; j >= 0; j--)
            {
                int1 = (int3 * (int(str1[j]) - 48) + int2) % 10;
                int2 = (int3 * (int(str1[j]) - 48) + int2) / 10;
                tempstr = char(int1 + 48) + tempstr;
            }
            if (int2 != 0)
                tempstr = char(int2 + 48) + tempstr;
        }
        str = ADD_INT(str, tempstr);
    }
    //ȥ�������ͷ�϶���� 0
    str.erase(0, str.find_first_not_of('0'));
    if (str.empty())
        str = "0";
    //��������Ϸ���
    if ((b == -1) && (str[0] != '0'))
        str = "-" + str;
    return str;
}
//�����ĳ�����Z��1 ʱ�����̣�Z=2 ʱ��������
string DIVIDE_INT(string str1, string str2, int z)
{
    string quotient, residue;
    int a = 1, b = 1;
    //�жϳ���Ϊ 0
    if (str2[0] == '0')
    {
        quotient = "ERROR!";
        residue = "ERROR!";
        if (z == 1)
            return quotient;
        else
            return residue;
    }
    if (str1[0] == '0')
    {
        quotient = "0";
        residue = "0";
    }
    //�������λ
    if (str1[0] == '-')
    {
        str1 = str1.erase(0, 1);
        a = a * -1;
        b = -1;
    }
    if (str2[0] == '-')
    {
        str2 = str2.erase(0, 1);
        a = a * -1;
    }
    if (comp(str1, str2) < 0)
    {
        quotient = "0";
        residue = str1;
    }
    if (comp(str1, str2) == 0)
    {
        quotient = "1";
        residue = "0";
    }
    if (comp(str1, str2) > 0)
    {
        int length1 = str1.length(), length2 = str2.length();
        string tempstr;
        tempstr.append(str1, 0, length2 - 1);
        //ģ���ֹ�����
        for (int i = length2 - 1; i < length1; i++)
        {
            tempstr = tempstr + str1[i];
            //����
            for (char ch = '9'; ch >= '0'; ch--)
            {
                string str;
                str = str + ch;
                if (comp(MULTIPLY_INT(str2, str), tempstr) <= 0)
                {
                    quotient = quotient + ch;
                    tempstr = MINUS_INT(tempstr, MULTIPLY_INT(str2, str));
                    break;
                }
            }
        }
        residue = tempstr;
    }
    //ȥ�������ͷ�϶���� 0
    quotient.erase(0, quotient.find_first_not_of('0'));
    //��������Ϸ���
    if (quotient.empty())
        quotient = "0";
    if ((a == -1) && (quotient[0] != '0'))
        quotient = "-" + quotient;
    if ((b == -1) && (residue[0] != '0'))
        residue = "-" + residue;
    if (z == 1)
        return quotient;
    else
        return residue;
}
string MOD(string str1, string str2)
{
    return DIVIDE_INT(str1, str2, 2);
}
string DIV(string str1, string str2)
{
    return DIVIDE_INT(str1, str2, 1);
}

int main(void){
    string s1 = "11";
    string s2 = "13";
    string s3 = "7";
    string s4 = "4";
    cout << s1 << " + " << s2 << " = " << ADD_INT(s1, s2) << endl;
    cout << s1 << " - " << s2 << " = " << MINUS_INT(s1, s2) << endl;
    cout << s1 << " % " << s4 << " = " << MOD(s1, s4) << endl;
    cout << s1 << " * " << s2 << " = " << MULTIPLY_INT(s1, s2) << endl;
}