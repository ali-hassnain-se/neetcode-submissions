class Solution {
public:
    bool isPalindrome(string s) {
// Optimized Approach, Using Two Pointer Approach, TC=O(N), SC=O(1)

        int st=0, end=s.size()-1;

        while(st<end) {
            while(st<end && !isalnum(s[st]))
            st++;

            while(st<end && !isalnum(s[end]))
            end--;

            if(tolower(s[st])!=tolower(s[end]))
            return false;

            st++;
            end--;
        }

        return true;

/*
Brute Force Approach, TC=O(N), SC=O(N)

        string clean="";
        for(int i=0;i<s.size();i++) {
            if(isalnum(s[i]))
            clean+=tolower(s[i]);
        }

        string ans=clean;
        reverse(ans.begin(), ans.end());

        for(int i=0;i<ans.size();i++) {
            if(clean[i]!=ans[i])
            return false;
        }

        return true;
*/
    }
};
