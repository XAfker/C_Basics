#include <iostream>
enum Banks {PKO, BGZ, BRE, BPH};
struct Account {
    Banks bank;
    int balance;
};
struct Person {
    char name[20];
    Account account;
};
struct Couple {
    Person he;
    Person she;
};
const Couple* bestClient(const Couple* cpls,
                         int size, Banks bank) {
    const Couple* bestCouple = nullptr;
    int maxSavings = INT_MIN;
    for (int i = 0; i < size; i++) {
        const Couple* currCouple = &cpls[i];
        if (currCouple->he.account.bank == bank || currCouple->she.account.bank == bank) {
            int currSavings = currCouple->he.account.balance + currCouple->she.account.balance;
            if (currSavings > maxSavings) {
                maxSavings = currSavings;
                bestCouple = currCouple;
            }
        }
    }
    return bestCouple;
}
int main() {
    using std::cout; using std::endl;
    Account accounts[8] = {
            {Banks::PKO, 1200},
            {Banks::BGZ, 1400},
            {Banks::BGZ, 1400},
            {Banks::BRE, -1500},
            {Banks::PKO, 1600},
            {Banks::BPH, 1500},
            {Banks::BPH, 200},
            {Banks::BRE, -201}
    };

    Person people[8] = {
            {"Johny", accounts[0]},
            {"Mary", accounts[1]},
            {"Peter", accounts[2]},
            {"Suzy", accounts[3]},
            {"Kevin", accounts[4]},
            {"Katy", accounts[5]},
            {"Kenny", accounts[6]},
            {"Lucy", accounts[7]}
    };
    Couple cpls[4] = {
            {people[0], people[1]},
            {people[2], people[3]},
            {people[4], people[5]},
            {people[6], people[7]}
    };
    const Couple* p = bestClient(cpls, 4, BRE);
    if (p)
        cout << p->he.name << " and " << p->she.name
             << ": " << p->he.account.balance +
                        p->she.account.balance << endl;
    else
        cout << "No such couple...\n";
}
