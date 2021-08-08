#include "card.h"
#include <iostream>

namespace card {
    Card::Card(Rank rank, Suit suit): rank(rank), suit(suit) {}

    Rank Card::getRank() {
        return rank;
    }

    Suit Card::getSuit() {
        return suit;
    }

    char Card::getSymbol() {
        return mapSymbol(rank);
    }

    std::string Card::getName() {
        return mapCardName(suit, rank);
    }

    char mapSymbol(Rank rank) {
        switch (rank) {
            case Rank::kAce:
                return 'A';
            case Rank::kTwo:
                return '2';
            case Rank::kThree:
                return '3';
            case Rank::kFour:
                return '4';
            case Rank::kFive:
                return '5';
            case Rank::kSix:
                return '6';
            case Rank::kSeven:
                return '7';
            case Rank::kEight:
                return '8';
            case Rank::kNine:
                return '9';
            case Rank::kTen:
                return 'T';
            case Rank::kJack:
                return 'J';
            case Rank::kQueen:
                return 'Q';
            case Rank::kKing:
                return 'K';
            default:
                throw "Card rank unknown";
        }
    }

    std::string mapCardName(Suit suit, Rank rank) {
        std::string rankString;
        std::string suitString;
        switch (rank) {
            case Rank::kAce:
                rankString = "Ace";
                break;
            case Rank::kTwo:
                rankString = "Two";
                break;
            case Rank::kThree:
                rankString = "Three";
                break;
            case Rank::kFour:
                rankString = "Four";
                break;
            case Rank::kFive:
                rankString = "Five";
                break;
            case Rank::kSix:
                rankString = "Six";
                break;
            case Rank::kSeven:
                rankString = "Seven";
                break;
            case Rank::kEight:
                rankString = "Eight";
                break;
            case Rank::kNine:
                rankString = "Nine";
                break;
            case Rank::kTen:
                rankString = "Ten";
                break;
            case Rank::kJack:
                rankString = "Jack";
                break;
            case Rank::kQueen:
                rankString = "Queen";
                break;
            case Rank::kKing:
                rankString = "King";
                break;
            default:
                throw "Card rank unknown";
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
        return rankString + " of " + suitString;
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
                    // TODO fill deck
                    // cards.push_back(Card(static_cast<Value>(rank), suit));
                    cards.push_back(Card(Rank::kAce, suit));
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
        return Card(Rank::kAce, Suit::kSpades);
    }

    Card Shoe::at(const std::size_t index) {
        return cards.at(index);
    }

    std::size_t Shoe::count() {
        return cards.size();
    };
}