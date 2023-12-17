struct heap
{
    // key들은 essentially complete binary tree를 이루고 있어야.
    // S의 인덱스는 1부터 n까지임
    // H.S[3]으로 heap array 에서 3th 요소에 접근
    keytype S[1...n];

    // heapsize는 0부터 n 사이의 값만 취함
    // H.heapsize
    int heapsize;
}


// 레코드의 저장 횟수를 최소화하기 위해서,
// root node의 초기 키(siftkey)는
// 그 키의 최종 위치가 결정될 때까지 어떤 마디에도 저장하지 않는다.
void siftdown(heap& H, index i) //⭐⭐⭐⭐⭐(index i)
{
    index parent, largerchild;
    keytype siftkey;
    bool spotfound;

    siftkey = H.S[i];   // 현재 위치의 key값
    parent = i;         // parent 변수를 현재 위치로 초기화
    spotfound = false;

    while (⭐2*parent <= H.heapsize && ⭐!spotfound) {
        if (2*parent <= H.heapsize && H.S[2*parent] < H.S[2*parent+1])
            largerchild = 2*parent + 1; // 오른쪽 자식마디의 인덱스는 부모마디 인덱스의 두 배보다 1 더 많다
        else
            largerchild = 2*parent; // 왼쪽 자식마디의 인덱스는 부모마디 인덱스의 두 배이다.

        if (⭐siftkey < H.S[largerchild]) {   //⭐⭐⭐⭐⭐ (siftkey는 계속 비교에만 사용됨.)
            H.S[parent] = H.S[largerchild]; 
            parent = largerchild;   //⭐⭐⭐⭐⭐
        }
        else
            spotfound = true;
    }
    H.S[parent] = ⭐siftkey;  // 위치를 찾은 최종 부모 위치에 siftkey 값을 저장. //⭐⭐⭐⭐⭐
}

keytype root(heap& H)
{
    keytype keyout;

    keyout = H.S[1];
    H.S[1] = H.S[H.heapsize];
    siftdown(H, 1);
    return keyout;
}

void removekeys(int n, heap& H, keytype S[])
{
    index i;

    for (i = n; i >= 1; i--) {
        S[i] = root(H);
    }
}

void makeheap(int n, heap& H)
{
    index i;

    H.heapsize = n; //⭐⭐⭐⭐⭐
    // 깊이가 d-1인 자식마디를 가진 마지막 마디는 배열의 ⌊ n/2 ⌋ 번째 슬롯에 있다.
    for (i = ⌊ n/2 ⌋; i >= 1; i--) { //⭐⭐⭐⭐⭐
        siftdown(H, i);
    }
}


void heapsort(int n, heap& H)
{
    makeheap(n, H);
    removekeys(n, H, H.S);
}