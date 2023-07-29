// Ninja is fond of sequences. He has a set of numbers and wants to make minimum decreasing subsequences such that all numbers 
// are part of exactly one subsequence. Can you help Ninja with this challenge?
// You are given an array ‘ARR’ having ‘N’ elements.Your task is to divide all ‘N’ elements of the array into a minimum number
//  of strictly decreasing subsequences. Each number can be in one subsequence only. Find the minimum number of such strictly 
//  decreasing subsequences.

#include<bits/stdc++.h>
using namespace std;

int decreasingSubsequences(int n, vector<int> &arr)
{
    reverse(arr.begin(),arr.end());
    multiset<int> s;
    for(int i=0;i<n;i++)
    {
        auto ind = s.lower_bound(arr[i]);
        
        if(ind == s.begin()) s.insert(arr[i]);
        else {
            ind--;
            s.erase(ind);
            s.insert(arr[i]);
        }
    }
    return s.size();
}