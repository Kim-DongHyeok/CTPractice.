#include <iostream>

using namespace std;

int main(){
    int arr[10000]={0};

    int x=666, y=0;
    int count=0, i=0, num;

    while(i<10000){
        y=x;
        while(y!=0){
            if(count==3){
                break;
            }
            else if(y%10==6){
                count++;
                y=y/10;
            }
            else if(y%10!=6){
                count=0;
                y=y/10;
            }
        }

        if(count==3) {
            arr[i]=x;
            i++;
        }
        
        count=0;
        x++;
    }

    cin >> num;
    cout << arr[num-1];
}
