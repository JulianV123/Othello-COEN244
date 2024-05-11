#include <iostream>
#include "Player.h"
#include "Game.h"
using namespace std;

int main() {

    int choice;
    bool isSavedGame;
    string name;
    bool tryAgain = true;

    cout << "Welcome to Othello! Choose one of these 3 options:\n"
            "1. Load a Game\n"
            "2. Quit\n"
            "3. Start a New Game\n";

    while (tryAgain) {

        cin >> choice;

        switch (choice) {

            case 1: {
                isSavedGame = true;
                Player p1("");
                Player p2("");
                Game game(p1,p2);
                game.load();
                game.play(isSavedGame);
                tryAgain = false;
                break;
            }
            case 2: {
                cout << "Bye!";
                tryAgain = false;
                break;
            }
            case 3: {
                Player player1(name);
                Player player2(name);
                Game game(player1, player2);
                game.start();
                tryAgain = false;
                break;
            }
            default: {
                cout << "Invalid number, please choose again:\n"
                        "1. Load a Game\n"
                        "2. Quit\n"
                        "3. Start a New Game\n";
                tryAgain = true;
            }
        }
    }
    return 0;
}
