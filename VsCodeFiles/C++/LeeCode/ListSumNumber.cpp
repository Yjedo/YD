/*��������?�ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ���?����?�ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢?һλ?���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
����Լ���������� 0 ֮�⣬���������������� 0?��ͷ��*/
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
 };
class Solution {
public:
    struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        struct ListNode *LTemp, *LSum, *p;
        struct ListNode *p1, *p2;
        p1=l1->next;
        p2=l2->next;
        int x=0;
        LSum = new struct ListNode;
        LTemp = LSum;
        while (p1&&p2) {
            p = new struct ListNode;
            p->val = (p1->val + p2->val + x)%10;
            x = (p1->val+p2->val + x)/10;
            p1 = p1->next;
            p2 = p2->next;
            p->next = NULL;
            LTemp->next = p;
            LTemp = p;
        }
        if (!p1) {
            while (p2) {
            p = new struct ListNode;
            p->val = (p2->val + x)%10;
            x = (p2->val + x)/10;
            p2 = p2->next;
            p->next = NULL;
            LTemp->next=p;
            LTemp = p;
        }
        }
        else if(!p2){
           while (p1) {
            p = new struct ListNode;
            p->val = (p1->val + x)%10;
            x = (p1->val + x)/10;
            p1 = p1->next;
            p->next = NULL;
            LTemp->next=p;
            LTemp = p;
        }
        }
        else{
            ;
        }
        if(x){
            p = new struct ListNode;
            p->val = x;
            p->next=NULL;
            LTemp->next=p;
            LTemp=p;
        }
        return LSum;
    }
};
ListNode *Createlist(void);
void Travelist(ListNode *p);
int main(void)
{
    Solution way1;
    ListNode *p1, *p2, *p3;
    p1 = Createlist();
    p2 = Createlist();
    p3 = way1.addTwoNumbers(p1,p2);
    Travelist(p3);
    return 0;
}
ListNode *Createlist(void){
    ListNode *p1, *p2, *p3;
    int date;
    p1 = new ListNode;
    p2=p1;
    while(1){
        cout << "Please input your list date:" << endl;
        cin >> date;
        if(date == -1){
            break;
        }
        p3 = new ListNode;
        p3->val = date;
        p3->next = NULL;
        p2->next=p3;
        p2=p3;
    }
    return p1;
}
void Travelist(ListNode *p){
    ListNode *px;
    px=p->next;
    while(px){
        cout << px->val;
        px=px->next;
    }
    cout << endl;
}
