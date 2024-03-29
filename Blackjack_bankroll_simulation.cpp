/*
----------------------------------
Wining a game: 49,5% 99/200 65637/132600
Blackjack: 32/663 6400/132600
----------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
vector<string> blackjack_game;

void start_rand() {
	timespec a;
	auto l = timespec_get(&a, TIME_UTC);
	srand(a.tv_nsec);
	return;
}

int simulation(float bankroll, int amount_of_bet, int amount_of_hands) {
	for (int i = 0; i < amount_of_hands; ++i) {
		int number = (rand() * rand()) % 132600;
		if (blackjack_game[number] == "bj") {
			bankroll += 3 / 2 * amount_of_bet;
		}
		else if (blackjack_game[number] == "w") {
			bankroll += amount_of_bet;
		}
		else {
			bankroll -= amount_of_bet;
		}
	}
	return bankroll;
}

int main() {
	start_rand();
	for (int i = 0; i < 132600; ++i) {
		if (i < 6400) {
			blackjack_game.push_back("bj");
		}
		else if (i < 65637) {
			blackjack_game.push_back("w");
		}
		else {
			blackjack_game.push_back("l");
		}
	}
	float bankroll;
	int amount_of_bet;
	int amount_of_hands;
	cout << "Welcome to the simulation of perfect strategy BJ!!!!!\n";
	cout << "Bankroll: ";
	cin >> bankroll;
	cout << "Amount of bet: ";
	cin >> amount_of_bet;
	cout << "How many hands?: ";
	cin >> amount_of_hands;

	cout << "The final bankroll is: " << simulation(bankroll, amount_of_bet, amount_of_hands) << "\n";
	system("pause");
	return 0;
}