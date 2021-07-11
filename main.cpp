#include <iostream>
#include <string>

using namespace std;

const double MIN_BET = 10;
const double BET_INCREMENT = 1;
const double STARTING_CASH = 1000;

int main() {
    string name;
    cout << "Now playing Blackjack!" << endl;
    cout << "You start with $" << STARTING_CASH << "." << endl;
    cout << "The minimum bet is $" << MIN_BET << "." << endl;
    cout << "Bets can only be in multiples of $" << BET_INCREMENT << "." << endl;
    cout << "Enter your name:" << endl;
    cin >> name;
    cout << "Your name is: " << name << endl;

    return 0;
}