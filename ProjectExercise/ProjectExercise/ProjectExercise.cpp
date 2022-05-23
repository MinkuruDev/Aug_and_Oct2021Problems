#include <iostream>
using manespace std;

void readNumber() {
	int n = 0;
	cout << "input number: ";
	cin >> n;
	if (n >= 1 && n <= 9) {
		cout << n << endl;
	}else {
		cout << "Error!\n";
	}
}

void toOtherCase() {
	char ch = 'a';
	cout << "input character: ";
	cin >> ch;
	string lowCase = "abcdefghijklmnopqrstuvwxyz";
	string upCase  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (ch >= 'a' && ch <= 'z') {
		int i = 0;
		while (ch != lowCase[i]) i++;
		cout << upCase[i] << endl;
	}
	else if (ch >= 'A' && ch <= 'Z') {
		int i = 0;
		while (ch != upCase[i]) i++;
		cout << lowCase[i] << endl;
	}else cout << "please enter a valid character!\n";
}

void solveEqualtion(int a, int b, int c) {
    if (a == 0) {
        if (b == 0) {
            c == 0 ? cout << "x = R" : cout << "x = null";
        }
        else {
            cout << "x = " << (float)-(c / b);
        }
        cout << endl;
        return;
    }

    // a != 0
    float delta = (b * b) - (4 * a * c);
    if (delta < 0) {
        cout << "x = null";
    }
    else if (delta == 0) {
        cout << "x = " << (float)-b / (2 * a);
    }
    else {
        cout << "x1 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b + sqrt(delta)) / (2 * a);
    }
    cout << endl;
}

void lv1Equaltion() {
	cout << "input a, b: ";
	int a, b;
	cin >> a >> b;
	solveEqualtion(0, a, b);
}

void lv2Equaltion() {
	cout << "input a, b, c: ";
	int a, b, c;
	cin >> a >> b >> c;
	solveEqualtion(a, b, c);
}

int main() {
	int selection = 0;
	do {
		cout << "\n1. read a number from 1 to 9\n";
		cout << "2. character to other case\n";
		cout << "3. slove lv1 elqualtion ax + b = 0\n";
		cout << "4. solve lv2 elqualtion ax2 + bx +c =0\n";
		cout << "0. exit\n"
		cin >> selection;

		switch (selection) {
			case 0: break;
			case 1:
				readNumber();
				break;
			case 2:
				toOtherCase();
				break;
			case 3:
				lv1Equaltion();
				break;
			case 4:
				lv2Equaltion();
				break;
			default:
				cout << "please select a valid number!\n";
		}

	} while (selection);
}