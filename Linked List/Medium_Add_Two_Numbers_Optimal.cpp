/*
  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;
        int carry = 0;
        while(t1 != NULL || t2 != NULL)
        {
            int sum = carry;
            if(t1)
            {
                sum = sum + t1->val;
            }
            if(t2)
            {
                sum = sum + t2->val;
            }
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            current->next = newNode;
            current = current->next;
            if(t1)
            {
                t1 = t1->next;
            }
            if(t2)
            {
                t2 = t2->next;
            }
        }
        if(carry)
        {
            ListNode* newNode = new ListNode(carry);
            current->next = newNode;
        }
        return dummyNode->next;
        
        
    }
};
//T.C. -> O(max(L1, L2)
//S.C. -> O(max(L1, L2)
