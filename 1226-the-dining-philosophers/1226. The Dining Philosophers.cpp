class DiningPhilosophers {
    #define NUM 5
    vector<mutex> m;
public:
    DiningPhilosophers() {
        m = vector<mutex>(NUM);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int lfork = (philosopher-1+NUM)%NUM;
		int rfork = (philosopher+NUM)%NUM;
        if(philosopher%2){
            swap(lfork,rfork);
        }
        unique_lock<mutex> lguard(m[lfork]);
        unique_lock<mutex> rguard(m[rfork]);
        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();
    }
};