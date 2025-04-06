class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
    vector<bool>isPrime(right+1,true);
    vector<int>ans(2,-1);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= right; ++i){
        if(isPrime[i]){
            for(int j = 2*i; j <= right; j+=i){
                isPrime[j] = false;
            }
        }
    }
    vector<int>store;
    for(int i=left; i <= right; ++i){
        if(isPrime[i]){
            store.push_back(i);
        }
    }
    if(store.size()<=1) return ans;
    int diff = INT_MAX;
    for(int i= store.size()-1; i > 0;--i){
      //  cout << store[i]-store[i-1] << endl;
        diff = min(diff,(store[i]-store[i-1]));
        // ans[0] = store[i-1];
        // ans[1] = store[i];
      //  cout << ans[0] << " " << ans[1] << endl;
       // cout << diff << endl;
        if(diff == (store[i]-store[i-1])){
            ans[0] = store[i-1];
            ans[1] = store[i];
        }
    }
    return ans;
    }
};