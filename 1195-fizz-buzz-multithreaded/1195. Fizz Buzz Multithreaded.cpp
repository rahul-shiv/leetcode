class FizzBuzz {
private:
    int n;
    int i;
    condition_variable cv;
    mutex m;
public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){return i>n or (i%3==0 and i%5);});
            if(i>n)break;
            printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){return i>n or (i%5==0 and i%3);});
            if(i>n)break;
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){return i>n or  (i%3==0 and i%5==0);});
            if(i>n)break;
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){return i>n or (i%3 and i%5);});
            if(i>n)break;
            printNumber(i++);
            cv.notify_all();
        }
    }
};