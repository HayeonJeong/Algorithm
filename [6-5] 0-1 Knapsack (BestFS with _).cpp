void knapsack3(int n,
               const int p[], const int w[],
               int W,
               int &maxprofit){

    queue_of_node PQ;
    node u, v;
    
    initialize(PQ);
    v.level = 0; v.profit = 0; v.weight = 0;
    v.bound = bound(v); // ⭐️⭐️⭐️


    maxprofit = 0;
    insert (PQ, v);

    while (!empty(Q)) {
        remove(PQ, v);

        if(v.bound⭐️ > maxprofit) {   // BestFS
            // 1. u를 v의 자식마디로 놓음
            u.level = v.level + 1;
            u.profit = v.profit + p[u.level];
            u.weight = v.weight + w[u.level];
            if ((u.weight <= W) && (u.profit > maxprofit)) {    // 넘지 않는 순간까지'만' 고려
                maxprofit = u.profit;
                u.bound = bound(u);
            }
            if (bound(u)⭐️ > maxprofit) {  // 넘는 순간까지 고려, Best일 때만 PQ에 Insert
                insert(PQ, u);
            }
        }
    }
}

struct node {
    int level;
    int profit;
    int weight;
    float bound;
}