class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=INT_MIN;
        int temp=0;
        int i=0;
        while(i<s.size()){
            if(s[i]==' '&&temp>0){
                ans=temp;
                temp=0;
            }
            else if(s[i]==' '&&temp==0){

            }
            else{
                temp++;
            }
            i++;
        }
        if(temp>0)ans=temp;
        return ans;
    }
};