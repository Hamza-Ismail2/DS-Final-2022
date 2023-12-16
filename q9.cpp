#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

class Project {
public:
    vector<string> array[SIZE];

    Project() {

        for (int i = 0; i < SIZE; i++) {
            vector<string> temp;

            array[i] = temp;
        }
    }

    int hashFunction(string str) {

        int sum = 0;

        for (int i = 0; i < str.size(); i++) {
            sum += str[i];
        }

        return sum % SIZE;
    }

    void add_record(string t) {

        int index = hashFunction(t);
      
        array[index].push_back(t);
    }

    void Word_Search() {
        string s;
        cout << "Enter the String you would like to Search: ";
        getline(cin, s);

        int index = hashFunction(s);
        
        for (int i = 0; i < array[index].size(); i++) {
            if(array[index][i] == s) {
                cout << "Found";
                return;
            }
        }
        cout << "Not Found";
    }

    void Print_Dictionary() {

        for (int i = 0; i < SIZE; i++) {
            if(array[i].size() != 0) { 
                for (int j = 0; j < array[i].size(); j++) {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
            
        }
    }
};

int main() {


    // put size to 10 to achieve the questions output.
    Project p;
    p.add_record("Tom Katz");
    p.add_record("Sarah Jones");
    p.add_record("John Smith");
    p.add_record("Tony Balognie");

    p.Print_Dictionary();

    p.Word_Search();

    return 0;
}