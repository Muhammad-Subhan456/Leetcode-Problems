class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int ans;
    float check=0;
    float area=0;
    int index;
    for(int i=0; i<dimensions.size();++i){
        float mult = sqrt((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]));
        if(mult>=area){
        area = max(area,mult);
        index=i;
        }
    }
    cout << index;
    ans = dimensions[index][0]*dimensions[index][1];
    float length = sqrt((dimensions[index][0]*dimensions[index][0])+(dimensions[index][1]*dimensions[index][1]));
    cout << ans;
    for(int i=0; i < dimensions.size();++i){
        if(length == sqrt((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1])))
        ans = max(ans,dimensions[i][0]*dimensions[i][1]);
    }
    return ans;
    }
};