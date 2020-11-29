#include <iostream>
#include <thread>
#include <algorithm>
#include <list>

using namespace std;

int l1, l2, l3, l4;
int *a1, *a2, *a3, *a4;

void printResult(list<int*> result) {
    for (list<int*>::iterator i = result.begin(); i != result.end(); ++i) {
        cout << (*i)[0] << " " << (*i)[1] << " " << (*i)[2] << " " << (*i)[3] << endl;
        delete[](*i);
    }
}

void fillSet(int set[], int length) {
    for (int i = 0; i < length; i++) {
        set[i] = i;
    }
}

void task(int from, int to, list<int*>& res) {
    for (int i1 = from; i1 < to; i1++) {
        for (int i2 = 0; i2 < l2; i2++) {
            for (int i3 = 0; i3 < l3; i3++) {
                for (int i4 = 0; i4 < l4; i4++) {
                    int* elems = new int[4];
                    elems[0] = a1[i1];
                    elems[1] = a2[i2];
                    elems[2] = a3[i3];
                    elems[3] = a4[i4];
                    res.push_back(elems);
                }
            }
        }
    }
}

int main()
{
    int N;
    cout << "Enter the number of threads: ";
    cin >> N;
    cout << endl;

    
    cout << "Enter the length of the first set: ";
    cin >> l1;
    cout << "Enter the length of the second set: ";
    cin >> l2;
    cout << "Enter the length of the third set: ";
    cin >> l3;
    cout << "Enter the length of the fourth set: ";
    cin >> l4;

    if (N <= 0 || l1 <= 0 || l2 <= 0 || l3 <= 0 || l4 <= 0) {
        cout << "Invalid input!" << endl;
        return -1;
    }

    a1 = new int[l1]; fillSet(a1, l1);
    a2 = new int[l2]; fillSet(a2, l2);
    a3 = new int[l3]; fillSet(a3, l3);
    a4 = new int[l4]; fillSet(a4, l4);

    a1[0] = 0;

    N = min(N, l1);
    int step = l1 / N;

    list<int*>* results = new list<int*>[N];
    thread* threads = new thread[N];

    int from = 0, to;
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            to = l1;
        }
        else {
            to = from + step;
        }
        
        results[i] = list<int*>();
        threads[i] = thread(task, from, to, ref(results[i]));
        from = to;
    }

    for (int i = 0; i < N; i++) {
        threads[i].join();
    }
    delete[] threads;

    list<int*> result;
    for (int i = 0; i < N; i++) {
        list<int*> l = results[i];
        result.insert(result.end(), l.begin(), l.end());
    }

    printResult(result);

    delete[] a1;
    delete[] a2;
    delete[] a3;
    delete[] a4;
    delete[] results;
}


