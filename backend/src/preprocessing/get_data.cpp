//
// Created by NouiliKh on 15.03.20.
//

#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

class GetData
{
public:
    string fileName;
    vector <string> data;
    //Default constructor
    GetData(string fileName)
    {
        this->fileName = fileName;
    }

    vector <string> readData()
    {
        vector <string> data;
        vector<string> filesPath;

        for (const auto & entry : fs::directory_iterator(this->fileName)) {
            filesPath.push_back(entry.path());
        };

        sort(filesPath.begin(), filesPath.end()) ;

        for (auto & filePath : filesPath)
        {
            ifstream infile(filePath);
            while (infile)
            {
                string s;
                if (!getline( infile, s )) break;
                istringstream ss( s );
                data.push_back(s);
            }
        }
        return data;
    }
};