class SnapshotArray {
    #define SNAP_INTERVAL  10
    int snap_id;
    vector<int> arr;
    unordered_map<int,vector<int>> snap_m;
    unordered_map<int,unordered_map<int,int>> diff_m;
    
    int replay(int index, int snap){
        int last_snap = (snap/SNAP_INTERVAL)*SNAP_INTERVAL;
        int val = snap_m[last_snap][index];
        for(int i = last_snap+1; i <= snap; i++){
            auto it = diff_m[i].find(index);
            if(it!=diff_m[i].end()){
                val = it->second;
            }
        }
        return val;
    }
public:
    SnapshotArray(int length) {
        arr = vector<int>(length);
        snap_id = -1;
    }
    
    void set(int index, int val) {
        arr[index] = val;
        if((snap_id+1)%SNAP_INTERVAL){
            diff_m[snap_id+1][index]=val;
        }
    }
    
    int snap() {
        snap_id++;
        if(snap_id%SNAP_INTERVAL==0){
            snap_m[snap_id] = arr;
        }
        return snap_id;
    }
    
    int get(int index, int snap_id) {
        if(snap_id%SNAP_INTERVAL==0){
            return snap_m[snap_id][index];
        }
        return replay(index, snap_id);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */