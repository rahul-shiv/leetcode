class Foo {
    int turn;
    mutex m;
    condition_variable cv;
public:
    Foo() {
        turn = 1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex>guard(m);
        cv.wait(guard,[this](){return this->turn==1;});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex>guard(m);
        cv.wait(guard,[this](){return this->turn==2;});
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex>guard(m);
        cv.wait(guard,[this](){return this->turn==3;});
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        turn++;
        cv.notify_all();
    }
};