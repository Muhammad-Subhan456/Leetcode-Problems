class Solution {
public:
    bool checkPowersOfThree(int n) {
    int mod=0;
    while(n!=0){
    if(n%3!=0 && n%3!=1) return false;
    n/=3;
    }
    return true;
    }
    
};