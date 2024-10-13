class ZeroEvenOdd {
private:
    int n;
    int i,j;
    bool pzero;
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        pzero = true;
        i = 1;
        j = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){
                return i>n or pzero;
            });
            if(i>n)break;
            printNumber(0);
            this->pzero=false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){
                return i>n or (!pzero and i%2==0);
            });
            if(i>n)break;
            printNumber(i++);
            this->pzero=true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){
                return i>n or (!pzero and i%2!=0);
            });
            if (i > n) break;
            printNumber(i++);
            this->pzero=true;
            cv.notify_all();
        }
    }
};