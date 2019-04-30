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
    /**
     * 双遍历
     * @param  head [description]
     * @param  n    [description]
     * @return      [description]
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int size = 0;
        while(p != NULL){
            p = p->next;
            size++;
        }
        int count = 0;
        p = head;
        if(n == size){
            head = head->next;
            return head;
        }
        while(count != size-n-1){
            p = p->next;
            count++;
        }
        p->next = p->next->next;
        return head;
    }

    /**
     * 单次遍历
     * @param  head [description]
     * @param  n    [description]
     * @return      [description]
     */
    ListNode* removeNthFromEnd2(ListNode* head, int n){
        ListNode* f = head, *s = head;// 双指针
        int count = n;
        while(count != 0 && f->next != NULL){
            f = f->next;
            count--;
        }
        while(f->next != NULL){
            f = f->next;
            s = s->next;
        }
        // cout<<f->val<<","<<s->val<<endl;
        if(s == head && count != 0){
            return head->next;
        }
        s->next = s->next->next;
        return head;
    }

    void display(ListNode* head){
        int count = 0;
        ListNode* p = head;
        while(p != NULL){
            if(count == 0){
                cout<<p->val;
                count++;
            }else{
                cout<<"->"<<p->val;
            }
            p = p->next;
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    s.display(head);
    s.display(s.removeNthFromEnd2(head, 2));
    system("pause");
    return 0;
}