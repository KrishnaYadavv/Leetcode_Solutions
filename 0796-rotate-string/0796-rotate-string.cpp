class Solution {
public:
    bool rotateString(string s, string goal) {
        int count=0;
        char temp;
        while(count<s.size()){
            temp=s[0];
            s=s.substr(1);
            s+=temp;
            if(s==goal){
                return true;
            }
            count++;
        }
        return false;
    }
};