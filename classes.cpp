#include "classes.h"

bool check(char c, string g) {

    for (int i = 0; i < g.size(); i++)
    {
        if (c == g[i]) {
            return true;
        }
    }

    return false;
}

void fill_char(char a, string s, string& wc) {
    int arr[7] = { 0,0,0,0,0,0,0 };
    int size = 0;
    for (int i = 0; i < 7; i++)
    {
        if (s[i] == a) {
            arr[size] = i;
            size++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        wc[arr[i]] = a;
    }

}

fileops::fileops(string n) {
    f_name = n;
}

void fileops::open(string n)
{
    f_name = n;
}

int fileops::get_num_lines(void) {
    int t = 0;
    string str = "";
    ifstream in(f_name);
    while (in.eof() == 0)
    {
        t++;
        getline(in, str);
    }
    in.close();
    return t;
}

string fileops::get_rd_word(void) {

    srand(time(NULL));
    int n = get_num_lines();
    string str = "";
    int rd = (rand() % n) + 1;
    ifstream in(f_name);
    for (int i = 0; i < (rd - 1); i++)
    {
        getline(in, str);
    }
    getline(in, str);
    in.close();
    return str;
}

void hangman::display(char h[8][9]) {
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << h[i][j];
        }
        cout << endl;
    }

}

void hangman::Hang_mod(int n) {
    // cout << "hang mode\n";
    switch (n)
    {
    case 1:
        display(h1);
        break;
    case 2:
        display(h2);
        break;
    case 3:
        display(h3);
        break;
    case 4:
        display(h4);
        break;
    case 5:
        display(h5);
        break;
    case 6:
        display(h6);
        break;
    case 7:
        display(h7);
        break;

    default:
        break;
    }

}

hangman::hangman(string str) {
    f.open(str);
    word = f.get_rd_word();
    // cout << word << endl;
}

void hangman::play(void) {
    char c;

    string cw = "-------";
    string gw = "";
    string ig = "";
    Hang_mod(1);
    char heart = 3;
    cout << "Word Length : " << "7\n";
    while (true)
    {
        if (lives == 0) { break; }
        if (cw == word) { break; }
        cout << "Current Word : " << cw << endl;
        // cout << "Guessed words : " << gw << endl;
        cout << "Incorrect guesses : " << ig << endl;
        cout << "                                 Lives remaining : ";
        for (int i = 0; i < lives; i++)
        {
            cout << heart;
        }
        cout << endl;
        cout << "Guess a character \n";
        cin >> c;
        if (check(c, gw)) {
            system("cls");
            cout << "Already guessed!!!\n";
            Hang_mod(8 - lives);
            continue;
        }
        gw += c;
        gw += " ";
        system("cls");
        cout << "you guessed " << c << "\n";
        // cout << "comparing " << c << " " << word[index] << endl;
        if (check(c, word)) {
            fill_char(c, word, cw);
            cout << "     Correct Guess!!\n";
        }
        else {
            ig += c;
            lives--;
            cout << "     Incorrect guess!\n";
        }
        // cout << "kdkjf\n";
        Hang_mod((8 - lives));
    }
    if (lives == 0) {
        cout << "      \n\n GAME OVER!!" << endl;
        cout << "Correct word was : " << word << endl;
        return;
    }
    cout << " \n\n      YOU WIN! " << endl;
    cout << " lives remaining " << lives << endl;
}
