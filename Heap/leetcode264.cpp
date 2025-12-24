// Ugly number II

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> seen;

        pq.push(1);
        seen.insert(1);

        long long ugly = 1;

        for (int i = 0; i < n; i++) {
            ugly = pq.top();
            pq.pop();

            if (!seen.count(ugly * 2)) {
                pq.push(ugly * 2);
                seen.insert(ugly * 2);
            }
            if (!seen.count(ugly * 3)) {
                pq.push(ugly * 3);
                seen.insert(ugly * 3);
            }
            if (!seen.count(ugly * 5)) {
                pq.push(ugly * 5);
                seen.insert(ugly * 5);
            }
        }

        return (int)ugly;
    }
};
