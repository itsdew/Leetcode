//Author: Devendra Uraon
class MyCalendar {
    vector<pair<int, int>> vec;
public:
    MyCalendar() {
    
    }
    
    bool book(int start, int end) {
        for (auto date: vec)
            if ((start >= date.first && start < date.second) or
                (end > date.first && end < date.second) or
                (start <= date.first && end > date.first))
                return false;
    
        vec.push_back({start, end});
        return true;
    }
};