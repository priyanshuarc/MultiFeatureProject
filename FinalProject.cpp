// ==============================
//         C++ Mini Project
//    Multi-Feature Application
// ==============================
// Features:
// 1. Password Generator
// 2. Tic-Tac-Toe Game
// 3. Marks Percentage Calculator
// 4. Unit Converter

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Password Generator
void passwordGen() {
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // yahan per string daal skte hai jo password mei chahiye vo
    int len;
    cout << "\n========== Password Generator ==========" << endl;
    cout << "Enter password length: ";
    cin >> len;
    string pass = "";
    for (int i = 0; i < len; i++) {
        pass += letters[(i * 13 + 7) % letters.length()];
    }
    cout << "Generated Password: " << pass << endl;
}

// Tic-Tac-Toe Game
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, column;

void display_board() {
    cout << "\n========== Tic-Tac-Toe ==========" << endl;
    cout << "\n Player1 [X] vs Player2 [O]\n";
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "     |     |     \n";
}

void player_turn() {
    int choice;
    cout << "\nPlayer " << turn << "'s turn. Enter a number (1-9): ";
    cin >> choice;
    if (choice < 1 || choice > 9) {
        cout << "Invalid input! Try again.\n";
        player_turn();
        return;
    }
    row = (choice - 1) / 3;
    column = (choice - 1) % 3;
    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Cell already occupied! Try again.\n";
        player_turn();
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

void ticTacToe() {
    display_board();
    while (true) {
        player_turn();
        display_board();
        if (checkWin()) {
            cout << "\nPlayer " << (turn == 'X' ? 'O' : 'X') << " wins!\n";
            break;
        }
    }
}

// Marks Percentage Calculator
void percentageCalculator() {
    int subjects, totalMarks;
    cout << "\n========== Marks Percentage Calculator ==========" << endl;
    cout << "Enter number of subjects: ";
    cin >> subjects;
    cout << "Enter total marks per subject: ";
    cin >> totalMarks;
    float total = 0, marks;
    for (int i = 0; i < subjects; i++) {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> marks;
        total += marks;
    }
    cout << "Total Marks: " << total << " out of " << (subjects * totalMarks) << endl;
    cout << "Percentage: " << (total / (subjects * totalMarks)) * 100 << "%\n";
}

// Unit Converter
void unitConverter() {
    int choice;
    double value;
    cout << "\n========== Unit Converter ==========" << endl;
    cout << "1. Kilometers to Miles\n2. Miles to Kilometers\n3. Celsius to Fahrenheit\n4. Fahrenheit to Celsius\nChoose: ";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;
    if (choice == 1) cout << value * 0.621371 << " miles\n";
    else if (choice == 2) cout << value * 1.60934 << " km\n";
    else if (choice == 3) cout << (value * 9/5) + 32 << " F\n";
    else if (choice == 4) cout << (value - 32) * 5/9 << " C\n";
    else cout << "Invalid choice!\n";
}

// Main Menu
int main() {
    int option;
    do {
        cout << "\n========== Main Menu ==========" << endl;
        cout << "1. Password Generator\n2. Tic-Tac-Toe\n3. Marks Percentage Calculator\n4. Unit Converter\n5. Exit\nChoose: ";
        cin >> option;
        if (option == 1) passwordGen();
        else if (option == 2) ticTacToe();
        else if (option == 3) percentageCalculator();
        else if (option == 4) unitConverter();
    } while (option != 5);
    cout << "\nThank you for using the program! Goodbye!\n";
    return 0;
}