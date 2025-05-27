/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL)
        {
            if(first->val != second->val)
            {
                reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;   
        }
        reverseList(newHead);
        return true;    
    }
};
// T.C. -> O(N/2) + O(N/2) + O(N/2) + O(N/2) ~ O(2N)
// S.C. -> O(1) if reverse recursive the O(n/2) + O(n/2) ~ O(N)
