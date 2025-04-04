/*
Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.

Examples:

Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
Output: 6, 8
Explanation: Floor of 7 is 6 and ceil of 7 is 8.
Input: x = 10 , arr[] = [5, 6, 8, 8, 6, 5, 5, 6]
Output: 8, -1
Explanation: Floor of 10 is 8 but ceil of 10 is not possible.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints :
1 ≤ arr.size ≤ 105
1 ≤ arr[i], x ≤ 106


*/
class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) 
    {
    
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        sort(arr.begin(), arr.end());
        int floorr = -1;
        int ceilll = -1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            // maybe answer
            if(arr[mid] <= x)
            {
                floorr = arr[mid];
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            
        }
        // Your code here
     // answer.push_back(ans);
      low = 0;
      high = n - 1;
     
      while(low <= high)
        {
            int mid = low + (high - low)/2;
            // maybe answer
            if(arr[mid] >= x)
            {
                ceilll = arr[mid];
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            
        }
        
        return {floorr, ceilll};
    }
    
        // code here
    
};
//T.C. => O(log2 N) +O(log2 N)
//S.C. => O(1)
