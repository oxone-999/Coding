// You are given an integer ‘N,’ and your task is to find the minimum steps to reach from 1 to 'N'. There are also ‘M’ mines on which you can not move.
// In each step, you can move in the following way:
// 1 - You move either 1 or 2 steps forward.

// 2 - Whenever you are at a prime number, you can make a special move, where you can move to the sum of digits in (Count the number of primes before the current prime + Difference between the next prime and current number) until it becomes a single-digit number. 

// 3- If you make a special move, you can’t make another special move for the next ‘L’ moves. 

#include <bits/stdc++.h>

vector<int> getPrimes(int n)
{
    vector<bool> isp(n+1, 1);
    isp[0] = isp[1] = 0;
    for(int i=2; i<=sqrt(n); i++)
    {
        if(!isp[i])
            continue;
        for(int j=i*i; j<=n; j+=i)
            isp[j] = 0;
    }
    vector<int> pv;
    for(int i=2; i<=n; i++)
        if(isp[i]) pv.push_back(i);
    return pv;
}

int dsm(int n)
{
    if(n==0)   return 0;
    if(n%9==0) return 9;
    return (n%9);
}

int rec(int level, int curl, int n, set<int> &s, int l, map<int, int> &mp, vector<vector<int>> &dp)
{
    if(s.find(level) != s.end())
        return 1e9;
    if(level > n)
        return 1e9;
    if(level == n)
        return 0;
    if(dp[level][curl] != -1)
        return dp[level][curl];
    int ans = min(rec(level+1, max(0, (curl-1)), n, s, l, mp, dp), rec(level+2, max(0, (curl-1)), n, s, l, mp, dp));
    if(mp.find(level)==mp.end() || curl!=0)
        return dp[level][curl] = (1+ans);
    ans = min(ans, rec(level+mp[level], l, n, s, l, mp, dp));
    return dp[level][curl] = (1+ans);
}

int moveSteps(int n, vector<int> &mines, int l)
{
    vector<int> pv = getPrimes(n+1);
    map<int, int> mp;
    for(int i=0; i<pv.size()-1; i++)
        mp[pv[i]] = dsm(i+(pv[i+1]-pv[i]));
    set<int> s(mines.begin(), mines.end());
    int ans = rec(1, 0, n, s, l, mp, dp);
    vector<vector<int>> dp(n+1, vector<int> (l+1, -1));
    if(ans >= 1e8)
        return -1;
    return ans;
}