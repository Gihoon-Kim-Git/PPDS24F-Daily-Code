class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt_b = 0;
        int cnt_a = 0;
        int cnt_l = 0;
        int cnt_o = 0;
        int cnt_n = 0;

        for (char c : text) {
            if (c=='b') cnt_b += 1;
            else if (c=='a') cnt_a += 1;
            else if (c=='l') cnt_l += 1;
            else if (c=='o') cnt_o += 1;
            else if (c=='n') cnt_n += 1;
            else {}
        }

        cnt_l /= 2;
        cnt_o /= 2;

        int cnt_balloon = cnt_b;
        cnt_balloon = cnt_balloon < cnt_a? cnt_balloon : cnt_a;
        cnt_balloon = cnt_balloon < cnt_l? cnt_balloon : cnt_l;
        cnt_balloon = cnt_balloon < cnt_o? cnt_balloon : cnt_o;
        cnt_balloon = cnt_balloon < cnt_n? cnt_balloon : cnt_n;

        return cnt_balloon;
    }
};
