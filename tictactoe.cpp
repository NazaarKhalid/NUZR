#include<iostream>
#include<string>
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
    

    if ((token=='x'||token=='X') && (board[row][col]!='x' ||board[row][col]!='X') && (board[row][col]!='o' ||board[row][col]!='O'))
    {
        board[row][col]='X';
        token='O';
    } 
    else if ((token=='o'||token=='O') && (board[row][col]!='x' ||board[row][col]!='X') && (board[row][col]!='o' ||board[row][col]!='O'))
    {
        board[row][col]='O';
        token='X';
    }
    else{cout<<"That space is already filled."<<endl;
    check();}
    display();
    
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
int main()
{
    cout<<"Enter the name of player 1: "<<endl;
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