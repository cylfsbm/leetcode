#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 
     * 节点翻转
     * 要求：（1）你的算法只能使用常数的额外空间。（2）你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
     * @param  head [description]
     * @param  k    [description]
     * @return      [description]
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1), *pre = dummy, *cur = head;
        dummy->next = head;
        for(int i=1;cur != NULL;i++){
            if(i % k == 0){// 每k个一组，到了每组的最后一个元素
                // cout<<i<<endl;
                ListNode *last = pre->next, *current = last->next, *next = cur->next;
                while(current != next){
                    last->next = current->next;
                    current->next = pre->next;
                    pre->next = current;
                    current = last->next;
                }
                pre = last;
                cur = pre->next;
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }

    /**
     * 博客园中的解法1
     * @param  head [description]
     * @param  k    [description]
     * @return      [description]
     */
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if (!head || k == 1) return head;
    //     ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = head;
    //     dummy->next = head;
    //     for (int i = 1; cur; ++i) {
    //         if (i % k == 0) {

    //             pre = reverseOneGroup(pre, cur->next);
    //             cur = pre->next;
    //         } else {
    //             cur = cur->next;
    //         }
    //     }
    //     return dummy->next;
    // }
    // ListNode* reverseOneGroup(ListNode* pre, ListNode* next) {
    //     ListNode *last = pre->next, *cur = last->next;
    //     while(cur != next) {
    //         last->next = cur->next;
    //         cur->next = pre->next;
    //         pre->next = cur;
    //         cur = last->next;
    //     }
    //     return last;
    // }
    void display(ListNode* head){
        int counter = 0;
        while(head != NULL){
            if(counter == 0){
                cout<<head->val;
                counter++;
            }else{
                cout<<"->"<<head->val;
            }
            head = head->next;
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    s.display(head);
    s.display(s.reverseKGroup(head, k));
    system("pause");
    return 0;
}