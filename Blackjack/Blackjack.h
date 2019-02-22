#include <iostream>
#include <stdlib.h>
#include <time.h>
#define DECK 52
#define NPLAYERS 2
using namespace std;

class Blackjack {
private:
	int *deck;
	int *cards;
	int **players;
	float *bet;
	float *bread;
	int current_player;
	int deck_location = DECK;
public:
	Blackjack();
	~Blackjack();
	void create_deck();
	void deal_cards();
	void make_bets();
	void hit();
	void print_hands();
	void check_win();
	void payout(const int player, const float amount);
	bool check_over();
};
