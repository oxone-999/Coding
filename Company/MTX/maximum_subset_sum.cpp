// Description

// Given an array of integers, find the subset of non-adjacent elements with the maximum sum. 
// Calculate the sum of that subset. 
// It is possible that the maximum sum is 0, the case when all elements are negative.
// Complete the function in the editor below. maxSubsetSum has the following parameter(s):
//     int arr[n]: an array of integers

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    int n = arr.size();
    long long dp[n+1];
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    
    for(int i=2;i<n;i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
    }
    if(dp[n-1] < 0) return 0;
    return dp[n-1];
}

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    cout << res << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}