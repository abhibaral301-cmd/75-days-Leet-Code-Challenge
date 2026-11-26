bool canAliceWin(int n) {
    int A = 10, k = 0;
    while (n >= A) {
        n -= A;
        A--;
        k++;
    }
    return k % 2 == 1;
}