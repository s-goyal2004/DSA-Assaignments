#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// (a) Concatenate one string to another
void concatenateStrings() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin.ignore(); // to clear buffer
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);
    strcat(str1, str2);
    cout << "Concatenated String: " << str1 << endl;
}

// (b) Reverse a string
void reverseString() {
    char str[100];
    cout << "Enter a string: ";
    cin.ignore();
    cin.getline(str, 100);
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
        cout << str[i];
    cout << endl;
}

// (c) Delete all vowels from string
void deleteVowels() {
    char str[100], result[100];
    cout << "Enter a string: ";
    cin.ignore();
    cin.getline(str, 100);

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    cout << "String without vowels: " << result << endl;
}

// (d) Sort strings in alphabetical order
void sortStrings() {
    int n;
    cout << "How many strings do you want to sort? ";
    cin >> n;
    cin.ignore();

    char arr[20][100];  // max 20 strings, each up to 100 chars
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin.getline(arr[i], 100);
    }

    // Bubble sort on strings
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

// (e) Convert uppercase to lowercase
void convertCase() {
    char str[100];
    cout << "Enter a string (with uppercase letters): ";
    cin.ignore();
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    cout << "Converted string (lowercase): " << str << endl;
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Concatenate Strings\n";
        cout << "2. Reverse String\n";
        cout << "3. Delete Vowels\n";
        cout << "4. Sort Strings Alphabetically\n";
        cout << "5. Convert Uppercase to Lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: concatenateStrings(); break;
        case 2: reverseString(); break;
        case 3: deleteVowels(); break;
        case 4: sortStrings(); break;
        case 5: convertCase(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
