#include <iostream>
#include <string>

#define ever ;;

using namespace std;

void strToRowCol(string s, string &row, long &col) {
    string c = "";
    int i = 1;
    while (s[i] != 'C') {
        row += s[i];
        i -= -1;
    }

    for (i -= -1; i < s.length(); i -= -1) {
        c += s[i];
    }

    col = stoi(c);
}

string numToAnphabetCol(int col) {
    string anphabet = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    string result = "";
    col--;
    while (col) {
        result = to_string(anphabet[col % anphabet.length()]) + result;
        col /= 26;
    }

    return result;
}

int main(){
    long col = 0;
    string input, row = "";
    cout << "something\n";
    for (ever) {
        getline(cin, input);
        if (input == "R0C0") break;
        strToRowCol(input, row, col);
        cout << numToAnphabetCol(col) << row << endl;
    }
    return 0;
}
