#include <iostream>

int swaps = 0;
int comparisons = 0;


void BubbleSort(int array[], int n);
void PrintArray(int a[], int n, int start, int end, int pivot);
void Swap(int& a, int& b);
bool Bigger(int& a, int& b);
void OptimisedBubbleSort(int array[], int n);
void CocktailShakerSort(int array[], int n);

int BinarySearch(int array[], int start, int end, int key);
int InterpolatedBinarySearch(int array[], int start, int end, int key);

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
        std::cout << "Enter a number to find in the sequence: -1 to end" << std::endl;
        int search_key = -1;
        std::cin >> search_key;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (search_key == -1) { break; }
        int r = BinarySearch(array_to_be_sorted, 0, array_size - 1,search_key);
        if (r == -1) { std::cout << "Couldn't find " <<search_key << " in the list" << std::endl << std::endl; }
        else { std::cout << "Found " <<search_key << " at position " << r << std::endl << std::endl; }
        r = InterpolatedBinarySearch(array_to_be_sorted, 0, array_size - 1, search_key);
        if (r == -1) { std::cout << "Couldn't find " << search_key << " in the list" << std::endl << std::endl; }
        else { std::cout << "Found " << search_key << " at position " << r << std::endl << std::endl; }
    }



    system("pause");
    return 0;
}


int BinarySearch(int array[], int start, int end, int key)
{
    while (start <= end)
    {
        int pivot = (start + end) / 2;
        PrintArray(array, key, start, end, pivot);
        if (array[pivot] == key) { return pivot; }
        if (key < array[pivot]) { end = pivot- 1; }
        else { start = pivot + 1; }
    }
    return -1;
}
int InterpolatedBinarySearch(int array[], int start, int end, int key)
{
    while (start <= end && key >= array[start] && key <= array[end])
    {
        int pivot = start + (end - start) * ((key - array[start]) / (array[end] - array[start]));

        PrintArray(array, key, start, end, pivot);
        if (array[pivot] == key) { return pivot; }
        if (key > array[pivot]) { start = pivot + 1; }
        else { end = pivot - 1; }
    }
    return -1;
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
void PrintArray(int a[], int n, int start, int end, int pivot)
{
    for (int i = 0; i != n; ++i)
    {
        if (i == start)
            std::cout << "[";
        else if (i == pivot)
            std::cout << "<";

        if (i<start || i>end)
            std::cout << (a[i] < 10 ? "." : "..");
        else
            std::cout << a[i];

        if (i + 1 != pivot)
            std::cout << (i == end ? "]" : (i + 1 != start ? (i != pivot ? " " : ">") : ""));
    }
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