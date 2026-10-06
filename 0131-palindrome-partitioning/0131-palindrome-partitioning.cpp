class Solution {
public:

bool check(string curr){
    int i=0;
    int j=curr.size()-1;
    while(i<j){
        if(curr[i]==curr[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

void hF(int i,int n,string s,string curr,vector<string>temp,vector<vector<string>>&ans){
    if(i>0&&check(curr)){
        temp.push_back(curr);
    }
    else if(i>0){
        return;
    }
    if(i>=n){
        ans.push_back(temp);
        return;
    }
    string s1;
    for(i;i<n;i++){
        s1+=s[i];
        hF(i+1,n,s,s1,temp,ans);
    }
}


    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>temp;
        hF(0,n,s,"",temp,ans);  
        return ans;
    }
};