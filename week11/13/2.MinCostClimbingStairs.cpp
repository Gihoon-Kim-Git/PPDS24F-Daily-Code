class Solution {
public:
    int min(int x, int y) {
        return (x > y) ? y : x;
    }

    int stairs(vector<int>& cost, int index, vector<int>& memo) {
        // 계단의 끝에 도달했을 때 비용은 0
        if (index >= cost.size()) {
            return 0;
        }

        // 메모이제이션: 이미 계산된 값이 있으면 반환
        if (memo[index] != -1) {
            return memo[index];
        }

        // 현재 위치에서 한 칸 또는 두 칸 이동했을 때의 최소 비용 계산
        int oneStep = cost[index] + stairs(cost, index + 1, memo);
        int twoStep = cost[index] + stairs(cost, index + 2, memo);

        // 최소 비용을 메모에 저장
        memo[index] = min(oneStep, twoStep);
        return memo[index];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);  // 메모 배열 초기화

        // 0번째와 1번째에서 시작할 때의 최소값을 비교
        return min(stairs(cost, 0, memo), stairs(cost, 1, memo));
    }
};
