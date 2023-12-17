// median을 찾음.
// a는 길이가 5인 int 배열
int FindMedian(int *a) {
    // 1
    if (a[0] < a[1]) {
        swap(a, 0, 1);
    }
    
    // 2
    if (a[2] < a[3]) {
        swap(a, 2, 3); // a[2] > a[3]
    }

    // 3
    if (a[0] < a[2]) {
        swap(a, 0, 2);
        swap(a, 1, 3);
    } // we only know a[0] > a[2]> a[3] and a[0] > a[1]

    // 4
    if (a[1] < a[4])
}