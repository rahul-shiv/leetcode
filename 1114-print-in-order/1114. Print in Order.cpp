class Foo {
    mutex mut;
    int turn;
    condition_variable cvar;
public:
    Foo() {
        turn = 1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> guard(mut);

        while(turn!=1){
            cvar.wait(guard);
        }
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn+=1;
        cvar.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> guard(mut);
        while(turn!=2){
            cvar.wait(guard);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn+=1;
        cvar.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> guard(mut);
        while(turn!=3){
            cvar.wait(guard);
        }
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        turn+=1;
        cvar.notify_all();

    }
};