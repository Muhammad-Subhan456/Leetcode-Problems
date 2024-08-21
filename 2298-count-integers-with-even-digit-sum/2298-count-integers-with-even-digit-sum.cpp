class Solution {
public:
    int countEven(int num) {
        int count =0;
        for(int i=2 ; i <= num; ++i){
        int sum=0;
        int swap=i;
            while(swap>0){
                int mod = swap % 10;
                sum+=mod;
                swap/=10;
            }
            if(sum%2==0)
                count++;
            
        }
        return count;
    }
};