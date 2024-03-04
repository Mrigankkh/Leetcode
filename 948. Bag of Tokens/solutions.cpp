class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int currentScore = 0;
        int maxScore = 0;
        sort(tokens.begin(), tokens.end());

        int start = 0;
        int end = tokens.size()-1;


        while(end>=start)
        {
            // Facedown
            if(power < tokens[start] && currentScore>0)
            {
                     --currentScore;
                power+=tokens[end];
                --end;
            }
            else if(power>=tokens[start])
            {
                maxScore = max(maxScore, ++currentScore);
                power-=tokens[start];
                start++;
            }
            else
            {
                break;
            }
    
        }
        return maxScore;
    }
};