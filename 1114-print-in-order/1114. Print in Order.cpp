class Foo {
    condition_variable cv;
    mutex m;
    int x;
public:
    Foo() {
        x = 1;
    }

    void first(function<void()> printFirst) {
        std::unique_lock lock(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        x=2;
        lock.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock lock(m);
        cv.wait(lock, [&]{return x==2;});
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        x=3;
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock lock(m);
        cv.wait(lock, [&]{return x==3;});
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};