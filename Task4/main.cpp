#include <iostream>
int gcdRec(int a, int b)
{
    return (a%b == 0 ? b : gcdRec(b, (a%b)));
};
int sumDigits(int n)
{
    return (n == 0 ? 0 : n%10 + sumDigits(n/10));
};
int numDigits(int n)
{
    return (n == 0 ? 0 : 1 + numDigits(n/10));
};
void printOddEven(int n)
{
    if(n>2)
    printOddEven(n-2);
      std::cout << n << " ";
};
void hailstone(int n) {
    std::cout << n << " ";
    if (n == 1)  return;
    if (n%2 == 0) return hailstone(n / 2);
    hailstone(3 * n + 1);

    //(n%2 == 0 ? hailstone(n / 2) : hailstone(3 * n + 1));
};
int main() {
    std::cout << "gcdRec(12, 42) = " <<
              gcdRec(12, 42) << std::endl
              << "gcdRec(12, 25) = " <<
              gcdRec(12, 25) << std::endl;
    std::cout << "sumDigits(123) = " <<
              sumDigits(123) << std::endl
              << "sumDigits(971) = " <<
              sumDigits(971) << std::endl;
    std::cout << "numDigits(12345) = " <<
              numDigits(12345) << std::endl
              << "numDigits(971) = " <<
              numDigits(971) << std::endl;
    std::cout << "printOddEven(15): ";
    printOddEven(15);
    std::cout << std::endl;
    std::cout << "printOddEven(14): ";
    printOddEven(14);
    std::cout << std::endl;
    std::cout << "hailstone(13): ";
    hailstone(13);
    std::cout << std::endl;
}
