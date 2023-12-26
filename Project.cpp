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
using namespace std;

    char board [3][3]={{'1', '2', '3'}, {'4','5','6'}, {'7', '8', '9'}};
    int row, col;
    char token='x';
    bool tie=false;
    string n1="";
    string n2="";
void display()
{
    
    
    cout<<"   |   |   "<<endl;
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"  "<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"  "<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"  "<<endl;
    cout<<"   |   |   "<<endl;
}

void check(){
    int dig;
    if (token=='x'|| token=='X')
    {
        cout<<n1<<", please enter your choice."<<endl;
        cin>>dig;
    }
    if (token=='o'|| token=='O')
    {
        cout<<n2<<", please enter your choice."<<endl;
        cin>>dig;
    }
    if (dig==1)
    {
        row=0;
        col=0;
    }
    if (dig==2)
    {
        row=0;
        col=1;
    }
    if (dig==3)
    {
        row=0;
        col=2;
    }
    if (dig==4)
    {
        row=1;
        col=0;
    }
    if (dig==5)
    {
        row=1;
        col=1;
    }
    if (dig==6)
    {
        row=1;
        col=2;
    }
    if (dig==7)
    {
        row=2;
        col=0;
    }
    if (dig==8)
    {
        row=2;
        col=1;
    }
    if (dig==9)
    {
        row=2;
        col=2;
    }
    else if (dig<1 || dig>9)
    {cout<<"Invalid input."<<endl;}
    

    if ((token == 'x' || token == 'X') && (board[row][col] != 'x' && board[row][col] != 'X' && board[row][col] != 'o' && board[row][col] != 'O'))
{
    board[row][col] = 'X';
    token = 'O';
} 
else if ((token == 'o' || token == 'O') && (board[row][col] != 'x' && board[row][col] != 'X' && board[row][col] != 'o' && board[row][col] != 'O'))
{
    board[row][col] = 'O';
    token = 'X';
}
    else{cout<<"That space is already filled."<<endl;
    check();}
    
    
}

bool winch(){
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0]==board[i][1] && board[i][0]==board[i][2] || board [0][i]==board[1][i] && board[0][i]==board[2][i])
        {
            return true;
        }
        if (board[0][0]==board[1][1] && board[0][0]==board[2][2] || board [0][2]==board[1][1] && board[1][1]==board[2][0])
        {
            return true;
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
for (int j = 0; j < 3; j++)
{
    if (board[i][j]!='x' || board[i][j]!='X' && board [i][j]!='o' || board[i][j]!='O')
    {
       return false;
    }
    
}
    }
    tie=true;
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
    int dec;
    char cont;

    cout<<"Greetings. It seems you have some free time on your hand! Do you have no friends? Then I would recommend you press 1 to play Rock, Paper, Scissors against the computer!\n Oh? You're lucky enough to have friends? Then press 2 for a player vs player Tic-Tac-Toe experience!"<<endl;
    cout<<"1. Rock, Paper Scissors!"<<endl;
    cout<<"2. Tic-Tac-Toe!"<<endl;
    cin>>dec;
do {

   switch (dec)
   {
   case 1:
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
    
    
    break;
   case 2:  { cout<<"Enter the name of player 1: "<<endl;
    cin>>n1;
    cout<<"Enter the name of player 2: "<<endl;
    cin>>n2;
    cout<<"Player 1, "<<n1<<" goes first."<<endl;
    
    while (!winch())
    {
       display();
       check();
       winch();

    }
    if ((token=='x'|| token=='X')&& tie==false)
    {
        cout<<n2<<" wins."<<endl;
    } else if ((token=='o'|| token=='O')&& tie==false)
    {
        cout<<n1<<" wins."<<endl;
    }
    else {cout<<"It's a draw."<<endl;}
 }
   break;
   default: cout<<"Invalid entry."<<endl;
    break;
   }
   
 

 cout<<"That seems to be the end of that! Would you like to play again?(Y if yes, any other input if no.)"<<endl;
 cin>>cont;
 if (cont=='y' || cont=='Y')
 {
    cout<<"Which game would you like to play this time?"<<endl;
    cout<<"1. Rock, Paper Scissors!"<<endl;
    cout<<"2. Tic-Tac-Toe!"<<endl;
    cin>>dec;
 }
 
} while (cont=='y'||cont=='Y');


    return 0;
}