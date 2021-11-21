// Time:  O(n * m)
// Space: O(m)

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int change(int amount, vector<int>& coins, int n) {
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int j=0; j<n; j++) {
        int coin = coins[j];
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

int main() {
    vector<int> coins(5);
    int n, amount = 100;
    cout<<"Enter the number of coins: ";
    cin>>n;

    for(int i=0; i<n; i++) {
        scanf("%d", &coins[i]);
    }
    cout<<"Minimum coin change required is: "<<change(amount, coins, n);

    return 0;
}
