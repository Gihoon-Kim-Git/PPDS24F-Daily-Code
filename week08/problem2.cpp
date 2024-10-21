class MyCalendarTwo {
public:
    vector<pair<int,int>> book1;
    vector<pair<int,int>> book2;
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        for(auto&it:book2){
            if (it.first<end && it.second>start){
                return false;
            }
        }
        for (auto&it:book1){
            if (it.first<end && it.second>start){
                book2.emplace_back(make_pair(max(it.first,start),min(it.second,end)));
            }
        }
        book1.emplace_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */