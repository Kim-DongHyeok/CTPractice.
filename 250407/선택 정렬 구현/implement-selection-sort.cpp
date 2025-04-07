#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){ 
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    // Please write your code here.

    return 0;
}
