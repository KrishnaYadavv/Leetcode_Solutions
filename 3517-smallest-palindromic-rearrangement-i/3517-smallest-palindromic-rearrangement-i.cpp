class Solution {
public:
    string smallestPalindrome(string s) {
        priority_queue<char,vector<char>,greater<char>>q;
        for(int i=0;i<s.size()/2;i++){
            q.push(s[i]);
        }
        string ans="";
        while(!q.empty()){
            ans+=q.top();
            q.pop();
        }
        if(s.size()%2==0){
            int i=ans.size()-1;
            while(i>=0){
                ans+=ans[i];
                i--;
            }
        }
        else{
            int i=s.size()/2;
            ans+=s[i];
            i--;
            while(i>=0){
                ans+=ans[i];
                i--;
            }
        }

        return ans;
    }
};