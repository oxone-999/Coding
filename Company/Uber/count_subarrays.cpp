int Solution::solve(vector<int> &A, int B) {
    int i=0;
    int j=0;
    int n = A.size();
    int sum = 0;
    int ans = 0;
    while(j<n){
        sum += A[j];
        if(sum < B){
            ans += (j-i+1);
            j++; 
        }else{
            while(sum >= B){
                sum -= A[i];
                i++;
            }
            if(sum < B){
                ans += (j-i+1);
                j++;
            } 
        }
    }
    return ans;
}
