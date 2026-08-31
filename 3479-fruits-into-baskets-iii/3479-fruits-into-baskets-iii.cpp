class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        vector<int>st(4*n,-1);

        function<void(int,int,int)> build = [&](int i, int l, int r)->void{
            if(l==r){
                st[i] = b[l];
                return;
            }
            int mid = l + (r-l)/2;
            build(2*i+1,l,mid);
            build(2*i+2,mid+1,r);
            st[i] = max(st[2*i+1],st[2*i+2]);
        };
        build(0,0,n-1);
        int unplace = 0;

        function<bool(int, int, int, int)> query = [&](int i, int l, int r, int f)-> bool{
            if(st[i] < f){
                return false;
            }
            if(l==r){
                st[i] = -1;
                return true;
            }

            int mid = l + (r-l)/2;
            bool place = false;
            if(st[2*i+1] >= f) {
                place = query(2*i+1,l,mid,f);
            }
            else{
                place = query(2*i+2,mid+1,r,f);

            }
            st[i] = max(st[2*i+1],st[2*i+2]);
            return place;
        };

        for(int &c : f){
            if(!query(0,0,n-1,c)){
                unplace++;
            }
        }
        return unplace;
    }
};