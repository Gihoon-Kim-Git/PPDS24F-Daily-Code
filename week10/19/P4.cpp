#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ExamRoom {
public:
    ExamRoom(int n) : n(n) {
        room = {};
        interval = {n - 1};
    }

    int seat() {
        if (room.empty()) {
            room.push_back(0);
            interval.insert(interval.begin(), 0);
            return 0;
        }

        if (room[0] != 0) {
            interval[0] *= 2;
        }
        if (room.back() != n - 1) {
            interval.back() *= 2;
        }

        int maxlen = (*max_element(interval.begin(), interval.end()) / 2) * 2;
        int offset = 0;

        // 최대 간격 위치를 찾고 새로운 좌석 위치 계산
        for (int i = 0; i < interval.size(); ++i) {
            if (interval[i] >= maxlen) {
                offset += maxlen / 2;
                if (i == 0 && room[0] != 0) {
                    offset = 0;
                }
                break;
            }
            if (i == 0 && room[0] != 0) {
                offset += interval[0] / 2;
            } else {
                offset += interval[i];
            }
        }

        // room과 interval 배열 업데이트
        for (int j = 0; j < room.size(); ++j) {
            if (room[j] > offset && j == 0) {
                room.insert(room.begin(), offset);
                interval.insert(interval.begin() + 1, interval[0] / 2);
                interval[0] = 0;
            } else if (room[j] < offset && j == room.size() - 1) {
                room.push_back(offset);
                interval[interval.size() - 1] /= 2;
                interval.push_back(0);
            } else if (room[j] < offset && room[j + 1] > offset) {
                room.insert(room.begin() + j + 1, offset);
                interval.insert(interval.begin() + j + 1, maxlen / 2);
                interval[j + 2] -= maxlen / 2;
            }
        }

        if (room[0] != 0) {
            interval[0] /= 2;
        }
        if (room.back() != n - 1) {
            interval.back() /= 2;
        }

        // Debug print statements
        cout << "maxlen: " << maxlen << ", offset: " << offset << endl;
        cout << "room: ";
        for (auto r : room) cout << r << " ";
        cout << "\ninterval: ";
        for (auto i : interval) cout << i << " ";
        cout << endl;

        return offset;
    }

    void leave(int p) {
        auto it = find(room.begin(), room.end(), p);
        if (it != room.end()) {
            int idx = it - room.begin();
            room.erase(it);
            interval[idx] = interval[idx] + interval[idx + 1];
            interval.erase(interval.begin() + idx + 1);
        }

        // Debug print statements
        cout << "room: ";
        for (auto r : room) cout << r << " ";
        cout << "\ninterval: ";
        for (auto i : interval) cout << i << " ";
        cout << endl;
    }

private:
    vector<int> room;        // 현재 좌석에 앉아 있는 위치
    vector<int> interval;    // 좌석 간 간격
    int n;                   // 좌석 수
};

int main() {
    ExamRoom obj(8);
    obj.seat();
    obj.seat();
    obj.seat();
    obj.leave(0);
    obj.leave(7);
    obj.seat();
    obj.seat();
    obj.seat();
    obj.seat();
    obj.seat();
    obj.seat();
    obj.seat();

    return 0;
}