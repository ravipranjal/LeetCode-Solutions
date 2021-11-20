// Time:  O(n)
// Space: O(1)
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int compress(vector<char>& chars, int write) {
    int anchor = 0;
    for (int read = 0; read < chars.size(); ++read) {
        if (read + 1 == chars.size() || chars[read + 1] != chars[read]) {
            chars[write++] = chars[read];
            if (read - anchor > 0) {
                int n = read - anchor + 1, cnt = 0;
                while (n > 0) {
                    chars[write++] = n % 10 + '0';
                    n /= 10;
                    ++cnt;
                }
                reverse(chars.begin() + write - cnt, chars.begin() + write);
            }
            anchor = read + 1;
        }
    }

    return write;
}

int main() {
    vector<char> chars(3);
    int write;

    cout<<"Enter the write size: ";
    cin>>write;
    cout<<endl;

    cout<<"Enter the chars input array of size 3"<<endl;
    char ch;
    for(int i=0; i<3; i++) {
        cin>>ch;
        chars.push_back(ch);
    }


    int ans = compress(chars, write);
    cout<<"Write is: "<<ans;

    return 0;
}
