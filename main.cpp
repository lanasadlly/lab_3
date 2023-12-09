#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>
#include <conio.h>
using namespace std;

void printMenu ()
{
    cout << "Choose an action:" << endl;
    cout << "1) Fill a square matrix N*N with random int values from 1 to N*N" << endl;
    cout << "2) Make a new matrix out of a matrix filled in point 1" << endl;
    cout << "3) Sort matrix elements" << endl;
    cout << "4) Decrease, increase, multiply or divide all matrix elements by some value" << endl;
    cout << "5) Finish" << endl;
}

void printPoint1 (int b)
{
    if (b == 1)
    {
        cout << "Choose a matrix order:" << endl;
        cout << "1) N = 6" << endl;
        cout << "2) N = 8" << endl;
        cout << "3) N = 10" << endl;
    }
    if (b == 2)
    {
        cout << "Choose a filling scheme:" << endl;
        cout << " 1)  ---------------     2)  --------------- " << endl;
        cout << "    |               |       |               |" << endl;
        cout << "    |  1 2..>.....  |       | 1  .>..  .>.. |" << endl;
        cout << "    |            .  |       | 2  .  .  .  . |" << endl;
        cout << "    |  .....>..  .  |       | .  .  .  .  . |" << endl;
        cout << "    |  .      .  .  |       | .  .  .  .  . |" << endl;
        cout << "    |  .    <..  .  |       | .  .  .  .  . |" << endl;
        cout << "    |  .         .  |       | .  .  .  .  . |" << endl;
        cout << "    |  .....<.....  |       | .>..  .>..  . |" << endl;
        cout << "    |               |       |               |" << endl;
        cout << "     ---------------         --------------- " << endl;
    }
}

void printPoint2 ()
{
    cout << "Choose a changing scheme:" << endl;
    cout << " 1)  ---------------     2)  --------------- " << endl;
    cout << "    |       |       |       |  _    |    _  |" << endl;
    cout << "    |  /\\...|....>  |       | |\\    |    /| |" << endl;
    cout << "    |   .   |   .   |       |    \\  |  /    |" << endl;
    cout << "    |   .   |   .   |       |      \\|/      |" << endl;
    cout << "    |---.-----------|       |---------------|" << endl;
    cout << "    |   .   |   .   |       |      /|\\      |" << endl;
    cout << "    |   .   |   .   |       |    /  |  \\    |" << endl;
    cout << "    |  <....|...\\/  |       | |/    |    \\| |" << endl;
    cout << "    |       |       |       |  -    |    -  |" << endl;
    cout << "     ---------------         --------------- " << endl << endl;
    cout << " 3)  ---------------     4)  --------------- " << endl;
    cout << "    |       |       |       |       |       |" << endl;
    cout << "    |  /\\   |   /\\  |       |  <....|....>  |" << endl;
    cout << "    |   .   |   .   |       |       |       |" << endl;
    cout << "    |   .   |   .   |       |       |       |" << endl;
    cout << "    |---------------|       |---------------|" << endl;
    cout << "    |   .   |   .   |       |       |       |" << endl;
    cout << "    |   .   |   .   |       |       |       |" << endl;
    cout << "    |  \\/   |   \\/  |       |  <....|....>  |" << endl;
    cout << "    |       |       |       |       |       |" << endl;
    cout << "     ---------------         --------------- " << endl;
}

void printPoint3 ()
{
    cout << "Choose a sorting method:" << endl;
    cout << "1) Shaker sort" << endl;
    cout << "2) Comb sort" << endl;
    cout << "3) Insert sort" << endl;
    cout << "4) Quick sort" << endl;
}

void printPoint4 ()
{
    cout << "Choose an action:" << endl;
    cout << "1) Decrease" << endl;
    cout << "2) Increase" << endl;
    cout << "3) Multiply" << endl;
    cout << "4) Divide" << endl;
}

void showMatrix (int *arr, int order)
{
    int *end = arr + order * order - 1;
    for (int *curr = arr; curr <= end; curr++)
    {
        cout << setw (3) << *curr << "  ";
        if ((curr - arr) % order == order - 1)
            cout << endl << endl << endl;
    }
}

void doFill1 (int *arr, int order)
{
    int *startUp = arr;
    int *endUp = arr + order - 1;
    int *startRight = arr + order * 2 - 1;
    int *endRight = arr + order * order - 1;
    int *startDown = arr + order * order - 1;
    int *endDown = arr + order * (order - 1);
    int *startLeft = arr + order * (order - 2);
    int *endLeft = arr + order;

    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle (STD_OUTPUT_HANDLE);

    for (int i = 0; i < order / 2; i++)
    {
        for (int *curr = startUp; curr <= endUp; curr++)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        startUp = startUp + order + 1;
        endUp = endUp + order - 1;
        for (int *curr = startRight; curr < endRight; curr += order)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        startRight = startRight + order - 1;
        endRight = endRight - order - 1;
        for (int *curr = startDown; curr >= endDown; curr--)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        startDown = startDown - order - 1;
        endDown = endDown - order + 1;
        for (int *curr = startLeft; curr >= endLeft; curr -= order)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        startLeft = startLeft - order + 1;
        endLeft = endLeft + order + 1;
    }
    destCoord.X = 0;
    destCoord.Y = order * 3 - 1;
    SetConsoleCursorPosition (hStdout, destCoord);
    cout << endl;
    cout.flush();
}

void doFill2 (int *arr, int order)
{
    int *startDown = arr;
    int *endDown = arr + order * (order - 1);
    int *startUp = arr + order * (order - 1) + 1;
    int *endUp = arr + 1;

    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle (STD_OUTPUT_HANDLE);

    for (int i = 0; i < order / 2; i++)
    {
        for (int *curr = startDown; curr <= endDown; curr += order)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        startDown += 2;
        endDown += 2;
        for (int *curr = startUp; curr >= endUp; curr -= order)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        startUp += 2;
        endUp += 2;

    }
    destCoord.X = 0;
    destCoord.Y = order * 3 - 1;
    SetConsoleCursorPosition (hStdout, destCoord);
    cout << endl;
    cout.flush();
}

void doScheme1 (int *arr, int order)
{
    int half = order / 2;
    for (int *beginCln = arr + half; beginCln < arr + order; beginCln++)
        for (int *currUpper = beginCln, *currLower = beginCln + order * half; currLower < beginCln + order * order; currUpper += order, currLower += order)
            swap (*currUpper, *currLower);
    for (int *beginStr = arr; beginStr < arr + order * half; beginStr += order)
        for (int *currLeft = beginStr, *currRight = beginStr + half; currRight < beginStr + order; currLeft++, currRight++)
            swap (*currLeft, *currRight);
}

void doScheme2 (int *arr, int order)
{
    int half = order / 2;
    for (int *beginStr = arr; beginStr < arr + order * order; beginStr += order)
        for (int *currLeft = beginStr, *currRight = beginStr + half; currRight < beginStr + order; currLeft++, currRight++)
            swap (*currLeft, *currRight);
    for (int *beginCln = arr; beginCln < arr + order; beginCln++)
        for (int *currUpper = beginCln, *currLower = beginCln + order * half; currLower < beginCln + order * order; currUpper += order, currLower += order)
            swap (*currUpper, *currLower);
}

void doScheme3 (int *arr, int order)
{
    int half = order / 2;
    for (int *beginCln = arr; beginCln < arr + order; beginCln++)
        for (int *currUpper = beginCln, *currLower = beginCln + order * half; currLower < beginCln + order * order; currUpper += order, currLower += order)
            swap (*currUpper, *currLower);
}

void doScheme4 (int *arr, int order)
{
    int half = order / 2;
    for (int *beginStr = arr; beginStr < arr + order * order; beginStr += order)
        for (int *currLeft = beginStr, *currRight = beginStr + half; currRight < beginStr + order; currLeft++, currRight++)
            swap (*currLeft, *currRight);
}

void doShakerSort (int *arr, int order)
{
    bool swapped = 1;
    int *start = arr;
    int *end = arr + order * order - 1;
    while (swapped)
    {
        swapped = 0;
        for (int *curr = start; curr < end; curr++)
        {
            if (*curr > *(curr + 1))
            {
                swap (*curr, *(curr + 1));
                swapped = 1;
            }
        }
        end--;
        for (int *curr = end - 1; curr >= start; curr--)
        {
            if (*curr > *(curr + 1))
            {
                swap (*curr, *(curr + 1));
                swapped = 1;
            }
        }
        start++;
    }
}

void doCombSort (int *arr, int order)
{
    int *start = arr;
    int *end = arr + order * order - 1;
    bool swapped = 1;
    float k = 1.247, step = order * order - 1;
    while (step >= 1)
    {
        for (int *curr = start; curr + int (step) < end + 1; curr++)
        {
            if (*curr > *(curr + int (step)))
                swap (*curr, *(curr + int (step)));
        }
        step /= k;
    }
    while (swapped)
    {
        swapped = 0;
        for (int *curr = arr; curr < end; curr ++)
        {
            if (*curr > *(curr + 1))
            {
                swap (*curr, *(curr + 1));
                swapped = 1;
            }
        }
        end--;
    }
}

void doInsertSort (int *arr, int order)
{
    int key;
    int *j;
    for(int *curr = arr + 1; curr < arr + order * order; curr++)
    {
        j = curr - 1;
        key = *curr;
        while (j >= arr && *j > key)
        {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}

void doQuickSort (int *arr, int *start, int *end)
{
    int *left = start;
    int *right = end;
    int key = *start;
    int countLess = 0;
    for (int *curr = start; curr <= end; curr++)
        if (*curr < key)
            countLess += 1;
    swap (*start, *(start + countLess));
    while (left <= right)
    {
        while (*left < key)
            left++;
        while (*right >= key)
            right--;
        if (left < right)
        {
            swap (*left, *right);
            left++;
            right--;
        }
    }
    if (right > start)
        doQuickSort (arr, start, right);
    if (left + 1 < end)
        doQuickSort (arr, left + 1, end);
}

void doDecrIncrMultiDiv (int *arr, int order, int value, int action)
{
    int *end = arr + order * order - 1;
    for (int *curr = arr; curr <= end; curr++)
    {
        switch (action)
        {
        case 1:
            *curr -= value;
            break;
        case 2:
            *curr += value;
            break;
        case 3:
            *curr *= value;
            break;
        case 4:
            *curr /= value;
            break;
        }
    }
}

void doPoint1 (int *arr6, int *arr8, int *arr10, int *order)
{
    int chooseScheme;
    bool choose1Done = 0;
    bool choose2Done = 0;
    while (!(*order == 1 || *order == 2 || *order == 3))
    {
        if (choose1Done)
            cout << "Wrong input!" << endl << endl;
        printPoint1 (1);
        *order = getch () - 48;
        choose1Done = 1;
        cout << endl;
    }
    while (!(chooseScheme == 1 || chooseScheme == 2))
    {
        if (choose2Done)
            cout << "Wrong input!" << endl << endl;
        printPoint1 (2);
        chooseScheme = getch () - 48;
        choose2Done = 1;
        cout << endl;
    }
    system ("cls");
    switch (*order)
    {
        case 1:
            *order = 6;
            if (chooseScheme == 1)
                doFill1 (arr6, *order);
            else if (chooseScheme == 2)
                doFill2 (arr6, *order);
            break;
        case 2:
            *order = 8;
            if (chooseScheme == 1)
                doFill1 (arr8, *order);
            else if (chooseScheme == 2)
                doFill2 (arr8, *order);
            break;
        case 3:
            *order = 10;
            if (chooseScheme == 1)
                doFill1 (arr10, *order);
            else if (chooseScheme == 2)
                doFill2 (arr10, *order);
            break;
    }
    cout << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void doPoint2 (int *arr6, int *arr8, int *arr10, int order)
{
    int choose;
    bool chooseDone = 0;
    while (!(choose == 1 || choose == 2 || choose == 3 || choose == 4))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        printPoint2 ();
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }
    switch (choose)
    {
    case 1:
        if (order == 6)
        {
            doScheme1 (arr6, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr6, order);
        }
        if (order == 8)
        {
            doScheme1 (arr8, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr8, order);
        }
        if (order == 10)
        {
            doScheme1 (arr10, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr10, order);
        }
        break;
    case 2:
        if (order == 6)
        {
            doScheme2 (arr6, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr6, order);
        }
        if (order == 8)
        {
            doScheme2 (arr8, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr8, order);
        }
        if (order == 10)
        {
            doScheme2 (arr10, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr10, order);
        }
        break;
    case 3:
        if (order == 6)
        {
            doScheme3 (arr6, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr6, order);
        }
        if (order == 8)
        {
            doScheme3 (arr8, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr8, order);
        }
        if (order == 10)
        {
            doScheme3 (arr10, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr10, order);
        }
        break;
    case 4:
        if (order == 6)
        {
            doScheme4 (arr6, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr6, order);
        }
        if (order == 8)
        {
            doScheme4 (arr8, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr8, order);
        }
        if (order == 10)
        {
            doScheme4 (arr10, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrix (arr10, order);
        }
        break;
    }
    cout << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void doPoint3 (int *arr6, int *arr8, int *arr10, int order)
{
    int choose;
    bool chooseDone = 0;
    while (!(choose == 1 || choose == 2 || choose == 3 || choose == 4))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        printPoint3 ();
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }
    switch (choose)
    {
        case 1:
            if (order == 6)
            {
                doShakerSort (arr6, order);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr6, order);
            }
            else if (order == 8)
            {
                doShakerSort (arr8, order);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr8, order);
            }
            else if (order == 10)
            {
                doShakerSort (arr10, order);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr10, order);
            }
            break;
        case 2:
            if (order == 6)
            {
                doCombSort (arr6, order);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr6, order);
            }
            else if (order == 8)
            {
                doCombSort (arr8, order);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr8, order);
            }
            else if (order == 10)
            {
                doCombSort (arr10, order);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr10, order);
            }
            break;
        case 3:
            if (order == 6)
            {
                doInsertSort (arr6, order);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr6, order);
            }
            else if (order == 8)
            {
                doInsertSort (arr8, order);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr8, order);
            }
            else if (order == 10)
            {
                doInsertSort (arr10, order);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr10, order);
            }
            break;
        case 4:
            if (order == 6)
            {
                doQuickSort (arr6, arr6, arr6 + order * order - 1);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr6, order);
            }
            else if (order == 8)
            {
                doQuickSort (arr8, arr8, arr8 + order * order - 1);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr8, order);
            }
            else if (order == 10)
            {
                doQuickSort (arr10, arr10, arr10 + order * order - 1);
                cout << "Sorted matrix:" << endl << endl;
                showMatrix (arr10, order);
            }
            break;
    }
    cout << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void doPoint4 (int *arr6, int *arr8, int *arr10, int order)
{
    int choose;
    int value;
    bool chooseDone = 0;
    while (!(choose == 1 || choose == 2 || choose == 3 || choose == 4))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        printPoint4 ();
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }
    switch (choose)
    {
        case 1:
            cout << "Enter a value that you want to decrease matrix elements by:" << endl << endl;
            value = getch () - 48;
            if (order == 6)
            {
                doDecrIncrMultiDiv (arr6, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr6, order);
            }
            if (order == 8)
            {
                doDecrIncrMultiDiv (arr8, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr8, order);
            }
            if (order == 10)
            {
                doDecrIncrMultiDiv (arr10, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr10, order);
            }
            break;
        case 2:
            cout << "Enter a value that you want to increase matrix elements by:" << endl << endl;
            value = getch () - 48;
            if (order == 6)
            {
                doDecrIncrMultiDiv (arr6, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr6, order);
            }
            if (order == 8)
            {
                doDecrIncrMultiDiv (arr8, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr8, order);
            }
            if (order == 10)
            {
                doDecrIncrMultiDiv (arr10, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr10, order);
            }
            break;
        case 3:
            cout << "Enter a value that you want to multiply matrix elements by:" << endl << endl;
            value = getch () - 48;
            if (order == 6)
            {
                doDecrIncrMultiDiv (arr6, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr6, order);
            }
            if (order == 8)
            {
                doDecrIncrMultiDiv (arr8, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr8, order);
            }
            if (order == 10)
            {
                doDecrIncrMultiDiv (arr10, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr10, order);
            }
            break;
        case 4:
            cout << "Enter a value that you want to divide matrix elements by:" << endl << endl;
            value = getch () - 48;
            if (order == 6)
            {
                doDecrIncrMultiDiv (arr6, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr6, order);
            }
            if (order == 8)
            {
                doDecrIncrMultiDiv (arr8, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr8, order);
            }
            if (order == 10)
            {
                doDecrIncrMultiDiv (arr10, order, value, choose);
                cout << "New matrix:" << endl << endl;
                showMatrix (arr10, order);
            }
            break;
    }
    cout << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

int main()
{
    srand (time(NULL));
    int order;
    int choose;
    bool filled = 0;
    int arr6 [6][6] = {{}, {}, {}, {}, {}, {}};
    int arr8 [8][8] = {{}, {}, {}, {}, {}, {}, {}, {}};
    int arr10 [10][10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
    while (true)
    {
        printMenu ();
        choose = getch () - 48;
        cout << endl;
        switch (choose)
        {
            case 1:
                doPoint1 (*arr6, *arr8, *arr10, &order);
                filled = 1;
                break;
            case 2:
                if (filled)
                    doPoint2 (*arr6, *arr8, *arr10, order);
                else
                    cout << "Fill the matrix first!!! (point 1)" << endl;
                break;
            case 3:
                if (filled)
                    doPoint3 (*arr6, *arr8, *arr10, order);
                else
                    cout << "Fill the matrix first!!! (point 1)" << endl;
                break;
            case 4:
                if (filled)
                    doPoint4 (*arr6, *arr8, *arr10, order);
                else
                    cout << "Fill the matrix first!!! (point 1)" << endl;
                break;
            case 5:
                exit (0);
            default:
                cout << "Wrong input!" << endl << endl;
                break;
        }
    }
    return 0;
}
