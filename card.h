#ifndef CARD_H
#define CARD_H
#include <string>

namespace card {
    enum class Value;
    enum class Suit;

    class Card {
        private:
            Value value;
            Suit suit;
            char symbol;
            std::string name;
        protected:
            void setSymbol();
            void setName();
        public:
            Card(Value value, Suit suit);
            Value getValue();
            Suit getSuit();
            char getSymbol();
            std::string getName();
    };
}

#endif