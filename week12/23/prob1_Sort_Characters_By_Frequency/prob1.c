// Sort Characters By Frequency
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char character;
    int frequency;
} CharFreq;

int compare(const void *a, const void *b) {
    CharFreq *freqA = (CharFreq *)a;
    CharFreq *freqB = (CharFreq *)b;
    if (freqA->frequency != freqB->frequency)
        return freqB->frequency - freqA->frequency; // Descending frequency
    return freqA->character - freqB->character;    // Ascending character order
}

char *frequencySort(char *s) {
    int freq[128] = {0};
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        freq[(int)s[i]]++;
    }

    CharFreq charFreqs[128];
    int count = 0;

    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            charFreqs[count].character = i;
            charFreqs[count].frequency = freq[i];
            count++;
        }
    }

    qsort(charFreqs, count, sizeof(CharFreq), compare);

    char *result = (char *)malloc(len + 1);
    int index = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < charFreqs[i].frequency; j++) {
            result[index++] = charFreqs[i].character;
        }
    }

    result[index] = '\0';
    return result;
}

// Example usage
int main() {
    char s[] = "tree";
    char *sorted = frequencySort(s);
    printf("%s\n", sorted);
    free(sorted);
    return 0;
}
