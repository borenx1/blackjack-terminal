#include "blackjack.h"

#include <iostream>
#include <string>

namespace blackjack {

Blackjack::Blackjack(Settings settings) : settings_(settings) {}

void Blackjack::start() {
    // Pre-game setup and messages
    printStartingMessage();
    generateSettings();
    initState();

    // Game loop
    endGame_ = false;
    while (!endGame_) {
        std::cout << "Round " << state_.round << '\n';
        std::string placeholder{};
        std::cin >> placeholder;
        if (placeholder == "quit") {
            endGame_ = true;
        } else if (placeholder == "settings" || placeholder == "setting") {
            displaySettings();
        } else {
            state_.round++;
        }
    }

    // Post-game messages
    printEndingMessage();
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
}

void Blackjack::printEndingMessage() {
    std::cout << "Goodbye!" << '\n';
}

void Blackjack::generateSettings() {
    // Init settings to default.
    Settings settings{};
    // Get settings from user input.
    std::cout << "Set the minimum bet ($) (Defaults to " << settings.min_bet << "):" << '\n';
    std::cout << "Set the bet increment ($) (Defaults to " << settings.bet_increment << "):" << '\n';
    std::cout << "Set the starting cash ($) (Defaults to " << settings.starting_cash << "):" << '\n';
    std::cout << "Set the number of decks to use (1 - 20) (Defaults to " << settings.decks << "):" << '\n';
}

void Blackjack::displaySettings() {
    std::cout << "You start with $" << settings_.starting_cash << "." << '\n';
    std::cout << "The minimum bet is $" << settings_.min_bet << "." << '\n';
    std::cout << "Bets can only be in multiples of $" << settings_.bet_increment << "." << '\n';
    std::cout << "The shoe consists of " << settings_.decks << " decks." << '\n';
}

}