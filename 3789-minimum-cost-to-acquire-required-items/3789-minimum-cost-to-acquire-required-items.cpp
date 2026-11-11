class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
            long long cost = 0;
            if(costBoth <= cost1+cost2){
                if(need1 <= need2){
                    cost = 1LL * need1 * costBoth  ;
                    need2 -= need1;
                    // complete need 2
                    if(cost2 <= costBoth) cost += 1LL * need2*cost2;
                    else cost += 1LL * need2*costBoth;
                }
                else{
                    cost =1LL * need2 * costBoth;
                    need1 -= need2;
                    // complete need 1
                    if(cost1 <= costBoth) cost +=1LL * need1*cost1;
                    else cost +=1LL * need1*costBoth;
                }
            }
            else cost =1LL * ((1LL*need1*cost1) + (1LL*need2*cost2));

            
            return cost;

    }
};