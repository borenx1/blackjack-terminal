#include "blackjack.h"
#include <iostream>
#include <string>

namespace blackjack {
    Blackjack::Blackjack() {};
    Blackjack::Blackjack(GameSettings settings): settings(settings) {}
    void Blackjack::start() {
        printStartingMessage();
        std::string name;
        std::cout << "Enter your name:" << '\n';
        std::cin >> name;
        std::cout << "Your name is: " << name << '\n';
    }
    void Blackjack::printStartingMessage() {
        std::cout << "Now playing Blackjack!" << '\n';
        std::cout << "You start with $" << settings.starting_cash << "." << '\n';
        std::cout << "The minimum bet is $" << settings.min_bet << "." << '\n';
        std::cout << "Bets can only be in multiples of $" << settings.bet_increment << "." << '\n';
    }
}