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
