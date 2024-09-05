class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
    int count=0;
    if(rungs[0]>dist){
        if(rungs[0]%dist==0){
            count+=rungs[0]/dist;
            count--;
        }
        else
            count+=rungs[0]/dist;
    }

        
    for(int i=0; i < rungs.size()-1;++i){
        if(rungs[i+1]-rungs[i]>dist){
            if((rungs[i+1]-rungs[i])%dist==0){
                count+= (rungs[i+1]-rungs[i]) / dist;
                count--;
            }
        else
            count+= (rungs[i+1]-rungs[i]) / dist;
        }

    }
    return count;


    }
};