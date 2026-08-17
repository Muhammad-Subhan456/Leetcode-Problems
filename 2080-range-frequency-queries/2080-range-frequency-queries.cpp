class RangeFreqQuery {
public:
    vector<unordered_map<int,int>>seg;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        seg.resize(4*n);
        build(0,0,n-1,arr);
        //display();
    }

    unordered_map<int,int> merge(const auto &left,const auto &right){
        unordered_map<int,int> mp;
        for(auto &c : left){
            mp[c.first] += c.second;
        }
        for(auto &c : right){
            mp[c.first] += c.second;
        }
        return mp;
    }

    void build(int i, int l, int r, const vector<int>&nums){
        if(l == r){
            seg[i][nums[l]]++;
            return;
        }
        int mid = l + (r-l)/2;
        build(2*i+1,l,mid,nums);
        build(2*i+2,mid+1,r,nums);
        seg[i] = merge(seg[2*i+1],seg[2*i+2]);
    }
    int query(int start,int end, int value, int i, int l, int r){
        if(r < start  || l > end) return 0;
        if(l >= start && r <= end) return seg[i][value];
        int mid = l + (r-l)/2;
        return query(start,end,value,2*i+1,l,mid) + 
        query(start,end,value,2*i+2,mid+1,r);
    }
    
    int query(int left, int right, int value) {
        return query(left,right,value,0,0,n-1);
    }
    void displaymap(auto &mp){
        for(auto &c : mp){
            cout << c.first << ' ' << c.second << '\n';
        }
    }
    void display(){
        for(int i=0; i < 4*n; ++i){
            cout << i << ": " << '\n';
            displaymap(seg[i]);
        }
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */