
#include <bits/stdc++.h>

using namespace std;

string lcp(vector<string>& word){
    string answer;
    
     if (word.empty()){
         return "";
     }
     
    int minLen = word[0].length();
    
     for (const string& str : word){
          minLen = min(minLen, static_cast<int>(str.length()));
     }
       
   for (int i = 0; i < minLen; ++i) {
        char c = word[0][i];
        
        for (size_t j = 1; j < word.size(); ++j) {
            if (word[j][i] != c) {
                // If a mismatch is found, skip the current word and continue with the next one.
                continue;
            }
        }
        
        // If all characters matched for all words at index 'i', add the character to the answer.
        answer.push_back(c);
    }
      return answer;
}

int main() {
   string paragraph = "apple bapple app";

transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower);

    // Use stringstream to tokenize the paragraph into words
    stringstream ss(paragraph);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    // for (const string& w : words) {
    //     cout << w << endl;
    // }

    string f = lcp(words);
    cout << "Longest Common Prefix: " << f << endl;

    return 0;
}
