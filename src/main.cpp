#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Started: 18th of November 2025
// Finished: N/A
// Card Shuffling
// Getting used to CXX: Project 2
// By Jack Vass


struct Card
{
    std::string cardRank;
    std::string cardSuite;
};
//Testing for each hand in it's own function
bool royalFlush   (Card cards[5])   {return false;}
bool straightFlush(Card cards[5])   {return false;}
bool fourKind     (Card cards[5])   {return false;}
bool fullHouse    (Card cards[5])   {return false;}
bool flush        (Card cards[5])   {return false;}
bool straight     (Card cards[5])   {return false;}
bool threeKind    (Card cards[5])   {return false;}
bool twoPair      (Card cards[5])   {return false;}
bool onePair      (Card cards[5])   {return false;}
bool highCard     (Card cards[5])   {return false;}
//Randomly generate cards, could be duplicates
void sorting(int* p, const int col, const int row)
{
    // this replaced col*(row-1)+1, not sure why this works
    int ending = col*(row);
    // the value being sorted is stored every 2 values
    // then i-1's value and i are shifted to j-1's and j's space if it matches up properly
    for (int i = 1; i < ending; i=i+2)
    {
        int vali = *(p+i);
        for (int j = i; j < ending; j=j+2)
        {
            if (*(p+i) < *(p+j))
            {
                int temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }

        }
    }
}
void display(int* p, const int col, const int row)
{
    // wat
    std::string suitArr[4] {"Hearts","Diamonds","Clubs","Spades"};
    std::string cardArr[14] {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

    int *start {p+1}, *end{(p+(col*(row-1))+1)};

    for (int i = 0; i < row; i++)
    {
        std::cout << cardArr[*(p+(1+(i*col)))] << " of " << suitArr[*(p+(i*col))] << std::endl;
    }

}
void cardGenerator(int* p, const int col, const int row)
{
    std::srand(std::time(0));

    for (int i = 0; i < row; i++)
    {
        int randSuit = (std::rand() % 4);
        int randRank = (std::rand() % 13);
        *(p+(1+(i*col))) = randRank;
        *(p+(i*col)) = randSuit;
    }
}

int main (int argc, char *argv[])
{
    //enums don't work as they don't store any actual strings. you'd have to do a switch case
    // It's complex because that's not their intended purpose!

    //Game Greeting
    std::cout << "Let's play some Poker." << '\n';
    std::cout << "You and I will both draw 5 cards, best hand wins." << '\n';
    std::cout << "First to three losses is out." << std::endl;



    int col = 2;
    int row = 5;
    int cards[row][col] {};

    int *p = cards[0];
    cardGenerator(p, col, row);
    std::cout << "Before sorting: " << '\n' << '\n';
    display(p, col, row);

    std::cout << "After sorting: " << '\n' << '\n';
    sorting(p, col, row);
    display(p, col, row);
}