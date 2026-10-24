class Solution {
    int toDay(const string& d) {
        static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int m = stoi(d.substr(0, 2));
        int day = stoi(d.substr(3, 2));
        int res = day;
        for (int i = 0; i < m - 1; i++) res += days[i];  // days in the months before m
        return res;                                     // day-of-year, 1..365
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int start = max(toDay(arriveAlice), toDay(arriveBob));
        int end   = min(toDay(leaveAlice), toDay(leaveBob));
        return max(0, end - start + 1);
    }
};