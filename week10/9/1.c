#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// 1. Find if path exists in graph
// 단일 연결 리스트 구조체 정의
typedef struct _slist {
    int *array; // 노드의 이웃을 저장하는 배열
    int len;    // 이웃의 수
} s_list;

// 유효한 경로 검사 함수
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    bool ret = false; // 반환값 초기화

    // 매우 희소한 행렬
    // 사용할 메모리 양 계산
    int *counts = calloc(n, sizeof(int)); // 각 노드의 연결 수를 세기 위한 배열
    for (int i = 0; i < edgesSize; i += 1) {
        counts[edges[i][0]] += 1; // 첫 번째 노드의 연결 수 증가
        counts[edges[i][1]] += 1; // 두 번째 노드의 연결 수 증가
    } // for i

    // 주어진 모든 링크를 기록
    s_list *row = calloc(n, sizeof(s_list)); // 각 노드의 연결 리스트를 위한 배열

    // 메모리 할당
    for (int i = 0; i < n; i += 1) {
        row[i].array = malloc(counts[i] * sizeof(int)); // 연결 수에 맞춰 메모리 할당
        row[i].len = 0; // 초기 길이 0으로 설정
    } // for i
    free(counts); // counts 배열 해제
    counts = NULL; // 포인터 초기화

    // 스택 푸시 스타일로 값 쓰기
    for (int i = 0; i < edgesSize; i += 1) {
        row[edges[i][0]].array[row[edges[i][0]].len] = edges[i][1]; // 첫 번째 노드의 이웃에 두 번째 노드 추가
        row[edges[i][0]].len += 1; // 길이 증가

        row[edges[i][1]].array[row[edges[i][1]].len] = edges[i][0]; // 두 번째 노드의 이웃에 첫 번째 노드 추가
        row[edges[i][1]].len += 1; // 길이 증가
    } // for i

    // 깊이 우선 탐색 (DFS)
    char *visited = calloc(n, sizeof(char)); // 방문한 노드를 기록할 배열
    int *stack = calloc(n, sizeof(int)); // 스택 배열
    int stack_top = 0; // 스택의 상단 인덱스 초기화

    stack[stack_top] = source; // 시작 노드를 스택에 추가
    stack_top += 1; // 상단 인덱스 증가
    visited[source] = 1; // 시작 노드 방문 표시
    int current; // 현재 노드 변수

    while (stack_top) { // 스택이 비어있지 않은 동안 반복
        stack_top -= 1; // 상단 인덱스 감소
        current = stack[stack_top]; // 현재 노드를 스택에서 꺼냄

        if (current == destination) { // 현재 노드가 목적지인 경우
            ret = true; // 경로 존재
            break; // 반복 종료
        } // if

        for (int i = 0; i < row[current].len; i += 1) { // 현재 노드의 모든 이웃에 대해 반복
            if (!visited[row[current].array[i]]) { // 이웃 노드가 방문되지 않은 경우
                stack[stack_top] = row[current].array[i]; // 이웃 노드를 스택에 추가
                stack_top += 1; // 상단 인덱스 증가
                visited[row[current].array[i]] = 1; // 이웃 노드 방문 표시
            } // if
        } // for i
    } // while

    // 메모리 정리
    for (int i = 0; i < n; i += 1) {
        free(row[i].array); // 각 노드의 이웃 배열 해제
        row[i].array = NULL; // 포인터 초기화
    } // for i

    free(row); // row 배열 해제
    free(visited); // visited 배열 해제
    row = NULL; // 포인터 초기화
    visited = NULL; // 포인터 초기화
    free(stack); // stack 배열 해제
    stack = NULL; // 포인터 초기화

    return ret; // 결과 반환
}