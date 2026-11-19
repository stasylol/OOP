#include <iostream>
#include <vector>
#include <algorithm>

int sumFirst2 = 0;

void sumElements(int x)
{
    sumFirst2 += x;
}

int main()
{
    std::vector<int> first = {1, 2, 3, 4};

    std::for_each(first.begin(), first.end(), sumElements);

    std::cout << sumFirst2;

    return 0;
}