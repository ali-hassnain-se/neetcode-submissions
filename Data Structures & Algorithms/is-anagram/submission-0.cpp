class Solution {
public:
    bool isAnagram(string s, string t) {
// Optimized Approach, TC=O(N), SC=O(1)

        if(s.size()!=t.size())
        return false;

        vector<int> ans(26, 0);

        for(int i=0;i<s.size();i++) {
            ans[s[i]-'a']++;
            ans[t[i]-'a']--;
        }

        for(int i=0;i<26;i++) {
            if(ans[i]!=0)
            return false;
        }

        return true;

/* 
Better Than Brute Force, TC=O(nlogn) sorting both strings, SC=O(logn) recursion stack of sort

    if(s.size()!=t.size())
    return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for(int i=0;i<s.size();i++) {
        if(s[i]!=t[i])
        return false;
    }

    return true;
*/

/*
Brute Force Approach, TC=O(n^2), SC=O(1)

    if(s.size()!=t.size())
    return false;

    for(int i=0;i<s.size();i++) {
        bool found=false;
        for(int j=0;j<t.size();j++) {
            if(s[i]==t[j]) {
                t[j]='#';
                found=true;
                break;
            }
        }

        if(!found)
        return false;
    }

    return true;
*/
    }
};
