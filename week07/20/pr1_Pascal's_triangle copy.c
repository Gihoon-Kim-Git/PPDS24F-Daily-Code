/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
        *returnSize = rowIndex+1;
        int* arr = (int*)malloc((*returnSize)*sizeof(int));
        for(int i=0;i<*returnSize;i++){
            arr[i] = 1;
        }
        if(*returnSize==0 || *returnSize==1) return arr;
        else{
            int* temp = getRow(rowIndex-1,returnSize);
            for(int j=1;j<*returnSize;j++){
                arr[j] = temp[j-1]+temp[j];
            }
            free(temp);
            *returnSize = rowIndex+1;
            return arr;}
}