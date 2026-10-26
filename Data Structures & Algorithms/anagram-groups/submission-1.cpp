class Solution {
public:

    string generate(string &word) {
        vector<int> freq(26, 0);

        for(int i=0;i<word.size();i++)
        freq[word[i]-'a']++;

        string new_word="";
        for(int i=0;i<26;i++) {
            int count=freq[i];

            if(count>0)
            new_word+=string(count, 'a'+i);
        }

        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n=strs.size();

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(int i=0;i<n;i++) {
            string word=strs[i];

            string new_word=generate(word);

            mp[new_word].push_back(word);
        }

        for(auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;


/*
// Optimized Approach, using Hashing, key = sorted word, TC=O(N * K log K), SC=O(N*K)
// N=words, K=maximum length of each string

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(int i=0;i<strs.size();i++) {
            string temp=strs[i];
            sort(temp.begin(), temp.end());

            mp[temp].push_back(strs[i]);
        }

        for(auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
*/

/*
// Brute Force Approach, TC=O(N^2 * K log K), SC=O(N*K)
// (N = words, K = max word length)

        int n=strs.size();

        vector<bool> visited(n, false);
        vector<vector<string>> ans;

        for(int i=0;i<n;i++) {
            if(visited[i])
            continue;

            vector<string> group={strs[i]};
            visited[i]=true;

            string temp1=strs[i];
            sort(temp1.begin(), temp1.end());

            for(int j=i+1;j<n;j++) {
                if(visited[j] || strs[j].size()!=temp1.size())
                continue;

                string temp2=strs[j];
                sort(temp2.begin(), temp2.end());

                if(temp1==temp2) {
                group.push_back(strs[j]);
                visited[j]=true;
                }
            }

            ans.push_back(group);
        }

        return ans;
*/
    }
};
