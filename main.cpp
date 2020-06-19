//============================================================================
// Author    : Zhenia Steger
//
// Purpose   : To demonstrate encryption and decryption using rotation
//              and cryptogram methods.
// Input     : Takes a text file as input to be encrypted.
// Output    : Outputs a text file encrypted with method of choice by user.
//
// Instructions: Use 'original.txt' for encoding with both methods.
//        : For decryption use:
//        :    'encryptRot.txt' for rotation decryption.
//        :    'encryptCrypt.txt' for cryptogram decryption.
//============================================================================

#include "encDec.h"

using namespace std;

// MAIN METHOD
int main() {

int sel1, sel2, encKey, decKey; // Used for user selection of encryption an key for rotation
vector<string> v;
encDec ed;
bool rerun = true; // To continue running the program until user exits
cout << "Encryption / Decryption Program\n" << endl; // introduction
while (rerun == true)
  {
  v.clear(); // Make sure there is nothing in the vector
  cout << "Are we doing encryption or decryption?" << endl;
  cout << "Enter 1 for Encryption, 2 for Decryption, 3 to exit." << endl;

  cin >> sel1;

    // Encryption prompt - selection 1
    if (sel1 == 1)
    {
      cout << "Encryption. Are we using rotation method or cryptogram method?" << endl;
      cout << "Enter 1 for rotation, 2 for cryptogram, 3 to exit." << endl;
      cin >> sel2;
        if (sel2 == 1) // Encryption using rotation method
          {
            v = ed.encDec::getOriginalData();
            cout << "What is the encryption key?" << endl;
            cin >> encKey;
            ed.encDec::DoEncUsingRot(v, encKey);
          }
        else if (sel2 == 2) // Encryption using cryptogram method
          {
            v = ed.encDec::getOriginalData();
            cout << "Opening 'cryptogram.txt'..." << endl;
            ed.encDec::DoEncUsingCrypt(v);
          }
        else if (sel2 == 3) {exit(1);}
        else
        {
          cout << "Invalid Selection." << endl;
        }
    }

    // Decryption prompt - selection 2
    else if (sel1 == 2)
    {
      cout << "Decryption. Are we using rotation method or cryptogram method?" << endl;
      cout << "Enter 1 for rotation, 2 for cryptogram, 3 to exit" << endl;
      cin >> sel2;
        if (sel2 == 1) // Decryption using rotation method
        {
          v = ed.encDec::getOriginalData();
          cout << "What is the decryption key?" << endl;
          cin >> decKey;
          ed.encDec::DoDecUsingRot(v, decKey);
        }
        else if (sel2 == 2) // Decryption using cryptogram method
        {
          v = ed.encDec::getOriginalData();
          cout << "Opening 'cryptogram.txt'..." << endl;
          ed.encDec::DoDecUsingCrypt(v);
        }
        else if (sel2 == 3) {exit(1);}
        else
        {
          cout << "Invalid Selection." << endl;
        }
    }
    // Exit - selection 3
    else if (sel1 == 3)
    {
      exit(1);
    }
    // Any other selection loops back to main
    else
    {
      cout << "Invalid Selection." << endl;
      rerun = true;
    }
  }
  return 0;
}
