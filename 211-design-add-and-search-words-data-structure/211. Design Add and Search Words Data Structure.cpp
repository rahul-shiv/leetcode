class WordDictionary {
    struct Trie{
        bool terminal;
        unordered_map<char,Trie*> m;
    };
    Trie t;
    bool recursiveSearch(const string &word, Trie*temp, int i){
        for(;i<word.length();i++){
            char c = word[i];
            if(c=='.'){
                for(auto &x:temp->m){
                    bool t = recursiveSearch(word,x.second,i+1);
                    if(t)return true;
                }
                return false;
            }else{
                auto it = temp->m.find(c);
                if(it==temp->m.end())return false;
                temp=it->second;
            }
        }
        return temp->terminal;

    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie * temp = &t;
        int i = 0;
        for(auto c:word){
            // temp->l.insert(word.length()-i);
            auto it = temp->m.find(c);
            if(it==temp->m.end()){
                temp->m[c]=new Trie();
                temp = temp->m[c];
            }else{
                temp = it->second;
            }
            i++;
        }
        // temp->l.insert(0);
        temp->terminal=true;
    }
    

    bool search(string word) {
        return recursiveSearch(word,&t,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */