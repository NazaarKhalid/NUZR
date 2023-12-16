#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

enum move {
    ROCK = 1, PAPER, SCISSOR
};

move player_choice() {
    int choice;
    cout << "ENTER YOUR MOVE: \n 1 for ROCK \n 2 for PAPER \n 3 for SCISSOR." << endl;
    cin >> choice;
    while (choice > 3 || choice < 1) {
        cout << "Wrong input, please enter:\n 1 for ROCK \n 2 for PAPER \n 3 for SCISSOR." << endl;
        cin >> choice;
    }
    return static_cast<move>(choice);
}

move computer_choice() {
    int choice1 = rand() % 3 + 1;
    return static_cast<move>(choice1);
}

void end_result(move player, move computer, int endResult1[], int rounds) {
    if (player == computer) {
        cout << "Tied\n";
        endResult1[rounds] = 0;
    }
    else if(player == ROCK && computer == SCISSOR){
        cout << "Rock beats scissor, you win\n";
        endResult1[rounds] = 1;
    }
    else if(player == PAPER && computer == ROCK){
        cout << "Paper beats rock, you win\n";
        endResult1[rounds] = 1;
    }
    else if(player == SCISSOR && computer == PAPER){
        cout << "Scissor beats paper, you win\n";
        endResult1[rounds] = 1;
    }
    else {
        cout << "You lose!\n";
        endResult1[rounds] = 2;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    char choice2;
    int maxGames = 10;
    int *ptr_maxGames;
    ptr_maxGames = &maxGames;
    move playerHistory[maxGames];
    move computerHistory[maxGames];
    int endResult1[maxGames];
    int rounds = 0;

    do {
        cout << "ROCK PAPER SCISSOR!" << endl;

        move player, computer;

        player = player_choice();
        computer = computer_choice();

        playerHistory[rounds] = player;
        computerHistory[rounds] = computer;

        end_result(player, computer, endResult1, rounds);
        rounds++;

        cout << "Do you wish to play again?\n Y for yes, N for No" << endl;
        cin >> choice2;
    } while ((choice2 == 'Y' || choice2 == 'y') && rounds < *ptr_maxGames);

    cout << "Rounds: " << endl;
    for (int i = 0; i < rounds; ++i) {
        cout << "Game " << i + 1 << ": Player " << playerHistory[i] << " vs Computer " << computerHistory[i] << " - ";
        if (endResult1[i] == 0) {
            cout << "Tied";
        } else if (endResult1[i] == 1) {
            cout << "YOU WON!";
        } else {
            cout << "COMPUTER WON!";
        }
        cout << endl;
    }

    if (rounds >= *ptr_maxGames) {
        cout << "Maximum games reached. Goodbye, thanks for playing!" << endl;
    } else {
        cout << "Goodbye, thanks for playing!" << endl;
    }

    return 0;
}
