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

    int first_Occurrence(vector<int>& nums, int target)
    {
        int n = nums.size();
        int first = -1;
        int last = -1;
        int low = 0;
        int high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1; 
            }
            
        }
        return first;
    }
    int last_Occurrence(vector<int>& nums, int target)
    {
        int n = nums.size();
        int first = -1;
        int last = -1;
        int low = 0;
        int high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1; 
            }
            
        }
        return last;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int first = first_Occurrence(nums, target);
        if(first == -1)
        {
            return {-1,-1};
        }
        int last = last_Occurrence(nums, target);
        return {first, last};
        
    }

    int countFreq(vector<int>& nums, int target) 
    {
        int first = first_Occurrence(nums, target);
        if(first == -1)
        {
            return 0;
        }
        int last = last_Occurrence(nums, target);
        return last - first + 1;
        // code here
    }
};
//T.C. ->
