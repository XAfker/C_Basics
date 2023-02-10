#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    int res = a;
    int times = 1;
    int input = 0;
    int timesSec = 0;
    while (a) {
     cin >> a;
     if (res == a){
         times++;
     } else if (input == a){
         timesSec++;
     } else {
         input = a;
         timesSec = 1;
     }
     if(timesSec > times){
         res = input;
         times = timesSec;
         timesSec = 0;
     }
    }
    cout << "Longest sequence: " << times << " times " << res;
}