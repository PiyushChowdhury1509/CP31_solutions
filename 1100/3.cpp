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
        cin>>n;
        vector<ll>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        unordered_map<ll,int>mp;
        vector<ll>og=nums;
        sort(nums.begin(),nums.end());
        vector<ll>v=nums;
        for(int i=1;i<n;i++) v[i]+=v[i-1];
        for(int i=0;i<n;i++){
            int ans=i;
            int j=ans;
            while(ans<n){
                ll target=v[ans];
                int low=0,high=n-1;
                j=ans;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(nums[mid]<=target){
                        ans=mid;
                        low=mid+1;
                    }
                    else high=mid-1;
                }
                if(ans==j) break;
            }
            mp[nums[i]]=ans;
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=mp[og[i]];
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}