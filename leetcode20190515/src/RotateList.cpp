#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int size = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            size++;
        }
        k %= size;
        while(k != 0){
            ListNode* cur = head;
            while(cur != tail && cur->next != tail)
                cur = cur->next;
            tail->next = head;
            cur->next = NULL;
            head = tail;
            tail = cur;
            k--;
        }
        return head;
    }

    void display(ListNode* node){
        int counter = 0;
        while(node != NULL){
            if(counter == 0){
                cout<<node->val;
                counter++;
            }else{
                cout<<"->"<<node->val;
            }
            node = node->next;
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    ListNode* node = new ListNode(1);
    // node->next = new ListNode(2);
    // node->next->next = new ListNode(3);
    // node->next->next->next = new ListNode(4);
    // node->next->next->next->next = new ListNode(5);
    s.display(node);
    s.display(s.rotateRight(node, 7));
    system("pause");
    return 0;
}