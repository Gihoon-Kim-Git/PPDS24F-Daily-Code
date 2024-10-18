int* getRow(int rowIndex, int* returnSize) {
    // Set the size of the returned row
    *returnSize = rowIndex + 1;

    // Allocate memory for the row
    int* row = (int*)malloc(sizeof(int) * (*returnSize));

    // Initialize the first element to 1 (first element is always 1)
    row[0] = 1;

    // If rowIndex is 0, return the row (it will contain only one element, 1)
    if (rowIndex == 0) {
        return row;
    }

    // 파스칼의 삼각형 i번째 row
    for (int i = 1; i <= rowIndex; ++i) {
        // 파스칼의 삼각형 i번째 row의 원소들을 계산
        for (int j = i; j > 0; --j) {
            if (j == i) {
                row[j] = 1;  // Last element of each row is always 1
            } else {
                row[j] = row[j] + row[j - 1];
            }
        }
    }

    return row;
}

/*
// ver 2

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    // pascal의 삼각형 할당
    int **pascal = (int **)(malloc(sizeof(int*)*(*returnSize)));
    for (int i = 0; i <= rowIndex; i++)
    {
        pascal[i] = (int *)malloc(sizeof(int)*(i + 1));
    }
    // 각 행에 첫번째, 마지막 element 1로 초기화
    for (int i = 0; i<=rowIndex; i++)
    {
        pascal[i][0]=1;
        pascal[i][i]=1;        
    }

    for(int i = 2; i <= rowIndex; i++)
    {
        for (int j = 1 ; j < i; j++)
        {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
    //return pascal[rowIndex];
        // 반환할 행 복사
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i) {
        result[i] = pascal[rowIndex][i];
    }

    // 2차원 배열 메모리 해제
    for (int i = 0; i <= rowIndex; ++i) {
        free(pascal[i]);
    }
    free(pascal);

    return result;
}

*/