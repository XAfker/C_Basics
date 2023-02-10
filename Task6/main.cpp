#include <iostream>

bool checkpass(const char* pass) {
    bool flag = true;
    if(pass== nullptr)
        return false;

    int charCount = 0,
            differentChar = 0,
            numCount = 0,
            bigChar = 0,
            smallChar = 0,
            notCharNum = 0;

    int j = 0;
    while (pass[j]!='\0'){
        charCount++;
        for (int i = ' '; i < '~'; ++i) {
            if ((i >= '0' && i <= '9') && (pass[j] == i))
                numCount++;
            if ((i >= 'A' && i <= 'Z') && (pass[j] == i))
                bigChar++;
            if ((i >= 'a' && i <= 'z') && (pass[j] == i))
                smallChar++;
            if(((i >= ' ' && i <= '/') || (i >= ':' && i <= '@') ||
            (i >= '[' && i <= '`') || (i >= '{' && i <= '~')) && (pass[j] == i))
                notCharNum++;
        }
        j++;
    }

    for (int i = ' '; i < '~'; ++i) {
        int asciiCount = 0;
        j = 0;
        while (pass[j]!='\0'){
            if (pass[j] == i)
                asciiCount++;
            j++;
        }
        if(asciiCount!=0)
            differentChar++;
    }


    if (charCount <= 7) {
        std::cout << "Too short" << std::endl;
        flag = false;
    }
    if (differentChar <= 5){
        std::cout << "Too few different characters" << std::endl;
        flag = false;
    }
    if (numCount == 0){
        std::cout << "No digit" << std::endl;
        flag = false;
    }
    if (bigChar == 0){
        std::cout << "No uppercase letter" << std::endl;
        flag = false;
    }
    if (smallChar == 0){
        std::cout << "No lowercase letter" << std::endl;
        flag = false;
    }
    if (notCharNum == 0){
        std::cout << "No non-alphanumeric character" << std::endl;
        flag = false;
    }

    return flag;
}

int main() {
    using std::cout; using std::endl;
    const char* passes[] =
            {
                    "AbcDe93", "A1b:A1b>", "Ab:Acb<",
                    "abc123><", "Zorro@123", nullptr
            };
    for (int i = 0; passes[i] != nullptr; ++i) {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}
