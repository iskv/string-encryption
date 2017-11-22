#include <iostream>
#include <string>

using namespace std;

string encrypt(string& str);
void decrypt(string& enc_str, string& key);

int main()
{
    string str = {"Test string for encrypt!"};

    string key = encrypt(str);

    decrypt(str, key);

    cin.get();
    return 0;
}

string encrypt(string& str)
{
     string key, enc_str;
     for (int i = 0; i < str.size(); i++) { // генерация ключа
         key.push_back(char(rand()%255));
     }

     for (int i = 0; i < str.size(); i++) { // кодирование
         enc_str.push_back(str[i] ^ key[i]);
     }

     cout << "Key: " << key
          << "\nEncrypt string: " << enc_str << endl;


     str = enc_str;

     return key;
}

void decrypt(string& enc_str, string& key)
{
    string dec_str;

    for (int i = 0; i < enc_str.size(); i++) {
        dec_str.push_back(enc_str[i] ^ key[i]);
    }

    cout << "Decrypt string: " << dec_str << endl;
}


