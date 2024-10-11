class Vector2D {
    vector<vector<int>>::iterator it;
    vector<int>::iterator init;
    vector<vector<int>>& vec;
public:
    Vector2D(vector<vector<int>>& vec) : vec(vec) {
        it = vec.begin();
        while(it!=vec.end() and it->empty()){
            it++;
        }
        if(it!=vec.end() and !it->empty()){
            init = it->begin();
        }
    }
    
    int next() {
        int ret = *init;
        init++;
        if(init == it->end()){
            it++;
            while(it!=vec.end() and it->empty()){
                it++;
            }
            if(it!=vec.end()){
                init=it->begin();
            }
        }
        return ret;
    }
    
    bool hasNext() {

        return it!=vec.end() and init!=it->end();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */