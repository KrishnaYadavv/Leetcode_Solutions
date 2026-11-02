class Solution {
public:
    int mirrorReflection(int p, int q) {
        // if(p==q){
        //     return 1;
        // }
        int n=lcm(p,q);
        int temp=n/p;
        if(temp%2==0){
            return 0;
        }
        int m=n/q;
        if(m%2==0){
            return 2;
        }
        return 1;
        
    }
};