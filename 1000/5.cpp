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

bool cmp(pair<ll,int>a,pair<ll,int>b){
    if(a.first==0 && b.first!=0) return true;
    if(a.first!=0 && b.first==0) return false;
    if(a.first!=b.first) return a.first>b.first; 
    return a.second<b.second;
}

int main() {
    fast_io;

    int t ;  
    cin>>t;
    while (t--) {
        int n;
        ll k;
        cin>>n>>k;
        vector<ll>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        vector<pair<ll,int>>v;
        for(int i=0;i<n;i++) v.push_back({nums[i]%k,i});
        sort(v.begin(),v.end(),cmp);
        vector<int>ans(n);  
        for(int i=0;i<n;i++) ans[i]=v[i].second;
        for(int i=0;i<n;i++) cout<<ans[i]+1<<" ";
        cout<<endl;
    }

    return 0;
}