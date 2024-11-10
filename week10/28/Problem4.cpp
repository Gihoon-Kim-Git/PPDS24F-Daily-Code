# include <algorithm>
# include <set>

using namespace std;

class ExamRoom {

public:
    ExamRoom(int n) : n(n) {}
    
    int seat() {
        int seat = 0;
        
        if (!occupied.empty()) {
            int maxDist = *occupied.begin();
            seat = 0;
    
            auto prev = occupied.begin();
            for (auto it = next(occupied.begin()); it != occupied.end(); ++it) {
                int dist = (*it - *prev) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                    seat = *prev + dist;
                }
                prev = it;
            }
            
            if (n - 1 - *occupied.rbegin() > maxDist) {
                seat = n - 1;
            }
        }
        
        occupied.insert(seat);
        return seat;
    }
    
    void leave(int p) {
        occupied.erase(p);
    }

    int n; 
    set<int> occupied;  
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */