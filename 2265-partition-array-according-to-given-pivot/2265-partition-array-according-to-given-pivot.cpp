class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int>a;
    vector<int>b;
    vector<int>c;

    for(auto ele : nums){
        if(ele < pivot) a.push_back(ele);
        else if(ele > pivot) b.push_back(ele);
        else c.push_back(ele);

    }
    for(auto ele : c)
        a.push_back(ele);
    for(auto ele : b)
        a.push_back(ele);

    return a;

    }
};