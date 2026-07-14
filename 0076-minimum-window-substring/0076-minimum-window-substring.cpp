class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        int i = 0;
        int j = 0;
        int arr[2] = {-1};
        int val = INT_MAX;
        unordered_map<char, int> mpp;
        int count = 0;
        int kri = 0;
        for (auto x : t) {
            if (mpp.find(x) != mpp.end()) {
                mpp[x]++;
            } else {
                mpp[x]++;
                kri++;
            }
        }
        while (j < s.size()) {
            mpp[s[j]]--;
            if (mpp[s[j]] == 0) {
                count++;
                while (count == kri) {
                    if (val > j - i + 1) {
                        arr[0] = i;
                        arr[1] = j;
                        val = j - i + 1;
                    }
                    if (mpp[s[i]] == 0) {
                        count--;
                    }
                    mpp[s[i]]++;
                    i++;
                }
            }
            j++;
        }
        // j--;
        // if (mpp[s[j]] == 0) {
        //     count++;
        //     while (count >= kri) {
        //         if (val > j - i + 1) {
        //             arr[0] = i-1;
        //             arr[1] = j;
        //             val = j - i + 1;
        //         }
        //         if (mpp[s[i]] == 0) {
        //             count--;
        //         }
        //         mpp[s[i]]++;
        //         i++;
        //     }
        // }
        string ans;
        if (arr[0] == -1)
            return "";
        for (int z = arr[0]; z <= arr[1]; z++) {
            ans += s[z];
        }
        return ans;
    }
};