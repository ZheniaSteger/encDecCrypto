//============================================================================
// Author      : Zhenia Steger
// Description : Header for encDec.
//============================================================================

#ifndef ENCDEC_H
#define ENCDEC_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class encDec
{
  public:
    class FileNotFound{}; // Error handling class

    // Constructor
    encDec();
    // Destructor
    ~encDec();

    // PURPOSE: Gets the text from the file to be encrypted or decrypted.
    vector<string> getOriginalData();

    // PURPOSE: Encodes using rotation method.
    void DoEncUsingRot(vector<string> v, int rotNum);

    // PURPOSE: Encodes individual word from a vector.
    string EncWordUsingRot(string word, int rotNum);

    // PURPOSE: Decodes using rotation method.
    void DoDecUsingRot(vector<string> v, int rotNum);

    // PURPOSE: Decodes individual word from a vector.
    string DecWordUsingRot(string word, int rotNum);

    // PURPOSE: Encodes using the cryptogram method.
    void DoEncUsingCrypt(vector<string> v);

    // PURPOSE: Decodes using the cryptogram method.
    void DoDecUsingCrypt(vector<string> v);

  private:
    vector<string> EncV; // Vector for encryptions
    vector<string> DecV; // Vector for decryptions

    // PURPOSE: Prints vector of words
    void PrintWordFromVector(vector<string> v);

    // PURPOSE: Converts all characters in a string to lower case.
    string toLowerCase(string s);

};
#endif
