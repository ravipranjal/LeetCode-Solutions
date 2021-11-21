// Time:  O(n * l^2)
// Space: O(n * l)

#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_set>

using namespace std;

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> lookup(words.begin(), words.end());
    vector<string> result;
    for (const auto& word : words) {
        vector<bool> dp(word.length() + 1);
        dp[0] = true;
        for (int i = 0; i < word.length(); ++i) {
            if (!dp[i]) {
                continue;
            }
            for (int j = i + 1; j <= word.length(); ++j) {
                if (j - i < word.length() && lookup.count(word.substr(i, j - i))) {
                    dp[j] = true;
                }
            }
            if (dp[word.length()]) {
                result.emplace_back(word);
                break;
            }
        }
    }
    return result;
}

int main() {
    char words[5][3];
    int n;
    cout<<"Enter the number of words followed by the words: ";
    cin>>n;
    vector<string> w;

    for(int i=0; i<n; i++) {
        scanf("%50s", &words[i]);
        w.push_back(words[i]);
    }

    vector<string> ans = findAllConcatenatedWordsInADict(w);
    cout<<"The answer is: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}
