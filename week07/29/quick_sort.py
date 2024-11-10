def quickSort(arr,low,high):
    if low<high:
        pi = partition(arr,low,high)  

        quickSort(arr,low,pi-1)
        quickSort(arr,pi+1,high)


def partition(arr,low,high):  # pivot을 기준으로 나눔
    pivot_idx = high
    arr[low], arr[pivot_idx] = arr[pivot_idx], arr[low]  # 첫 번째로 이동
    pivot = arr[low]
    i = low + 1  # 피벗보다 작은 값이 배치될 위치를 추적

    for j in range(low + 1, high + 1):  # pivot 이후부터 끝까지
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1  # 다음 피벗보다 작은 값이 들어갈 위치를 준비
    
    arr[low], arr[i-1] = arr[i-1], arr[low]  # 피벗을 i-1 위치 (pivot보다 작은 마지막 값)에 놓음
    return i-1   # 현재 피벗의 위치


arr = [1, 1, 2, 3, 4, 6, 7, 9, 10]
quickSort(arr,0,len(arr)-1)
print(arr)
