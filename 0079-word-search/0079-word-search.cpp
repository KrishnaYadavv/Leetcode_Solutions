class Solution {
public:

bool hF(vector<vector<char>>& board, string word,int i,int j,string ans,int count){
    if(ans.size()==word.size()){
        if(ans==word){
            return true;
        }
        return false;
    }
    if(i<0||i>=board.size()||j<0||j>=board[0].size()){
        return false;
    }
    if(word[count]==board[i][j]){
        char temp=board[i][j];
        ans+=board[i][j];
        board[i][j]='.';
        bool a = hF(board,word,i,j+1,ans,count+1);
        bool b = hF(board,word,i,j-1,ans,count+1);
        bool c = hF(board,word,i+1,j,ans,count+1);
        bool d = hF(board,word,i-1,j,ans,count+1);
        board[i][j]=temp;
        return a||b||c||d;
    }
    else{
        return false;
    }
}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(hF(board,word,i,j,"",0)){
                    return true;
                }
            }
        }
        return false;
    }
};