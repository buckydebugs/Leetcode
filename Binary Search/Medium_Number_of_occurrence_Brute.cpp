/*
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106
*/

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) 
    {
        int n = arr.size();
        int first = -1;
        int last = -1;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == target)
            {
                count++;
            }
        }
        return count;
        // code here
    }
};
//T.C. -> O(n)
//S.C. -> O(1)
