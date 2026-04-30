class Solution {
public:
    
    long long countSubarrays(vector<int>& a,int k) {
        long long maxi = *max_element(a.begin(),a.end());
        long long n = a.size();
        long long l =0, r = 0, cnt = 0 ,subarr = 0;

        for(long long r=0; r < n; r++){
            if(a[r] == maxi) cnt++;
            while(cnt >= k){
                if(a[l] == maxi) cnt--;
                l++;
            }
            subarr += (long long)(r-l+1);
        }
        return (long long)(((n*(n+1))/2) - subarr);
    }
};