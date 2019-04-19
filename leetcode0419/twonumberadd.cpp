/*
 * townumberadd.cpp
 *
 *  Created on: 2019Äê4ÔÂ19ÈÕ
 *      Author: Administrator
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int r = 0, s = 0;
    	ListNode* res = new ListNode(0);
    	ListNode* p = res;
    	while(true){
    		r = (l1->val + l2->val + s) % 10;
			s = (l1->val + l2->val + s) / 10;
			p->val = r;
			l1 = l1->next;
			l2 = l2->next;
			if(l1 != NULL && l2 != NULL){
				p->next = new ListNode(0);
				p = p->next;
			}else{
				break;
			}
    	}
    	if(l1 == NULL && l2 == NULL && s != 0){
    		p->next = new ListNode(0);
    		p = p->next;
    		p->val = s;
    	}else{
    		while(l1 != NULL){
    			p->next = new ListNode(0);
    			p = p->next;
				r = (s + l1->val) % 10;
				s = (s + l1->val) / 10;
				p->val = r;
				l1 = l1->next;
			}
			while(l2 != NULL){
    			p->next = new ListNode(0);
    			p = p->next;
				r = (s + l2->val) % 10;
				s = (s + l2->val) / 10;
				p->val = r;
				l2 = l2->next;
			}
			if(s != 0){
				p->next = new ListNode(0);
				p = p->next;
				p->val = s;
			}
    	}
    	return res;
    }

    void display(ListNode* ln){
    	int count = 0;
    	while(ln != NULL){
    		if(count == 0){
				printf("%d",ln->val);
    		}else{
    			printf("%s%d","->",ln->val);
    		}
    		count++;
    		ln = ln->next;
    	}
    	printf("\n");
    }
};

/*int main(){
	Solution s = Solution();
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
//	l2->next->next->next = new ListNode(9);
	s.display(l1);
	s.display(l2);
	ListNode* res = s.addTwoNumbers(l1, l2);
	s.display(res);
	return 1;
}*/



