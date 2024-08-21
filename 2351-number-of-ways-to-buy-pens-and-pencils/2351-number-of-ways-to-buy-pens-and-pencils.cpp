class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int buy = total/cost1;
        long long ans=0;
        for(int i=0; i<= buy; ++i){
            int check = total;
            check -= (i*cost1);
            ans +=((check/cost2)+1);
        }
        return ans;
    }
};