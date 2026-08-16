class StockSpanner {
public:

    stack<pair<int,int>> s;
    int i = 0;

    StockSpanner() {
        
    }

    int next(int price) {

        while(!s.empty() && s.top().first <= price) {
            s.pop();
        }

        int ans;

        if(s.empty()) {
            ans = i + 1;
        }
        else {
            ans = i - s.top().second;
        }

        s.push({price, i});

        i++;

        return ans;
    }
};