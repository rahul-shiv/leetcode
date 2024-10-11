class H2O {
    int hc;
    int oc;
    mutex m;
    condition_variable cv;
public:
    H2O() {
        oc=hc=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> guard(m);
        while(hc>1){
            cv.wait(guard);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        hc+=1;
        if(oc==1 and hc==2){
            oc = hc = 0;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> guard(m);
        while(oc>0){
            cv.wait(guard);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        oc+=1;
        releaseOxygen();
        if(oc==1 and hc==2){
            oc = hc = 0;
        }
        cv.notify_all();
    }
};