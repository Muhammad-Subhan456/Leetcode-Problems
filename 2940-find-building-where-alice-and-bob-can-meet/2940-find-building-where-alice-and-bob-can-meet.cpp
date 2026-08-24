class Solution {
public:

    void buildSegmentTree(int i, int l, int r, int seg[], vector<int>&h){
        if(l == r){
            seg[i] = l;
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1,l,mid,seg,h);
        buildSegmentTree(2*i+2,mid+1,r,seg,h);

        int left = seg[2*i+1];
        int right = seg[2*i+2];
        seg[i] = (h[left] >= h[right]) ? left : right;


    }

    int query(int start,int end,int i, int l, int r, int st[], vector<int>&h){
        if(l > end || r < start){
            return -1;  
        }
        if(l >=  start && r <= end) return st[i];
        int mid = l + (r-l)/2;
        int left = query(start,end,2*i+1,l,mid,st,h);
        int right = query(start,end,2*i+2,mid+1,r,st,h);
        if(left == -1) return right;
        if(right == -1 ) return left;
        return (h[left] >= h[right] ) ? left : right;
    }

    int RMIQ(int st[], vector<int>&h, int n, int a, int b){
        return query(a,b,0,0,n-1,st,h);
    }

    int* constructST(vector<int>&h,int n){
        int* seg = new int[4*n];
        buildSegmentTree(0,0,n-1,seg,h);
        return seg;

    }

    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n = h.size();
        int *segmentTree = constructST(h,n);
        vector<int> result;
        for(auto & query : q){
            int mini = min(query[0],query[1]);
            int maxi = max(query[0],query[1]);
            if(mini == maxi) result.push_back(mini);
            else if(h[mini] < h[maxi]) result.push_back(maxi);
            else{
                int l = maxi + 1;
                int r = n-1;
                int res_idx = INT_MAX;
                while(l <= r){
                    int mid = l + (r-l)/2;
                    int idx = RMIQ(segmentTree,h,n,l,mid);
                    if(h[idx] > max(h[maxi],h[mini])){
                        res_idx = min(idx,res_idx);
                        r = mid - 1;
                    }
                    else l = mid + 1;
                }
            if(res_idx == INT_MAX) result.push_back(-1);
            else result.push_back(res_idx);
            }
        }
        
        return result;
    }
};