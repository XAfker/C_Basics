#include <iostream>
using std::cout;
using std::endl;
unsigned short koduj(int plec, int stan_cyw,
                     int grupa_wiek, int edu,
                     int zam, int region,
                     int odp){
    return (plec << 15)
           | (stan_cyw << 13)
           | (grupa_wiek << 11)
           | (edu << 9)
           | (zam << 7)
           | (region << 3)
           | (odp);
};

void info(unsigned short kod){
    cout << (( kod & ( 1 << 15 )) >> 15) << endl;
    cout << (( kod & ( 3 << 13 )) >> 13) << endl;
    cout << (( kod & ( 3 << 11 )) >> 11) << endl;
    cout << (( kod & ( 3 << 9 )) >> 9) << endl;
    cout << (( kod & ( 3 << 7 )) >> 7) << endl;
    cout << (( kod & ( 15 << 3 )) >> 3) << endl;
    cout << ( kod & (7)) << endl;
};


int main() {
    unsigned short spr = koduj(0,3,2,3,0,12,6);
    info(spr);
}
