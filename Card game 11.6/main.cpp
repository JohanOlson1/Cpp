#include <iostream>
#include <array>		// std::array
#include <algorithm>	// std::shuffle
#include <ctime>		// std::time
#include <random>		// To seed shuffle for random shuffling 

//// Program defined types ----------------------------

enum class BlackjackResult
{
	player_win,
	dealer_win,
	tie
};

enum class cardRank
{
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,

	max_ranks
};

enum class cardSuit
{
	club,
	heart,
	diamond,
	spade,

	max_suits
};

struct Card
{
	cardRank rank{};
	cardSuit suit{};
};

// ---------------------------------------------------

// Make syntax easier using some aliases
using Deck = std::array<Card, 52>;
using Index = Deck::size_type;

//// Functions ---------------------------------------
 
// Print out an individual card
void printCard(const Card& card)
{
	// Print rank first
	switch (card.rank)
	{
		case cardRank::Two:		std::cout << '2';  break;
		case cardRank::Three:	std::cout << '3';  break;
		case cardRank::Four:	std::cout << '4';  break;
		case cardRank::Five:	std::cout << '5';  break;
		case cardRank::Six:		std::cout << '6';  break;
		case cardRank::Seven:	std::cout << '7';  break;
		case cardRank::Eight:	std::cout << '8';  break;
		case cardRank::Nine:	std::cout << '9';  break;
		case cardRank::Ten:		std::cout << 'T';  break;
		case cardRank::Jack:	std::cout << 'J';  break;
		case cardRank::Queen:	std::cout << 'Q';  break;
		case cardRank::King:	std::cout << 'K';  break;
		case cardRank::Ace:		std::cout << 'A';  break;
		default:				std::cout << '?';  break;
	}

	// Print suit second
	switch (card.suit)
	{
	case cardSuit::club:		std::cout << 'C';  break;
	case cardSuit::heart:		std::cout << 'H';  break;
	case cardSuit::diamond:		std::cout << 'D';  break;
	case cardSuit::spade:		std::cout << 'S';  break;
	default:					std::cout << '?';  break;
	}
}

// Create and return a deck of 52 cards
Deck createDeck()
{
	Deck deck{};
	// Loop to create all cards
	Index index{ 0 }; // in order to go through each card, Index makes sure correct type of iterator
	for (int suit{ 0 }; suit < static_cast<int>(cardSuit::max_suits); ++suit)
	{
		for (int rank{ 0 }; rank < static_cast<int>(cardRank::max_ranks); ++rank)
		{
			deck[index].suit = static_cast<cardSuit>(suit);
			deck[index].rank = static_cast<cardRank>(rank);
			++index;
		}
	}
	return deck;
}

// Print out whole deck
void printDeck(const Deck& deck)
{
	for (const Card& card : deck)
	{
		printCard(card);
		std::cout << ' '; 		// Add a blankspace between cards
	}
	std::cout << '\n';
}

// We don't use const argument since we want to change the array/deck by shuffling
void shuffleDeck(Deck& deck)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) }; // Random seed
	std::shuffle(deck.begin(), deck.end(), mt);									   // Shuffle deck, since an array, no need to return
}

// Output the value of a card
int getCardValue(const Card& card)
{
	// Add 2 since we start with index 0 which corresponds to card rank 2
	int value{ static_cast<int>(card.rank) + 2 };

	// Recast values, Ten, Jack, Queen and King worth 10, Ace worth 11
	if (14 > value && value > 10)
		value = 10;
	else if (value == 14)
		value = 11;

	return value;
}
// ---------------------------------------------------

//// Black Jack Functions ----------------------------

// Maximum score before losing.
constexpr int g_maximumScore{ 21 };

// Minimum score that the dealer has to have.
constexpr int g_dealerLimit{ 17 };

// Use references to manipulate score and cardCount, updating them after card is drawn
void drawCardBlackJack(const Deck& deck, int& score, int& cardCount)
{
	// Draw a card and print it
	std::cout << "Draws: ";
	printCard(deck[cardCount]);
	// Store its value
	int cardValue{ getCardValue(deck[cardCount]) };
	// Increase the score by the value
	score += cardValue;
	std::cout << '\n' << "Score is: " << score << '\n' << '\n';
	++cardCount;
}

// Use references to manipulate the scores and cardCount, updating them after card is drawn
void dealBlackJack(const Deck& deck, int& playerScore, int& dealerScore, int& cardCount)
{
	// Dealer draws a card first
	std::cout << "Dealers turn: " << '\n';
	drawCardBlackJack(deck, dealerScore, cardCount);
	// Player next, two cards
	std::cout << "Players turn: " << '\n';
	drawCardBlackJack(deck, playerScore, cardCount);
	drawCardBlackJack(deck, playerScore, cardCount);
}

// Ask player for a decision whether to hit or stand
bool playerDecision(const Deck& deck, int& score, int& cardCount)
{
	char answer{};
	std::cout << "Do you wish to hit? (y/n): ";
	std::cin >> answer; 

	switch (answer)
	{
	case 'y': drawCardBlackJack(deck, score, cardCount); return true;
	default:  std::cout << "Player stands \n"; 			 return false;
	}
}

// Ask dealer for a decision whether to hit or stand
bool dealerDecision(const Deck& deck, int& score, int& cardCount)
{
	// Dealer only hits if score is below g_dealerLimit (stop limit), otherwise stands
	if (score < g_dealerLimit)
	{
		std::cout << "Dealer Hits \n";
		drawCardBlackJack(deck, score, cardCount);
	}
	else
	{
		std::cout << "Dealer stands \n";
		return false;
	}

	}

// Runs an entire round of back jack
// Returns true: Player won round
// Returns false: Player lost round
BlackjackResult playBlackJack(const Deck& deck)
{
	int playerScore{ 0 };		// Track Player score
	int dealerScore{ 0 };		// Track Dealer score
	int cardCount{ 0 };			// Track card in deck
	bool playerHits{ true };	// No choice in startup, can choose to stand afterwards
	bool dealerHits{ true };	// No choice in startup, can choose to stand afterwards

	// Call start-up function for Black Jack
	dealBlackJack(deck, playerScore, dealerScore, cardCount);

	// Keep playing deals until something happens
	while (true)
	{
		// Player decides first, if not already standing
		if (playerHits)
		{
			playerHits = playerDecision(deck, playerScore, cardCount);
			if (playerScore > g_maximumScore) return BlackjackResult::dealer_win; // if player is over max score, dealer wins
		}

		// Dealer decides next, if not already standing
		if (dealerHits)
		{
			dealerHits = dealerDecision(deck, dealerScore, cardCount);
			if (dealerScore > g_maximumScore) return BlackjackResult::player_win; // if dealer is over max score, player wins
		}

		// If both stands, check score to see who won
		if (!playerHits && !dealerHits) 
		{
			std::cout << "Both standing \n";
			std::cout << "Player score is: " << playerScore << '\n';
			std::cout << "Dealer score is: " << dealerScore << '\n';

			if (playerScore > dealerScore)			
				return BlackjackResult::player_win;
			else if (playerScore == dealerScore)	
				return BlackjackResult::tie;
			else									
				return BlackjackResult::dealer_win;							
		}
	}
}

// --------------------------------------------------

int main()
{
	// Create a deck
	Deck deck{ createDeck() };

	// Shuffle the deck, 
	shuffleDeck(deck);

	// Print out the deck in order
	//printDeck(deck);

	// play a round of black jack
	switch (playBlackJack(deck))
	{
	case BlackjackResult::player_win: std::cout << "You win\n";		break;
	case BlackjackResult::dealer_win: std::cout << "You lose\n";	break;
	case BlackjackResult::tie:		  std::cout << "Tie\n";			break;
	}
	return 0;
}