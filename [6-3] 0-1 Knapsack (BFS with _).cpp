void knapsack2(int n,
               const int p[], const int w[],
               int W,
               int &maxprofit) {

    queue_of_node Q;
    node u, v;

    initialize(Q);  // Q를 빈 대기열로 초기화
    v.level = 0; v.profit = 0; v.weight = 0; // v가 뿌리마디가 되게 초기화


    
    maxprofit = 0;
    enqueue(Q, v); 

    while (!empty(Q)) {
        dequeue(Q, v);
        
        // 1. u를 v의 자식마디로 놓음
        u.level = v.level + 1;
        u.profit = v.profit + p[u.level];   // u를 다음 아이템을 포함하는 자식마디로 놓음
        u.weight = v.weight + w[u.level];
        if ((u.weight <= W) && (u.profit > maxprofit ⭐️)) {    // 넘지 않는 순간까지'만' 고려
            maxprofit = u.profit; ⭐️
        }
        if (bound(u) > maxprofit) { ⭐️ // 넘는 순간까지 고려
            enqueue(Q, u);
        }

        // 2. u를 다음 아이템을 포함하지 않는 자식마디로 놓음
        u.weight = v.weight;
        u.profit = v.profit;
        // 넣지 않아서 maxprofit 업데이트 필요 없음.
        if (bound(u) > maxprofit) {
            enqueue(Q, u);
        }
    }
} // 문제점 : 경로 출력? include, bestset 출력

// 함수 bound는 함수 promising과 본질적으로 같다.
float bound(node u) {
    index j, k; 
    int totweight; 
    float result; // ⭐️⭐️⭐️
    
    if (u.weight >= W) {
        return 0; // ⭐️⭐️⭐️
    }
    else {
        j = u.level +1; // ⭐️⭐️⭐️
        totweight = u.weight; 
        result = u.profit; // ⭐️⭐️⭐️
    
        while ((j <= n) && (totweight + w[j] <= W)) {   // Sigma(j = i+1 ~ k-1)(w_j)
            totweight = totweight + w[j]; 
            result = result + p[j]; 
            j++;    
        }

        k = j;

        // 남은 아이템이 있으면 fractional knapsack problem에서 구한 값을 이용해 bound 갱신
        if (k <= n) {
            result = result + (W - totweight) * (p[k] / w[k]);
            return result;  // ⭐️⭐️⭐️
        }
    }
}