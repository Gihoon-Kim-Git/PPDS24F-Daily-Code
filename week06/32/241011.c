int maxNumberOfBalloons(char* text) {
    int arr[5] = {};
    for (int i=0; i < strlen(text); ++i) {
        char x = text[i];
        if (x == 'b') {
            arr[0]++;
        } else if (x == 'a') {
            arr[1]++;
        } else if (x == 'l') {
            arr[2]++;
        } else if (x == 'o') {
            arr[3]++;
        } else if (x == 'n') {
            arr[4]++;
        }
    }
    arr[2] /= 2;
    arr[3] /= 2;

    int minimum = arr[0];
    for (int i=1; i < 5; ++i) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}