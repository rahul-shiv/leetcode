class H2O {
    int h;
    mutex m;
    condition_variable cv;
public:
    H2O() {
        h = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> guard(m);
        cv.wait(guard,[this](){return h<2;});
        h++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> guard(m);
        cv.wait(guard,[this](){return h==2;});
        h=0;
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        cv.notify_one();
    }
};