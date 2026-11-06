class Solution {
public:
// Optimized Approach, TC=O(N), SC=O(N)

    string encode(vector<string>& strs) {

        string encoded_string="";

        for(int i=0;i<strs.size();i++) {
            encoded_string+=to_string(strs[i].size());
            encoded_string.push_back('#');
            encoded_string.append(strs[i]);
        }

        return encoded_string;
    }

    vector<string> decode(string s) {

        vector<string> decoded_strs;
        string num="";

        int i=0;
        while(i<s.size()) {
            int len=0;

            while(s[i]!='#') {
                len=len*10+(s[i]-'0');
                i++;
            }

            i++;  // skip '#'

            decoded_strs.push_back(s.substr(i, len));

            i+=len;
        }

        return decoded_strs;
    }
};
