class Solution {
public:
    using ll = long long;
    ll minRemoval(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        ll n = a.size();
        ll ans = n, l = 0;
        for(ll r=0; r < n; r++){
            while(a[r] > 1LL*a[l]*k) l++;
            ans = min(ans,n-(r-l+1));
        }
        return ans;
    }
};