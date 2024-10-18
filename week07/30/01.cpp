#include <iostream>
#include <vector>

using namespace std; 

def getRow(rowIndex: int) -> List[int]:
    # [1] Pascal의 삼각형의 특정 행(rowIndex)을 구하기 위한 초기 리스트 설정
    # 첫 번째 행은 항상 [1]이므로 이를 초기값으로 설정
    row = [1]
    
    # [2] rowIndex가 0이 아니면 계속 행을 계산해야 하므로 반복문 실행
    # 1부터 rowIndex까지 각 행을 계산
    for i in range(1, rowIndex + 1):
        # [2.1] 새로운 행을 만들기 위해 [1]로 시작
        new_row = [1]
        
        # [2.2] 이전 행(row)의 두 값씩 더하여 새로운 값 계산
        # row[j-1]과 row[j]를 더한 값을 새로 계산된 행(new_row)에 추가
        for j in range(1, len(row)):
            new_row.append(row[j - 1] + row[j])
        
        # [2.3] 새 행의 마지막은 항상 1이므로 마지막에 [1] 추가
        new_row.append(1)
        
        # [2.4] 새로 계산된 행을 다음 반복에서 사용할 수 있도록 row를 업데이트
        row = new_row
    
    # [3] 계산이 끝난 후, 해당 rowIndex에 해당하는 행을 반환
    return row

int main() {
    int rowIndex;
    cout << "Enter Row index: ";
    cin >> rowIndex;

    vector<int> result = getRow(rowIndex);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;  
}