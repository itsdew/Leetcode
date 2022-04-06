class FrontMiddleBackQueue {
    deque<int> l;
    deque<int> r;
    
    void resize() {
        if (l.size() > r.size() + 1) {
            r.push_front(l.back());
            l.pop_back();
        } else if (r.size() > l.size()) {
            l.push_back(r.front());
            r.pop_front();
        }
    }
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        l.push_front(val);
        resize();
    }
    
	// if they aren't the same size, transfer last element in left queue to right queue before adding to middle
    void pushMiddle(int val) {
        if (l.size() > r.size()) {
            r.push_front(l.back());
            l.pop_back();
        }
        l.push_back(val);
    }
    
    void pushBack(int val) {
        r.push_back(val);
        resize();
    }
    
    int popFront() {
        if (l.empty()) return -1;
        
        int val = l.front();
        l.pop_front();
        resize();
        return val;
    }
    
    int popMiddle() {
        if (l.empty()) return -1;
        
        int val = l.back();
        l.pop_back();
        resize();
        return val;
    }
    
	// pop back from right deque if not empty, else pop from left deque
    int popBack() {
        if (l.empty() && r.empty()) return -1;
        
        deque<int>& curr = r.empty() ? l : r;
        int val = curr.back();
        curr.pop_back();
        resize();
        return val;
    }
};