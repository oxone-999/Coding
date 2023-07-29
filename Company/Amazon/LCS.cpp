//top-down

int Solution::solve(string A, string B) {
    int n = A.size();
    int m = B.size();
    
    int t[n+1][m+1];
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i == 0 || j == 0) t[i][j] = 0;
        }
    }   
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(A[i-1] == B[j-1]) t[i][j] = t[i-1][j-1] + 1;
            else t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][m];
}

//bottom-up

int t[1006][1006];

int rec(string A,string B,int n, int m)
{
    if(n == 0 || m == 0) return 0;
    if(t[n][m] != -1) return t[n][m];

    if(A[n-1] == B[m-1]) return t[n][m] = rec(A,B,n-1,m-1) + 1;
    else return t[n][m] = max(rec(A,B,n-1,m),rec(A,B,n,m-1));
}

int Solution::solve(string A, string B) {
    memset(t,-1,sizeof(t));
    int n = A.size();
    int m = B.size();
    return rec(A,B,n,m);
}
