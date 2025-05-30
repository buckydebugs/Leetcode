/*
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

 

Example 1:

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
 

Example 2:

Input: 
1 <-> 5 <-> 6
target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPairsWithGivenSum() which takes head node of the doubly linked list and an integer target as input parameter and returns an array of pairs. If there is no such pair return empty array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 105
1 <= target <= 105
*/

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    Node* findTail(Node* head)
    {
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) 
    {
        vector<pair<int, int>> answer;
        if(head == NULL)
        {
            return answer;
        }
        Node* left = head;
        Node* right = findTail(head);
        while(left->data < right->data)
        {
            if(left->data + right->data == target)
            {
                answer.push_back({left->data,right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return answer;
        // code here
        
    }
};
//T.C -> O(2N)
//S.C. -> O(1)
