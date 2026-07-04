class Solution {
public:
    int divide(long int n, long int d) {
        // int sign=1;
        // sign = n<0?-1:1;
        // sign=sign*(d<0?-1:1);
        int sign = ((n<0)^(d<0))?-1:1;
        // if(n==INT_MIN&&d==-1)return INT_MAX;
        // if(n==INT_MIN&&d==1)return INT_MIN;
        if(n==INT_MAX&&d==-1)return INT_MIN+1;
        // if(n==INT_MAX&&d==1)return INT_MAX;
        // if(n==INT_MIN){
        //     n=n+1;
        // }

        d=abs(d);
        n=abs(n);
        if(n<d)return 0;
        if(n==d)return sign*1;
        long int count=0;
        while(n>=d){
            long int temp=d;
            long int i=0;
            long int cnt=0;
            while(n>=(temp<<i)){
                n-=(temp<<i);
                cnt+=(1<<i);
                i++;
            }
            count+=cnt;
        }
        if(count>=INT_MAX&&sign==1)return INT_MAX;
        if(count>=INT_MAX&&sign==-1)return INT_MIN;
        return sign*count;
    }
};