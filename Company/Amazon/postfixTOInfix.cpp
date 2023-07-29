int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
        
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i] != "+" && A[i] != "-" && A[i] != "/" && A[i] != "*") s.push(stoi(A[i]));
        else 
        {
            int num1 = s.top();
            s.pop();
            int num2 = s.top();
            s.pop();
            
            char ch = A[i][0];
            
            switch(ch)
            {
                case '+' : s.push(num1+num2);
                    break;
                case '-' : s.push(num2-num1);
                    break;
                case '*' : s.push(num1*num2);
                    break;
                case '/' : s.push(num2/num1);
                    break;
                default: cout<<"error";
            }
        }
    }
    return s.top();
}
