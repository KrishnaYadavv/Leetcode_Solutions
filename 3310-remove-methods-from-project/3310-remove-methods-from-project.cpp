class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {

        vector<vector<int>> list(n);

        for(int i=0;i<in.size();i++){
            list[in[i][0]].push_back(in[i][1]);
        }

        vector<int> vis(n,0);
        queue<int> q;

        q.push(k);
        vis[k]=-1;

        while(!q.empty()){
            int val=q.front();
            q.pop();

            for(int i=0;i<list[val].size();i++){
                if(vis[list[val][i]]==0){
                    vis[list[val][i]]=-1;
                    q.push(list[val][i]);
                }
            }
        }

        int flag=0;

        for(int i=0;i<in.size();i++){
            int u=in[i][0];
            int v=in[i][1];

            if(vis[u]==0 && vis[v]==-1){
                flag=1;
                break;
            }
        }

        vector<int> ans;

        if(flag==0){
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    ans.push_back(i);
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }

        return ans;
    }
};