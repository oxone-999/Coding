// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl "\n"
// #define deb(x) cout<<#x<<'='<<x<<endl
// #define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
// #define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
// #define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
// #define MOD 1e9

// void bubble_Sort(vector<int> &A){
//     int n = A.size();

//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-1-i;j++){
//             if(A[j] > A[j+1]){
//                 swap(A[j],A[j+1]);
//             }
//         }
//     }
// }

// void solve()
// {
//     int n;
//     cin>>n;

//     vector<int> A(n);
//     for(auto &it:A){
//         cin>>it;
//     }
//     bubble_Sort(A);
//     for(auto it:A){
//         cout<<it<<" ";
//     }
// }

// signed main(){
// ios_base::sync_with_stdio(false);
// cin.tie(0);cout.tie(0);
//     solve();
//     return 0;
// }












































































#include <bits/stdc++.h>
using namespace std;

string calculateFraction(int num, int den)
{
	if (num == 0) return "0";
	int sign = (num < 0) ^ (den < 0) ? -1 : 1;

	num = abs(num);
	den = abs(den);

	int initial = num / den;
	string res;

	if (sign == -1) res += "-";
	res += to_string(initial);
	if (num % den == 0) return res;
	res += ".";

	int rem = num % den;
	map<int, int> mp;
	int index;
	bool repeating = false;

	while (rem > 0 && !repeating) {
		if (mp.find(rem) != mp.end()) {
			index = mp[rem];
			repeating = true;
			break;
		}else mp[rem] = res.size();
		rem = rem * 10;
		int temp = rem / den;
		res += to_string(temp);
		rem = rem % den;
	}
	if (repeating) {
		res += ")";
		res.insert(index, "(");
	}
	return res;
}

int main()
{
	int num = 2, den = 3;
	cout << calculateFraction(num, den) << endl;

	num = -1, den = 2;
	cout << calculateFraction(num, den) << endl;
	return 0;
}
