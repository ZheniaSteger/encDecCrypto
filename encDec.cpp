//============================================================================
// Author      : Zhenia Steger
// Description : Class to perform encryption/decryption of a text file.
//============================================================================

#include "encDec.h"

using namespace std;

// Constructor
encDec::encDec() {}

// Destructor
encDec::~encDec() {}

// PURPOSE: Gets the text from the file to be encrypted or decrypted.
// PARAMETERS: None
// RETURNS: Vector with individual words from un-encrypted file.
vector<string> encDec::getOriginalData()
{
  vector<string> originalV;
  ifstream fin;
  string fname;
  cout << "What is the name of the file to be Encrypted/Decrypted?" << endl;
  cin >> fname;
  fin.open(fname.data());
  string word;
  while (fin >> word)
    {
      originalV.push_back(word);
    }
  fin.close();
  return originalV;
}

// PURPOSE: Encodes using rotation method.
// PARAMETERS: Takes a vector of words and number of characters to rotate by as parameters.
// RETURNS: Nothing.
void encDec::DoEncUsingRot(vector<string> v, int rotNum)
{
  vector<string> EncV;
  ofstream encrypt01;
  encrypt01.open("encryptRot.txt");

  for (int i = 0; i < v.size(); i++)
  {
    string DecWord = EncWordUsingRot(v[i], rotNum);
    EncV.push_back(DecWord);
  }
  for (int i = 0; i < EncV.size(); i++)
    encrypt01 << EncV[i] << " ";
  encrypt01.close();
}

// PURPOSE: Encodes individual word from a vector.
// PARAMETERS: Takes a string and number of characters to rotate by as parameters.
// RETURNS: Encoded string according to the rotation key.
string encDec::EncWordUsingRot(string word, int rotNum)
{
  char ch;
  string EncWord = word;
  word = toLowerCase(word);
  for (int i = 0; i < word.size(); i++)
  {
    ch = word[i];
    if (ch >= 'a' && ch <= 'z')
      EncWord[i] = (word[i] + rotNum) % 26 + 'a';
    else EncWord[i] = ch;
  }
  return EncWord;
}

// PURPOSE: Decodes using rotation method.
// PARAMETERS: Takes a vector of words and number of characters to rotate by as parameters.
// RETURNS: Nothing.
void encDec::DoDecUsingRot(vector<string> v, int rotNum)
{
  vector<string> DecV;
  ofstream decrypt01;
  decrypt01.open("decryptRot.txt");

  for (int i = 0; i < v.size(); i++)
  {
    string DecWord = DecWordUsingRot(v[i], rotNum);
    DecV.push_back(DecWord);
  }
  for (int i = 0; i < DecV.size(); i++)
    decrypt01 << DecV[i] << " ";
  decrypt01.close();
}

// PURPOSE: Decodes individual word from a vector.
// PARAMETERS: Takes a string and number of characters to rotate by as parameters.
// RETURNS: Decoded string according to rotation key.
string encDec::DecWordUsingRot(string word, int rotNum)
{
  char ch;
  string EncWord = word;
  for (int i = 0; i < word.size(); i++)
  {
    ch = word[i];
    if (ch >= 'a' && ch <= 'z')
      EncWord[i] = (word[i] + rotNum) % 26 + 'a';
    else EncWord[i] = ch;
  }
  return EncWord;
}

// PURPOSE: Encodes using the cryptogram method.
// PARAMETERS: Takes a vector of words as a parameter.
// RETURNS: Nothing.
void encDec::DoEncUsingCrypt(vector<string> v)
{
  vector<string> EnCryptV;
  string word, theCryptogram;
  char ch;
  int index;
  ifstream cryptogram;
  cryptogram.open("cryptogram.txt");
  cryptogram >> theCryptogram;
  cryptogram.close();
  ofstream encrypt02;
  encrypt02.open("encryptCrypt.txt");

  for (int i = 0; i < v.size(); i++)
  {
    word = v[i];
    word = toLowerCase(word);

    for (int j = 0; j < word.size(); j++)
    {
      ch = word[j];
      if (ch >= 'a' && ch <= 'z')
      {
        index = ch - 'a';
        word[j] = theCryptogram[index];
      }
    }
    EnCryptV.push_back(word);
  }
  for (int i = 0; i < EnCryptV.size(); i++)
    encrypt02 << EnCryptV[i] << " ";
  encrypt02.close();
}

// PURPOSE: Decodes using the cryptogram method.
// PARAMETERS: Takes a vector of words as a parameter.
// RETURNS: Nothing.
void encDec::DoDecUsingCrypt(vector<string> v)
{
  vector<string> DeCryptV;
  string word, theCryptogram;
  char ch, ch2;
  int index = 0;
  ifstream cryptogram;
  cryptogram.open("cryptogram.txt");
  cryptogram >> theCryptogram;
  cryptogram.close();
  ofstream decrypt02;
  decrypt02.open("decryptCrypt.txt");

  for (int i = 0; i < v.size();  i++)
  {
    word = v[i];

    for (int j = 0; j < word.size(); j++)
    {
      index = 0;
      ch = word[j];
      if (ch >= 'a' && ch <= 'z')
      {
        for (int k = 0; !(ch == theCryptogram[k]); k++)
          index = k;
        ch2 = index + 'a';
      }
      else ch2 = ch;
      word[j] = ch;
    }
    DeCryptV.push_back(word);
  }
  for (int i = 0; i < DeCryptV.size(); i++)
    decrypt02 << DeCryptV[i] << " ";
  decrypt02.close();
}

// PURPOSE: Prints vector of words
// PARAMETERS: Takes a vector of words as a parameter.
// RETURNS: Prints on screen the vector delimited by spaces.
void encDec::PrintWordFromVector(vector<string> v)
{
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
}

// PURPOSE: Converts all characters in a string to lower case.
// PARAMETERS: Takes a string as a parameter.
// RETURNS: String converted to lower case.
string encDec::toLowerCase(string s)
{
  for (int i = 0; i < s.size(); i++)
    s[i] = tolower(s[i]);
  return s;
}
