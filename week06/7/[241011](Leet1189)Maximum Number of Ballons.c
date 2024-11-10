/*문제 :
text가 주어졌을 때, text가 최대한 많은 'balloon'을 만들도록 하고 싶다. text 안의 character는 최대 한 번만 사용할 수 잇음. 
만들 수 있는 'balloon'의 최대 개수*/

/*문제풀이
    1. 128 크기의 array 선언. 각 문자의 ASCII코드가 index인. : b, a, l, o,n의 개수 기록을 위한. 
    2. text를 순회하면서 해당하는 AsCii코드 자리에 +1
    3. b(98), a(97), l(108), o(111), n(110) 에 따라서, array[98], array[97], array[108]/2, array[111]/2, array[110]의 개수 중에사 가장 min값을 찾아서 return.
*/

#include <stdio.h>
#include <stdlib.h>

int maxNumberOfBalloons(char* text){
    //1. array 선언 및 초기화
    int array[128];
    for (int i = 0; i < 128; i++) array[i] = 0;
    //2. text 순회. 개수 세기
    int i = 0;
    while (text[i]){
        char ch = text[i];
        array[ch]++;  //여기서 ch가 가는 값은 ASCII값임.  ( char 타입은 실제로는 작은 정수형이며, 각 문자는 정수 값(ASCII 코드)으로 표현)
        i++;
    }
    //3. 
    int min_num = array[97]; //a
    if (min_num > array[98]) min_num = array[98]; //b
    if (min_num > array[110]) min_num = array[110]; //n
    if (min_num > array[108]/2) min_num = array[108]/2; //l
    if (min_num > array[111]/2) min_num = array[111]/2; //o

    return min_num;
}

int main(){
    char* text1 = "nlaebolko";//1
    printf("%d\n", maxNumberOfBalloons(text1));

    char* text2 = "loonbalxballpoon"; //2
    printf("%d\n", maxNumberOfBalloons(text2));

    char* text3 = "leetcode"; //0
    printf("%d\n", maxNumberOfBalloons(text3));
}