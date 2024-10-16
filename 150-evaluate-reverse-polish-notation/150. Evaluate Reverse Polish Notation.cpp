class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int num1;
        for(auto x:tokens){
            if(x=="+"){
                num1 = s.top();
                s.pop();
                s.top() += num1;
            }else if(x=="*"){
                num1 = s.top();
                s.pop();
                s.top() *= num1;
            }else if(x=="-"){
                num1 = s.top();
                s.pop();
                s.top() -= num1;
            }else if(x=="/"){
                num1 = s.top();
                s.pop();
                s.top() /= num1;
            }else{
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};