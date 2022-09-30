/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

    For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.



Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].


*/

// This problem is the variation of LCS
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }
    bool isPossible(string &s1, string &s2)
    {
        if (s2.size() + 1 != s1.size())
            return false;
        int first = 0;
        int second = 0;
        while (first < s1.size())
        {
            if (second < s2.size() && s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        if (first == s1.size() && second == s2.size())
            return true;
        return false;
    }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        int maxi = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPossible(words[i], words[j]) && ((dp[j] + 1) > dp[i]))
                    dp[i] = dp[j] + 1;
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

int main()
{

    return 0;
}