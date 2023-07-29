int func(vector<int> &A,int sum){
    int n = A.size();
    int t[n+1][sum+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i == 0 || j != 0){
                t[i][j] = 0;
            }else if(j == 0) t[i][j] = 1;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(A[i-1] <= j){
                t[i][j] = t[i-1][j-A[i-1]] | t[i-1][j];
            }else t[i][j] = t[i-1][j];
        }
    }
    
    int ans = INT_MAX;
    
    for(int i=0;i<sum+1;i++){
        if(t[n][i]){
            ans = min(ans,abs(sum-2*i));        
        }
    }
    return ans;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += A[i];
    }
    
    return func(A,sum);
}
