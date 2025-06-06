#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <cstring>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define F first
#define S second
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m - b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
ll mod_exp(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    fast_io;

    int t ;
    cin>>t;  
    while (t--) {
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(s[i]=='g') v.push_back(i);
        }
        int m=v.size();
        for(int i=0;i<m;i++) v.push_back(v[i]+n);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                int low=0;
                int high=v.size()-1;
                int answer=-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(v[mid]>=i){
                        answer=mid;
                        high=mid-1;
                    }
                    else low=mid+1;
                }
                ans=max(ans,v[answer]-i);
            }
        }   
        cout<<ans<<endl;
    }

    return 0;
}