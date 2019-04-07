#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int arr[], int len);
void changeArray(int arr[], int len);
void randomiseArray(int arr[], int len, int low, int high);
void asked(int val);

//Random functions
int randI(int low, int high);
void randomSeed(unsigned int t);

int amount = 5;
int numbers[5] = {1, 2, 3, 4, 5};
int val;

int main()
{
    printArray(numbers, amount);
    while (val != 4){
        cout << "Would you like to 1. Change the values individually, 2. Randomise the values in the array, 3. Print out the current array, or 4. Quit" << endl;
        cin >> val;
        asked(val);
    }

    return 0;
}

void printArray(int arr[], int len){
    cout << "This current array contains the integers: \n" << endl;

    for (int i = 0; i < len; i++){
            cout << arr[i] << " in position " << i << endl;
    }
}

void asked(int val){
    if (val == 1){
        changeArray(numbers, amount);
    } else if (val == 2){
        int low, high;
        cout << "Lowest: ";
        cin >> low;
        cout << "Highest: ";
        cin >> high;
        while (low > high){
            cout << "Sorry, we cannot allow you to make the lowest integer greater than the highest integer" << endl;
            cout << "Lowest: ";
            cin >> low;
            cout << "Highest: ";
            cin >> high;
        }
        randomiseArray(numbers, amount, low, high);
    } else if (val == 3){
        printArray(numbers, amount);
    }
}

void changeArray(int arr[], int len){
    int n;
    for (int i = 0; i < len; i++){
        cout << "What value would you like to give for position " << i << " in this array?" << endl;
        cin >> n;
        arr[i] = n;
    }
}
void randomiseArray(int arr[], int len, int low, int high){
    int n;
    randomSeed(time(0));
    for (int i = 0; i < len; i++){
        n = randI(low, high);
        arr[i] = n;
    }
}


int randI(int low, int high){
    int r = 1 + (rand()) /(RAND_MAX/(high-low));
    return r;
}

void randomSeed(unsigned int t) {
    srand(t);
}
