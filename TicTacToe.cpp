#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int number = 1;
char board[9]={'1','2','3','4','5','6','7','8','9'};
bool Status = false;
int a,b;
string player1,player2;
int choice1,choice2;
int turns=0;

void display();
void welcome();
void TakeNames();
void Info();
void win();
void tie();
void Input1();
void Input2();

int main() {
    welcome();
    TakeNames();
    Info();
    while (number!=0){
        if (Status==false){
            Input1();
        }
        else{
            break;
        }
        if (Status==false){
            Input2();
        }
        else{
            break;
        }
    }

    cout<<endl;
    if(turns!=9){
        if (turns%2==1){
            if (a==1){
                cout<<player1<<" wins the Game";
            }
            else{
                cout<<player2<<" wins the Game";
            }
        }
        else{
            if (a==0){
                cout<<player2<<" wins the Game";
            }
            else{
                cout<<player1<<" wins the Game";
            }
        }

    }

    cout<<endl<<"Game Over!!";
}



void display(){
    cout<<" "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<endl;
}

void welcome(){
    cout<<endl<< "Welcome to the TicTacToe game!!"<<endl<<endl;
    display();
}

void TakeNames(){
    cout<<endl<<"Enter Player1's Name: ";
    cin>>player1;
    cout<<"Enter Player2's Name: ";
    cin>>player2;
    cout<<endl;
    display();
}

void Info(){
    srand(time(0)); 
    a = rand()%2;
    if(a==0){
        b=1;
    }
    else{
        b=0;
    }
}

void win(){
    if ((board[0]==board[1])&&(board[0]==board[2])){
        Status = true;
    }
    else if ((board[3]==board[4])&&(board[3]==board[5])){
        Status = true;
    }
    else if ((board[6]==board[7])&&(board[6]==board[8])){
        Status = true;
    }
    else if ((board[0]==board[3])&&(board[0]==board[6])){
        Status = true;
    }
    else if ((board[1]==board[4])&&(board[1]==board[7])){
        Status = true;
    }
    else if ((board[2]==board[5])&&(board[2]==board[8])){
        Status = true;
    }
    else if ((board[0]==board[4])&&(board[0]==board[8])){
        Status = true;
    }
    else if ((board[2]==board[4])&&(board[2]==board[6])){
        Status = true;
    }
}

void tie(){
    number=0;
    for (int i=0;i<9;i++){
        if ((board[i]!='X')&&(board[i]!='O')){
            number++;
        }
    }
    if (number == 0){
        Status = true;
        cout <<endl<< "It's a tie!! Nobody wins the game";
    }
}

void Input1(){
    redo:
        if (b==1){
            cout<<endl<<player2<<", Enter Your Choice: ";
            cin>>choice1;
        }
        else if (a==1){
            cout<<endl<<player1<<", Enter Your Choice: ";
            cin>>choice1;
        }
    if ((choice1 != 1) && (choice1 != 2) && (choice1 != 3) && (choice1 != 4) && (choice1 != 5) && (choice1 != 6) && (choice1 != 7) && (choice1 != 8) && (choice1 != 9)){
        cout<<"Enter a valid Choice";
        goto redo;
    }
    cout<<endl;
    board[choice1-1]='X';
    display();
    win();
    tie();
    turns++;
}

void Input2(){
    redo:
        if (b==0){
            cout<<endl<<player2<<", Enter Your Choice: ";
            cin>>choice2;
        }
        else if (a==0){
            cout<<endl<<player1<<", Enter Your Choice: ";
            cin>>choice2;
        }
    if ((choice2 != 1) && (choice2 != 2) && (choice2 != 3) && (choice2 != 4) && (choice2 != 5) && (choice2 != 6) && (choice2 != 7) && (choice2 != 8) && (choice2 != 9)){
        cout<<"Enter a valid Choice";
        goto redo;
    }
    cout<<endl;
    board[choice2-1]='O';
    display();
    win();
    turns++;
}
