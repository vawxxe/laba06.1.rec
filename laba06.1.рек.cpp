
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Перевірка критерію
bool ShouldReplace(int value, int index)
{
    return value % 2 == 0 || index % 8 != 0;
}

// 1. Створення масиву рекурсивно
void Create(int c[], int n, int i = 0)
{
    if (i >= n)
        return;

    c[i] = 5 + rand() % 86;
    Create(c, n, i + 1);
}

// 2. Виведення масиву рекурсивно
void Print(const int c[], int n, int i = 0)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(4) << c[i];
    Print(c, n, i + 1);
}

// 3. Обчислення кількості рекурсивно
int Count(const int c[], int n, int i = 0)
{
    if (i >= n)
        return 0;

    if (ShouldReplace(c[i], i))
        return 1 + Count(c, n, i + 1);

    return Count(c, n, i + 1);
}

// 4. Обчислення суми рекурсивно
int Sum(const int c[], int n, int i = 0)
{
    if (i >= n)
        return 0;

    if (ShouldReplace(c[i], i))
        return c[i] + Sum(c, n, i + 1);

    return Sum(c, n, i + 1);
}

// 5. Заміна елементів нулями рекурсивно
void Replace(int c[], int n, int i = 0)
{
    if (i >= n)
        return;

    if (ShouldReplace(c[i], i))
        c[i] = 0;

    Replace(c, n, i + 1);
}

int main()
{
    const int n = 25;
    int c[n];

    srand(static_cast<unsigned int>(time(nullptr)));

    Create(c, n);

    cout << "Original array:" << endl;
    Print(c, n);

    int quantity = Count(c, n);
    int sum = Sum(c, n);

    Replace(c, n);

    cout << "Quantity = " << quantity << endl;
    cout << "Sum = " << sum << endl;

    cout << "Modified array:" << endl;
    Print(c, n);

    return 0;
}
