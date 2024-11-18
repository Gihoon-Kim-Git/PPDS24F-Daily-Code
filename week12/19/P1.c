#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_SIZE 256

typedef struct Map {
    char c;
    int i;
} Map;

int compare(const void *a, const void *b) {
    return ((Map *)b)->i - ((Map *)a)->i;
}

char* frequencySort(char *s) {
    int length = strlen(s);
    int ascii[ASCII_SIZE] = {0};
    for (int i = 0; i < length; i++) ascii[(unsigned char)s[i]]++;
    Map dict[ASCII_SIZE];
    int value = 0;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (ascii[i] > 0) {
            dict[value].c = i;
            dict[value].i = ascii[i];
            value++;
        }
    }
    qsort(dict, value, sizeof(Map), compare);
    char *result = (char *)malloc(length + 1);
    int pos = 0;
    for (int i = 0; i < value; i++) {
        for (int j = 0; j < dict[i].i; j++) {
            result[pos++] = dict[i].c;
        }
    }
    result[pos] = '\0';
    return result;
}

int main() {
    printf("%s\n", frequencySort("tree"));
    printf("%s\n", frequencySort("cccaaa"));
    printf("%s\n", frequencySort("Aabb"));
    return 0;
}