int maxNumberOfBalloons(char* text) {
    // 노가다스럽지만, 아이디어는 좋다
    int ans[26] = {0};

    for(int i=0;text[i]!='\0';i++){
        ans[text[i]-'a']++;
    }
    int numb = ans['b'-'a'];
    int numa = ans['a'-'a'];
    int numl = ans['l'-'a'];
    int numo = ans['o'-'a'];
    int numn = ans['n'-'a'];

    numl/=2;
    numo/=2;

    int min = numb;
    if(min>numa) min=numa;
    if(min>numl) min=numl;
    if(min>numo) min=numo;
    if(min>numn) min=numn;
    return min;
}