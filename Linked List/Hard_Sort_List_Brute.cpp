/*
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    ListNode* convertToLinkedList(vector<int> arr)
    {
        if(arr.size() == 0)
        {
            return NULL;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        for(int i = 1; i < arr.size(); i++)
        {
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) 
    {
        vector<int> arr;
        ListNode* temp = head;
        while(temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        ListNode* newHead = convertToLinkedList(arr);
        return newHead;
    }
};
//T.C. -> O(n) + O(nlogn) + O(n)
//S.C. -> O(2n)
