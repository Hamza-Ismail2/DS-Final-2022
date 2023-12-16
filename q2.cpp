#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    float *cgpa;
    int *roll_num;
    int ind;

    vector<pair<int, float>> v;

    Student() {
        cgpa = new float[100];
        roll_num = new int[100];
        ind = 0;
        for (int i = 0; i < 100; i++) {
            cgpa[i] = 0.0;
            roll_num[i] = 0;
        }
    }

    ~Student() {
        delete[] cgpa;
        delete[] roll_num;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return (2 * i) + 1;
    }

    int rightChild(int i) {
        return (2 * i) + 2;
    }

    void insert(int roll, float gpa) {
        roll_num[ind] = roll;
        cgpa[ind] = gpa;

        for (int i = ind; i > 0 && cgpa[parent(i)] > cgpa[i]; i = parent(i)) {
            swap(cgpa[parent(i)], cgpa[i]);
            swap(roll_num[parent(i)], roll_num[i]);
        }

        ind++;
    }

    float getMinCgpa() {
        return cgpa[0];
    }

    void deleteMin() {
        swap(cgpa[ind - 1], cgpa[0]);
        swap(roll_num[ind - 1], roll_num[0]);
        ind--;

        for (int i = 0; i < ind; i++) {
            int smallest = i;
            int left = leftChild(i);
            int right = rightChild(i);

            if (left < ind && cgpa[left] < cgpa[smallest]) {
                smallest = left;
            }

            if (right < ind && cgpa[right] < cgpa[smallest]) {
                smallest = right;
            }

            if (smallest != i) {
                swap(cgpa[i], cgpa[smallest]);
                swap(roll_num[i], roll_num[smallest]);
            }
        }
    }

    void display() {
        for (int i = 0; i < ind; i++) {
            cout << "Roll Number: " << roll_num[i] << " CGPA: " << cgpa[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    Student s;

    s.insert(1234, 2.5);
    s.insert(5678, 3.0);
    s.insert(9123, 2.3);
    cout << s.getMinCgpa() << endl;
    s.display();
    s.deleteMin();

    cout << s.getMinCgpa() << endl;
    return 0;
}
