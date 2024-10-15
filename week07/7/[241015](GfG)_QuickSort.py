"""Quick Sort
    1. Divide : Pivot을 기준으로 왼쪽, 오른쪽 2개의 list로 분류한다.
    2. 하나의 list를 sort하는 방법 : low, high index를 활용한다.
        pivot을 제외하고 low는 맨 왼쪽, high는 맨 오른쪽에서 시작함.
        low는 왼->오, high는 오->왼으로 움직이다가
            pivot < list[low] 이면 멈춤.
            pivot > list[high] 이면 멈춤
        low, high가 둘 다 멈춘 시점에는 low, high가 역전되지 않았다면, list[low], list[high]를 swap.
        >> 위 과정은 low >= high가 되는 시점까지 진행한다.(엇갈리는 시점)
    3. 2번과정이 끝나면 Pivot과 high를 바꾼다.
        Recursive하게 호출한 하위 partition에서 새로운 pivot을 설정한다.
"""

"""Quick Sort의 Divide and Conquer
    1. Divide : Pivot을 기준으로 왼쪽은 작은값, 오른쪽은 큰 값들의 partition으로 만든다.
                더이상 divide하지 않는 시점은 partition의 크기가 0 또는 1
    2. Conquer : 들어온 partition을 sort한다. (low, High index를 관리하면서 pivot 기준으로 값 분류하는 과정)
    3. Combine : 1,2가 끝난 2개의 partitions를 결합한다.
"""

class Solution:
    def partition(self,arr,low,high):
        pivotValue = arr[high];
        i = low;
        
        for j in range(low, high):
            if arr[j] <= pivotValue:
                temp = arr[j]
                arr[j] = arr[i]
                arr[i] = temp
                i+=1
        
        temp2 = arr[i]
        arr[i] = pivotValue
        arr[high] = temp2
        
        return i
        
    #Function to sort a list using quick sort algorithm.
    def quickSort(self,arr,low,high):
        if low < high:
            pivot_done = self.partition(arr, low, high)
            self.quickSort(self, low, pivot_done-1);
            self.quickSort(self, pivot_done+1, high)
            
            
    
