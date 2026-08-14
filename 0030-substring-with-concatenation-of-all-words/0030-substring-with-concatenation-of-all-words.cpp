class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n = words.size();
        int k = words[0].size();

        unordered_map < string, int > mpp;
        for (auto i : words) {
            mpp[i]++;
        }

        vector<int>ans;

        for(int j=0;j<s.size();j++){

            string temp=s.substr(j,k);

            if(mpp.find(temp)!=mpp.end()){

                unordered_map<string,int>mpp2;
                int count=0;
                int i=j;

                while(count<n&&i<s.size()){

                    string curr=s.substr(i,k);
                    mpp2[curr]++;
                    i+=k;
                    count++;

                }
                if(mpp==mpp2){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};