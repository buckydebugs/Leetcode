/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/


class Solution {
public:

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> ds;
        helper(0, s, ds, ans);
        return ans;
    }
    void helper(int index, string s, vector<string> &ds, vector<vector<string>> &ans)
    {
        if(index == s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i = index; i < s.size(); i++)
        {
            if(isPalindrome(s, index, i))
            {
                ds.push_back(s.substr(index, i - index + 1));
                helper(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }

        bool isPalindrome(string s, int start, int end)
        {
            while(start <= end)
            {
                if(s[start++] != s[end--])
                {
                    return false;
                }
            }
            return true;
        }
    
};

/*Time Complexity: O( (2^n) *k*(n/2) )

Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

Space Complexity: O(k * x)

Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).*/
