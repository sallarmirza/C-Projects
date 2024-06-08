#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int a, int b) {
    string encryptedText = "";
    for (int i = 0; i < text.length(); i++) {
        char character = text[i];
        if (isalpha(character)) {
            char base = islower(character) ? 'a' : 'A';
            char encryptedChar = (char)(((a * (character - base) + b) % 26 + 26) % 26 + base);
            encryptedText += encryptedChar;
        } else {
            encryptedText += character;
        }
    }
    return encryptedText;
}

string decrypt(string encryptedText, int a_inverse, int b) {
    string decryptedText = "";
    for (int i = 0; i < encryptedText.length(); i++) {
        char character = encryptedText[i];
        if (isalpha(character)) {
            char base = islower(character) ? 'a' : 'A';
            char decryptedChar = (char)(((a_inverse * (character - base - b + 26) % 26 + 26) % 26) + base);
            decryptedText += decryptedChar;
        } else {
            decryptedText += character;
        }
    }
    return decryptedText;
}

int main() {
    int a, b;
    string plaintext;
    cout << "Enter your message: ";
    getline(cin, plaintext);
    
    cout << "Enter the value of a (shift factor): ";
    cin >> a;

    cout << "Enter the value of b (additional shift): ";
    cin >> b;

    string encryptedText = encrypt(plaintext, a, b);
    cout << "Encrypted Text: " << encryptedText << endl;

    int a_inverse = 0;
    for (int i = 1; i <= 25; i++) {
        if ((a * i) % 26 == 1) {
            a_inverse = i;
            break;
        }
    }

    string decryptedText = decrypt(encryptedText, a_inverse, b);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}