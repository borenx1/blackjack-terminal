#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "card.h"
#include <iostream>
#include <string>

namespace blackjack {
    struct GameSettings {
        double starting_cash;
        double min_bet;
        double bet_increment;
        unsigned int decks;
        GameSettings(double starting_cash = 1000, double min_bet = 10, double bet_increment = 1, unsigned int decks = 4);
    };

    struct State {
        unsigned int round;
        int cash;
        card::Card hand[20];
        card::Card deck[52 * 20];
    };

    class Blackjack {
        private:
            GameSettings settings;
        protected:
            void printStartingMessage();
        public:
            Blackjack();
            Blackjack(GameSettings settings);
            void start();
    };
}

#endif