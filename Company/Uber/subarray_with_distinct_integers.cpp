int Solution::solve(vector<int> &A, int B) {
    map<int,int> mp;
    int n = A.size();
    int i=0;
    int j=0;
    int ans = 0;
    while(j<n){
        mp[A[j]]++;
        if(mp.size() <= B){
            ans += j-i+1;
        }else if(mp.size() > B){
            while(mp.size() > B){
                mp[A[i]]--;
                if(mp[A[i]] == 0){
                    mp.erase(A[i]);
                }
                i++;
            }
            if(mp.size() <= B){
                ans += j-i+1;
            }
        }
        j++;
    }
    i=0;
    j=0;
    B--;
    mp.clear();
    int ans2 = 0;
    while(j<n){
        mp[A[j]]++;
        if(mp.size() <= B){
            ans2 += j-i+1;
        }else if(mp.size() > B){
            while(mp.size() > B){
                mp[A[i]]--;
                if(mp[A[i]] == 0){
                    mp.erase(A[i]);
                }
                i++;
            }
            if(mp.size() <= B){
                ans2 += j-i+1;
            }
        }
        j++;
    }
    return ans-ans2;
}
