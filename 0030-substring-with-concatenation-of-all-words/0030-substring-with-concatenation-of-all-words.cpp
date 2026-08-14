class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n = words.size();
        int k = words[0].size();

        unordered_map<string, int> mpp;
        for (auto i : words) {
            mpp[i]++;
        }

        vector<int> ans;

        for (int j = 0; j < k; j++) {

            unordered_map<string, int> mpp2;
            int count = 0;
            int i = j;
            int val = i;

            while (i < s.size()) {

                string curr = s.substr(i, k);
                mpp2[curr]++;
                i += k;
                count++;
                if (count == n) {
                    if (mpp == mpp2) {
                        ans.push_back(val);
                    }
                    string s2 = s.substr(val, k);
                    mpp2[s2]--;
                    if (mpp2[s2] == 0) {
                        mpp2.erase(s2);
                    }
                    val += k;
                    count--;
                }
            }
        }
        return ans;
    }
};