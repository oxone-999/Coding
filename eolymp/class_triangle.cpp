#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

class Triangle
{
  private: 
  int x1, x2, x3, y1, y2, y3;

  public:

  void Out(){
    string str = "";
    str += to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2) + " " + to_string(x3) + " " + to_string(y3);
    cout<<str<<endl;
  }

  double area(int x1,int x2,int x3,int y1,int y2,int y3){
    
  }
  double perimeter(int y1){
    y = y1;
  }
  void setZ(int z1){
    z = z1;
  }

  int getX() {return x;}
  int getY() {return y;}
  int getZ() {return z;}

  double length(){
    return sqrt(x*x+y*y+z*z);
  } 
  void Out(){
    string str = "";
    str += to_string(x) + " " + to_string(y) + " " + to_string(z);
    cout<<str<<endl;
  }
};

void solve()
{
    Triangle T;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}