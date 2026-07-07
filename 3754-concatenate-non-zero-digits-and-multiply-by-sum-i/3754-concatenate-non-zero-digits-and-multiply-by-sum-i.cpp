class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>temp;
        while(n>0){
            temp.push_back(n%10);
            n/=10;
        }
        long long sum=0;
        long long ans=0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
        }
        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i]!=0){
                ans*=10;
                ans+=temp[i];
            }
        }

        return ans*sum;
    }
};