#include <iostream>
//#define ANG
#define POL

#if defined(POL) && defined(ANG)
    #error Please define only one country
#elif !(defined(POL) || defined(ANG))
    #error Please define a country
#endif // defined

#ifdef POL
    #define message "wprowadz liczbe naturalna (0 aby zakonczyc): "
    #define result "Maksymalna suma numerow to: "
    #define fornum " dla "
#elif defined(ANG)
    #define message "enter a natural number (0 if done):"
    #define result "Max sum of digits was: "
    #define fornum " for "
#endif // POL


using namespace std;

int main(){
    int a, sumFinal, seriesFinal;
    sumFinal = 0;
    cout << message;
    cin >> a;
    seriesFinal = a;

    while (a){
        int sumTmp=0, seriesTmp;
        seriesTmp = a;
        while(seriesTmp){
         sumTmp += seriesTmp%10;
         seriesTmp/=10;
        }
        if(sumTmp > sumFinal){
            sumFinal = sumTmp;
            seriesFinal = a;
        }
        cout << message;
        cin >> a;
    }
    cout << result << sumFinal << fornum << seriesFinal;
}
