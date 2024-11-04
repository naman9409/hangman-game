#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayProgress(const string &word, const vector<bool> &guessed) {
    for (size_t i = 0; i < word.length(); i++) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const vector<bool> &guessed) {
    for (bool b : guessed) {
        if (!b) return false;
    }
    return true;
}

int main() {
    vector<string> wordList = {"hangman", "computer", "programming", "game", "puzzle"};
    srand(static_cast<unsigned int>(time(0)));
    string word = wordList[rand() % wordList.size()];
    vector<bool> guessed(word.size(), false);
    int attempts = 6;
    char guess;

    cout << "Welcome to Hangman!" << endl;
    while (attempts > 0 && !isWordGuessed(guessed)) {
        displayProgress(word, guessed);
        cout << "Attempts remaining: " << attempts << endl;
        cout << "Guess a letter: ";
        cin >> guess;

        bool found = false;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = true;
                found = true;
            }
        }

        if (!found) {
            attempts--;
            cout << "Incorrect guess!" << endl;
        } else {
            cout << "Good guess!" << endl;
        }
    }

    if (isWordGuessed(guessed)) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "Sorry, you've been hanged! The word was: " << word << endl;
    }

    return 0;
}

