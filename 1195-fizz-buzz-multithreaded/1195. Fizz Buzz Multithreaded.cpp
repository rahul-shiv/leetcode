class FizzBuzz {
private:
    int n;
    int x;
    mutex mut;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
        x = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> guard(mut);
            while(x<=n and !(x%3==0 and x%5!=0)){
                cv.wait(guard);
            }
            if(x>n)return;
            printFizz();
            x++;
            guard.unlock();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> guard(mut);
            while(x<=n and !(x%3!=0 and x%5==0)){
                cv.wait(guard);
            }
            if(x>n) return;
            printBuzz();
            x++;
            guard.unlock();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> guard(mut);
            while(x<=n and !(x%3==0 and x%5==0)){
                cv.wait(guard);
            }
            if(x>n)return;
            printFizzBuzz();
            x++;
            guard.unlock();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> guard(mut);
            while(x<=n and (x%3==0 or x%5==0)){
                cv.wait(guard);
            }
            if(x>n)return;
            printNumber(x);
            x++;
            guard.unlock();
            cv.notify_all();
        }
    }
};