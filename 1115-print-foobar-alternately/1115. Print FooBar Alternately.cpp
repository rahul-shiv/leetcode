class FooBar {
private:
    int n;
    int turn;
    mutex m;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        turn = 0;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> guard(m, defer_lock);
        for (int i = 0; i < n; i++) {
            guard.lock();
            while(turn){
                cv.wait(guard);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn=1;
            guard.unlock();
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> guard(m, defer_lock);
        for (int i = 0; i < n; i++) {
            guard.lock();
            while(turn==0){
                cv.wait(guard);
            }
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn=0;
            guard.unlock();
            cv.notify_all();
        }
    }
};