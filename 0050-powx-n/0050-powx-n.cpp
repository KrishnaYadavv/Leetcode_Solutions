class Solution {
public:
    double myPow(double x, long int n) {
        double ans=1;
        if(n<0){
            x=1/x;
            n=n*(-1);
        }
        while(n>0){
            if(n%2==1){
                ans=ans*x;
            }
            x=x*x;
            n=n/2;
        }
        return ans;
        
    }
};