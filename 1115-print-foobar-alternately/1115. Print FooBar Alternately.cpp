class FooBar {
private:
    int n;
    int turn;
    mutex m;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        this->turn = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lock(m);
            cv.wait(lock, [&]{return turn==0;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn = 1;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lock(m);
            cv.wait(lock, [&]{return turn==1;});
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = 0;
            cv.notify_one();
        }
    }
};