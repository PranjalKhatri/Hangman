#include "classes.h"

int main()
{

    char a;
    while (true) {
        hangman m("Words.txt");
        m.play();
        cout << "Want to play again ?(Y/N)" << endl;
        cin >> a;
        if (a == 'Y' || a=='y') { continue; }
        else {
            cout << "Thanks for playing!!\n press any key to exit.....";
            getch();
            break;
        }
    }
    return 0;
}