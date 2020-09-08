/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0,tail = 0;
        int maxLen = 0;
        bool flag[1000000];
        for(int j = 0; j<300;j++) flag[j] = false;

        while(head < s.length()){
            if(flag[s[head]] != true){
                flag[s[head]] = true;
            }else{
                maxLen = (head - tail) > maxLen? (head - tail): maxLen;
                while(s[tail] != s[head]){
                    flag[s[tail]] = false;
                    tail++;
                }
                tail++;
            }
            head++;
        }
        maxLen = (head - tail) > maxLen? (head - tail): maxLen;

        return maxLen;
    }
};
// @lc code=end

