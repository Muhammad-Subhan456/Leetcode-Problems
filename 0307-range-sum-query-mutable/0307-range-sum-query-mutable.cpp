class NumArray {
public:
    vector<int>seg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(0,0,n-1,nums);
    }
    void build(int i,int l, int r, const vector<int>&nums){
        if(l == r){
            seg[i] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(2*i+1,l,mid,nums);
        build(2*i+2,mid+1,r,nums);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
    void update(int idx, int val, int i, int l, int r){
        if(l == r){
            seg[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid){
            update(idx,val,2*i+1,l,mid);
        }
        else{
            update(idx,val,2*i+2,mid+1,r);
        }
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
    
    void update(int index, int val) {
        update(index,val,0,0,n-1);
    }
    
    int query(int start, int end, int i, int l, int r){
        if(r < start || l > end) return 0; // No Overlap
        if(l >= start && r <= end) return seg[i]; // Complete Overlap
        // Partial Overlap
        int mid = l + (r-l)/2;
        return query(start,end,2*i+1,l,mid) + query(start,end,2*i+2,mid+1,r);

    }
    
    int sumRange(int left, int right) {
        return query(left,right, 0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */