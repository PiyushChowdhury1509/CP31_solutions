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
        for(int i=0;i<n;i++) cin>>nums[i];
        vector<ll>legs(q);
        for(int i=0;i<q;i++) cin>>legs[i];
        vector<ll>v(n,0);
        vector<ll>search(n,LLONG_MIN);
        v[0]=nums[0];
        search[0]=nums[0];
        for(int i=1;i<n;i++){
            v[i]=v[i-1]+nums[i];
            search[i]=max(nums[i],search[i-1]);
        }
        vector<ll>ans(q,0);
        for(int i=0;i<q;i++){
            ll target=legs[i];
            ll low=0;
            ll high=n-1;
            ll answer=-1;
            while(low<=high){
                ll mid=low+(high-low)/2;
                if(search[mid]<=target){
                    answer=mid;
                    low=mid+1;
                }
                else high=mid-1;
            }
            if(answer==-1) ans[i]=0;
            else ans[i]=v[answer];
        }
        for(int i=0;i<q;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}