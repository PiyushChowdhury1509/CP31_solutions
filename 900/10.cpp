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
        int n,q;
        cin>>n>>q;
        vector<ll>nums(n);
        vector<vector<ll>>queries(q,vector<ll>(3));
        for(int i=0;i<n;i++) cin>>nums[i];
        for(int i=0;i<q;i++){
            for(int j=0;j<3;j++) cin>>queries[i][j];
        }
        vector<ll>pre(n,0);
        ll sum=nums[0];
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
            sum+=nums[i];
        }
        for(int i=0;i<q;i++){
            ll l=queries[i][0];
            ll r=queries[i][1];
            ll sum1=queries[i][2]*(r-l+1);
            ll subsum=pre[r-1]-(l>1 ? pre[l-2]:0);
            if((sum+sum1-subsum)%2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}