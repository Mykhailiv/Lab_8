#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // визначаємо розмірність матриці
    const int rows = 3;
    const int cols = 4;
    // ініціалізуємо матрицю
    int matrix[rows][cols] = { {-3, 4, -6, 0}, {-2, 0, -7, -3}, {-2, -6, -8, 5} };

    // знаходимо позиції першого та другого додатніх елементів матриці
    int* first_pos = find_if(&matrix[0][0], &matrix[0][0] + rows * cols, [](int x) { return x > 0; });
    int* second_pos = find_if(first_pos + 1, &matrix[0][0] + rows * cols, [](int x) { return x > 0; });

    // обчислюємо суму елементів між першим та другим додатнім елементами
    int sum = accumulate(first_pos + 1, second_pos, 0);
    // виводимо суму на екран
    cout << "Sum: " << sum << endl;

    return 0;
}