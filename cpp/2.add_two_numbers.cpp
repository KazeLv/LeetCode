/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

//@lc code=start
/*
//Definition for singly-linked list.
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *res = new ListNode;
        ListNode *pre = res;
        ListNode *q;

        int carry = 0;
        while(p1 != nullptr || p2 != nullptr){
            q = new ListNode(carry);

            if(p1 != nullptr) {q->val += p1->val; p1 = p1->next;}
            if(p2 != nullptr) {q->val += p2->val; p2 = p2->next;}

            if(q->val > 9) carry = 1;
            else carry = 0;
            q->val %= 10;

            pre->next = q;
            pre = q;
            q = q->next;
        }

        if(carry == 1) pre->next = new ListNode(1);
        
        return res->next;
    }
};
// @lc code=end

