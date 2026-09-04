class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int cq, cw, ce, cr;
        cq=cw=ce=cr=0;
        for (auto& i : s) {
            if (i == 'Q')
                cq++;
            if (i == 'W')
                cw++;
            if (i == 'E')
                ce++;
            if (i == 'R')
                cr++;
        }
        cq = max(0, cq - n / 4);
        cw = max(0, cw - n / 4);
        ce = max(0, ce - n / 4);
        cr = max(0, cr - n / 4);
        if(cq==0&&cw==0&&ce==0&&cr==0)return 0;
        int c1, c2, c3, c4;
        c1 = c2 = c3 = c4 = 0;
        int i = 0;
        int ans=INT_MAX;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'Q')
                c1++;
            if (s[j] == 'W')
                c2++;
            if (s[j] == 'E')
                c3++;
            if (s[j] == 'R')
                c4++;
            while (c1 >= cq && c2 >= cw && c3 >= ce && c4 >= cr&&i<=j) {
                ans=min(ans,j-i+1);
                if (s[i] == 'Q')
                    c1--;
                if (s[i] == 'W')
                    c2--;
                if (s[i] == 'E')
                    c3--;
                if (s[i] == 'R')
                    c4--;
                i++;
            }
        }
        return ans;
    }
};