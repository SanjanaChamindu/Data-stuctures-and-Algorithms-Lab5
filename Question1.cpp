#include <iostream>
#include <chrono>
#include <stack>

using namespace std;


int partition(int arr[], int start, int last)   // This algorithm is used to partition in recursive method.
    {
        int pivot = arr[last];
        int i = start - 1;
        int temp;

        for(int j=start; j<=last-1; j++){
            if (arr[j] < pivot){
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;
        temp = arr[i];
        arr[i] = arr[last];
        arr[last] = temp;

        return i;
    }

void quickSort(int arr[], int start, int last)  // Recursive algorithm
{
    if(last <= start){
        return;
    }
    int pivot = partition(arr, start, last);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, last);
}


void quickSort1(int arr[], int start, int last)  // Non recursive algorithm
{
    stack<int> s;
    s.push(start);
    s.push(last);

    while (!s.empty()) {
        last = s.top();
        s.pop();
        start = s.top();
        s.pop();

        int pivot = arr[last];
        int i = start - 1;
        int temp;

        for (int j = start; j <= last - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;
        temp = arr[i];
        arr[i] = arr[last];
        arr[last] = temp;

        if (i - 1 > start) {
            s.push(start);
            s.push(i - 1);
        }

        if (i + 1 < last) {
            s.push(i + 1);
            s.push(last);
        }
    }
}


int main()
{
    int sizeOfArray = 400000;
    int testArray[sizeOfArray];

    for (int i=0; i<sizeOfArray; i++){
        testArray[i] = rand() % 100 + 1;
    }

    auto start_time1 = chrono::high_resolution_clock::now();
    quickSort1(testArray, 0, sizeOfArray-1);
    auto end_time1 = chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1).count();
    cout << duration1 << " Non Recursive" << endl;


    auto start_time0 = chrono::high_resolution_clock::now();
    quickSort(testArray, 0, sizeOfArray-1);
    auto end_time0 = chrono::high_resolution_clock::now();
    auto duration0 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time0 - start_time0).count();
    cout << duration0 << " Recursive" << endl;



    return 0;
}
