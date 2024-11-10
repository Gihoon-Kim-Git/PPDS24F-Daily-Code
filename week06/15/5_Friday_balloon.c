int maxNumberOfBalloons(char* text) {
    int b = 0, a = 0, l = 0, o = 0, n = 0;
    for(int i=0; text[i] != '\0'; i++) {
        if (text[i] == 'b') b++; 
        else if (text[i] == 'a') a++;
        else if (text[i] == 'l') l++;
        else if (text[i] == 'o') o++;
        else if (text[i] == 'n') n++;
    }
    l /= 2;
    o /= 2;

    int min = b;
    min = min > a? a : min; 
    min = min > l? l : min;
    min = min > o? o : min;
    min = min > n? n : min;

    return min;
}