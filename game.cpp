#include <iostream>

using namespace std;

char board[3][3];

void printboard(){
    cout << endl << endl << "TIC TAC TOE"  << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            (board[i][j] != '3')? cout << board[i][j] : cout << ' ';
            (j<2)? cout << " | " : cout << "   ";
        }

        cout << endl;
        if(i<2)
            for(int k=0; k<5; k++){
                cout << "--";
            }

        cout << endl;
    }
    cout << endl;
}

char checkboard(){
    for(int i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '3')
            return board[i][0];
    }

    for(int j=0; j<3; j++){
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '3')
            return board[0][j];

    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '3')
        return board[0][0];

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '3')
        return board[1][1];


    return '2';
}

void userinput(int player){
    int posArr[9]={0}, pos=1, index=0, flag=1;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == '3')
                posArr[index++] = pos;

            pos++;
        }
    }

    do{
        cout << "Player " << player << " enter a position  [";
            
        for(int i=0; i<9; i++){
            if(posArr[i] != 0)
                cout << ' ' << posArr[i];

            if(i<index-1)
              cout  << ',';
        }
        
        cout << "]: ";
        cin >> pos;

        for(int i=0; i<index; i++){
            if(pos == posArr[i]){
                flag = 0;
                break;
            }
            
        }

    } while(flag);

    switch(pos){
        case 1:
            board[0][0] = (player)?'1':'0';
            break;

        case 2:
            board[0][1] = (player)?'1':'0';
            break;

        case 3:
            board[0][2] = (player)?'1':'0';
            break;

        case 4:
            board[1][0] = (player)?'1':'0';
            break;

        case 5:
            board[1][1] = (player)?'1':'0';
            break;

        case 6:
            board[1][2] = (player)?'1':'0';
            break;

        case 7:
            board[2][0] = (player)?'1':'0';
            break;

        case 8:
            board[2][1] = (player)?'1':'0';
            break;

        case 9:
            board[2][2] = (player)?'1':'0';
            break;

    }

}

void initboard(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = '3';
        }
    }
}

int main(){
    initboard();
    char result = '2';
    int player = 0, turns=0;

    cout << "Welcome! Player 0 is \"0\" and player 1 is \"1\"." << endl << "Player 0 goes first." << endl;

    while(result == '2' && turns < 9){
        turns++;
        printboard();
        userinput(player);
        player = !player;
        result = checkboard();
        cout << result;
    }

    printboard();
    switch(result){
        case '0':
            cout << endl << "Player 0 won!" << endl;
            break;

        case '1':
            cout << endl << "Player 1 won!" << endl;
            break;

        case '2':
            cout << endl << "Nobody won!" << endl;
            break;
    }

    return 0;
}
