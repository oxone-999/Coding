// You are given ‘N’ roses and you are also given an array ‘Arr’ where ‘Arr[i]’ denotes that the ith rose will bloom on the Arr[i]th day.
// You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly ‘R’ adjacent 
// bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least ‘B’ bouquets each containing ‘R’ roses. Return “-1” if it is not possible.

int roseGarden(int n, vector<int> arr, int r, int b) {
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mn = min(mn,arr[i]);
        mx = max(mx,arr[i]);
    }
    
    int st = mn;
    int en = mx;
    int res = -1;
    
    while(st<=en){
        int mid = st + (en-st)/2;
//         cout<<mid<<" ";
        int c = b;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(c == 0){
                res = mid;
                en = mid-1;
                break;
            }
            if(arr[i] <= mid) cnt++;
            else{
                c -= cnt/r;
                if(c<0) c = 0;
//                 cout<<cnt<<" "<<c<<" ";
                cnt = 0;
            }
        }
        c -= cnt/r;
        if(c<0) c = 0;
        if(c == 0){
            res = mid;
            en = mid-1;
        }
        else st = mid+1;
//         break;
    }
    return res;
}