#include <bits/stdc++.h>

using namespace std;

struct Point{
    long location;
    bool whiteColored;
    bool operator<(Point other){
        return location < other.location;
    }
};

int main(){
    vector<Point> points;
    int n, k=0;
    Point temp;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> temp.location;
        temp.whiteColored = false;
        points.push_back(temp);
    }
    for(int i = 0; i<n; i++){
        cin >> temp.location;
        temp.whiteColored = true;
        points.push_back(temp);
    }
    sort(points.begin(), points.end());
    auto it = points.begin(), endit = points.end();
    Point fr = *it;

    while(it < endit){
        if(fr.whiteColored^(*it).whiteColored){
            k++;
            it++;
        }
        fr = *it;
        it++;
    }

    cout << k;
    return 0;
}
