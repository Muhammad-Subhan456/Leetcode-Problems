class Solution {
public:
    vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int>a(n);
    for(int i=0; i < n; ++i){
        int sum=0;
        for(int j=0; j < n; ++j){
            if(boxes[j]=='1') sum += abs(i-j);
        }
        a[i] = sum;
    }
    return a;
    }
};