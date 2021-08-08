#include "card.h"
#include <iostream>

namespace card {
    Card::Card(Value value, Suit suit): value(value), suit(suit) {}

    Value Card::getValue() {
        return value;
    }

    Suit Card::getSuit() {
        return suit;
    }

    char Card::getSymbol() {
        return mapSymbol(value);
    }

    std::string Card::getName() {
        return mapCardName(suit, value);
    }

    char mapSymbol(Value value) {
        switch (value) {
            case Value::kAce:
                return 'A';
            case Value::kTwo:
                return '2';
            case Value::kThree:
                return '3';
            case Value::kFour:
                return '4';
            case Value::kFive:
                return '5';
            case Value::kSix:
                return '6';
            case Value::kSeven:
                return '7';
            case Value::kEight:
                return '8';
            case Value::kNine:
                return '9';
            case Value::kTen:
                return 'T';
            case Value::kJack:
                return 'J';
            case Value::kQueen:
                return 'Q';
            case Value::kKing:
                return 'K';
            default:
                throw "Card value unknown";
        }
    }

    std::string mapCardName(Suit suit, Value value) {
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
        return valueString + " of " + suitString;
    }

    Shoe::Shoe(int num_decks): num_decks(num_decks) {
        if (num_decks < 1) {
            throw "Number of decks in shoe must be greater than 0";
        }
    }

    void Shoe::refresh(bool shuffle) {
        cards = {};
        for (int i = 0; i < num_decks; i++) {
            for (const auto& suit : {Suit::kSpades, Suit::kHearts, Suit::kClubs, Suit::kDiamonds}) {
                for (int rank = 1; rank <= 13; rank++) {
                    // cards.push_back(Card(static_cast<Value>(rank), suit));
                    cards.push_back(Card(Value::kAce, suit));
                }
            }
        }
        if (shuffle) {
            this->shuffle();
        }
    }

    void Shoe::shuffle() {
        std::cout << "Shuffle" << '\n';
    }

    Card Shoe::draw() {
        std::cout << "Draw" << '\n';
        return Card(Value::kAce, Suit::kSpades);
    }

    Card Shoe::at(const std::size_t index) {
        return cards.at(index);
    }

    std::size_t Shoe::count() {
        return cards.size();
    };
}