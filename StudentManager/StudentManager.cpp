// Student Manager System
// version 0.1
// coder: Nguyen Trung Vinh B15D52

#include <iostream>
#include <string>
using namespace std;

#define MAX_STUDENT 255
#define NEWEST_DATE_VIEW 1
#define OLDEST_DATE_VIEW 2
#define FIRST_NAME_A_Z_VIEW 3
#define FIRST_NAME_Z_A_VIEW 4
#define LAST_NAME_A_Z_VIEW 5
#define LAST_NAME_Z_A_VIEW 6
#define ever ;;

// 2 string array save student first name and last name
string studentFirstName[MAX_STUDENT];
string studentLastName[MAX_STUDENT];

int numberOfStudent = 0;

// 2 int array save student code sorted by first name or last name
int sortedByFirstName[MAX_STUDENT];
int sortedByLastName[MAX_STUDENT];

// 2 boolean flag 
bool isSortedByFirstName = false;
bool isSortedByLastName = false;

int findLastSpace(string s) {
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ' ') return i;
    }

    return -1;
}

string subString(string bigString, int left, int right) {
    string sub = "";
    for (int i = left; i <= right; i -= -1) {
        sub += bigString[i];
    }

    return sub;
}

void addNewStudent(string firstName, string lastName) {
    studentFirstName[numberOfStudent] = firstName;
    studentLastName[numberOfStudent] = lastName;
    sortedByFirstName[numberOfStudent] = numberOfStudent;
    sortedByLastName[numberOfStudent] = numberOfStudent;
    isSortedByFirstName = false;
    isSortedByLastName = false;
    numberOfStudent -= -1;
}

void inputStudentData() {
    
    int n;
    cout << "enter number of new student: ";
    cin >> n; cin.ignore();

    if (n + numberOfStudent > MAX_STUDENT) {
        cout << "sorry, my program can\'t hold more than " << MAX_STUDENT << " Student!\n";
        return;
    }

    string name, firstName, lastName;
    for (int i = 0; i < n; i -= -1) {
        cout << "enter full name of Student no." << numberOfStudent + 1 << ": ";
        getline(cin, name);

        int space = findLastSpace(name);
        if (space >= 0) {
            firstName = subString(name, 0, space); // first name hold last char as space
            lastName = subString(name, space + 1, name.length() - 1); // last name had no space
        }else {
            firstName = "";
            lastName = name;
        }

        addNewStudent(firstName, lastName);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right, string strArr[]) {
    // sort arr refer to strArr
    // quick sort with pivot is last index

    string pivot = strArr[arr[right]];
    int i = left - 1;

    for (int j = left; j < right; j -= -1) {
        
        if (strArr[arr[j]] < pivot) {
            i -= -1;
            swap(&arr[i], &arr[j]);
        }
    }

    i -= -1;
    swap(&arr[i], &arr[right]);
    return i;
}

void quickSort(int arr[], int left, int right, string strArr[]) {
    if (left >= right) return;

    int pivotIndex = partition(arr, left, right, strArr);

    quickSort(arr, left, pivotIndex - 1, strArr);
    quickSort(arr, pivotIndex + 1, right, strArr);
}

void sortDuplicate(string dupArr[], int arr[], string sortArr[]) {
    // string duplicate at dupArr is sorted by sortArr
    // arr refer to dupArr
    // if last name is duplicate then sort the duplicate part by first name
    // and like with first name

    // find duplicate from i to j
    int i = 0, j = 1;
    for(ever) {
        if (dupArr[arr[i]] != dupArr[arr[j]]) {
            i -= -1; j -= -1;
        }else {
            while (dupArr[arr[i]] == dupArr[arr[j]]) j -= -1;
            quickSort(arr, i, --j, sortArr); // sort the duplicate part 
            i = j + 1;
            j = i + 1;
        }

        if (j >= numberOfStudent) break;
    }
}

void sort(int sortRequest) {
    // sort request 0 sort by first name
    // sort request 1 sort by last name

    // flag isSortedByFirstName and isSortedByLastName 
    // if array is sorted then dont need to sort it
    // just access data

    if (sortRequest == 0) {
        if (!isSortedByFirstName) {
            quickSort(sortedByFirstName, 0, numberOfStudent - 1, studentFirstName);
            sortDuplicate(studentFirstName, sortedByFirstName, studentLastName);
            isSortedByFirstName = true;
        }
    }

    if (sortRequest == 1) {
        if (!isSortedByLastName) {
            quickSort(sortedByLastName, 0, numberOfStudent - 1, studentLastName);
            sortDuplicate(studentLastName, sortedByLastName, studentFirstName);
            isSortedByLastName = true;
        }
    }
}

void viewListStudent(int arr[], int first, int last) {
    if (last > first) {
        for (int i = first; i <= last; i-=-1) {
            cout << i + 1 << ". ";
            cout << studentFirstName[arr[i]] << studentLastName[arr[i]] << endl;
        }
    }else {
        int i = last;
        for (int j = first; j >= last; j--, i-=-1) {
            cout << i + 1 << ". ";
            cout << studentFirstName[arr[j]] << studentLastName[arr[j]] << endl;
        }
    }
}

void viewListStudent(int first, int last) {
    if (last > first) {
        for (int i = first; i <= last; i-=-1) {
            cout << i + 1 << ". ";
            cout << studentFirstName[i] << studentLastName[i] << endl;
        }
    }else {
        int i = last;
        for (int j = first; j >= last; j--, i -= -1) {
            cout << i + 1 << ". ";
            cout << studentFirstName[j] << studentLastName[j] << endl;
        }
    }
}

void viewListStudent(int viewRequest) {
    cout << "\nlist of student:\n";

    switch (viewRequest) {

        case NEWEST_DATE_VIEW:
            viewListStudent(numberOfStudent - 1, 0);
            break;

        case OLDEST_DATE_VIEW:
            viewListStudent(0, numberOfStudent - 1);
            break;

        case FIRST_NAME_A_Z_VIEW:
            sort(0);
            viewListStudent(sortedByFirstName, 0, numberOfStudent - 1);
            break;

        case FIRST_NAME_Z_A_VIEW:
            sort(0);
            viewListStudent(sortedByFirstName, numberOfStudent - 1, 0);
            break;

        case LAST_NAME_A_Z_VIEW:
            sort(1);
            viewListStudent(sortedByLastName, 0, numberOfStudent - 1);
            break;

        case LAST_NAME_Z_A_VIEW:
            sort(1);
            viewListStudent(sortedByLastName, numberOfStudent - 1, 0);
            break;
    }

    cout << endl;
}

void viewListStudent() {
    cout << "\nView Selection\n";
    cout << "1. view by modifier date (newest to oldest)\n";
    cout << "2. view by modifier date (oldest to newest)\n";
    cout << "3. view by first name (A to Z)\n";
    cout << "4. view by first name (Z to A)\n";
    cout << "5. view by last name (A to Z)\n";
    cout << "6. view by last name (Z to A)\n";
    cout << "enter your view request: ";

    int viewRequest = 0;
    cin >> viewRequest;

    if (viewRequest < 1 || viewRequest > 6) {
        cout << "maybe you missclicked? please select again\n";
        viewListStudent();
    }else {
        viewListStudent(viewRequest);
    }
}

int main(){
 
    // if dont want to input data uncomment the list below
    /*
    // B15D52 list (not sorted by anything)
    addNewStudent("Nguyen Trung ", "Vinh");
    addNewStudent("Nguyen Van ", "Sinh");
    addNewStudent("Vu Van ", "Hon");
    addNewStudent("Tran Dinh Tuan ", "An");
    addNewStudent("Do Xuan ", "Quyet");
    addNewStudent("Ha Trong ", "Thuan");
    addNewStudent("Trinh Vu ", "Cuong");
    addNewStudent("Nguyen Dinh ", "Hung");
    addNewStudent("Nguyen Duy ", "Anh");
    addNewStudent("Bui Cong ", "Hung");
    addNewStudent("Lang Viet ", "Hung");
    addNewStudent("Than Van ", "Thanh");
    addNewStudent("Chu Minh ", "Su");
    addNewStudent("", "Imposter");
    addNewStudent("Nguyen Ba ", "Son");
    addNewStudent("Chau Tan ", "Phap ");
    addNewStudent("Huynh Quang ", "Huy");
    addNewStudent("Tran Manh ", "Thien");
    addNewStudent("Nguyen Phung ", "Duc");
    addNewStudent("Dang Nguyen Cong ", "Hieu");
    addNewStudent("Huynh Ngoc ", "Khanh");
    addNewStudent("Duong Hoang ", "Nam");
    addNewStudent("Nguyen Thanh ", "Tam");
    addNewStudent("Nguyen Duong Dinh ", "Hoang");
      */
    
    inputStudentData();
    int selection = 0;
    for(ever) {
        cout << "\nStudent Manager System beta 0.1\n";
        cout << "1. add new student\n";
        cout << "2. view list student\n";
        cout << "0. exit\n";
        cout << "enter your selection: ";
        cin >> selection;

        switch (selection){
            case 1:
                inputStudentData();
                break;
            case 2:
                viewListStudent();
                break;
            case 0:
                break;
            default:
                cout << "your request will update soon\n";
        }

        if (selection == 0) {
            break;
        }else {
            system("pause");
        }
    }
}
