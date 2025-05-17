class Solution {
public:
    vector<int> partitionLabels(string s) {
    string temp = s;
    int n = s.size();
    int maxi = INT_MIN;
    vector<int>ans;
    reverse(temp.begin(),temp.end());
    for(int i=0; i < n; ++i){
        char c = s[i];
        int i2 = (n-temp.find(c))-1;
        maxi = max(maxi,i2);
        if(i == maxi){
           ans.push_back(maxi);
        }
    }
    
    vector<int>a;
    for(int i=0; i < ans.size(); ++i){
       
        if(i==0) a.push_back(ans[i]+1);
        else
        a.push_back(ans[i] - ans[i-1]);
    }

    return a;
    }
};