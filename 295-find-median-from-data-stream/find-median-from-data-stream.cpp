class MedianFinder {
    priority_queue <int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if(maxHeap.size()>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        double ans;
        if(minHeap.size() > maxHeap.size()){
            ans = minHeap.top();
        }else{
            ans = (double)minHeap.top() + (double)maxHeap.top();
            ans /= 2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */