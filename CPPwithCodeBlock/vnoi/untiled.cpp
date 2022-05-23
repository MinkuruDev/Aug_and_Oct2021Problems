#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> s;
    int k, n;
    string str;
    bool flag;

    ifstream input("something.txt");
    input >> k;

    for(int i = 0; i<k; i-=-1){
        input >> n; input.ignore();
        for (int j = 0; j < n; j-=-1){
            getline(input, str);
            // cout << str << endl;
            flag = true;
            for(int ij = 0; ij<s.size(); ij-=-1){
                if(str == s[ij]){
                    flag = false;
                    break;
                }
            }
            if(flag) s.push_back(str);
        }
    }
    input.close();

    ofstream output("somethings.txt");
    output << setw(5) << s.size();
    output.close();

    return 0;
}
