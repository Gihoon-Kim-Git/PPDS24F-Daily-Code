//[방법 1-1] python 코드의 방법 1-1 그대로 적용
#include <vector>
#include <algorithm>

class ExamRoom {
public:
    ExamRoom(int n) : n(n) {}

    int seat() {
        int student = 0;

        if (students.empty()) {
            student = 0; // 첫 번째 학생은 항상 0번 좌석에 앉음
        } else {
            int max_dist = students[0]; // 가장 왼쪽 간격 초기화

            // 중간 좌석 간의 최대 간격을 찾음
            for (int i = 1; i < students.size(); ++i) {
                int prev = students[i - 1];
                int curr = students[i];
                int dist = (curr - prev) / 2;
                if (dist > max_dist) {
                    max_dist = dist;
                    student = prev + dist;
                }
            }

            // 마지막 좌석(n-1)과 마지막 학생 간의 간격 확인
            if (n - 1 - students.back() > max_dist) {
                student = n - 1;
            }
        }

        // student 위치에 오름차순으로 삽입
        students.insert(std::lower_bound(students.begin(), students.end(), student), student);
        return student;
    }

    void leave(int p) {
        // p 위치의 학생 제거
        students.erase(std::remove(students.begin(), students.end(), p), students.end());
    }

private:
    int n;
    std::vector<int> students; // 현재 앉아 있는 학생들의 좌석 번호를 저장
};

//[방법 1-1인데  sort 적용해서 삽입위치 찾는 로직 간단히 함.] : 125/126개 통과. 하나는 time limit exceeded
#include <vector>
#include <algorithm>

class ExamRoom {
public:
    ExamRoom(int n) : n(n) {}

    int seat() {
        int student = 0;

        if (students.empty()) {
            student = 0; // 첫 번째 학생은 항상 0번 좌석에 앉음
        } else {
            int max_dist = students[0];
            student = 0;

            // 중간 좌석 간의 최대 간격을 찾음
            for (int i = 1; i < students.size(); ++i) {
                int prev = students[i - 1];
                int curr = students[i];
                int dist = (curr - prev) / 2;
                if (dist > max_dist) {
                    max_dist = dist;
                    student = prev + dist;
                }
            }

            // 마지막 좌석(n-1)과 마지막 학생 간의 간격 확인
            if (n - 1 - students.back() > max_dist) {
                student = n - 1;
            }
        }

        // 학생을 추가한 후 정렬
        students.push_back(student);
        std::sort(students.begin(), students.end());
        return student;
    }

    void leave(int p) {
        // p 위치의 학생 제거
        students.erase(std::remove(students.begin(), students.end(), p), students.end());
    }

private:
    int n;
    std::vector<int> students; // 현재 앉아 있는 학생들의 좌석 번호를 저장
};