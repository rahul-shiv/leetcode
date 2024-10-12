class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int r = 0;
        vector<string> ans;
        int wc = 0, chars = 0, n = words.size(), spaces;
        float extra;
        string sentence;
        while(r<n){
            sentence = "";
            chars = 0;
            wc = 0;
            while(r<n and chars<=maxWidth){
                chars += words[r++].length();
                wc++;
                if(chars<maxWidth){
                    chars++;
                }
            }
            if(chars>maxWidth){
                chars -= words[--r].length();
                wc--;
            }
            chars = 0;
            for(int i = r-wc; i<r;i++){
                chars += words[i].length();
            }
            extra = maxWidth-chars;
            if(r==n){
                for(int i = r-wc; i<r;i++){
                    sentence+=words[i];
                    if(extra--)sentence+=" ";
                }
                while(extra>0){
                    extra--;
                    sentence+=" ";
                }
            }else{
                for(int i = r-wc; i<r;i++){
                    sentence+=words[i];
                    spaces = ceil(extra/max(wc-1,1));
                    extra-=spaces;
                    for(int j = 0; j<spaces;j++)
                        sentence+=" ";
                    wc--;
                }
            }
            ans.push_back(sentence);
        }
        return ans;
    }
};