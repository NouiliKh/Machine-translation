//
// Created by NouiliKh on 17.03.20.
//

#include "get_data.cpp"
#include <vector>
#include <regex>
#include<iostream>

class PreprocessData
{
public:
    string dataPath;

     // default constructor
     PreprocessData(string dataPath)
     {
         this->dataPath = dataPath;
         GetData data = GetData(this->dataPath);
         vector<string> rawData = data.readData();
         vector<vector<string>> tokenized;

         // remove tag lines
         cmatch m;
         regex e ("<(.+?)>");
         rawData.erase(remove_if(rawData.begin(), rawData.end(), [e](string x){ return regex_match(x.begin(), x.end(), e)  or x.length() ==0 ;}), rawData.end());

         for ( auto & i : rawData) {

             // convert messages to lowercase
             transform(i.begin(), i.end(), i.begin(), ::tolower);
             // Remove Punctuation
             i.erase(remove_if(i.begin (), i.end (), ::ispunct), i.end());
             // tokenize
             vector<string> tokens;
             string word;
             istringstream iss(i);
             while (getline(iss, word, ' ')) {
                 tokens.push_back(word);
             }
             tokenized.push_back(tokens);
         }

         int a = 0 ;

     }


};