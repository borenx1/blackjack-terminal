#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

namespace blackjack {
    struct BlackjackSettings {
        double starting_cash;
        double min_bet;
        double bet_increment;
        unsigned int decks;
        BlackjackSettings(double starting_cash = 1000, double min_bet = 10, double bet_increment = 1, unsigned int decks = 4)
            : starting_cash(starting_cash), min_bet(min_bet), bet_increment(bet_increment) {}
    };

    struct State {
        unsigned int round;
        int cash;
        card::Card hand[20];
        card::Card deck[52 * 20];
    };

    class Blackjack {
        public:
            Blackjack() {}

            Blackjack(BlackjackSettings settings): settings(settings) {}

            void start() {
                printStartingMessage();
                string name;
                cout << "Enter your name:" << endl;
                cin >> name;
                cout << "Your name is: " << name << endl;
            }
        protected:
            void printStartingMessage() {
                cout << "Now playing Blackjack!" << endl;
                cout << "You start with $" << settings.starting_cash << "." << endl;
                cout << "The minimum bet is $" << settings.min_bet << "." << endl;
                cout << "Bets can only be in multiples of $" << settings.bet_increment << "." << endl;
            }
        private:
            BlackjackSettings settings;
    };
}