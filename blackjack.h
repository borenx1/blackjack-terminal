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
        int round{};
        double cash{};
        std::vector<card::Card> hand{};
        card::Shoe shoe;
    };

    class Blackjack {
        private:
            Settings settings;
        protected:
            void printStartingMessage();
        public:
            Blackjack();
            Blackjack(Settings settings);
            void start();
    };
}

#endif