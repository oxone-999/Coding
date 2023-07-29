int solve(vector<int> &A) {
    int n = A.size();
    int odd = 0, even = 0;
    int leftOdd[n], rightOdd[n];
    int leftEven[n], rightEven[n];
    for(int i = 0;i < n; i++){
        leftOdd[i] = odd;
        leftEven[i] = even;
        if(i%2 == 0)
            even += A[i];
        else
            odd += A[i];
    }
    odd = 0;
    even = 0;
    for(int i = n-1; i >= 0; i--){
        rightOdd[i] = odd;
        rightEven[i] = even;
        if(i%2 == 0)
            even += A[i];
        else
            odd += A[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(leftOdd[i] + rightEven[i] == leftEven[i] + rightOdd[i]){
            ans++;
        }
    }
    return ans;
}