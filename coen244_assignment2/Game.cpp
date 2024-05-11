#include "Player.h"
#include "Board.h"
#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;

Game::Game(Player p1, Player p2): first(p1), second(p2), board("") {
    p1 = first;
    p2 = second;
}

void Game::start() {

    bool isSavedGame = false;
    string name1;
    string name2;
    Position black;
    Position white;
    black.setPiece(Position::BLACK);
    white.setPiece(Position::WHITE);

    cout << "Please type the first player's name:\n";
    cin >> name1;
    first.setName(name1);

    cout << "Please type the second player's name:\n";
    cin >> name2;
    second.setName(name2);

    cout << "Welcome, " << first.getName() << " and " << second.getName() << "!\n";

    cout << first.getName() << ": Black" << endl;
    cout << second.getName() << ": White" << endl;
    cout << "The '*' symbol means that the move is unplayable (you cannot put any pieces there)." << endl;
    cout << "Watch out! If the move you input is invalid, you will lose the turn.";
    first.setPiece(black);
    second.setPiece(white);

    Game game(first, second);

    game.play(isSavedGame);

}

void Game::play(bool isSavedGame) {

    if (!isSavedGame) {
        if (board.setBoard()) {
            first.setPieceCount(2);
            second.setPieceCount(2);
        } else {
            first.setPieceCount(8);
            second.setPieceCount(8);
        }
    }
    board.drawBoard();
    while (makeMove()) {
        takeTurn();
        board.drawBoard();
    }

}

bool Game::makeMove() {
    int row;
    int column;
    int choice;
    bool tryAgain = true;
    Position black;
    Position white;
    Position empty;
    Position unplayable;
    Position oppositePiece;
    Position currentPiece;
    black.setPiece(Position::BLACK);
    white.setPiece(Position::WHITE);
    empty.setPiece(Position::EMPTY);
    unplayable.setPiece(Position::UNPLAYABLE);
    if (current == &first) {
        currentPiece.setPiece(Position::BLACK);
        oppositePiece.setPiece(Position::WHITE);
    } else if (current == &second) {                    //Set the oppositePiece piece
        currentPiece.setPiece(Position::WHITE);
        oppositePiece.setPiece(Position::BLACK);
    }

    cout << first.getName() << " has :" << first.getPieceCount() << " pieces." << endl;
    cout << second.getName() << " has :" << second.getPieceCount() << " pieces." << endl;

    cout << "It's " << current->getName() << "'s turn:" << endl;
    cout << "Choose one of these 5 options:\n"
            "1. Make a move (make sure your move is valid)\n"
            "2. Save\n"
            "3. Concede (concede if no moves are available)\n"
            "4. Skip the turn\n"
            "5. End the game (player with the most pieces wins)\n";

    while (tryAgain) {

    cin >> choice;

    switch (choice) {

        case 1: {

            cout << "Choose a row from 0 to 7" << endl;
            cin >> row;
            cout << "Choose a column from 0 to 7" << endl;
            cin >> column;

            if (board.getBoardPosition(row, column) == empty.getPiece()) {  //Check if it's an empty space

                if (board.getBoardPosition(row, column + 1) == oppositePiece.getPiece()) {     //Right     (Check adjacent spaces)
                    for (int i = column + 1; i < 8; i++) {
                        if (board.getBoardPosition(row, i) == empty.getPiece()) {
                            break;
                        }
                        if (board.getBoardPosition(row, i) == currentPiece.getPiece()) {
                            for (int j = column + 1; j < i; j++) {
                                if (board.getBoardPosition(row, column) == empty.getPiece()) {
                                    current->setPieceCount(current->getPieceCount() + 1);
                                }
                                board.setBoardPosition(row, column, currentPiece);
                                flipPieces(currentPiece, row, j);
                            }
                            break;
                        }
                    }
                }
                if (board.getBoardPosition(row, column - 1) == oppositePiece.getPiece()) {     //Left
                    for (int i = column - 1; i > 0; i--) {
                        if (board.getBoardPosition(row, i) == empty.getPiece()) {
                            break;
                        }
                        if (board.getBoardPosition(row, i) == currentPiece.getPiece()) {
                            for (int j = column - 1; j > i; j--) {
                                if (board.getBoardPosition(row, column) == empty.getPiece()) {
                                    current->setPieceCount(current->getPieceCount() + 1);
                                }
                                board.setBoardPosition(row, column, currentPiece);
                                flipPieces(currentPiece, row, j);
                            }
                            break;
                        }
                    }
                }
                if (board.getBoardPosition(row + 1, column) == oppositePiece.getPiece()) {     //Down
                    for (int i = row + 1; i < 8; i++) {
                        if (board.getBoardPosition(i, column) == empty.getPiece()) {
                            break;
                        }
                        if (board.getBoardPosition(i, column) == currentPiece.getPiece()) {
                            for (int j = row + 1; j < i; j++) {
                                if (board.getBoardPosition(row, column) == empty.getPiece()) {
                                    current->setPieceCount(current->getPieceCount() + 1);
                                }
                                board.setBoardPosition(row, column, currentPiece);
                                flipPieces(currentPiece, j, column);
                            }
                            break;
                        }
                    }
                }
                if (board.getBoardPosition(row - 1, column) == oppositePiece.getPiece()) {     //Up
                    for (int i = row - 1; i > 0; i--) {
                        if (board.getBoardPosition(i, column) == empty.getPiece()) {
                            break;
                        }
                        if (board.getBoardPosition(i, column) == currentPiece.getPiece()) {
                            for (int j = row - 1; j > i; j--) {
                                if (board.getBoardPosition(row, column) == empty.getPiece()) {
                                    current->setPieceCount(current->getPieceCount() + 1);
                                }
                                board.setBoardPosition(row, column, currentPiece);
                                flipPieces(currentPiece, j, column);
                            }
                            break;
                        }
                    }
                }
                if (board.getBoardPosition(row + 1, column + 1) == oppositePiece.getPiece()) {   //Down-Right
                    int x = 1;
                    for (int i = row + 1; i < 8; i++) {
                        int j = column + x++;
                        if (board.getBoardPosition(i, j) == empty.getPiece()) {
                            break;
                        }
                        if (board.getBoardPosition(i, j) == currentPiece.getPiece()) {
                            int y = 1;
                            for (int k = row + 1; k < i; k++) {
                                j = column + y++;
                                if (board.getBoardPosition(row, column) == empty.getPiece()) {
                                    current->setPieceCount(current->getPieceCount() + 1);
                                }
                                board.setBoardPosition(row, column, currentPiece);
                                flipPieces(currentPiece, k, j);
                            }
                            break;
                        }
                    }
                }
                if (board.getBoardPosition(row + 1, column - 1) == oppositePiece.getPiece()) {   //Down-Left
                    int x = -1;
                    for (int i = row + 1; i < 8; i++) {
                        int j = column + x--;
                        if (board.getBoardPosition(i, j) == empty.getPiece()) {
                            break;
                        }
                        if (board.getBoardPosition(i, j) == currentPiece.getPiece()) {
                            int y = -1;
                            for (int k = row + 1; k < i; k++) {
                                j = column + y--;
                                if (board.getBoardPosition(row, column) == empty.getPiece()) {
                                    current->setPieceCount(current->getPieceCount() + 1);
                                }
                                board.setBoardPosition(row, column, currentPiece);
                                flipPieces(currentPiece, k, j);
                            }
                            break;
                        }
                    }
                }
                if (board.getBoardPosition(row - 1, column + 1) == oppositePiece.getPiece()) {   //Up-Right
                    int x = 1;
                    for (int i = row - 1; i > 0; i--) {
                        int j = column + x++;
                        if (board.getBoardPosition(i, j) == empty.getPiece()) {
                            break;
                        }
                        if (board.getBoardPosition(i, j) == currentPiece.getPiece()) {
                            int y = 1;
                            for (int k = row - 1; k > i; k--) {
                                j = column + y++;
                                if (board.getBoardPosition(row, column) == empty.getPiece()) {
                                    current->setPieceCount(current->getPieceCount() + 1);
                                }
                                board.setBoardPosition(row, column, currentPiece);
                                flipPieces(currentPiece, k, j);
                            }
                            break;
                        }
                    }
                }
                if (board.getBoardPosition(row - 1, column - 1) == oppositePiece.getPiece()) {   //Up-Left
                    int x = -1;
                    for (int i = row - 1; i > 0; i--) {
                        int j = column + x--;
                        if (board.getBoardPosition(i, j) == empty.getPiece()) {
                            break;
                        }
                        if (board.getBoardPosition(i, j) == currentPiece.getPiece()) {
                            int y = -1;
                            for (int k = row - 1; k > i; k--) {
                                j = column + y--;
                                board.setBoardPosition(row, column, currentPiece);
                                if (board.getBoardPosition(row, column) == empty.getPiece()) {
                                    current->setPieceCount(current->getPieceCount() + 1);
                                }
                                board.setBoardPosition(row, column, currentPiece);
                                flipPieces(currentPiece, k, j);
                            }
                            break;
                        }
                    }
                }

            } else {
                cout << "Invalid move (not an empty space)" << endl;
            }
            return true;
        }
        case 2: {
            save();
            return false;
        }
        case 3: {
            cout << current->getName() << " conceded." << endl;
            takeTurn();
            cout << current->getName() << " has won the game by forfeit!" << endl;
            return false;
        }
        case 4: {
            return true;
        }
        case 5: {
            verifyWinner();
            return false;
        }

        default: {
            cout << "Invalid number, please choose again:\n"
                    "1. Make a move (make sure your move is valid)\n"
                    "2. Save\n"
                    "3. Concede (concede if there are no moves available)\n"
                    "4. Skip the turn\n"
                    "5. End the game (player with the most pieces wins)\n";
            tryAgain = true;
        }
    }
}
}
void Game::flipPieces(Position piece1, int row, int column) {

    board.setBoardPosition(row,column,piece1);
    current->setPieceCount(current->getPieceCount()+1);
    takeTurn();
    current->setPieceCount(current->getPieceCount()-1);
    takeTurn();

}

void Game::takeTurn() {
    if (current == &first) {
        current = &second;
    } else {                        //Changes the current player (first -> second, second -> first)
        current = &first;
    }
}

void Game::verifyWinner() {
    cout << "Here is the current state of the board:" << endl;

    board.drawBoard();

    if (first.getPieceCount() > second.getPieceCount()) {
        cout << first.getName() << " is the winner with " << first.getPieceCount() << " Black pieces!" << endl;
    }
    else if (second.getPieceCount() > first.getPieceCount()){
        cout << second.getName() << " is the winner with " << second.getPieceCount() << " White pieces!" << endl;
    }
    else if (first.getPieceCount() == second.getPieceCount()) {
        cout << "It's a draw!" << endl;
    }
}

Game Game::load() {

    string filename;
    string player1Name;
    string player2Name;
    string currentName;
    string characters;
    int player1Pieces;
    int player2Pieces;
    cout << "Type the name of the file you would like to load (example: save1.txt):" << endl;
    cin >> filename;
    fstream fs;
    fs.open(filename, fstream::in);
    fs >> player1Name >> player2Name >> currentName >> characters >> player1Pieces >> player2Pieces;
    fs.close();

    first.setName(player1Name);
    second.setName(player2Name);
    first.setPieceCount(player1Pieces);
    second.setPieceCount(player2Pieces);

    Position board1[8][8];
    int k = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board1[i][j].setPiece(characters.at(k));
            board.setBoardPosition(i,j,board1[i][j]);
            k++;
        }
    }

    Game game(first,second);

    int nameEquality = player1Name.compare(currentName);

    if (nameEquality == 0) {
        current = &first;
    } else {
        current = &second;
    }

    return game;

}

void Game::save() {

    string filename;
    cout << "Type a file name for your save file (example: save1.txt):" << endl;         //Save files are in cmake-build-debug folder
    cin >> filename;
    fstream fs;
    fs.open(filename, fstream::out);
    fs << first.getName() << endl;
    fs << second.getName() << endl;
    fs << current->getName() << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fs << board.getBoardPosition(i,j);
        }
    }
    fs << endl;
    fs << first.getPieceCount() << endl;
    fs << second.getPieceCount() << endl;
    fs.close();

}
