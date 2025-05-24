/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if(fast == NULL)
        {
            return head->next;
            delete head;
        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};
//T.C. -> O(len) because we see traversal of fast only, the secoond loop starts from wher the fast loop leaves the fast pointer
//S.C. -> O(1)
