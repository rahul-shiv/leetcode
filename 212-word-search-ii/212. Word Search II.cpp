class trie{
    public:
    unordered_map<char, trie*> m;
    int cnt = 0;
    string s;
    trie(){
        cnt = 0;
    }
    void setc(char c){
        if(!this->m[c])this->m[c]= new trie();
        this->m[c]->cnt++;
    }
    void build(string &word, int i = 0){
        if(i==0) this->cnt++;
        if(i<word.length()){
            this->setc(word[i]);
            this->m[word[i]]->build(word, i+1);
        }else{
            s = word;
        }
    }
    void del(string &word, int i = 0){
        this->cnt--;
        if(i < word.length()){
            auto it = this->m.find(word[i]);
            it->second->del(word, i+1);
        }
    }
};
class Solution {
    trie * roott; 
    vector<string> ans;
    int m, n;
    void solve(vector<vector<char>>& board, trie * t, vector<vector<bool>> & vis, int i, int j){
        vis[i][j]=true;
        if(t==nullptr)return;
        if(t->s.length()){
            ans.push_back(t->s);
            t->s="";
            roott->del(t->s);
        }
        int dirs[][2] = {{0,1},{1,0},{-1,0},{0,-1}}, x,y;
        #define check(x,y) x<m and y<n and x>=0 and y>=0 and !vis[x][y]
        for(auto dir:dirs){
            x = i + dir[0];
            y = j + dir[1];
            if(check(x,y)){
                auto it = t->m.find(board[x][y]);
                if(it!=t->m.end()){
                    solve(board, it->second, vis, x, y);
                    vis[x][y]=false;
                    if(!it->second->cnt){
                        delete it->second;
                        t->m.erase(it);
                    }
                }
            }
        }

    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        roott = new trie();
        for(auto word:words){
            roott->build(word);
        }
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                auto it = roott->m.find(board[i][j]);
                if(it!=roott->m.end()){
                    vector<vector<bool>> vis(m,vector<bool>(n));
                    solve(board, it->second, vis, i, j);
                }
                if(!roott->cnt)break;
            }
            if(!roott->cnt)break;
        }
        return ans;
    }
};