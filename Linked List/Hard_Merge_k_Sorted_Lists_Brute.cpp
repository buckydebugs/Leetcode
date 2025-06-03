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
    ListNode* convertToLinkedList(vector<int> arr)
    {
        if (arr.empty()) return nullptr; 
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        for(int i = 1; i < arr.size(); i++)
        {
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = newNode;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        vector<int> arr;
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp != NULL)
            {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(arr.begin(), arr.end());
        ListNode* head = convertToLinkedList(arr);
        return head;
    }
};
//T.C. -> O(n*k) + O(nmlognm) + O(n*k)
//S.C. -> O(n*k)
// where n is the length of linked list and m is the length of vector of lists
