class Solution {
public:
    int totalNumbers(vector<int>& d) {
        set<int>s;
        map<int,int>mp;
        for(auto c : d) mp[c]++;
        int n = d.size();
        for(int i=0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k= 0; k < n; ++k){
                    vector<int>freq(10,0);
                    int num = (d[i]*100) + (d[j]*10) + d[k];
                    freq[d[i]]++;
                    freq[d[j]]++;
                    freq[d[k]]++;
                    if(to_string(num).size() < 3) continue;
                    if(freq[d[i]] <= mp[d[i]] && freq[d[j]] <= mp[d[j]] && freq[d[k]] <= mp[d[k]] && (num%2==0)) s.insert(num);
                    
                }
            }
        }
        // for(auto c : s) cout << c << ' ';
        return s.size();
    }
};