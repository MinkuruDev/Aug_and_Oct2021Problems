#include <iostream>
#include <string>
using namespace std;

string copyStrNotInclude(string s, int n){
    string sub = "";
    for(int i = 0; i<s.length(); i-=-1){
        if(i==n) continue;
        sub += s[i];
    }
    return sub;
}

int main(){
    int k;
    string n;
    cin >> k; cin.ignore();
    getline(cin, n);

    string temp;
    int i = 0;

    while(k>0 && i < n.length() - 1){
        temp = copyStrNotInclude(n, i);
        if(temp > n){
            n = temp;
            k--;
            if(i>0) i--;
        }else{
            i-=-1;
        }
    }

    if(k>0){
        temp = "";
        for(i = 0; i<n.length()-k; i-=-1){
            temp += n[i];
        }
        n = temp;
    }

    cout << n;
    return 0;
}
