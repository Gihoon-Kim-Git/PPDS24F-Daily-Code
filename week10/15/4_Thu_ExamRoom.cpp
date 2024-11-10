#include <set>
#include <cmath>
using namespace std;

class ExamRoom {
public:
    ExamRoom(int N) : n(N) {}

    int seat() {
        int student = 0;

        // 만약 시험장에 아무도 앉아있지 않은 경우, 첫 번째 자리 선택
        if (students.empty()) {
            student = 0;
        } else {
            int dist = *students.begin();  // 첫 학생과 맨 앞자리 사이의 거리

            // 인접한 학생들 사이의 최대 거리 탐색
            auto prev = students.begin();
            for (auto it = next(students.begin()); it != students.end(); ++it) {
                int s1 = *prev;
                int s2 = *it;
                int d = (s2 - s1) / 2;
                if (d > dist) {
                    dist = d;
                    student = s1 + d;
                }
                prev = it;
            }

            // 맨 끝자리와 마지막 학생 사이의 거리 확인
            if (n - 1 - *students.rbegin() > dist) {
                student = n - 1;
            }
        }

        // 학생이 앉은 자리를 set에 추가
        students.insert(student);
        return student;
    }

    void leave(int p) {
        // 학생이 떠난 자리를 set에서 제거
        students.erase(p);
    }

private:
    int n;                    // 시험장 좌석 수
    set<int> students;        // 앉아있는 학생들의 좌석 위치를 정렬된 상태로 유지
};