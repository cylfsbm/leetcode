#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        ListNode *p1 = l1, *p2 = l2, *res = new ListNode(0), *result = res;
        int count = 0;
        while(p1 != NULL && p2 != NULL){
            if(count == 0){
                count++;
            }else{
                res->next = new ListNode(0);
                res = res->next;
            }
            int i1 = p1->val;
            int i2 = p2->val;
            if(i1 <= i2){
                res->val = i1;
                p1 = p1->next;
            }else{
                res->val = i2;
                p2 = p2->next;
            }
        }
        while(p1 != NULL){
            if(count == 0){
                count++;
            }else{
                res->next = new ListNode(0);
                res = res->next;
            }
            res->val = p1->val;
            p1 = p1->next;
        }
        while(p2 != NULL){
            if(count == 0){
                count++;
            }else{
                res->next = new ListNode(0);
                res = res->next;
            }
            res->val = p2->val;
            p2 = p2->next;
        }
        return result;
    }

    void display(ListNode* l){
        int count = 0;
        while(l != NULL){
            if(count == 0){
                cout<<l->val;
                count++;
            }else{
                cout<<"->"<<l->val;
            }
            l = l->next;
        }
        cout<<endl;
    }
};


int main(){
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    s.display(l1);
    s.display(l2);
    s.display(s.mergeTwoLists(l1, l2));
    system("pause");
    return 0;
}