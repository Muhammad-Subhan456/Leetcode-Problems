class Solution {
public:
    vector<int> findMissingElements(vector<int>& a) {
        int mini = *min_element(a.begin(),a.end());
        int maxi = *max_element(a.begin(),a.end());
        vector<int>res;
        for(int i=mini; i <= maxi; ++i){
            if(find(a.begin(),a.end(),i) == a.end()) res.push_back(i);
        }
        sort(res.begin(),res.end());
        return res;
    }
};