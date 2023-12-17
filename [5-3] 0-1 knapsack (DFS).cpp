void knapsack(index i, int profit, int weight) {
    // 현재까지의 최대 이익과 현재까지의 최적해 정보 갱신
    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;
        numbest = i;
        bestset = include;
    }

    // promising 함수를 통해 현재 상태가 유망한지 검사
    if (promising(i, profit, weight)) {
        // 1. i+1번째 아이템을 선택한 경우
        include[i + 1] = "YES";
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);  // 선택한 경우에 대한 재귀 호출
        
        // 2. i+1번째 아이템을 선택하지 않은 경우
        include[i + 1] = "NO";
        knapsack(i + 1, profit, weight);  // 선택하지 않은 경우에 대한 재귀 호출
    }
}

bool promising(index i, int profit, int weight) {
    index j, k;
    int totweight;
    float bound;

    // 현재 무게가 제한을 초과하면 유망하지 않음 (유망 조건 1)
    if (weight >= W) {
        return false;
    }
    else {
        j = i + 1;  // item 순회하면서 현재 선택 가능한 item을 가리키는 인덱스
        bound = profit; // 현재까지 선택한 item의 이익으로 초기화
        totweight = weight; // 현재까지 선택한 item의 w 합으로 초기화

        // 현재 이후의 아이템들을 추가하면서 무게 제한을 초과하지 않는 범위 내에서 이익 갱신
        while ((j <= n) && (totweight + w[j]⭐ <= W)) {   // Sigma(j = i+1 ~ k-1)(w_j)
            totweight = totweight + w[j];
            bound = bound + p[j];   // Sigma(j = i+1 ~ k-1)(p_j)
            j++;
        }

        k = j;

        // 남은 아이템이 있으면 fractional knapsack problem에서 구한 값을 이용해 bound 갱신
        if (k <= n) {
            bound = bound + (W - totweight) * (p[k] / w[k]);
            return bound > maxprofit; // 유망 조건 2
        }
    }
}
