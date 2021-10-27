#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <Windows.h> 
#include <vector>
#include <string>
#include <fstream>
using namespace std;
#define MAX_LEN 100
long length = 10000;
const long max_length = 1000000;
int list[max_length];
int n; // кількість елементів масиву 
void print(int* a);
int control();
void exch(int& a, int& b);
void sort_bubble(int* array);
void printArray(int array[], int size);
void insertionSort(int array[], int size);
void selectionSort(int array[], int size);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void quickSwap(int* a, int* b);
void printQuickSortArray(int array[], int size);
void merge(int a[], int b[], int low, int mid, int high);
void mergeSort(int a[], int len);
void printMergekSortArray(int array[], int size);
void selectionSortStr(char arr[][MAX_LEN], int n);
void quickSortMain(char items[][10], int count);
void quickSortStr(char items[][10], int left, int right);
void read();
void write();
void bubbleSort();
void insertionSort2();
long partition2(long left, long right);
void quickSort2(long left, long right);
void selectionSort2(int size);
void swap2(int* a, int* b);
void merge2(int a[], int b[], int low, int mid, int high);
void mergeSort2(int a[], int b[], int low, int high);
void mergeSort2(int len);
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /////////////// Створення масиву /////////////// 
    n = control();
    int* a = new int[n];
    int* data = new int[n];
    int* data1 = new int[n];
    int* data2 = new int[n];
    int* data3 = new int[n];
    int* testData = new int[n];
    int it = 10;

    //1.1
    //ofstream outf("SortingFile.txt");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 2001 - 1000;
        data[i] = a[i];
        data1[i] = a[i];
        data2[i] = a[i];
        data3[i] = a[i];
    }


    ofstream file;
    file.open("test.txt");
    for (length = 10000; length <= max_length; length += 10000) {

        /*cout << "\nLength:\t" << length << endl;*/
        write();
        read();
        file << "\t" << length << "\t";
        unsigned int start_time = clock();
        mergeSort2(length);
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;
        file << search_time << "\n";

    }
    file.close();
    /////////////// Сортування /////////////// 
    unsigned int start_time1 = clock(); // початковий час 
    sort_bubble(a);
    unsigned int end_time1 = clock(); // кінцевий час 
    // шуканий час 
    unsigned int search_time1 = end_time1 - start_time1;
    cout << "\nBubble sort:" << endl;
    cout << "Час роботи програми:" <<
        search_time1 << "ms" << endl;

    unsigned int start_time2 = clock();
    insertionSort(data, n);
    unsigned int end_time2 = clock();
    unsigned int search_time2 = end_time2 - start_time2;
    cout << "\nInsertion sort:" << endl;
    cout << "" << "Час роботи програми:" <<
        search_time2 << "ms" << endl;

    unsigned int start_time3 = clock();
    selectionSort(data1, n);
    unsigned int end_time3 = clock();
    unsigned int search_time3 = end_time3 - start_time3;
    cout << "\nSelection sort:" << endl;
    cout << "" << "Час роботи програми:" <<
        search_time3 << "ms" << endl;

    unsigned int start_time4 = clock();
    mergeSort(data2, n);
    unsigned int end_time4 = clock();
    unsigned int search_time4 = end_time4 - start_time4;
    cout << "\nMerge sort:" << endl;
    cout << "Час роботи програми:" << search_time4 << "ms" << endl;

    /*cout << "Sorted array in ascending order:\n";
    printArray(data, size);*/
    unsigned int start_time5 = clock();
    quickSort(data3, 0, n - 1);
    unsigned int end_time5 = clock();
    unsigned int search_time5 = end_time5 - start_time5;
    cout << "\nQuick sort:" << endl;
    cout << "Час роботи програми:" << search_time5 << "ms" << endl;
    //cout << "bubble" << endl;
    //print(a);
    //cout << "insertion" << endl;
    //printMergekSortArray(data, n);
    //cout << "selection" << endl;
    //printMergekSortArray(data1, n);
    //cout << "merge" << endl;
    //printMergekSortArray(data2, n);
    //cout << "quick" << endl;
    //printQuickSortArray(data3, n);
    cout << "selection sort stability test" << endl;
    char arrC[][MAX_LEN] = { "Alzem 208", "Aaron 208","Brown 308","Alzem 108","Aaron 108" }; // Example of instability
    int num = sizeof(arrC) / sizeof(arrC[0]);
    cout << "Given array is\n";
    for (int i = 0; i < num; i++)
        cout << i << ": " << arrC[i] << endl;

    selectionSortStr(arrC, num);
    cout << "\nSorted array is\n";
    for (int i = 0; i < num; i++)
        cout << i << ": " << arrC[i] << endl;
    char str[][10] = { "Alzem 208", "Aaron 208","Brown 308","Aaron 108","Alzem 108" };
    quickSortMain(str, 5);
    cout << "\nQuick sort stability test:" << endl;

    for (int i = 0; i < 5; i++) {
        printf("%s ", str[i]);
    }
    cout << endl;
    system("pause");
    return 0;
}

// Друк елементів масиву 
void print(int* a) {
    for (int i = 0; i < n; i++)
        cout << a[i] << '\t';
    cout << endl;
}
// Контроль введення 
int control() {
    while (true) {
        cout << "Введіть чило: ";
        cin >> n;
        if (cin.get() == '\n' && n > 0) break;
        else {
            cout << "Очікується ціле число!";
            cin.clear(); // скидає прапори помилок 
            cin.sync(); // видаляються усі символи до '\n' 
        }
    }
    return n;
}
// Перестановка 
void exch(int& a, int& b) {
    int tmp = a;
    a = b; b = tmp;
}
// Сортування бульбашоковим методом 
void sort_bubble(int* array) {
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < j; i++) {
            if (array[i] < array[i + 1])
                exch(array[i], array[i + 1]);
        }
    }
}
// Function to print an array 
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than 
        // it is found. 
        // For descending order, change key<array[j] to key>array[j]. 
        while (key > array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

            // To sort in descending order, change > to < in this line. 
            // Select the minimum element in each loop. 
            if (array[i] > array[min_idx])
                min_idx = i;
        }

        // put min at the correct position 
        swap(&array[min_idx], &array[step]);

    }
}




// function to swap elements(Quick Sort)
void quickSwap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] >= pivot) {    //<= - ascending order >= - descending

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            quickSwap(&array[i], &array[j]);
        }
    }

    // swap pivot with the greater element at i
    quickSwap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}
void quickSort(int array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}
void printQuickSortArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void merge(int a[], int b[], int low, int mid, int high)
{
    for (int i = low; i <= high; i++) {
        b[i] = a[i];
    }
    int left = low;
    int right = mid + 1;
    int index = low;
    while (left <= mid && right <= high) {
        //<= to >= to swap sorting order
        if (b[left] >= b[right])
            a[index++] = b[left++];
        else
            a[index++] = b[right++];
    }

    // copy remainder of the left side
    int remainder = mid - left + 1;
    for (int i = 0; i < remainder; i++) {
        a[index + i] = b[left + i];
    }
}
void mergeSort(int a[], int b[], int low, int high)
{
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(a, b, low, mid);
    mergeSort(a, b, mid + 1, high);
    merge(a, b, low, mid, high);
}

// prepare for real mergesort()
void mergeSort(int a[], int len)
{
    int* b = new int[len];
    mergeSort(a, b, 0, len - 1);
    delete[] b;
}
void printMergekSortArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void selectionSortStr(char arr[][MAX_LEN], int n) // This one is added just to show instability of this sorting method
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    char minStr[MAX_LEN];
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        strcpy_s(minStr, arr[i]);
        for (j = i + 1; j < n; j++)
        {
            // If min is greater than arr[j]
            if (strcmp(minStr, arr[j]) > 0)
            {
                // Make arr[j] as minStr and update min_idx
                strcpy_s(minStr, arr[j]);
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            char temp[MAX_LEN];
            strcpy_s(temp, arr[i]); //swap item[pos] and item[i]
            strcpy_s(arr[i], arr[min_idx]);
            strcpy_s(arr[min_idx], temp);
        }
    }
}
void quickSortMain(char items[][10], int count)
{
    quickSortStr(items, 0, count - 1);
}

void quickSortStr(char items[][10], int left, int right)
{
    int i, j;
    char* x;
    char temp[10];

    i = left;
    j = right;
    x = items[(left + right) / 2];

    do {
        while ((strcmp(items[i], x) < 0) && (i < right)) {
            i++;
        }
        while ((strcmp(items[j], x) > 0) && (j > left)) {
            j--;
        }
        if (i <= j) {
            strcpy_s(temp, items[i]);
            strcpy_s(items[i], items[j]);
            strcpy_s(items[j], temp);
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) {
        quickSortStr(items, left, j);
    }
    if (i < right) {
        quickSortStr(items, i, right);
    }
}
void read()
{
    ifstream fin("random.dat", ios::binary);
    for (long i = 0; i < length; i++)
    {
        fin.read((char*)&list[i], sizeof(int));
    }
    fin.close();
}
void write() {


    ofstream fout("random.dat", ios::binary);

    srand(time(NULL));

    int r;
    for (size_t i = 0; i < length; i++)
    {
        r = rand();
        fout.write((char*)&r, sizeof(r));
    }

    fout.close();
}
void bubbleSort()//rewritten bubble sort to task 3
{
    int temp;
    for (long i = 0; i < length; i++)
    {
        for (long j = 0; j < length - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void insertionSort2()//rewritten insertion sort to task 3(no params)
{
    int temp;
    for (long i = 1; i < length; i++)
    {
        temp = list[i];
        long j;
        for (j = i - 1; j >= 0 && list[j] > temp; j--)
        {
            list[j + 1] = list[j];
        }
        list[j + 1] = temp;
    }
}
long partition2(long left, long right)
{
    int pivot_element = list[left];
    int lb = left, ub = right;
    int temp;

    while (left < right)
    {
        while (list[left] <= pivot_element)
            left++;
        while (list[right] > pivot_element)
            right--;
        if (left < right)
        {
            temp = list[left];
            list[left] = list[right];
            list[right] = temp;
        }
    }
    list[lb] = list[right];
    list[right] = pivot_element;
    return right;
}

void quickSort2(long left, long right)
{
    if (left < right)
    {
        long pivot = partition2(left, right);
        quickSort2(left, pivot - 1);
        quickSort2(pivot + 1, right);
    }
}
void selectionSort2(int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

            // To sort in descending order, change > to < in this line. 
            // Select the minimum element in each loop. 
            if (list[i] > list[min_idx])
                min_idx = i;
        }

        // put min at the correct position 
        swap2(&list[min_idx], &list[step]);

    }
}
void swap2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void merge2(int a[], int b[], int low, int mid, int high)
{
    for (int i = low; i <= high; i++) {
        b[i] = a[i];
    }
    int left = low;
    int right = mid + 1;
    int index = low;
    while (left <= mid && right <= high) {
        //<= to >= to swap sorting order
        if (b[left] >= b[right])
            a[index++] = b[left++];
        else
            a[index++] = b[right++];
    }

    // copy remainder of the left side
    int remainder = mid - left + 1;
    for (int i = 0; i < remainder; i++) {
        a[index + i] = b[left + i];
    }
}
void mergeSort2(int a[], int b[], int low, int high)
{
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(a, b, low, mid);
    mergeSort(a, b, mid + 1, high);
    merge(a, b, low, mid, high);
}

// prepare for real mergesort()
void mergeSort2(int len)
{
    int* b = new int[len];
    mergeSort(list, b, 0, len - 1);
    delete[] b;
}
