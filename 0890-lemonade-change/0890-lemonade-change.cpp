class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5=0, count_10=0;
    for(int i=0; i < bills.size(); ++i){
        if(bills[i]==5)
            count_5+=5;
        else if(bills[i]==10){
            if(count_5>=5){
                count_5-=5;
                count_10+=10;
            }
            else
                return false;
        }
        else{
            if(count_5>=5 && count_10>=10){
                count_5-=5;
                count_10-=10;
            }
            else if(count_5>=15)
                count_5-=15;
            else
                return false;
        }
    }
    return true;

    }
};