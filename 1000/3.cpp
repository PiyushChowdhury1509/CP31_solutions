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

    int t = 1;
    cin>>t;  
    while (t--) {
        ll n,p;
        cin>>n>>p;
        vector<ll>a(n),b(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];
        vector<pair<ll,ll>>v;
        for(ll i=0;i<n;i++){
            v.push_back({b[i],a[i]});
        }
        sort(all(v));
        ll idx=0;
        ll cost=p;
        ll prev=0;
        ll i=1;
        while(i<n){
            if(v[idx].first<p){
                ll people=min(v[idx].second,n-i);
                i=i+min(v[idx].second,n-i);
                cost+=((ll)v[idx].first*(ll)people);
                idx++;
            } else break;
        }
        if(i<n) cost+=((ll)(n-i)*(ll)p);
        cout<<cost<<endl;
    }

    return 0;
}