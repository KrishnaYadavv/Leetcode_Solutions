class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i=0;
        unordered_map<char,char>mpp;
        unordered_map<char,char>mpp1;
        while(i<s.size()){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]]==t[i]){
                }
                else{
                    return false;
                }
            }
            else{
                mpp[s[i]]=t[i];
            }
            if(mpp1.find(t[i])!=mpp1.end()){
                if(mpp1[t[i]]==s[i]){
                }
                else{
                    return false;
                }
            }
            else{
                mpp1[t[i]]=s[i];
            }
            i++;
        }
        return true;
    }
};