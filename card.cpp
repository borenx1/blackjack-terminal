#include "card.h"
#include <string>

namespace card {
    enum class Value {
        kAce = 1, kTwo, kThree, kFour, kFive, kSix, kSeven, kEight, kNine, kTen, kJack, kQueen, kKing
    };
    enum class Suit {
        kSpades, kHearts, kClubs, kDiamonds
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
            case Value::kAce:
                symbol = 'A';
                break;
            case Value::kTwo:
                symbol = '2';
                break;
            case Value::kThree:
                symbol = '3';
                break;
            case Value::kFour:
                symbol = '4';
                break;
            case Value::kFive:
                symbol = '5';
                break;
            case Value::kSix:
                symbol = '6';
                break;
            case Value::kSeven:
                symbol = '7';
                break;
            case Value::kEight:
                symbol = '8';
                break;
            case Value::kNine:
                symbol = '9';
                break;
            case Value::kTen:
                symbol = 'T';
                break;
            case Value::kJack:
                symbol = 'J';
                break;
            case Value::kQueen:
                symbol = 'Q';
                break;
            case Value::kKing:
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
            case Value::kAce:
                valueString = "Ace";
                break;
            case Value::kTwo:
                valueString = "Two";
                break;
            case Value::kThree:
                valueString = "Three";
                break;
            case Value::kFour:
                valueString = "Four";
                break;
            case Value::kFive:
                valueString = "Five";
                break;
            case Value::kSix:
                valueString = "Six";
                break;
            case Value::kSeven:
                valueString = "Seven";
                break;
            case Value::kEight:
                valueString = "Eight";
                break;
            case Value::kNine:
                valueString = "Nine";
                break;
            case Value::kTen:
                valueString = "Ten";
                break;
            case Value::kJack:
                valueString = "Jack";
                break;
            case Value::kQueen:
                valueString = "Queen";
                break;
            case Value::kKing:
                valueString = "King";
                break;
            default:
                throw "Card value unknown";
        }
        switch (suit) {
            case Suit::kSpades:
                suitString = "Spades";
                break;
            case Suit::kHearts:
                suitString = "Hearts";
                break;
            case Suit::kClubs:
                suitString = "Clubs";
                break;
            case Suit::kDiamonds:
                suitString = "Diamonds";
                break;
            default:
                throw "Card suit unknown";
        }
        name =  valueString + " of " + suitString;
    }
}