#include <stdio.h>
#include <string.h>

int maxNumberOfBalloons(char *text) {
    // Array to store counts for characters b, a, l, o, n
    int count[5] = {0};
    
    // Iterate over the text and count relevant characters
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'b') count[0]++;
        else if (text[i] == 'a') count[1]++;
        else if (text[i] == 'l') count[2]++;
        else if (text[i] == 'o') count[3]++;
        else if (text[i] == 'n') count[4]++;
    }
    
    // Since we need two 'l' and two 'o' for "balloon", divide their counts by 2
    count[2] /= 2;  // 'l'
    count[3] /= 2;  // 'o'
    
    // Find the minimum count among b, a, l, o, n
    int min_count = count[0];  // Start with count of 'b'
    for (int i = 1; i < 5; i++) {
        if (count[i] < min_count) {
            min_count = count[i];
        }
    }
    
    return min_count;  // Return the maximum number of "balloon" words we can form
}

int main() {
    char text[] = "loonbalxballpoon";
    printf("Maximum number of 'balloon' instances: %d\n", maxNumberOfBalloons(text));
    return 0;
}
