/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
    ListNode* covertFromArraytoLinkedList(vector<int>& arr) 
    {
        if (arr.empty()) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for(int i = 1; i < arr.size(); i++)
        {
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
           
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == NULL && list2 == NULL)
        {
            return NULL;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        vector<int> arr;
        while(temp1 != NULL)
        {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2 != NULL)
        {
            arr.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(arr.begin(), arr.end());
        ListNode* head = covertFromArraytoLinkedList(arr);
        return head;
        
    }
};
//T.C. -> O(n1) + O(n2) + O(nlogn) + O(n1 + n2)
//        list1   list2    sort     array to LL
//S.C. -> O(n1 + n2) + O(n1 + n2)
