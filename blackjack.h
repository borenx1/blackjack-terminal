#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "card.h"
#include <string>
#include <vector>

namespace blackjack {

struct Settings {
    double starting_cash{1000};
    double min_bet{10};
    double bet_increment{1};
    int decks{4};
};

struct State {
    int round{1};
    double cash{};
    std::vector<card::Card> hand{};
    card::Shoe shoe{};
};

class Blackjack {
    private:
        bool endGame_{ true };
        Settings settings_;
        State state_;
    protected:
        void initState();
        void printStartingMessage();
    public:
        Blackjack(Settings settings = Settings{});
        /**
         * The main function to run the game. Calling this function will play
         * the game on a loop until the game is ended.
         */
        void start();
        void restart();
};

}

#endif