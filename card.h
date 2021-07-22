#ifndef CARD_H
#define CARD_H
#include <string>

namespace card {
    enum class Value {
        kAce = 1, kTwo, kThree, kFour, kFive, kSix, kSeven, kEight, kNine, kTen, kJack, kQueen, kKing
    };
    enum class Suit {
        kSpades, kHearts, kClubs, kDiamonds
    };

    class Card {
        private:
            Value value;
            Suit suit;
        public:
            Card(Value value, Suit suit);
            Value getValue();
            Suit getSuit();
            char getSymbol();
            std::string getName();
    };

    char mapSymbol(Value value);
    std::string mapCardName(Suit suit, Value value);

    class Shoe {
        private:
            unsigned int num_decks;
            // Card cards[52 * 20];
        public:
            Shoe(unsigned int num_decks);
            void refresh();
            void shuffle();
            Card draw();
            int count();
    };
}

#endif