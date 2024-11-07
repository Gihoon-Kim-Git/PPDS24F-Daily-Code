#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* seats;
    int capacity;
    int size;
    int n;
} ExamRoom;

ExamRoom* examRoomCreate(int n) {
    ExamRoom* obj = (ExamRoom*)malloc(sizeof(ExamRoom));
    obj->seats = (int*)malloc(sizeof(int) * n); // 최대 n개의 좌석
    obj->capacity = n;
    obj->size = 0;
    obj->n = n - 1;
    return obj;
}

// 이진 탐색을 통한 좌석 위치 찾기
int findInsertPosition(ExamRoom* obj, int value) {
    int left = 0, right = obj->size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (obj->seats[mid] == value)
            return mid;
        else if (obj->seats[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

// 좌석을 추가하는 함수
void insertSeat(ExamRoom* obj, int value) {
    int pos = findInsertPosition(obj, value);
    for (int i = obj->size; i > pos; --i) {
        obj->seats[i] = obj->seats[i - 1];
    }
    obj->seats[pos] = value;
    obj->size++;
}

// 좌석을 삭제하는 함수
void removeSeat(ExamRoom* obj, int value) {
    int pos = findInsertPosition(obj, value);
    if (pos < obj->size && obj->seats[pos] == value) {
        for (int i = pos; i < obj->size - 1; ++i) {
            obj->seats[i] = obj->seats[i + 1];
        }
        obj->size--;
    }
}

int examRoomSeat(ExamRoom* obj) {
    if (obj->size == 0) {
        insertSeat(obj, 0);
        return 0;
    }

    int left = obj->seats[0];
    int diff = left;
    int max = 0;

    // 중간 위치 계산
    for (int i = 1; i < obj->size; i++) {
        int right = obj->seats[i];
        int mid = left + (right - left) / 2;
        int distance = mid - left < right - mid ? mid - left : right - mid;
        if (distance > diff) {
            diff = distance;
            max = mid;
        }
        left = right;
    }

    // 마지막 자리와의 거리 확인
    int last = obj->seats[obj->size - 1];
    if (obj->n - last > diff) {
        max = obj->n;
    }

    // 선택된 좌석 추가
    insertSeat(obj, max);
    return max;
}

void examRoomLeave(ExamRoom* obj, int p) {
    removeSeat(obj, p);
}

void examRoomFree(ExamRoom* obj) {
    free(obj->seats);
    free(obj);
}

// 테스트용 main 함수
int main() {
    ExamRoom* obj = examRoomCreate(8);
    printf("Seat: %d\n", examRoomSeat(obj)); // 첫 번째 학생이 앉을 좌석
    printf("Seat: %d\n", examRoomSeat(obj)); // 두 번째 학생이 앉을 좌석
    printf("Seat: %d\n", examRoomSeat(obj)); // 세 번째 학생이 앉을 좌석
    examRoomLeave(obj, 0);                   // 첫 번째 학생이 떠남
    examRoomLeave(obj, 7);                   // 마지막 학생이 떠남
    printf("Seat: %d\n", examRoomSeat(obj)); // 추가 학생이 앉을 좌석
    printf("Seat: %d\n", examRoomSeat(obj));
    printf("Seat: %d\n", examRoomSeat(obj));

    examRoomFree(obj); // 메모리 해제
    return 0;
}

