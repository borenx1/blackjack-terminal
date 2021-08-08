#include "blackjack.h"
#include <iostream>
#include <string>

namespace blackjack {
    Blackjack::Blackjack() {
        initState();
    };
    Blackjack::Blackjack(Settings settings): settings(settings) {
        initState();
    }
    void Blackjack::start() {
        printStartingMessage();
        std::string name;
        std::cout << "Enter your name:" << '\n';
        std::cin >> name;
        std::cout << "Your name is: " << name << '\n';
    }
    void Blackjack::restart() {
        std::cout << '\n' << "New game" << '\n';
        initState();
        start();
    }
    void Blackjack::initState() {
        // Create new state struct
        State newState{};
        newState.cash = settings.starting_cash;
        newState.shoe = card::Shoe(settings.decks);
        state = newState;
        // Init shoe
        state.shoe.refresh();
    }
    void Blackjack::printStartingMessage() {
        std::cout << "Now playing Blackjack!" << '\n';
        std::cout << "You start with $" << settings.starting_cash << "." << '\n';
        std::cout << "The minimum bet is $" << settings.min_bet << "." << '\n';
        std::cout << "Bets can only be in multiples of $" << settings.bet_increment << "." << '\n';
    }
}