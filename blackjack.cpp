#include "blackjack.h"

#include <iostream>
#include <string>

namespace blackjack {

Blackjack::Blackjack(Settings settings): settings_(settings) {
    initState();
}

void Blackjack::start() {
    // Pre-game setup and messages
    printStartingMessage();
    std::string name;
    std::cout << "Enter your name:" << '\n';
    std::cin >> name;
    std::cout << "Your name is: " << name << '\n';

    // Game loop
    endGame_ = false;
    while (!endGame_) {
        std::cout << "Round " << state_.round << '\n';
        std::string placeholder{};
        std::cin >> placeholder;
        if (placeholder == "quit") {
            endGame_ = true;
        }
        state_.round++;
    }

    // Post-game messages
    std::cout << "Goodbye!" << '\n';
}

void Blackjack::restart() {
    std::cout << '\n' << "New game" << '\n';
    initState();
    start();
}

void Blackjack::initState() {
    // Create new state struct
    State newState{};
    newState.cash = settings_.starting_cash;
    newState.shoe = card::Shoe(settings_.decks);
    state_ = newState;
    // Init shoe
    state_.shoe.refresh();
}

void Blackjack::printStartingMessage() {
    std::cout << "Now playing Blackjack!" << '\n';
    std::cout << "You start with $" << settings_.starting_cash << "." << '\n';
    std::cout << "The minimum bet is $" << settings_.min_bet << "." << '\n';
    std::cout << "Bets can only be in multiples of $" << settings_.bet_increment << "." << '\n';
}

}