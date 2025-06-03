/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
    {
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(t1 != NULL && t2 != NULL)
        {
            if(t1->val < t2->val)
            {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if(t1)
        {
            temp->next = t1;
        }
        else if(t2)
        {
            temp->next = t2;
        }
        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size() == 0)
        {
            return NULL;
        }
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++)
        {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};
//T.C. -> O(N*(K*K+1)/2) ~ O(n^3)
//S.C. -> O(1)
