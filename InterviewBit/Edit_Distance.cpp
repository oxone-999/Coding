// Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

int Solution::minDistance(string A, string B) {
    int x = A.size();
    int y = B.size();
    
    int t[x+1][y+1];
    for(int i=0;i<x+1;i++){
        for(int j=0;j<y+1;j++){
            if(i == 0) t[i][j] = j;
            if(j == 0) t[i][j] = i;
        }
    }
    
    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){
            t[i][j] = min(t[i-1][j-1] + (A[i-1] != B[j-1]),min(t[i-1][j], t[i][j-1]) + 1);
            //taking minimum of replace,insertion,deletion;
        }
    }
    return t[x][y];
}
