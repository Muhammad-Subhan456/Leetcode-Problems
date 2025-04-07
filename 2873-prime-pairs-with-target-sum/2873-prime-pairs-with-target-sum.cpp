class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
       vector<bool>isPrime(n+1,true); 
       isPrime[0] = isPrime[1] = false;
       for(int i=2; i <= n; ++i){
            if(isPrime[i]){
                for(int j = 2*i; j <= n; j+=i)
                    isPrime[j] = false;
            }
       }
       vector<int>store;
       for(int i=0; i <= isPrime.size()-1; ++i){
            if(isPrime[i])
                store.push_back(i);
       }
       int lo=0, hi = store.size()-1;
       vector<vector<int>> ans;
       while(lo <= hi){
        if(store[lo]+store[hi]==n){
            ans.push_back({store[lo],store[hi]});
            lo++;
            hi--;
        }
        else if (store[lo]+store[hi] < n) lo++;
        else hi--;

       }
        return ans;

    }
};