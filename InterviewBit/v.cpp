#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct linked_list{
    int val;
    linked_list* next;
    linked_list(int x){
        val = x;
        next = NULL;
    }
};

void solve()
{
    linked_list* head = new linked_list(1);
    head->next = new linked_list(2);
    head->next->next = new linked_list(3);
    head->next->next->next = new linked_list(4);
    head->next->next->next->next = new linked_list(5);
    head->next->next->next->next->next = new linked_list(6);

    print_linked_list(head);
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}