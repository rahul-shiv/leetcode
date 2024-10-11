class SnapshotArray {
    int snap_id;
    vector<map<int,int>> arr;
public:
    SnapshotArray(int length) {
        arr = vector<map<int,int>>(length);
        snap_id = 0;
    }
    
    void set(int index, int val) {
        if(arr[index].empty() or arr[index].rbegin()->second!=val){
            arr[index][snap_id]=val;
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = arr[index].upper_bound(snap_id);
        if(it==arr[index].begin())return 0;
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */