void breadth_first_branch_and_bound(state_space_tree T, number& best){
    queue_of_node Q;
    node u, v;
    
    initialize(Q);
    v = root of T;
    
    enqueue(Q,v);
    best = value(v);

    while (!empty(Q)) {
        dequeue(Q,v);

        for(each child u of v) {
            if(value(u) is better than best) {
                best = value(u); 
            }
            if(bound(u) is better than best) {
                enqueue(Q,u); 
            }
        }
    }
}

struct node {
    int level;
    int profit;
    int weight;
}