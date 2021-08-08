#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>

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
            // TODO const arguments
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
            int num_decks;
            std::vector<Card> cards;
        public:
            Shoe(int num_decks = 2);
            /**
             * Refill the shoe with cards and optionally shuffle the deck
             * 
             * @param shuffle Shuffle the shoe after refilling. Defaults to true.
             */
            void refresh(bool shuffle = true);
            void shuffle();
            Card draw();
            Card at(const std::size_t index);
            std::size_t count();
    };
}

#endif