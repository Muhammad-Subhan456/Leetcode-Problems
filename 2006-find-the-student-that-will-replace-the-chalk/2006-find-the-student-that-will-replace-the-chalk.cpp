class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
    long long sum=0;
    for(auto ele : chalk)
        sum+=ele;
    k = k % sum;
        sum=0;
    for(int i=0 ; i < chalk.size();++i){
            sum+=chalk[i];
            if(sum>k)
                return i;
    }
    return -1;
    }   
};