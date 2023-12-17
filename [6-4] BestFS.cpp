void best_first_branch_and_bound (state_space_tree T, number best) {
    priority_queue_of_node PQ;
    node u,v;
    
    initialize(PQ);
    v = root of T;

    insert(PQ,v);   // ⭐️ (BFS에서는 enqueue(Q, v)였음)
    best = value(v);

    while (!empty(PQ)) { // initialize PQ to empty
        remove(PQ,v);   // Remove node with best bound

        if (bound(v) is better than best) { // ⭐️⭐️⭐️ Check if node is still promising
            for(each child u of v) {
                if(value(u) is better than best) {
                    best = value(u);
                }
                if(bound(u) is better than best) {
                    insert(PQ,u);
                }
            }
        }
    }
}