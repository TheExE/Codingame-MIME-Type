#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

 string strToLower(string text);
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    // Map each extension to specific mime
    std:unordered_map<string,string> extensionMap;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        extensionMap.emplace(strToLower(EXT), MT); // Standartize extensions to lower case
    }                                                   
    
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        
        // Get the file extension
        int index = FNAME.find_last_of('.'); 
        if(index == -1)
        {
            // There is no file extension
            cout << "UNKNOWN" << endl;
        }
        else
        {
            // +1 since we dont want the '.' itself
            index++; 
            
            // Look for the corresponding extension in map
            string extension = strToLower(FNAME.substr(index));
            string mime = extensionMap[extension];
            if(!mime.empty())
            {
                // Mime found    
                cout << mime  << endl;    
            }
            else
            {
                // Mime not found in the map
                cout << "UNKNOWN" << endl;   
            }
        }      
    }
}

// Go trough all string and make each character lower case
string strToLower(string text)
{
    std::locale loc;
    string resultText = "";
    for(int i=0; i < text.length(); i++)
    {
        resultText += std::tolower(text[i], loc);
    }
    
    return resultText;
}