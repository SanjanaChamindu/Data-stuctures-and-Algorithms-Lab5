#include <iostream>
#include <iomanip>

using namespace std;
void FindMedian(int arr[], int length);

int main()
{
    int arr[5] = {7, 3, 5, 2, 9};
    FindMedian(arr, 5);
    return 0;
}


void FindMedian(int arr[], int length)
{
    int key, j;
    double median;

    for (int i=0; i< length; i++){
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        if (i%2 == 0){
            median = arr[i/2];
        }
        else{
            median = (arr[i/2] + arr[i/2 + 1])/2;
        }
        double scaled = static_cast<double>(median);
        cout << fixed << setprecision(1) << scaled << endl;
    }
}
