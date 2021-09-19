#include "StackTest.h"
using namespace std;

//˳��ջ��ʼ��
ArrayStack::ArrayStack(){
    top = 0;
}
//˳��ջ��ջ
bool ArrayStack::push_stack(int newdate){
    if(top == MAXLEN){
        cout << "ջ������" << endl;
        return false;
    }
    date[top++] = newdate;
    return true;
}
//˳��ջ��ջ
int ArrayStack::pop_stack(void){
    if (top == 0){
        cout << "ջΪ�գ�" << endl;
        return -1;
    }
    top--;
    return date[top];
}
//˳��ջ��ȡջ������
int ArrayStack::get_top_date(void){
    return date[top-1];
}
//�ж�˳��ջ�Ƿ�Ϊ��
bool ArrayStack::is_empty(void){
    if (top == 0){
        return true;
    }
    return false;
}
//�ж�˳��ջ�Ƿ�����
bool ArrayStack::is_full(void){
    if (top == MAXLEN){
        return true;
    }
    return false;
}
//��ȡջ�߶�
int ArrayStack::get_top(void){
    return top;
}
//��������
Linklist::Linklist(){
    head = new Node;
    head->pnext = NULL;
}
//������ͷ���½��
bool Linklist::AddNode(Date newdate){
    Node *newnode = new Node;
    newnode->node_date = newdate;
    newnode->pnext = head->pnext;
    head->pnext = newnode;
    cout << "��ӳɹ���" << endl;
    return true;
}
//������ɾ����һ�����
bool Linklist::DeleteNode(void){
    if(head->pnext == NULL){
        cout << "ջ�ѿգ�" << endl;
        return false;
    }
    Node *p;
    p = head->pnext;
    head->pnext = p->pnext;
    delete p;
    cout << "ɾ���ɹ���" << endl;
    return true;
}
//��ջ��ʼ��
LinkStack::LinkStack() {}
//��ջ��ջ
bool LinkStack::push_stack(char newdate){
    list.AddNode(newdate);
    return true;
}
//��ջ��ջ
int LinkStack::pop_stack(void){
    int temp = list.head->pnext->node_date;
    list.DeleteNode();
    return temp;
}
//�ж���ջ�Ƿ�Ϊ��
bool LinkStack::is_empty(void){
    if (list.head->pnext == NULL){
        return true;
    }
    else{
        return false;
    }
}
//��ȡ��ջջ������
int LinkStack::get_top_date(void){
    return list.head->pnext->node_date;
}
//��ʮ������ת��Ϊʮ�����������ַ�����ʽ��
char * ChangeNumber1(int number){
    ArrayStack stack;
    char *str = new char[20];
    int temp;
    int i = 0;
    while(number!=0){
        stack.push_stack(number % 16);
        number /= 16;
    }
    while(!stack.is_empty()){
        temp = stack.pop_stack();
        if (temp < 9){
            str[i] = '0' + temp;
        }
        else{
            str[i] = 'A'+(temp-10);
        }
        i++;
    }
    str[i] = '\0';
    return str;
}

char * ChangeNumber2(int number){
    LinkStack stack;
    char *str = new char[20];
    int temp;
    int i = 0;
    while(number!=0){
        stack.push_stack(number % 16);
        number /= 16;
    }
    while(!stack.is_empty()){
        temp = stack.pop_stack();
        if (temp < 9){
            str[i] = '0' + temp;
        }
        else{
            str[i] = 'A'+(temp-10);
        }
        i++;
    }
    str[i] = '\0';
    return str;
}
//�ж�һ����ѧ���ʽ�������Ƿ�Ϸ�
bool Legalbracket1(char *input){
    vector<char> str(100);
    char ch;
    int i = 0, j = 0;
    while(input[i] != '\0'){
        ch = input[i++];
        if (ch == '{' || ch == '[' ||ch == '('){
            str[j] = ch;
            j++;
        }
        else if(ch == '}' || ch == ']' ||ch == ')'){
            if (ch-str[j-1] < 3 && ch - str[j-1] > -3){
                j--;
            }
            else {
                str[j++] = ch;
            }
        }
        else {}
    }
    if (j==0){
        cout << "������ʽ�����źϷ���" << endl;
        return true;
    }
    else{
        cout << "������ʽ�����Ų��Ϸ���" << endl;
        return false;
    }
}

bool Legalbracket2(char *input){
    LinkStack listStack;
    char ch;
    int i = 0;
    while(input[i] != '\0'){
        ch = input[i++];
        if (ch == '{' || ch == '[' ||ch == '('){
           listStack.push_stack(ch);
        }
        else if(ch == '}' || ch == ']' ||ch == ')'){
            if (ch-listStack.get_top_date() < 3 && ch - listStack.get_top_date() > -3){
               listStack.pop_stack();
            }
            else {
                listStack.push_stack(ch);
            }
        }
        else {}
    }
    if (listStack.is_empty()){
        cout << "������ʽ�����źϷ���" << endl;
        return true;
    }
    else{
        cout << "������ʽ�����Ų��Ϸ���" << endl;
        return false;
    }
}
//�ж������Ƿ�Ϊջ�ĺϷ��������
bool legal_put_array(vector<int> & input_array, vector<int> & put_array){
    ArrayStack stack;
    int i = 0, j = 0;
    while(i<input_array.size()){
        stack.push_stack(input_array[i++]);           
        while(!stack.is_empty()){
            if (stack.get_top_date() == put_array[j]){
            j++;
            stack.pop_stack();
            }
            else{
                break;
            }
        }
        //�ж�ջ��Ԫ�������������е�ǰԪ���Ƿ����
        //����򽫽�ջ��Ԫ�ص�����jָ�����������е���һ��Ԫ��
        //������������ջ
        //����������ȫ����ջ�����˴��жϹ��̹���ջ��Ϊ�գ���˵��������в��Ϸ�
        //��Ϊ�գ���Ϸ�
    }
    if (stack.is_empty()){
        cout << "�Ϸ���" << endl;
        return true;
    }
    cout << "���Ϸ���" << endl;
    return false;
}

