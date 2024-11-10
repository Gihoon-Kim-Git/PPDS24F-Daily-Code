// [방법 1-1]
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int n;
    int students[10000]; // 좌석 번호를 저장하는 배열, 최대 크기를 임의로 설정
    int size; // 현재 앉아 있는 학생 수
} ExamRoom;

ExamRoom* examRoomCreate(int n) {
    ExamRoom* obj = (ExamRoom*) malloc(sizeof(ExamRoom));
    obj->n = n;
    obj->size = 0; // 초기에는 학생이 없음
    return obj;
}

int  examRoomSeat(ExamRoom* obj) {
    int student = 0;

    if (obj->size == 0) {
        student = 0; // 첫 번째 학생은 0번 좌석에 앉음
    } else {
        int max_dist = obj->students[0];
        student = 0;

        // 중간 좌석 간의 최대 간격을 찾음
        for (int i = 1; i < obj->size; ++i) {
            int prev = obj->students[i - 1];
            int curr = obj->students[i];
            int dist = (curr - prev) / 2;
            if (dist > max_dist) {
                max_dist = dist;
                student = prev + dist;
            }
        }

        // 마지막 좌석(n-1)과 마지막 학생 간의 간격 확인
        if (obj->n - 1 - obj->students[obj->size - 1] > max_dist) {
            student = obj->n - 1;
        }
    }

    // student 위치에 오름차순으로 삽입
    int i = obj->size - 1;
    while (i >= 0 && obj->students[i] > student) {
        obj->students[i + 1] = obj->students[i];
        i--;
    }
    obj->students[i + 1] = student;
    obj->size++;

    return student;
}

void  examRoomLeave(ExamRoom* obj, int p) {
    // p 위치의 학생 제거
    int i;
    for (i = 0; i < obj->size; ++i) {
        if (obj->students[i] == p) {
            break;
        }
    }
    for (; i < obj->size - 1; ++i) {
        obj->students[i] = obj->students[i + 1];
    }
    obj->size--;
}

void examRoomFree(ExamRoom* obj) {
    free(obj);
}

//----------------------------------------------------------------------------------------------------------------------
//[방법 1-1인데 sort 활용] 직접 오름차순위치에 맞는 자리 찾아가는 게 아니라, sort해서 오름차순 정렬. 이렇게하면 삽입 위치 찾는 로직이 간단.
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int n;
    int students[10000]; // 좌석 번호를 저장하는 배열, 최대 크기를 임의로 설정
    int size; // 현재 앉아 있는 학생 수
} ExamRoom;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

ExamRoom* examRoomCreate(int n) {
    ExamRoom* obj = (ExamRoom*) malloc(sizeof(ExamRoom));
    obj->n = n;
    obj->size = 0; // 초기에는 학생이 없음
    return obj;
}

int examRoomSeat(ExamRoom* obj) {
    int student = 0;

    if (obj->size == 0) {
        student = 0; // 첫 번째 학생은 0번 좌석에 앉음
    } else {
        int max_dist = obj->students[0];
        student = 0;

        // 중간 좌석 간의 최대 간격을 찾음
        for (int i = 1; i < obj->size; ++i) {
            int prev = obj->students[i - 1];
            int curr = obj->students[i];
            int dist = (curr - prev) / 2;
            if (dist > max_dist) {
                max_dist = dist;
                student = prev + dist;
            }
        }

        // 마지막 좌석(n-1)과 마지막 학생 간의 간격 확인
        if (obj->n - 1 - obj->students[obj->size - 1] > max_dist) {
            student = obj->n - 1;
        }
    }

    // 학생 추가 후 정렬
    obj->students[obj->size] = student;
    obj->size++;
    qsort(obj->students, obj->size, sizeof(int), compare);

    return student;
}

void examRoomLeave(ExamRoom* obj, int p) {
    // p 위치의 학생 제거
    int i;
    for (i = 0; i < obj->size; ++i) {
        if (obj->students[i] == p) {
            break;
        }
    }
    for (; i < obj->size - 1; ++i) {
        obj->students[i] = obj->students[i + 1];
    }
    obj->size--;
}

void examRoomFree(ExamRoom* obj) {
    free(obj);
}

/**
 * Your ExamRoom struct will be instantiated and called as such:
 * ExamRoom* obj = examRoomCreate(n);
 * int param_1 = examRoomSeat(obj);
 
 * examRoomLeave(obj, p);
 
 * examRoomFree(obj);
*/