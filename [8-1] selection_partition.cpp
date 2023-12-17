// keytype: 배열 S의 원소 타입
// index: 배열 S의 인덱스 타입

// 선택 알고리즘의 주 함수
keytype selection(index low, index high, index k) {
    index pivotpoint;

    // 베이스 케이스: low와 high가 같으면 배열에는 하나의 원소만 남음
    if (low == high) {
        return S[low]; // 해당 원소를 반환
    }
    else {
        // 배열을 두 부분으로 분할하고 pivotpoint를 찾음
        partition(low, high, pivotpoint);

        // pivotpoint가 k와 같으면 k번째로 작은 원소를 찾았음
        if (k == pivotpoint) {
            return S[pivotpoint];
        }
        // k가 pivotpoint보다 작으면 왼쪽 부분 배열에서 찾음
        else if (k < pivotpoint) {
            return selection(low, pivotpoint - 1, k);
        }
        // k가 pivotpoint보다 크면 오른쪽 부분 배열에서 찾음
        else {
            return selection(pivotpoint + 1, high, k);
            // return selection(pivotpoint + 1, high, k - (pivotpoint + 1));
        }
    }
}

// 배열을 분할하는 보조 함수
void partition(index low, index high, index& pivotpoint) {
    index i, j;
    keytype pivotitem;

    pivotitem = S[low]; // pivotitem으로 첫 번째 아이템을 선택
    j = low;

    // 배열을 순회하면서 pivotitem보다 작은 원소는 왼쪽으로 이동
    for (i = low + 1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            // S[i]와 S[j]를 교환
            swap(S[i], S[j]);
        }
    }

    // pivotpoint를 결정하고 pivotitem을 올바른 위치로 이동
    pivotpoint = j;
    // S[low]와 S[pivotpoint]를 교환
    swap(S[low], S[pivotpoint]);
}

// 사용 예시: k번째로 작은 원소 찾기
kthsmallest = selection(1, n, k);