#include "card.h"
#include <string>

namespace card {
    enum class Value {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    };
    enum class Suit {
        SPADES, HEARTS, CLUBS, DIAMONDS
    };

    Card::Card(Value value, Suit suit): value(value), suit(suit) {
        setSymbol();
        setName();
    }
    Value Card::getValue() {
        return value;
    }
    Suit Card::getSuit() {
        return suit;
    }
    char Card::getSymbol() {
        return symbol;
    }
    std::string Card::getName() {
        return name;
    }
    void Card::setSymbol() {
        switch (value) {
            case Value::ACE:
                symbol = 'A';
                break;
            case Value::TWO:
                symbol = '2';
                break;
            case Value::THREE:
                symbol = '3';
                break;
            case Value::FOUR:
                symbol = '4';
                break;
            case Value::FIVE:
                symbol = '5';
                break;
            case Value::SIX:
                symbol = '6';
                break;
            case Value::SEVEN:
                symbol = '7';
                break;
            case Value::EIGHT:
                symbol = '8';
                break;
            case Value::NINE:
                symbol = '9';
                break;
            case Value::TEN:
                symbol = 'T';
                break;
            case Value::JACK:
                symbol = 'J';
                break;
            case Value::QUEEN:
                symbol = 'Q';
                break;
            case Value::KING:
                symbol = 'K';
                break;
            default:
                throw "Card value unknown";
        }
    }
    void Card::setName() {
        std::string valueString;
        std::string suitString;
        switch (value) {
            case Value::ACE:
                valueString = "Ace";
                break;
            case Value::TWO:
                valueString = "Two";
                break;
            case Value::THREE:
                valueString = "Three";
                break;
            case Value::FOUR:
                valueString = "Four";
                break;
            case Value::FIVE:
                valueString = "Five";
                break;
            case Value::SIX:
                valueString = "Six";
                break;
            case Value::SEVEN:
                valueString = "Seven";
                break;
            case Value::EIGHT:
                valueString = "Eight";
                break;
            case Value::NINE:
                valueString = "Nine";
                break;
            case Value::TEN:
                valueString = "Ten";
                break;
            case Value::JACK:
                valueString = "Jack";
                break;
            case Value::QUEEN:
                valueString = "Queen";
                break;
            case Value::KING:
                valueString = "King";
                break;
            default:
                throw "Card value unknown";
        }
        switch (suit) {
            case Suit::SPADES:
                suitString = "Spades";
                break;
            case Suit::HEARTS:
                suitString = "Hearts";
                break;
            case Suit::CLUBS:
                suitString = "Clubs";
                break;
            case Suit::DIAMONDS:
                suitString = "Diamonds";
                break;
            default:
                throw "Card suit unknown";
        }
        name =  valueString + " of " + suitString;
    }
}