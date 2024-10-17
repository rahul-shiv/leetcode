class FooBar {
private:
    int n;
    int turn;
    mutex m;
    condition_variable cv;

public:
    FooBar(int n) {
        turn = 0;
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){return !this->turn;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn=1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){return this->turn;});
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn=0;
            cv.notify_all();
        }
    }
};