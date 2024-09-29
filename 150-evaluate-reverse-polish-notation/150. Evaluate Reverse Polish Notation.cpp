class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int num;
        for(auto token:tokens){
            if(token == "+"){
                num=nums.top();
                nums.pop();
                nums.top() += num;
            }else if(token == "-"){
                num=nums.top();
                nums.pop();
                nums.top() -= num;
            }else if(token == "*"){
                num=nums.top();
                nums.pop();
                nums.top() *= num;
            }else if(token == "/"){
                num=nums.top();
                nums.pop();
                nums.top() /= num;
            }else{
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};