// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: BonusCipheringProgram.cpp
// Program Description: includes 10 different ciphers and user can choose from it
// Last Modification Date: 24/3/2022
// Author1 and ID and Group: Hazem Mohamed Waheed, 20210115, A
// Author2 and ID and Group: Abdelrahman Gomaa Fathy, 20210224, A
// Author3 and ID and Group: Mohamed Khaled El-Sayed, 20210338, A
// Teaching Assistant: Professor Mohammad EL-Ramly
// Purpose: Ciphering and deciphering using 10 different methods


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string lowerPlainAlphabet = "abcdefghijklmnopqrstuvwxyz";
string capitalPlainAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


// these are functions for cipher 0
char ciphering0(int a, int b, char character) {
    character = lowerPlainAlphabet[((a * (character - 'a') + b) % 26 + 26) % 26];
    return character;
}

char deciphering0(int b, int c, char character) {
    character = lowerPlainAlphabet[(c * ((character - 'a') - b) % 26 + 26) % 26];
    return character;
}

void affineCipher0() {
    while (true) {
        int a, b, c;
        string plainText, cipheredText, choice;
        cout << "Welcome to affine Cipher" << endl;
        cout << endl << "What do you like to do today?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter : ";
        cin >> choice;

        while (choice != "1" && choice != "2" && choice != "3") {
            cout << "ENTER A VALID CHOICE\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter : ";
            cin >> choice;
        }

        if (choice == "3") {
            cout << "PROGRAM ENDED";
            break;
        }


        cout << "Enter a, b, c which satisfy that (a*c) mod 26 = 1 : ";
        cin >> a >> b >> c;

        // defensive
        while (cin.fail()) {
            cout << "Enter valid numbers for a,b,c : ";
            cin.clear();
            cin.sync();
            cin >> a >> b >> c;
        }

        while (((a * c % 26) + 26) % 26 != 1) {
            cout << "Enter a, b, c which satisfy that (a*c) mod 26 = 1 : ";
            cin >> a >> b >> c;
        }
        cin.clear();
        cin.sync();

        if (choice == "1") {
            cout << endl << "Please Enter Text you want to cipher : ";
            getline(cin, plainText);
            // changing the text to lower case

            for (int i = 0; i < plainText.length(); i++) {
                if (isalpha(plainText[i])) {
                    plainText[i] = tolower(plainText[i]);
                }
            }
            // generating ciphered text
            for (int i = 0; i < plainText.length(); i++) {
                if (isalpha(plainText[i])) {
                    cipheredText += ciphering0(a, b, plainText[i]);
                }
                else {
                    cipheredText += plainText[i];
                }
            }
            cout << endl << "this is your ciphered text : " << cipheredText << endl;
        }

        else if (choice == "2") {
            cout << endl << "Please Enter Text you want to decipher : ";
            getline(cin, plainText);

            // changing the text to lower case
            for (int i = 0; i < plainText.length(); i++) {
                if (isalpha(plainText[i])) {
                    plainText[i] = tolower(plainText[i]);
                }
            }
            // generating deciphered text
            for (int i = 0; i < plainText.length(); i++) {
                if (isalpha(plainText[i])) {
                    cipheredText += deciphering0(b, c, plainText[i]);
                }
                else {
                    cipheredText += plainText[i];
                }
            }
            cout << endl << "this is your deciphered text : " << cipheredText << endl;
        }
    }
}

// cipher 1
void caesarCipher1() {
    while (true) {
        int shift;
        string choice, plainText, cipheredText;
        cout << "Welcome to caesar Cipher" << endl;
        cout << "What do you like to do today?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter : ";
        cin >> choice;

        while (choice != "1" && choice != "2" && choice != "3") {
            cout << "ENTER A VALID CHOICE\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter : ";
            cin >> choice;
        }

        if (choice == "3") {
            cout << "PROGRAM ENDED";
            break;
        }
        if (choice == "1") {
            cout << "Enter the number of shifts you want : ";
            cin >> shift;
        }
        else if (choice == "2") {
            cout << "Enter the number of shifts you used in ciphering : ";
            cin >> shift;
        }

        while (cin.fail()) {
            cout << "Enter a valid number of shifts : ";
            cin.clear();
            cin.sync();
            cin >> shift;
        }

        shift = (shift % 26 + 26) % 26; // in case shift is more than 26 or less than -26
        if (choice == "2") {
            shift = 26 - shift;
        }
        getline(cin, plainText); // dummy getline

        if (choice == "1") {
            cout << "Enter the text you want to cipher : ";
            getline(cin, plainText);
        }
        else if (choice == "2") {
            cout << "Enter the text you want to decipher : ";
            getline(cin, plainText);
        }

        for (int i = 0; i < plainText.length(); i++) {
            if (isalpha(plainText[i])) {
                plainText[i] = toupper(plainText[i]);
            }
        }

        for (int i = 0; i < plainText.length() + 1; i++) {
            if (isalpha(plainText[i])) {
                int ind = (plainText[i] - 'A') + shift;
                cipheredText += capitalPlainAlphabet[(ind % 26)];
            }
            else {
                cipheredText += plainText[i];
            }
        }
        if (choice == "1") {
            cout << "your ciphered text is : " << cipheredText;
            cout << "\n";
        }
        else if (choice == "2") {
            cout << "your deciphered text is : " << cipheredText;
            cout << "\n";
        }
    }
}

// cipher 2
void atbashCipher2() {
    while (true) {
        string cipherAlphabet, plainText, cipherText, choice;

        cout << "Welcome to atbash Cipher" << endl;
        cout << "What do you like to do today?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter : ";
        cin >> choice;

        while (choice != "1" && choice != "2" && choice != "3") {
            cout << "ENTER A VALID CHOICE\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter : ";
            cin >> choice;
        }

        getline(cin, plainText); // dummy

        if (choice == "1") {
            cout << "Enter the text you want to cipher : ";
            getline(cin, plainText);
        }
        else if (choice == "2") {
            cout << "Enter the text you want to decipher : ";
            getline(cin, plainText);
        }
        else if (choice == "3") {
            cout << "PROGRAM ENDED";
            break;
        }

        for (int i = 0; i < plainText.length(); i++) {
            if (isalpha(plainText[i]) && islower(plainText[i])) {
                cipherText += lowerPlainAlphabet[25 - (plainText[i] - 'a')];
            }
            else if (isalpha(plainText[i]) && isupper(plainText[i])) {
                cipherText += capitalPlainAlphabet[25 - (plainText[i] - 'A')];
            }
            else {
                cipherText += plainText[i];
            }
        }
        cout << cipherText << endl;
    }
}

// cipher 3

string cipher3_encrypt(string message, string keyword) {
    string encrypted_message;

    while (keyword.length() != message.length()) {
        for (int i = 0; i < keyword.length(); ++i) {
            if (keyword.length() == message.length()) break;
            keyword += keyword[i];
        }
    }

    for (int i = 0; i < message.length(); ++i) {
        if (isalpha(message[i])) {
            encrypted_message += char(((message[i] + keyword[i]) % 26) + 65);
        }
        else encrypted_message += message[i];
    }
    return encrypted_message;
}

string cipher3_decrypt(string decrypted, string keyword) {

    string message;

    while (decrypted.length() != keyword.length()) {

        for (int i = 0; i < keyword.length(); ++i) {
            if (decrypted.length() == keyword.length()) break;
            keyword += keyword[i];
        }
    }

    for (int i = 0; i < keyword.length(); ++i) {
        if (isalpha(decrypted[i])) {

            if (decrypted[i] - keyword[i] >= 0) {
                message += char((decrypted[i] - keyword[i]) + 65);
            }
            else {
                message += char(((decrypted[i] - keyword[i]) + 26) + 65);
            }
        }
        else message += decrypted[i];

    }

    return message;
}

void vignereCipher3() {
    cout << "this Vignere cipher, give us your message and its keyword and no one will know it\n\n";

    while (true) {
        string choice;
        cout << "choose what you want to do on your message\n"
            "1- enter 1 to encrypt your message\n"
            "2- enter 2 to decrypt your message\n"
            "3- enter 3 to end this programme\n\n";

        cout << "enter the number of operation you want to do : ";
        cin >> choice;
        while (true) {
            if (choice == "1" || choice == "2" || choice == "3") break;
            else {
                cout << "your choice must be 1 ,2 or 3 \n";
                choice = "";
                cout << "try again but this time choose carefully : ";
                cin >> choice;
            }
        }

        if (choice == "3") {
            cout << "you choose to end this programme\n\n";
            break;
        }
        if (choice == "1") {

            string message, keyword;
            cout << "your information must be classified to make you come here and encrypt it,\n"
                " don`t worry we will encrypt it for you, enter what you want : ";
            while (message.empty()) getline(cin, message);

            cout << "enter a helpful keyword to make sure that your information"
                "will be decrypted by this keyword : ";
            while (keyword.empty()) getline(cin, keyword);

            //            it is better to make all characters in uppercase
            for (int i = 0; i < message.length(); ++i) {
                message[i] = toupper(message[i]);
            }

            for (int i = 0; i < keyword.length(); ++i) {
                keyword[i] = toupper(keyword[i]);
            }

            //    defensive to make the length of the message does not exceed 80
            while (message.length() > 80) {
                message = "";
                cout << " this message is too long and can be decrypted by others, try a shorter one : ";
                while (message.empty()) getline(cin, message);
            }

            //            defensive to make sure that the keyword`s length does not exceed 8
            while (keyword.length() > 8) {
                keyword = "";
                cout << "this key word is a bit long, try something less than or equal to 8 characters : ";
                while (keyword.empty()) getline(cin, keyword);
            }

            cout << "here is your encrypted message : " << cipher3_encrypt(message, keyword) << "\n\n";
        }


        if (choice == "2") {
            cout << "you choose to enter an encrypted word and we will decrypt for you. \n\n";

            string encrypted_word, keyword;
            cout << "enter your encrypted word : ";
            while (encrypted_word.empty()) getline(cin, encrypted_word);

            for (int i = 0; i < encrypted_word.length(); ++i) {
                encrypted_word[i] = toupper(encrypted_word[i]);
            }

            cout << "enter the keyword to help with the decryption : ";
            while (keyword.empty()) getline(cin, keyword);

            for (int i = 0; i < keyword.length(); ++i) {
                keyword[i] = toupper(keyword[i]);
            }

            cout << "that is what we came out with after the decryption of " << encrypted_word << " : " << cipher3_decrypt(encrypted_word, keyword) << "\n\n";
        }
    }
}


// cipher 4
void baconianCipher4() {
    map<char, string> letter_code = { {'A', "aaaaa"}, {'B', "aaaab"}, {'C', "aaaba"}, {'D', "aaabb"}, {'E', "aabaa"}, {'F', "aabab"}
            ,{'G', "aabba"}, {'H', "aabbb"}, {'I', "abaaa"}, {'J', "abaab"}, {'K', "ababa"}, {'L', "ababb"}, {'M', "abbaa"}
            ,{'N', "abbab"}, {'O', "abbba"}, {'P', "abbbb"}, {'Q', "baaaa"}, {'R', "baaab"}, {'S', "baaba"}, {'T', "baabb"}
            ,{'U', "babaa"}, {'V', "babab"}, {'W', "babba"}, {'X', "babbb"}, {'Y', "bbaaa"}, {'Z', "bbaab"} };

    map<string, char> code_letter = { {"aaaaa",'A'}, {"aaaab",'B'}, {"aaaba",'C'}, {"aaabb",'D'}, {"aabaa",'E'}, {"aabab",'F'}
            ,{"aabba",'G'}, {"aabbb",'H'}, {"abaaa",'I'}, {"abaab",'J'}, {"ababa",'K'}, {"ababb",'L'}, {"abbaa",'M'}
            ,{"abbab",'N'}, {"abbba",'O'}, {"abbbb",'P'}, {"baaaa",'Q'}, {"baaab",'R'}, {"baaba",'S'}, {"baabb",'T'}
            ,{"babaa",'U'}, {"babab",'V'}, {"babba",'W'}, {"babbb",'X'}, {"bbaaa",'Y'}, {"bbaab",'Z'} };

    cout << """welcome user, if you choose this program that means that you want to encrypt or decrypt BACONIAN CIPHER.\n"
        "     let`s see if you want to encrypt or decrypt your text: \n";

    // here is a big while loop for choices
    while (true) {
        cout << "\n";
        cout << "     1-enter 1 if you want to cipher a message.\n"
            "     2-enter 2 if you want to decipher a message.\n"
            "     3-enter 3 if you want to end.\n""" << "\n";

        string choice;
        cout << "enter your choice : ";
        cin >> choice;


        while (true) {
            if (choice == "1" || choice == "2" || choice == "3") break;
            else {
                cout << "you have to enter a number 1 , 2 or 3 : ";
                cin >> choice;
            }
        }

        if (choice == "3") {
            cout << "you choose to end this program\n";
            break;
        }

        if (choice == "1") {

            string word_to_cipher;
            cout << "if you want to be safe, enter your text and cipher it : ";
            while (word_to_cipher.empty()) { getline(cin, word_to_cipher); }


            //    the next while is a defensive if the user inputs anything but words
            while (true) {
                int flag = 0;
                for (char i : word_to_cipher) {
                    if (isalpha(i) || i == ' ') continue;
                    else {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) break;
                else {
                    cout << "only letters can be encrypted" << "\n";
                    cout << "you have to enter a word_to_cipher that only contains letters :  ";
                    word_to_cipher = "";
                    while (word_to_cipher.empty()) { getline(cin, word_to_cipher); }
                }
            }

            // it is allowed for the user to input lowercase or uppercase characters but for the code i will convert all characters to uppercase

            for (int i = 0; i < word_to_cipher.length(); ++i) {
                if (word_to_cipher[i] == ' ') continue;
                if (islower(word_to_cipher[i])) word_to_cipher[i] = toupper(word_to_cipher[i]);
            }


            //    here we will change each character with its equivalent in the map
            cout << "now you are safe " << "\n";
            cout << "here is your encrypted text : ";
            for (int i = 0; i < word_to_cipher.length(); ++i) {
                cout << letter_code[word_to_cipher[i]] << " ";
            }
            cout << "\n";

        }

        if (choice == "2") {

            cout << "\n";
            cout << "by making this choice you will decipher your message \n";

            string word_to_decipher;
            cout << "enter the encrypted text to decipher it : ";
            while (word_to_decipher == "") { getline(cin, word_to_decipher); }


            //    the next while is here as defensive if input is not a or b or a space
            while (true) {
                int flag = 0;
                for (int i = 0; i < word_to_decipher.length(); ++i) {
                    if (word_to_decipher[i] == 'a' || word_to_decipher[i] == 'b' || word_to_decipher[i] == ' ' || word_to_decipher[i] == 'A' || word_to_decipher[i] == 'B') continue;
                    else {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) break;
                else {
                    cout << "mmmmmm, it seams like you don`t know our cipher " << "\n";
                    cout << "i will give you a hint that will help you remember it, our cipher works only with two letters \n";
                    cout << "now enter your ciphered text :  ";
                    word_to_decipher = "";
                    while (word_to_decipher == "") { getline(cin, word_to_decipher); }

                }
            }

            // here a defensive for each character because each character has length of 5
            while (true) {
                int count = 0;
                for (int i = 0; i < word_to_decipher.length(); ++i) {
                    if (word_to_decipher[i] == ' ') continue;
                    else count += 1;
                }
                if (count % 5 == 0) break;
                else {
                    cout << "you look like know the cipher, but you have written it wrong \n";
                    cout << "please, enter your ciphered message again : ";
                    while (word_to_decipher == "") { getline(cin, word_to_decipher); }
                }

            }


            //  here we convert all letters to small
            for (int i = 0; i < word_to_decipher.length(); ++i) {
                if (word_to_decipher[i] == ' ') continue;
                if (isupper(word_to_decipher[i])) word_to_decipher[i] = tolower(word_to_decipher[i]);

            }

            // here we change every five letters(a,b) with their equivalent
            string letter = "";
            for (int i = 0; i < word_to_decipher.length(); ++i) {
                if (word_to_decipher[i] != ' ') letter += word_to_decipher[i];
                if (word_to_decipher[i] == ' ' && word_to_decipher[i + 1] == ' ') cout << " ";
                if (letter.length() == 5) {
                    cout << code_letter[letter];
                    letter = "";
                }
            }
            cout << "\n";
        }
    }
}

// cipher 5

void simpleSubstitutionCipher5() {
    while (true) {
        string cipherAlphabet, plainText, cipherText, keyword;
        string choice;
        set<char> s;

        cout << "Welcome to Simple Substitution Cipher" << endl;
        cout << "What do you like to do today?\n1- Cipher a message\n2- Decipher a message\n3- End\nenter : ";
        cin >> choice;
        while ((choice != "1") && (choice != "2") && (choice != "3")) {
            cout << "Please enter a valid input\n1- Cipher a message\n2- Decipher a message\n3- End\nenter : ";
            cin >> choice;
        }
        if (choice == "1") {
            cout << "Please enter the keyword you want : ";
            cin >> keyword;

            // changing the keyword to lower case
            for (int i = 0; i < keyword.length(); i++) {
                keyword[i] = tolower(keyword[i]);
            }

            // for putting characters of keyword in a set
            for (int i = 0; i < keyword.length(); i++) {
                if (isalpha(keyword[i])) {
                    s.insert(keyword[i]);
                }
            }

            // generating the cipher alphabet
            for (int i = 0; i < keyword.length(); ++i) {
                if (isalpha(keyword[i]))
                    cipherAlphabet += keyword[i];
            }

            for (int i = 0; i < lowerPlainAlphabet.length(); i++) {
                if (s.count(lowerPlainAlphabet[i])) {
                    continue;
                }
                else {
                    cipherAlphabet += lowerPlainAlphabet[i];
                }
            }
            // dummy get-line to read the \n
            getline(cin, plainText);

            cout << "Enter the text you want to cipher : ";
            getline(cin, plainText, '\n');

            // changing plain text to lower case
            for (int i = 0; i < plainText.length(); i++) {
                plainText[i] = tolower(plainText[i]);
            }

            // ciphering the plain text
            for (int i = 0; i < plainText.length(); ++i) {
                if (isalpha(plainText[i])) {
                    cipherText += cipherAlphabet[plainText[i] - 'a'];
                }
                else {
                    cipherText += plainText[i];
                }
            }
            cout << "\n";
            cout << "Your ciphered text is : " << cipherText << endl;
        }

        else if (choice == "2") {
            string cipherAlphabet, plainText, cipherText, keyword;
            string choice;
            set<char> s;


            cout << "Please enter the keyword you want : ";
            cin >> keyword;

            // changing the keyword to lower case
            for (int i = 0; i < keyword.length(); i++) {
                keyword[i] = tolower(keyword[i]);
            }

            // for putting characters of keyword in a set
            for (int i = 0; i < keyword.length(); i++) {
                if (isalpha(keyword[i])) {
                    s.insert(keyword[i]);
                }
            }

            // generating the cipher alphabet
            for (int i = 0; i < keyword.length(); ++i) {
                if (isalpha(keyword[i]))
                    cipherAlphabet += keyword[i];
            }
            for (int i = 0; i < lowerPlainAlphabet.length(); i++) {
                if (s.count(lowerPlainAlphabet[i])) {
                    continue;
                }
                else {
                    cipherAlphabet += lowerPlainAlphabet[i];
                }
            }

            // dummy getline to read the \n
            getline(cin, plainText);

            cout << "Enter the cipher you want to decipher : ";
            getline(cin, plainText, '\n');

            // changing plain text to lower case
            for (int i = 0; i < plainText.length(); i++) {
                plainText[i] = tolower(plainText[i]);
            }

            // ciphering the plain text
            for (int i = 0; i < plainText.length(); ++i) {
                if (isalpha(plainText[i])) {
                    for (int j = 0; j < cipherAlphabet.length(); j++) {
                        if (plainText[i] == cipherAlphabet[j]) {
                            cipherText += lowerPlainAlphabet[j];
                        }
                    }
                }
                else {
                    cipherText += plainText[i];
                }
            }
            cout << "\n";
            cout << "Your deciphered text is : " << cipherText << endl;
        }
        else if (choice == "3") {
            cout << "ENDED";
            break;
        }
    }
}

// cipher 6
void polybiusSquareCipher6() {
    map<char, pair<int, int>>cipher;
    map<pair<int, int>, char>decipher;
    string message, choice;
    cout << "Welcome to Polybius Square Cipher" << endl;
    cout << "What do you like to do today?\n1-cipher a message.\n2-decipher a message.\n3-End the program.\n";
    cin >> choice;
    int arr[5];
    while (true) {
        if (choice == "1") {
            cout << "First , Enter the five keys (numbers from 1 to 5 in any order): \n";
            int counter = 1, iterator = 0;

            cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
            for (char c = 'a'; c < 'z'; c++) {
                cipher[c] = { arr[iterator],counter };
                counter++;
                if (counter > 5) {
                    counter = 1;
                    iterator++;
                }
            }
            cout << "Now enter the message you want to cipher :\n";
            cin.get();
            getline(cin, message);
            transform(message.begin(), message.end(), message.begin(), ::tolower);
            for (int i = 0; i < message.size(); i++) {
                if (message[i] == ' ')
                    cout << " ";
                else
                    cout << cipher[message[i]].first << cipher[message[i]].second;
            }
            cout << "\nEnter '1' to cipher a message.\nEnter '2' to decipher a message.\nEnter '3' to End the program.\n";
            cin >> choice;
        }
        else if (choice == "2") {
            cout << "First , Enter the five keys :(numbers from 1 to 5 in any order) \n";
            int counter = 1, iterator = 0;
            cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
            for (char c = 'a'; c < 'z'; c++) {
                decipher[{ arr[iterator], counter }] = c;
                counter++;
                if (counter > 5) {
                    counter = 1;
                    iterator++;
                }
            }
            cout << "Now enter the message you want to decipher :\n";
            cin.get();
            getline(cin, message);
            for (int i = 0; i < message.size() - 1; i += 2) {
                if (message[i] == ' ') { cout << " "; i--; }
                else cout << decipher[{message[i] - '0', message[i + 1] - '0'}];
            }
            cout << "\nEnter '1' to cipher a message.\nEnter '2' to decipher a message.\nEnter '3' to End the program.\n";
            cin >> choice;

        }
        else if (choice == "3") {
            break;
        }
        else {
            cout << "Enter correct number" << endl;
            cin >> choice;
        }
    }
}

// cipher 7
void morseCodeCipher7() {
    string message, choice;
    map<char, string>cipher;
    map<string, char>decipher;
    cipher['a'] = ".-"; cipher['b'] = "-..."; cipher['c'] = "-.-."; cipher['d'] = "-.."; cipher['e'] = ".";
    cipher['f'] = "..-."; cipher['g'] = "--."; cipher['h'] = "...."; cipher['i'] = ".."; cipher['j'] = ".---";
    cipher['k'] = "-.-"; cipher['l'] = ".-.."; cipher['m'] = "--"; cipher['n'] = "-."; cipher['o'] = "---";
    cipher['p'] = ".--."; cipher['q'] = "--.-"; cipher['r'] = ".-."; cipher['t'] = "-"; cipher['u'] = "..-";
    cipher['v'] = "...-"; cipher['w'] = ".--"; cipher['x'] = "-..-"; cipher['z'] = "--.."; cipher['y'] = "-.--";
    cipher[':'] = "---···"; cipher[','] = "--··--"; cipher['-'] = "-····-"; cipher['_'] = "··--·-"; cipher['s'] = "...";

    // filling up the first map with each character in the alphabet and its shape in morse code
    for (auto it : cipher) {
        decipher[it.second] = it.first;
    }
    // filling up the second map with the morse code of each character in the alphabet
    cout << "Welcome to morse code cipher" << endl;
    cout << "What do you like to do today?\n1-cipher a message.\n2-decipher a message.\n3-End the program.\n";
    cin >> choice;
    while (true) {
        if (choice == "1") {
            cout << "Enter The message You want to cipher!" << endl;
            cin.get();
            getline(cin, message);
            transform(message.begin(), message.end(), message.begin(), ::tolower);
            for (int i = 0; i < message.size(); i++) {
                if (message[i] == ' ')cout << "   ";
                else {
                    if (message[i + 1] == ' ')cout << cipher[message[i]];
                    else cout << cipher[message[i]] << " ";
                }
            }
            cout << "\n'1' if you want to cipher\n'2' if you want to decipher\n'3' if you want to end the program\n";
            cin >> choice;

        }
        else if (choice == "2") {
            cout << "Enter the message You want to decipher!" << endl;
            string s;
            cin.get();
            getline(cin, message);
            for (int i = 0; i < message.size(); i++) {
                if (message[i] == ' ') {
                    if (message[i - 1] == ' ' && message[i + 1] == ' ') {
                        cout << " ";
                    }
                    cout << decipher[s];
                    s.clear();

                }
                else {
                    s += message[i];
                }
            }
            cout << decipher[s];
            if (message.empty() == 0) {
                cout << "\n'1' if you want to cipher\n'2' if you want to decipher\n'3' if you want to end the program\n";
                cin >> choice;
            }
        }
        else if (choice == "3") {
            break;
        }
        else {
            cout << "Please Enter correct number \n'1' if you want to cipher\n'2' if you want to decipher\n'3' if you want to end the program\n";
            cin >> choice;
        }
    }
}

// cipher 8
void xorCipher8() {
    string choice;
    string message;
    char secret_letter;
    // declaring two strings choice and message , choice is the choice which the user will make , message is the message that the user will enter for either encypting or decrypting
    //secret character that the user will enter to xor with
    cout << "What do you like to do today?\n1-cipher a message.\n2-decipher a message.\n3-End the program.\n";
    cin >> choice;
    while (true) {
        if (choice == "1") {
            cout << "Enter The message You want to cipher " << endl;
            cin.get();
            getline(cin, message);
            transform(message.begin(), message.end(), message.begin(), ::tolower);
            string encrypted;
            cout << "Enter the Secret Character." << endl;
            cin >> secret_letter;
            secret_letter = toupper(secret_letter);
            for (int i = 0; i < message.size(); i++) {
                encrypted += message[i] ^ secret_letter;
            }
            cout << encrypted << endl;
            for (auto i : encrypted) {
                cout << hex << (int) static_cast <unsigned char>(i);
            }
            cout << "\nEnter '1' to cipher a message.\nEnter '2' to decipher a message.\nEnter '3' to End the program.\n";
            cin >> choice;
        }

        else if (choice == "2") {
            cout << "Enter the message you want to decipher\n";
            cin.get();
            getline(cin, message);
            cout << "Enter the secret character\n";
            cin >> secret_letter;
            secret_letter = toupper(secret_letter);
            transform(message.begin(), message.end(), message.begin(), ::tolower);
            string decrypted, ascii;
            set<char> hex{ 'a', 'b', 'c', 'd', 'e', 'f' };
            for (size_t i = 0; i < message.length(); i += 2) {
                string part = message.substr(i, 2);//taking every two characters in the string message in the string part
                if ((isdigit(part[0])) || (hex.count(part[0])) && (isdigit(part[1])) || (hex.count(part[1])))//checking if the character is digit or one of the character that the hexadecimal representation has
                {
                    char hexa = stoul(part, nullptr, 16);//storing the hexadecimal in the character
                    ascii += hexa;
                }
            }
            for (char i : ascii) {
                decrypted += (char)(i ^ secret_letter);
            }
            cout << decrypted;
            cout << "\nEnter '1' to cipher a message.\nEnter '2' to decipher a message.\nEnter '3' to End the program.\n";
            cin >> choice;
        }
        else if (choice == "3") {
            break;
        }
        else {
            cout << "Enter correct number" << endl;
            cin >> choice;
        }
    }

}

// cipher 9

string to_rail_fence(string word) {
    //    I made every line in a in rail-force in a string to help with code
    string line1, line2, line3;
    string rail, rail2;
    /*    here I placed a space in the position of every character to use this latter in replacing the space with characters,
     and you should ignore the ( - ) , I used - to give my self a chick we are the characters are and the - in the output
     */
    for (int i = 0; i < word.length(); ++i) {
        if (i % 4 == 0) line1 += ' ';
        else line1 += '-';

        if (i % 2 == 0) line2 += '-';
        else line2 += ' ';

        if (i % 2 == 0 && i % 4 != 0) line3 += ' ';
        else line3 += '-';
    }
    //  this loop is where we replace each space from the past loop with the equivalent character
    for (int i = 0; i < word.length(); ++i) {
        if (line1[i] == ' ') {
            line1[i] = word[i];
        }
        else if (line2[i] == ' ') {
            line2[i] = word[i];
        }
        else if (line3[i] == ' ') {
            line3[i] = word[i];
        }
    }
    //    here we add every line in together in one string and ignore the -
    rail += line1 + line2 + line3;
    for (int i = 0; i < rail.length(); ++i) if (isalpha(rail[i])) rail2 += rail[i];
    return rail2;
}
// this function converts the encoded message to plain message

string from_rail_fence(string word) {
    string line1, line2, line3;
    cin.clear();
    cin.sync();
    string rail;
    rail.resize(word.length());
    //    the next for loop determines the length of every line from the zigzag
    int len1 = 0, len2 = 0, len3 = 0;
    for (int i = 0; i < word.length(); ++i) {
        if (i % 4 == 0) len1 += 1;
        else if (i % 2 != 0) len2 += 1;
        else  len3 += 1;
    }
    //    here we place the sequence of the characters in their line
    line1 = word.substr(0, len1);
    line2 = word.substr(len1, len2 + len1);
    line3 = word.substr(len2 + len1, len3 + len1 + len2);

    //    here we place the index of the character in his right position
    for (int i = 0, j = 0; j < line1.length(); i += 4, j++) rail[i] = line1[j];

    for (int i = 1, j = 0; j < line2.length(); i += 2, j++) rail[i] = line2[j];

    for (int i = 2, j = 0; j < line3.length(); i += 4, j++) rail[i] = line3[j];

    return rail;
}

void railfenceCipher9() {
    cout << "this is RAIL-FENCE cipher\n\n";

    while (true) {
        string  message;
        cout << "these are your choices\n"
            "1- enter 1 to cipher a message\n"
            "2- enter 2 to decipher  a message\n"
            "3- enter 3 to end this program\n";
        cout << "\n";
        string choice;
        cout << "enter your choice : ";
        cin >> choice;

        if (choice == "3") {
            cout << "you choose to end this program\n";
            break;
        }

        else if (choice == "1") {
            message = "";
            cout << "enter your message : ";
            while (message.empty()) getline(cin, message);

            //            the next three lines are here to resize the length of the message
            int len_before_spaces = message.length(), spaces = count(message.begin(), message.end(), ' ');
            message.erase(remove(message.begin(), message.end(), ' '), message.end());
            message.resize(len_before_spaces - spaces);

            for (int i = 0; i < message.length(); ++i) message[i] = toupper(message[i]);

            cout << "this is your zig-zag message : " << "\n" << to_rail_fence(message) << "\n";
        }

        else if (choice == "2") {
            message = "";
            cout << "\n";
            cout << "you choose to enter an encoded message \n";
            cout << "enter your message : \n";
            while (message.empty()) getline(cin, message);

            int len_before_spaces = message.length(), spaces = count(message.begin(), message.end(), ' ');
            message.erase(remove(message.begin(), message.end(), ' '), message.end());
            message.resize(len_before_spaces - spaces);

            for (int i = 0; i < message.length(); ++i) message[i] = toupper(message[i]);

            cout << "this is your rail-fence message : " << from_rail_fence(message) << "\n\n";

        }

        else {
            cout << "you have to choose 1, 2 or 3 not " << choice << "\n\n";
            choice = "";
        }
    }
}

int main() {
    while (true) {
        string continueChoice;
        int cipherChoice;
        cout << "\n1. Affine Cipher \n2. Caesar Cipher \n3. Atbash Cipher \n4. Vignere Cipher \n5. Baconian Cipher \n6. Simple Substitution Cipher \n7. Polybius Square Cipher \n8. Morse Code \n9. XOR Cipher \n10. Rail-fence Cipher";
        cout << "\nPlease choose a cipher to use from 1 to 10:\n";
        cin >> cipherChoice;
        cin.clear();
        cin.sync();


        switch (cipherChoice) {
        case 1:
            affineCipher0();
            break;
        case 2:
            caesarCipher1();
            break;
        case 3:
            atbashCipher2();
            break;
        case 4:
            vignereCipher3();
            break;
        case 5:
            baconianCipher4();
            break;
        case 6:
            simpleSubstitutionCipher5();
            break;
        case 7:
            polybiusSquareCipher6();
            break;
        case 8:
            morseCodeCipher7();
            break;
        case 9:
            xorCipher8();
            break;
        case 10:
            railfenceCipher9();
            break;
        default:
            cout << "INVALID" << endl;
        }
        cout << endl << "IF YOU WISH TO END THE PROGRAM ENTER '1' : ";
        cin >> continueChoice;
        if (continueChoice == "1") {
            cout << "THE CIPHERING PROGRAM IS ENDED";
            break;
        }
    }
}