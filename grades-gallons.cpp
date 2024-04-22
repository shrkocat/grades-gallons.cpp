/*
* Programmer: SANTECO, Enrique S.
* Date Created: 04/02/2024
* Program: BMCS
* Course / Section: CS122L/BM1
*/

#include<iostream>
#include<iomanip>
using namespace std;

// Global declaration
int i;
const int size = 10;
typedef double *pointers; // typedefinition used for miles per gallon pointer variables

// Prototypes
void getInput(double *input); // prompt the user to input 10 grades
double getLow(double *low); // compute and returns the value of the lowest grade
double getSum(double *sum); // compute for the sum of 10 grades
char getChoice(char *ch); // display the menu of choices and input the choice of the user

// Miles per gallon
void MilesPerrGallon(double *ptr1, double *ptr2, int sz); // final output of the computer miles and gallons
void MperG(); // prompts the user to specify the size of the array for miles and gallons
// verify and validate the input for miles and gallons using exception handling

int main() {
    char choice;
    char *chr = &choice;
    int opt;

    do {
        chr = &choice;
        opt = getChoice(chr);

        switch (*chr) {
        case '1': {
            double grade[size];
            double *ptr;
            double *plow, *psum, *pave;
            double gsum, glow;
            double ave;

            system("cls");
            getInput(grade); 
            gsum = getSum(grade); 
            glow = getLow(grade); 
            ave = (gsum - glow) / (size - 1); 

            system("cls"); 
            cout << "You entered:\n";
            for (i = 0; i < size; i++) {
                cout << "grade [" << i + 1 << "] : " << grade[i] << endl; 
            }
            cout << fixed << setprecision(2);
            cout << "sum = " << gsum << endl; 
            cout << "lowest = " << glow << endl; 
            cout << "average = " << ave << endl; 

            char tryAgain;
            do {
                cout << "Do you want to try again? [y/n]: ";
                cin >> tryAgain;
                if (tryAgain != 'y' && tryAgain != 'n') {
                    cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n'); 
                }
            } while (tryAgain != 'y' && tryAgain != 'n');

            if (tryAgain == 'n') {
                cout << "Leaving program..." << endl;
                return 0;
            }

            break;
        }
        case '2':
            MperG();
            break;
        case '3':
            cout << "goodbye for now....\n";
            system("pause"); 
            exit(1); 
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

        cout << endl;
        system("pause"); 
    } while (true);

    return 0;
}

// Display the menu and input the choice
char getChoice(char *ch) {
    cout << "<<<<<<<<<<MENU>>>>>>>>>>\n";
    cout << "[1] Score of 10 quizzes\n";
    cout << "[2] Miles per gallon\n";
    cout << "[3] To QUIT\n";
    cout << "Enter your choice: ";
    cin >> *ch;
    return *ch;
}

// Prompt to input 10 grades
void getInput(double *input) {
    for (i = 0; i < size; i++) {
        do {
            cout << "grade [" << i + 1 << "]: ";
            cin >> input[i];
            if (input[i] < 1 || input[i] > 100)
                cout << "Invalid input. Grade must be between 1-100." << endl;
        } while (input[i] < 1 || input[i] > 100); 
    }
}

// Compute sum of 10 grades
double getSum(double *sum) {
    double add = 0;
    for (i = 0; i < size; i++) {
        add += sum[i]; 
    }
    return add; 
}

// Return the value of the lowest grade
double getLow(double *low) {
    double lowest = low[0];
    for (i = 1; i < size; i++) {
        if (low[i] < lowest)
            lowest = low[i];
    }
    return lowest;
}

// Prompts to specify the size of the array for miles and gallons
void MperG() {
    int ctr;
    pointers milPtr, galPtr;
    int msize;
    system("cls");

    do {
        cout << "Specify the size of the array (5-15): ";
        cin >> msize;
        if (msize < 5 || msize > 15)
            cout << "Size 5-15 only." << endl;
    } while (msize < 5 || msize > 15);

    milPtr = new double[msize];
    galPtr = new double[msize];

    // Prompt for miles input
    for (ctr = 0; ctr < msize; ctr++) {
        bool validInput = false;
        do {
            try {
                cout << "miles [" << ctr << "]: ";
                cin >> milPtr[ctr];

                if (milPtr[ctr] < 100 || milPtr[ctr] > 250) {
                    throw milPtr[ctr]; 
                }

                validInput = true;
            } catch (double invalidValue) {
                cout << fixed << setprecision(2) << invalidValue << " is invalid... 100-250 only." << endl;
                cout << "Reenter a new value" << endl;
            }
        } while (!validInput); 
    }

    // Prompt for gallons input
    cout << "GALLONS\n";
    for (ctr = 0; ctr < msize; ctr++) {
        bool validInput = false;
        while (!validInput) {
            try {
                cout << "gallons [" << ctr << "]: ";
                cin >> galPtr[ctr];

                if (galPtr[ctr] < 5 || galPtr[ctr] > 25) {
                    throw galPtr[ctr];
                }

                validInput = true; 
            } catch (double invalidValue) {
                cout << fixed << setprecision(2) << invalidValue << " is invalid... 5-25 only." << endl;
                cout << "Reenter a new value" << endl;
            }
        }
    }

    MilesPerrGallon(milPtr, galPtr, msize);

    delete[] milPtr;
    delete[] galPtr;
}

// Final output of the computer miles and gallons
void MilesPerrGallon(double *ptr1, double *ptr2, int sz) {
    double mpg[sz]; 
    pointers mpgPtr; 
    int index;

    mpgPtr = new double[sz]; 

    cout << fixed << setprecision(2);
    cout << "miles\t/\tgallon\t=\tMPG\n";

    for (index = 0; index < sz; index++) {
        mpg[index] = ptr1[index] / ptr2[index]; 
        mpgPtr[index] = mpg[index]; 
        cout << ptr1[index] << "\t/\t" << ptr2[index] << "\t=\t" << mpg[index] << endl;
    }
    delete[] mpgPtr;
}
