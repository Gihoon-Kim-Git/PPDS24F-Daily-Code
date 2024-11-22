#include <queue>
#include <stdexcept>

class MyStack {
private:
    std::queue<int> in;  // 데이터 저장
    std::queue<int> out; // 임시 데이터 이동

public:
    MyStack() {}

    // 스택에 요소 추가
    void push(int x) {
        in.push(x);
    }

    // 스택에서 마지막 요소 제거 및 반환
    int pop() {
        if (in.empty()) {
            throw std::runtime_error("Stack is empty");
        }

        // 마지막 요소를 제외하고 모두 `out`으로 이동
        while (in.size() > 1) {
            out.push(in.front());
            in.pop();
        }

        // 마지막 요소를 제거하고 저장
        int lastElement = in.front();
        in.pop();

        // `out`을 다시 `in`으로 교체
        std::swap(in, out);

        return lastElement;
    }

    // 스택의 마지막 요소 반환
    int top() {
        if (in.empty()) {
            throw std::runtime_error("Stack is empty");
        }

        while (in.size() > 1) {
            out.push(in.front());
            in.pop();
        }

        // 마지막 요소 확인
        int lastElement = in.front();
        out.push(lastElement); // 다시 `out`에 넣음
        in.pop();

        // `out`을 다시 `in`으로 교체
        std::swap(in, out);

        return lastElement;
    }

    // 스택이 비었는지 확인
    bool empty() {
        return in.empty();
    }
};
