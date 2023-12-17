// 배열 S에서 k번째로 작은 원소를 찾는 함수
keytype select(int n, keytype S[], index k) {
    return selection2(S, 1, n, k);
}

// Median of Medians 알고리즘을 사용하여 배열에서 k번째로 작은 원소를 찾는 함수
keytype selection2(keytype S[], index low, index high, index k) {
    if (high == low) {
        return S[low];
    }
    else {
        // 배열을 부분 그룹으로 나누고 중앙값들의 중앙값을 찾아 pivotitem으로 설정
        partition2(S, low, high, k);

        if (k == pivotpoint) {
            return S[pivotpoint];
        }
        // 배열 분할 횟수 : n
        else if (k < pivotpoint) {
            return selection2(S, low, pivotpoint - 1, k); // 7n/10 - 3/2
        }
        else {
            return selection2(S, pivotpoint + 1, high, k); // 7n/10 - 3/2
        }
    }
}

// Median of Medians를 수행하여 배열을 분할하는 함수
void partition2(keytype S[], index low, index high, index k) {
    const arraysize = high - low + 1;
    const r = ⌈arraysize / 5⌉;⭐️ // 몇 개의 부분 그룹으로 나누어질 수 있는가

    index i, j, mark, first, last;
    keytype pivotitem, T[1...r];

    // 각 부분 그룹에서 중앙값을 찾아 T 배열에 저장
    for (i = 1; i <= r; i++) {
        first = low + 5 * i - 5;⭐️
        // 마지막 그룹의 요소가 5개일거란 보장 없음.
        last = minimum(low + 5 * i - 1, arraysize);
        T[i] = median of S[first] through S[last];  // 6n/5
    }

    // 중앙값들의 중앙값을 찾아 pivotitem으로 설정
    pivotitem = select(r, T, ⌊(r + 1) / 2⌋);⭐️ // W(n/5)

    // 배열 분할: j와 mark를 활용하여 배열 S를
    //          pivotitem을 기준으로 왼쪽은 작은 원소들,
    //          오른쪽은 큰 원소들로 분할
    j = low;
    for (i = low + 1; i <= high; i++) {
        if (S[i] == pivotitem) {
            swap(S[i], S[j]);
            mark = j;   // pivotitem을 위치시킬 장소에 표시
            j++;
        }
        // pivotitem과 작은 원소는 왼쪽으로 이동
        else if (S[i] < pivotitem) {
            swap(S[i], S[j]);
            j++;
        }
    }

    // pivotpoint를 결정하고 pivotitem을 올바른 위치로 이동
    pivotpoint = j - 1;
    swap(S[mark], S[pivotpoint]);
}

kthsmallest = select(n, S, k);