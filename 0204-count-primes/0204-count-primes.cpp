class Solution {
public:
    int countPrimes(int n) {
        if(n==0||n==1)return 0;
        vector<int>arr(n,1);
        arr[0]=arr[1]=0;
        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<n;j+=i){
                arr[j]=0;
            }
        }
        int ans=count(arr.begin(),arr.end(),1);
        return ans;
    }
};