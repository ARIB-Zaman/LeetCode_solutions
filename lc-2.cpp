#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    unsigned long long val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(unsigned long long x) : val(x), next(nullptr) {}
    ListNode(unsigned long long x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 5-6-7-8-9
    //1-2
    //98765+21
    ListNode* ans = new ListNode();
    ListNode* t = ans;
    int c = 0;
    while(l1 || l2){
        int a, b;
        if(l1){
            a = l1->val;
            l1 = l1->next;
        }else a = 0;
        if(l2){
            b = l2->val;
            l2 = l2->next;
        }else b = 0;

        c = a+b+c;
        ans->val = c%10;
        c /= 10;
        if(l1||l2||c){
            ans->next = new ListNode(c);
            ans = ans->next;
        }
    }
    return t;
    
}