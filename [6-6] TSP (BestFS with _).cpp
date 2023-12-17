void travel2(int n,
             const number W[][],
             ordered_set &opttour,
             number &minlength) {
    
    priority_queue_of_node PQ;
    node u, v;

    initialize(PQ); // PQ를 빈 대기열로 초기화
    v.level = 0;
    v.path = [1];   // 첫째 노드를 출발 정점으로 놓음
    v.bound = bound(v); // v의 bound 계산

    minlength = INFINITE; // 초기 minlength를 무한대로 설정
    insert(PQ, v); // 초기 노드 v를 우선순위 큐에 삽입

    while (!empty(PQ)) {
        remove(PQ, v); // 현재 bound가 가장 작은 노드 v를 우선순위 큐에서 제거
        
        if (v.bound⭐️ < minlength) { // ⭐️ BestFS : 현재 노드 v의 bound가 현재까지의 최소 길이보다 작을 때만 진행
            u.level = v.level + 1;  // u를 v의 자식 노드로 설정

            for ((2 < i < n인 모든 i) && (v.path에 속하지 않은 i)) {
                u.path = v.path;
                u.path의 끝에 i 추가; // 현재까지의 경로에 i를 추가

                if (u.level == n-2⭐️) {   // 다음 노드에서 여행을 마치는지 검사
                    u.path에 없는 유일한 정점의 인덱스를 u.path의 끝에 추가;
                    u.path의 끝에 1⭐️을 추가; // 첫째 노드를 마지막 노드로 돌아감

                    if (length(u)⭐️ < minlength) {    // length는 여행 경로의 길이를 계산
                        minlength = length(u);
                        opttour = u.path; // 최적 경로 업데이트
                    }
                } else {
                    //u.bound = bound(u); // u의 bound 계산
                    if (bound(u) < minlength) { // 현재까지의 최소 길이보다 작은 경우에만 PQ에 추가
                        insert(PQ, u);
                    }
                }
            }
        }
    }
}

struct node {
    int level;
    ordered_set path;
    number bound;
}
