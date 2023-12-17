void breadth_first_search(tree T) {
    queue_of_node Q;
    node u, v;
    
    initialize(Q); 
    v = root of T;

    visit v; 
    enqueue(Q,v); 

    while (!empty(Q)) {
        dequeue(Q,v);

        for(each child u of v) {
            visit u;
            enqueue(Q,u);
        }
    }
}
