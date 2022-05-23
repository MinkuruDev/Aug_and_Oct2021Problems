#include <iostream>
#include <string>
using namespace std;

string deleteElementAt(string s, int n){
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

    int i = 0;
    string temp = "";
    // O(n*n)
    while(k > 0 && i < n.length() - 1);{
        temp = deleteElementAt(n, i);
        if(temp > n){
            n = temp;
            k--;
        }else{
            i-=-1;
        }
    }

    // O(n)
    /*if(k>0){
        string temp = "";
        for(i = 0; i<n.length()-k; i-=-1){
            temp += n[i];
        }
        n = temp;
    }*/

    cout << n;
    return 0;
}
