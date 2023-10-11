#include "classes.h"

bool check(char c, string g) {
    //returns true if the given character c is present in given string
    for (int i = 0; i < g.size(); i++)
    {
        if (c == g[i]) {
            return true;
        }
    }

    return false;
}

/// @brief fills the given string wc with the given letter at every position it appears in s
/// @param a the letter to check and fill
/// @param s the string s to check from
/// @param wc the string to fill into
void fill_char(char a, string s, string& cw) {
    vector<int> arr;
    int size = 0;
    for (int i = 0; i <s.length(); i++)
    {
        if (s[i] == a) {
            cw[i] = a;
        }
    }

    // for (int i = 0; i < size; i++)
    // {
    //     cw[arr[i]] = a;
    // }

}

/// @brief initializes the fileops class
/// @param n the name of the file to open
fileops::fileops(string n) {
    f_name = n;
}

/// @brief opens the given file for operations
/// @param n name of the file
void fileops::open(string n)
{
    f_name = n;
}

/// @brief counts number of lines in the opened file
/// @return number of lines
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

/// @brief picks a random word from the opened file
/// @return the random word
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

/// @brief initializes the game , opens the given file and loads a random word
/// @param str name of file
hangman::hangman(string str) {
    f.open(str);
    word = f.get_rd_word();
    // cout << word << endl;
}
/// @brief Game loop 
void hangman::play(void) {
    char c;
    //current word on screen user is filling
    string cw = "";
    for (int i = 0; i < word.length(); i++)
    {
        cw += "-";
    }
    //list of guessed letters
    string gw = "";
    //incorrect guesses
    string ig = "";
    //set initial state of hangman
    Hang_mod(1);
    //Heart emoji asci = 
    char heart = 3;
    cout << "Word Length : " << word.length()<<endl;
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
        //check if c is already guessed
        if (check(c, gw)) {
            system("cls");
            cout << "Already guessed!!!\n";
            Hang_mod(8 - lives);
            continue;
        }
        //add c to guessed words
        gw += c;
        // gw += " ";
        //clear screen
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
    //Check if player is out of lives
    if (lives == 0) {
        cout << "      \n\n GAME OVER!!" << endl;
        cout << "Correct word was : " << word << endl;
        return;
    }
    cout << " \n\n      YOU WIN! " << endl;
    cout << " lives remaining " << lives << endl;
}
