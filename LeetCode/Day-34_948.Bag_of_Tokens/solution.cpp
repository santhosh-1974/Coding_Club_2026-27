class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int st = 0, end = tokens.size() - 1, scr = 0;
        int maxScore = 0;

        while (st <= end) {
            if (power >= tokens[st]) {
                scr++;
                power -= tokens[st++];
                maxScore = max(maxScore, scr);
            } else if (scr > 0) {
                scr--;
                power += tokens[end--];
            } else {
                break;
            }
        }

        return maxScore;
    }
};
