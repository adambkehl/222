#include "Blackjack.h"
int main() {
	Blackjack game;
	game.create_deck();
	while (game.check_over()) {
		game.deal_cards();
		game.print_hands();
		game.make_bets();
		game.hit();
		game.check_win();
	}
	cin.get();
	cin.get();
}

Blackjack::Blackjack(){
	current_player = 1;
	deck = new int[DECK];
	cards = new int[NPLAYERS];
	bet = new float[NPLAYERS];
	bread = new float[NPLAYERS];
	players = new int *[NPLAYERS];
	for (int i = 0; i < NPLAYERS; i++)
		players[i] = new int[5];
	for (int i = 0; i < NPLAYERS - 1; i++)
		bread[i] = 10000;
	bread[NPLAYERS - 1] = 10000000;
}

Blackjack::~Blackjack() {
	delete[] deck;
	delete[] cards;
	delete[] bet;
	delete[] bread;
	for (int i = 0; i < NPLAYERS; i++)
		delete[] players[i];
	delete[] players;
}

void Blackjack::create_deck() {
	deck_location = 0; //position in deck
	int num_cards = 0; //loop until this is 52
	int total_cards[14];
	srand(time(0));
	for (int i = 0; i < 14; i++) {
		total_cards[i] = 0;
	}
	while (num_cards < 52) {
		int card = rand() % 13 + 1;
		if (total_cards[card] < 4) {
			deck[num_cards] = card;
			total_cards[card]++;
			num_cards++;
		}
	}
}

void Blackjack::deal_cards() {
	for (int i = 0; i < NPLAYERS; i++) {
		cards[i] = 2;
	}
	for (int i = 0; i < NPLAYERS; i++) {
		for (int j = 0; j < 5; j++) {
			players[i][j] = 0;
		}
	}
	for (int i = 0; i < NPLAYERS; i++) {
		players[i][0] = deck[deck_location];
		deck_location++;
		players[i][1] = deck[deck_location];
		deck_location++;
	}
}

void Blackjack::make_bets() {
	for (int i = 0; i < NPLAYERS - 1; i++) {
		if (bread[i] <= 0) {
			cout << "Sorry, you are out of bread. ";
		} else {
			cout << "Player " << i << ", make your bet: ";
			cin >> bet[i];
		}
	}
}

void Blackjack::print_hands() {
	for (int i = 0; i < NPLAYERS; i++) {
		cout << "Player " << i << endl;
		for (int j = 0; j < cards[i]; j++) {
			cout << players[i][j] << " ";
		}
		cout << endl;
	}
}

void Blackjack::hit() {
	int hitme; //if the player wants to hit
	int cards_in_hand; //
	for (int i = 0; i < NPLAYERS - 1; i++) {
		hitme = 1;
		cards_in_hand = cards[i]; //number of cards (2 on start)
		while (hitme && cards_in_hand < 5) { //couple loop instead of nesting
			print_hands();
			cout << "Hit? (1 = yes, 0 = no)";
			cin >> hitme;
			if (hitme == 1) {
				cards[i]++;
				players[i][cards_in_hand++]++;
				deck_location++;
			}
		}
	}
	int score = 0, num_aces = 0;

	for (int i = 0; i < 2; i++) {
		if (players[NPLAYERS - 1][i] == 1) {
			score += 11;
			num_aces++;
		} else {
			if (players[NPLAYERS-1][i] > 10) {
				score += 10;
			} else {
				score += players[NPLAYERS - 1][i];
			}
		}
	}

	if (score > 21 && num_aces > 0) { //if busted, make an ace 1 instead of 11
		score -= 10;
		num_aces--;
	}

	while (score < 17 && !(score > 21)) { 
		int current_card_value = deck[deck_location];
		deck_location++;
		if (current_card_value == 1) { //if aces
			score += 11;
			num_aces++;
		}
		if (current_card_value > 10) {
			score += 10;
		}
		else {
			score += current_card_value; //else add face value
		}
		if (score > 21 && num_aces > 0) { //if busted and have aces
			num_aces--;
			score -= 10;
		}
		cards[NPLAYERS - 1]++; 
		players[NPLAYERS - 1][cards[NPLAYERS - 1] - 1] = current_card_value;
		if (cards[NPLAYERS - 1] > 4) break; //no more hitting if too many cards
	}//while
	//score = players[NPLAYERS - 1][0] + players[NPLAYERS - 1][1]; //adds first two cards
}//hit

void Blackjack::check_win() {
	int scores[NPLAYERS];
	int num_aces = 0;
	for (int i = 0; i < NPLAYERS; i++) {
		num_aces = 0;
		for (int j = 0; j < cards[i]; j++) {
			if (players[i][j] == 1) {
				num_aces++;
				scores[i] += 11;
			}
			if (players[i][j] > 10) {
				scores[i] += 10;
			} else {
				scores[i] += players[i][j];
			}
			for (int k = 0; k < num_aces; k++) {
				if (scores[i] > 21)
					scores[i] -= 10;
				else break;
			}
		}
	}

	for (int i = 0; i < NPLAYERS - 1; i++) {
		if (scores[i] > 21) payout(i, -bet[i]); //if you bust, you lose
		else if (scores[NPLAYERS - 1] > 21) {//house busts, 
			payout(i, bet[i] * 2);
		}
		else {
			if (scores[i] > scores[NPLAYERS - 1]) {
				payout(i, bet[i] * 2);
			}
			if (scores[i] < scores[NPLAYERS - 1]) {
				payout(i, -bet[i]);
			}
			//tie, do nothing
		}
	}
}

void Blackjack::payout(const int player, const float amount) {
	bread[player] += amount;
}

bool Blackjack::check_over() {
	if (deck_location < 5 * NPLAYERS) return true;
	return false;
}
