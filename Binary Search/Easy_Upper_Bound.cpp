/*
Given a sorted array arr[] and an integer x, find the index (0-based) of the smallest element in arr[] that is greater to x. This element is called the ceil of x. If such an element does not exist, return -1.

Note: In case of multiple occurrences of ceil of x, return the index of the last occurrence.

Examples

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 2
Explanation: Largest number less than or equal to 5 is 2, whose index is 1.
Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 11
Output: 5
Explanation: Largest Number less than or equal to 11 is 10, whose indices are 3 and 4. The index of last occurrence is 4.
Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 0
Output: -1
Explanation: No element less than or equal to 0 is found. So, output is -1.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
0 ≤ x ≤ arr[n-1]
*/
class Solution {
  public:

    int findFloor(vector<int>& arr, int x)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            // maybe answer
            if(arr[mid] > x)
            {
                ans = mid;
                high = mid + 1;
            }
            else
            {
                low = mid - 1;
            }
            
        }
        // Your code here
      return ans;  
    }
};

//T.C. => O(log2 N)
//S.C. => O(1)
