#include <iostream>
#include<cmath>
using namespace std;

/* Given Arrays. */
int array1[] = { 1,1,1,4,5,6,9,9,7,8,6,6,9,9,3,2,3,2,1,5,5,5 };
int array2[] = { 3,4,5,1,4,2,3,3,8,9,8,1,1,1,6,4,3 };
int array3[] = { 5,1,4,2,3 };
int array4[] = { 1,4,5,3 };

/* Functions outside of class.*/
void swap(int* a, int* b);
void bubbleSort(int array[], int size);
int counting(int array[], int size, int value);
int counting(int array[], int size, int value);
bool foundByLinearSearch(int array[], int size, int value);
void Print(int array[], int size);
bool isSubset(int array_1[], int size_1, int array_2[], int size_2);
int* insert(int array[], int size, int value, int position);
int* deletion(int array[], int size, int place);
int* merge(int array_1[], int size_1, int array_2[], int size_2);
void minAndMax(int array[], int size, int* min, int* max);

/* This is a swap function */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Performs the bubble sort */
void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
    }
}

/* This function counts the total number of an element present in an array */
int counting(int array[], int size, int value)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
            count++;
    }
    return count;
}

/* Prints the elemets of an array */
void Print(int array[], int size)
{
    int* ptr;
    ptr = array;
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

/* This function checks whether an element is present in an array */
bool foundByLinearSearch(int array[], int size, int value)
{
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            temp = 1;
            break;
        }
    }
    if (temp == 0)
        return false;
    else
        return true;
}

/*This function checks whether the second array is a subset of the first. */
bool isSubset(int array_1[], int size_1, int array_2[], int size_2)
{
    int j = 0;
    for (int i = 0; i < size_2; i++)
    {
        for (j = 0; j < size_1; j++)
        {
            if (array_1[j] == array_2[i])
            {
                break;
            }
        }
        if (j == size_1)
            return false;
    }
    return true;
}

/* This function adds an element in an array */
int* insert(int array[], int size, int value, int position)
{
    int* array_1 = new int[size + 1];
    array_1[position - 1] = value;
    int a = position - 1;
    for (int i = 0; i < position - 1; i++)
    {
        array_1[i] = array[i];
    }
    for (int j = position; j < size + 1; j++)
    {
        array_1[j] = array[a];
        a++;
    }

    return array_1;

    delete[] array_1;
    array_1 = NULL;
}

/* This function deletes an element from an array */
int* deletion(int array[], int size, int place)
{
    int* array_1 = new int[size - 1];
    int i = 0, j = 0;
    place = place - 1;
    while (i < size && j < size)
    {
        if (i == place)
        {
            j = place + 1;
        }
        array_1[i] = array[j];
        i++;
        j++;
    }

    return array_1;

    delete[] array1;
    array_1 = NULL;
}

/* This function merges two arrays. */
int* merge(int array_1[], int size_1, int array_2[], int size_2)
{
    int* array = new int[size_1 + size_2];
    int k = 0;
    for (int i = 0; i < size_1; i++)
    {
        array[i] = array_1[i];
    }
    for (int j = size_1; j < size_2 + size_1; j++)
    {
        array[j] = array_2[k];
        k++;
    }

    return array;

    delete[] array;
    array = NULL;
}

/* This function finds the maximum and minimum value of an array using pointers. */
void minAndMax(int array[], int size, int* min, int* max)
{

    for (int i = 1; i < size; i++)
    {
        if (array[i] < *min)
            *min = array[i];
        if (array[i] > *max)
            *max = array[i];
    }
}

/* This class finds the maximum and minimum value of an array */
class maxAndMin
{
public:
    int max;
    int min;


    void max_Min(int array[], int size)
    {
        for (int i = 1; i < size; i++)
        {
            if (array[i] > max)
                max = array[i];
            if (array[i] < min)
                min = array[i];
        }
    }
    maxAndMin(int m, int n)
    {
        max = m;
        min = n;
    }
};

/* This class calculates the mean, median and modal value of an array. */
class statistics
{
public:

    int size;
    int* array = new int[size];

    double findMean()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += array[i];
        }

        double Mean = (double)sum / size;
        return Mean;
    }

    int findMedian()
    {
        bubbleSort(array, size);
        return array[(int)round(size / 2)];
    }

    int findMode()
    {
        int max = 0, Mode = 0;
        for (int i = 0; i < size; i++)
        {
            if (max < counting(array, size, array[i]))
                max = counting(array, size, array[i]);

        }
        for (int j = 0; j < size; j++)
        {
            if (counting(array, size, array[j]) == max)
                Mode = array[j];
        }
        if (max == 1)
            Mode = 0;

        return Mode;
    }

    statistics(int a[], int s)
    {
        array = a;
        size = s;
    }
};


int main()
{
    int question;

    cout << "1. Swap." << endl;
    cout << "2. Sort an array." << endl;
    cout << "3. Count the frequency of an element in an array." << endl;
    cout << "4. Look for the presence of an element in an array." << endl;
    cout << "5. Check if one array is a subset of the other." << endl;
    cout << "6. Insert an element into an array." << endl;
    cout << "7. Deletes an element from an array. " << endl;
    cout << "8. Merges two arrays." << endl;
    cout << "9. Finds the maximum and minimum value of an array." << endl;
    cout << "10. Find the mean,median and modal value from an array" << endl;

    cout << endl << endl;

    cout << "Arrays: " << endl;

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int size3 = sizeof(array3) / sizeof(array3[0]);
    int size4 = sizeof(array4) / sizeof(array4[0]);

    Print(array1, size1);
    Print(array2, size2);
    Print(array3, size3);
    Print(array4, size4);

    do
    {
        cout << endl;
        cout << "Enter the number (Press 0 to exit) : ";
        cin >> question;
        cout << endl << endl;

        switch (question)
        {
        case 0:
            break;
        case 1:
        {
            int a, b;
            cout << "Enter the value of a and b: " << endl;
            cin >> a >> b;
            swap(&a, &b);
            cout << "After swapping, a is " << a << " b is " << b << endl;
            break;
        }
        case 2:

        {
            bubbleSort(array1, size1);
            Print(array1, size1);
            break;
        }
        case 3:
        {
            int value;
            cout << "Enter the value: " << endl;
            cin >> value;
            cout << "The frequency of " << value << " is " << counting(array3, size3, value) << endl;
            break;
        }
        case 4:
        {
            int value1;
            cout << "Enter the value you are looking for: " << endl;
            cin >> value1;
            foundByLinearSearch(array2, size2, value1) ? cout << "Found" : cout << "Not Found";
            break;
        }
        case 5:
        {
            isSubset(array1, size1, array2, size2) ? cout << "The second array is a subset of the first." << endl : cout << "The second array is not a subset of the first." << endl;
            isSubset(array1, size1, array3, size3) ? cout << "The second array is a subset of the first." << endl : cout << "The second array is not a subset of the first." << endl;
            isSubset(array1, size1, array4, size4) ? cout << "The second array is a subset of the first." << endl : cout << "The second array is not a subset of the first." << endl;
            isSubset(array2, size2, array3, size3) ? cout << "The second array is a subset of the first." << endl : cout << "The second array is not a subset of the first." << endl;
            isSubset(array2, size2, array4, size4) ? cout << "The second array is a subset of the first." << endl : cout << "The second array is not a subset of the first." << endl;
            isSubset(array3, size3, array4, size4) ? cout << "The second array is a subset of the first." << endl : cout << "The second array is not a subset of the first." << endl;
            break;
        }
        case 6:
        {
            int value2, position;
            cout << "Enter the value and position respectively: " << endl;
            cin >> value2 >> position;
            int* ptr;
            ptr = insert(array4, size4, value2, position);
            for (int i = 0; i < size4 + 1; i++)
            {
                cout << *(ptr + i) << " ";
            }
            break;
        }
        case 7:
        {
            int position1;
            cout << "Enter the position you want to delete: " << endl;
            cin >> position1;
            int* ptr1 = deletion(array3, size3, position1);
            for (int i = 0; i < size3 - 1; i++)
            {
                cout << *(ptr1 + i) << " ";
            }
            break;
        }
        case 8:
        {
            cout << "After merging the two arrays: " << endl;
            int* ptr2 = merge(array3, size3, array4, size4);
            for (int i = 0; i < size3 + size4; i++)
            {
                cout << *(ptr2 + i) << " ";
            }
            break;
        }
        case 9:
        {
            int max1 = array3[0];
            int min1 = array3[0];
            minAndMax(array3, size3, &min1, &max1);
            cout << "MIN: " << min1 << endl;
            cout << "MAX: " << max1 << endl;
            cout << endl << endl;

            int max2 = array4[0];
            int min2 = array4[0];
            maxAndMin M = maxAndMin(max2, min2);
            M.max_Min(array4, size4);
            cout << "MAX: " << M.max << endl;
            cout << "MIN: " << M.min << endl;
            break;
        }
        case 10:
        {
            statistics S = statistics(array2, size2);
            cout << "Mean: " << S.findMean() << endl;
            cout << "Median: " << S.findMedian() << endl;
            cout << "Mode: " << S.findMode() << endl;
            break;
        }
        default:
            cout << "Invalid option." << endl;
            break;
        }
    } while (question != 0);

    return 0;
}