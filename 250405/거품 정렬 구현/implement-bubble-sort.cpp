#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    bool sorted = false;
    int tmp=0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while(sorted==false){
        sorted=true;
        for(int i=0; i<n-1; i++){
            if(arr[i]> arr[i+1]){
                tmp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=tmp;
                sorted=false;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
