class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        map<int,int>mp;
        int k = 1;
        for(auto &c : temp){
            if(mp.find(c) == mp.end()){
                mp[c] = k;
                k++;
            }
        }
        //for(auto p : mp) cout << p.first << ' ' << p.second << '\n';
        for(int i=0; i < n; i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};