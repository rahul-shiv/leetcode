class BoundedBlockingQueue {
    mutex m;
    int capacity;
    condition_variable cv;
    queue<int> q;
public:
    BoundedBlockingQueue(int capacity): capacity(capacity) {
        
    }
    
    void enqueue(int element) {
        unique_lock<mutex> guard(m);
        cv.wait(guard,[this](){return q.size()<capacity;});
        q.push(element);
        cv.notify_one();
    }
    
    int dequeue() {
        int ret;
        unique_lock<mutex> guard(m);
        cv.wait(guard,[this](){return !q.empty();});
        ret = q.front();
        q.pop();
        cv.notify_one();
        return ret;
    }
    
    int size() {
        return q.size();
    }
};