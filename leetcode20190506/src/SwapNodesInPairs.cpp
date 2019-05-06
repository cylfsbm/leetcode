#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;
        ListNode* after = NULL, *pre = NULL;
        while(p != NULL && p->next != NULL){
            after = p->next;
            p->next = after->next;
            after->next = p;
            if(pre != NULL){
                pre->next = after;
            }else{
                head = after;
            }
            pre = p;
            p = p->next;
        }
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
    s.display(head);
    s.display(s.swapPairs(head));
    system("pause");
    return 0;
}