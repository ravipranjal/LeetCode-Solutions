// Time:  O((m + n)logn), m is the number of queries, n is the number of words
// Space: O(n)

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*Helper function to calculate frequency of smallest element*/
int getF(string &s){
    int a[26] = {0,};
    for(int i = 0; i < s.size(); i++){
        a[s[i]-'a']++;
    }
    
    for(int i = 0; i < 26; i++){
        if(a[i] != 0) return a[i];
    }
    return 0;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fr(12, 0);
    int f;
    vector<int> q;
    for(int i = 0; i < words.size(); i++){
        f = getF(words[i]);
        fr[f]++;
    }
    //Find cumulative frequency i.e. ith item will have sum of i..end.
    for(int i = 9; i >= 0; i--){
        fr[i] = fr[i] + fr[i+1];
    }
    
    for(int i = 0; i < queries.size(); i++){
        f = getF(queries[i]);
        q.push_back(fr[f+1]);
    }
    return q;
}


int main() {
    char queries[5][5];
    char words[5][5];
    int n;
    cout<<"Enter the number of queries: ";
    cin>>n;

    vector<string> q;
    vector<string> w;

    cout<<"Enter query and word: "<<endl;
    for(int i=0; i<n; i++) {
        scanf("%50s", &queries[i]);
        q.push_back(queries[i]);

        scanf("%50s", &words[i]);
        w.push_back(words[i]);
    }


    vector<int> ans = numSmallerByFrequency(q, w);

    cout<<"Answer is: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }

    return 0;
}
