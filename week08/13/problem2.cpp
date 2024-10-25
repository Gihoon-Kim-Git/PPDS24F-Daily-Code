class MyCalendarTwo {
public:
// 아래처럼 하면 너무 메모리 사용량이 많음
    // vector<int> check(1000000000, 0);
// 이럴 때는 map을 사용해보자 -> 시작점과 끝점만 관리하는 방식?
    std::map<int, int> check;

    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        check[start]++;
        check[end]--;

        int active=0;

        //auto로 해두면 타입을 추론함
        for(auto i=check.begin(); i!=check.end(); ++i){
            //map의 두번째 value를 가져오라는 뜻
            active+=i->second;

            if(active>=3){
                check[start]--;
                check[end]++;
                if (check[start] == 0) check.erase(start);  // 값이 0이 되면 해당 시점 삭제
                if (check[end] == 0) check.erase(end);      // 값이 0이 되면 해당 시점 삭제
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */