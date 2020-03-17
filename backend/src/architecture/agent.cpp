//
// Created by NouiliKh on 17.03.20.
//

#include "../preprocessing/preprocess_data.cpp"
#include <string>

using namespace std;

class Agent
{
public:
    string dataBasePath = "../../data/";
    string agentLanguage;

    Agent(string agentLanguage)
    {
        this->agentLanguage = agentLanguage;
        PreprocessData data_preprocessed = PreprocessData(dataBasePath + agentLanguage);
        // vector<string> rawData = data_preprocessed.rawData;
    }


};