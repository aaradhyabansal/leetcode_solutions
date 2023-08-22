#include <bits/stdc++.h>
using namespace std;

string encrypt(string& str, unordered_map<int, char>& alpha, unordered_map<char, int>& num, string& keyw) {
    string arr = "";
    for (int i = 0; i < str.length(); i++) {
        int k = num[str[i]];
        k = (k ^ num[keyw[i]]);
        arr += alpha[k];
    }
    return arr;
}

string decrypt(string& str, unordered_map<int, char>& alpha, unordered_map<char, int>& num, string& keyw) {
    string arr = "";
    for (int i = 0; i < str.length(); i++) {
        int k = num[str[i]];
        k = (k ^ num[keyw[i]]);
        arr += alpha[k];
    }
    return arr;
}

int main() {
    char ch = 'a';
    int k;
    unordered_map<int, char> alpha;
    for (int i = 0; i < 26; i++) {
        alpha[i] = ch;
        ch++;
    }
    int j = 0;
    unordered_map<char, int> num;
    for (char i = 'a'; i <= 'z'; i++) {
        num[i] = j;
        j++;
    }
    string str, keyw, nkeyw;

    cout << "Enter string to be encrypted" << endl;
    getline(cin, str);
    int n = str.length(), i = 0;
    cout << "Enter the keyword" << endl;
    getline(cin, keyw);
    nkeyw = keyw;
    while (keyw.length() != str.length()) {
        if (i == nkeyw.length())
            i = 0;
        keyw += nkeyw[i++];
    }
    string encrypted = encrypt(str, alpha, num, keyw);
    cout << "Encrypted: " << encrypted << endl;
    string decrypted = decrypt(encrypted, alpha, num, keyw);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
