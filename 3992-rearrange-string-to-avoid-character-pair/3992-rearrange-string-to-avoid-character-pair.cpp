class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        int countX = 0, countY = 0;
        string middle = "";

       
        for(char ch : s) {
            if(ch == x)
                countX++;
            else if(ch == y)
                countY++;
            else
                middle += ch;
        }

        string ans = "";

      
        while(countY--) {
            ans += y;
        }

       
        ans += middle;

       
        while(countX--) {
            ans += x;
        }

        return ans;
    }
};