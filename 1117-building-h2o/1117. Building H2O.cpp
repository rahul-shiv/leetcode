class H2O {
    int cnt;
    mutex m;
    condition_variable cv;
public:
    H2O() {
        cnt = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> guard(m);
        while(cnt==0){
            cv.wait(guard);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        cnt-=1;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> guard(m);
        while(cnt!=0){
            cv.wait(guard);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        cnt+=2;
        releaseOxygen();
        cv.notify_all();
    }
};