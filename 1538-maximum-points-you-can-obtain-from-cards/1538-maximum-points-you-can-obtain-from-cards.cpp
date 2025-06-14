class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0;
        int r = cardPoints.size()-1;
        int i=0;
        for(;i<k;++i) lsum += cardPoints[i];
        i--;
        int maxi = INT_MIN;
        maxi = max(maxi,lsum);
        while(lsum!=0){
            lsum -= cardPoints[i--];
            rsum += cardPoints[r--];
            maxi = max(maxi,(lsum+rsum));
        }
        return maxi;
    }
};