#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    /**
     * 我的解法，运行速度较慢
     * @param  lists [description]
     * @return       [description]
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 1){
            return lists[0];
        }else{
            ListNode* res = NULL, *result = NULL;
            int count = 0;
            while(!this->stop(lists)){
                // this->display(result);
                if(count == 0){
                    count++;
                    res = new ListNode(this->min(lists));
                    result = res;
                }else{
                    res->next =  new ListNode(this->min(lists));
                    res = res->next;
                }
            }
            return result;
        }
    }

    bool stop(vector<ListNode*>& lists){
        for(auto l : lists){
            if(l != NULL){
                return false;
            }
        }
        return true;
    }

    int min(vector<ListNode*>& lists){
        int min = INT_MAX;
        int pos = 0;
        for(int i = 0;i < lists.size();i++){
            if(lists[i] != NULL && lists[i]->val < min){
                min = lists[i]->val;
                pos = i;
            }
        }
        lists[pos] = lists[pos]->next;
        return min; 
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

    /**
     * 分治法 每两个链表两两合并
     * @param  lists [description]
     * @return       [description]
     */
    ListNode* mergeKLists2(vector<ListNode*>& lists){
        if(lists.empty()) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    }
};

int main(){
    Solution s;
    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    lists.push_back(l1);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(9);
    lists.push_back(l2);
    for(auto l:lists){
        s.display(l);
    }
    cout<<"result:"<<endl;
    s.display(s.mergeKLists(lists));
    system("pause");
    return 0;
}