#include "SimplePokerhandEvaluator.h"
#include "StringHelper.h"

#include <stdlib.h>

int const getRank(const string value) {
	string rankString = value.substr(1);
	if (rankString == "J") {
		return 11;
	}
	if (rankString == "Q") {
		return 12;
	}
	if (rankString == "K") {
		return 13;
	}
	if (rankString == "A") {
		return 14;
	}
	return stoi(rankString);
}

bool stringCompare(string left, string right) {
	return getRank(left) < getRank(right);
}

string SimplePokerhandEvaluator::evaluateHand(string hand) {
	vector<string> cards;
	StringHelper::split(hand, cards);
	sort(begin(cards), end(cards), stringCompare);
	return cards.back();
}
