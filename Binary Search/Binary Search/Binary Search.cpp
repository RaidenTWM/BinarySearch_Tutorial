#include <iostream>

int swaps = 0;
int comparisons = 0;


void BubbleSort(int array[], int n);
void PrintArray(int array[], int n);
void Swap(int& a, int& b);
bool Bigger(int& a, int& b);
void OptimisedBubbleSort(int array[], int n);
void CocktailShakerSort(int array[], int n);

int main()
{
    //Define our data
    const int array_size = 25;
    int array_to_be_sorted[array_size] = {
        14,65,63,1,54,
        89,84,9,98,57,
        71,18,21,84,69,
        28,11,83,13,42,
        64,58,78,82,13
    };
    CocktailShakerSort(array_to_be_sorted, array_size);

    while (true)
    {
        std::cout << std::endl << std::endl << "Enter a number to find in the sequence: -1 to end" << std::endl;
    }



    system("pause");
    return 0;
}

void BubbleSort(int array[], int n)
{
    //Bail for single element or invalid indices
    if (n < 2) { return; }
    //Track if list is sorted
    bool sorted = false; // Set to false to ensure the while loop starts up
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < n - 1; ++i)
        {
            if (Bigger(array[i], array[i + 1]))
            {
                Swap(array[i], array[i + 1]);
                sorted = false;
            }
        }
    }
}
void PrintArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << ",\t";
        if (i % 10 == 9) { std::cout << std::endl; }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    swaps++;
}
bool Bigger(int& a, int& b)
{
    comparisons++;
    if (a > b) { return true; }
    return false;
}
void OptimisedBubbleSort(int array[], int n)
{
    //Bail for single element or invalid indices
    if (n < 2) { return; }
    //Track if list is sorted
    bool sorted = false; // Set to false to ensure the while loop starts up
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < n - 1; ++i)
        {
            if (Bigger(array[i], array[i + 1]))
            {
                Swap(array[i], array[i + 1]);
                sorted = false;
            }
        }
        n -= 1;
    }
}
void CocktailShakerSort(int array[], int n)
{
    //Bail for single element or invalid indices
    if (n < 2) { return; }
    //Track if list is sorted
    bool sorted = false; // Set to false to ensure the while loop starts up
    int count = 1; int count2 = 0;
    while (!sorted)
    {
        sorted = true;
        for (int i = count2; i < n - count; i++)
        {
            if (Bigger(array[i], array[i + 1]))
            {
                Swap(array[i], array[i + 1]);
                sorted = false;
            }
        }
        for (int i = n - count - 1; i > count2; i--)
        {
            if (Bigger(array[i - 1], array[i]))
            {
                Swap(array[i - 1], array[i]);
                sorted = false;
            }
        }
        count++;
        count2++;
    }
}