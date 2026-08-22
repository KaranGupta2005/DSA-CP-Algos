#include <bits/stdc++.h>
using namespace std;

/*
Coin Change
- We are given coins array containing coins of different denominations and a target amount
- We have to return the minimum number of coins required to make the target amount
- We can use each coin an infinite number of times

- DP array of size (amount+1)
- State : dp[i] : minimum number of coins required to make amount i
- Transition : We have multiple choices to try : each coin
             : Apply a for loop ( for (coin : coins))
             : dp[i] = min(dp[i] , 1 + dp[i - coin])
- Base Case : dp[0] = 0 ( no coins needed to be chosen )
            : if amount<0 : 1e9 ( impossible )
- We will be moving in forward direction
*/

// Memoization
vector<int> dp;
int solve(int amount , vector<int>& coins) {
    
    if(amount==0) return 0;

    if(amount < 0) return 1e9;

    if(dp[amount]!=-1) return dp[amount];

    int ans=1e9;
    for(auto &coin : coins){
        ans=min(ans , 1 + solve(amount - coin, coins));
    }
    
    return dp[amount] = ans;
}

int coinChange(vector<int>& coins, int amount) {
    dp.assign(amount + 1, -1);
    int ans = solve(amount, coins);
    return ans >= 1e9 ? -1 : ans;
}

// Tabulation
int coinChangeTab(vector<int>& coins , int amount){

    vector<int> dp(amount+1 , 1e9);
    dp[0]=0;

    for(int i=1 ; i<=amount ; i++){
        for(auto &coin : coins){
            if(i>=coin){
                dp[i] = min(dp[i] , 1 + dp[i - coin]);
            }
        }
    }
    
    return dp[amount] == 1e9 ? -1 : dp[amount];
}

/*
This is an interesting reverse Coin Change II problem.

Instead of:

coins → number of ways

you are given:

number of ways → find the coins

The key observation is that the standard Coin Change II DP is deterministic, so we can reconstruct the coins one by one.

Recall the forward DP

Given coins:

coins = [1,3]

we compute

dp[0] = 1;

for (coin : coins)
    for (amt = coin; amt <= n; amt++)
        dp[amt] += dp[amt - coin];

Each coin adds new ways.

Reverse thinking

Suppose you're given

numWays

amount : 1 2 3 4

ways   : 1 1 2 2

Initially we know nothing.

We simulate the forward DP while discovering coins.

Start with

dp

1 0 0 0 0

Here

dp[i]

means

Ways explained by the coins we've already discovered.

Process amounts from small to large
Amount = 1

Current DP says

dp[1]=0

But expected

numWays[1]=1

We're missing exactly one way.

Could that happen without coin 1?

No.

The only way to create amount 1 is with a coin of value 1.

Therefore

coin 1 exists

Add it.

Run the normal update

for (amt = 1; amt <= n; amt++)
    dp[amt] += dp[amt-1];

Now

dp

1 1 1 1 1
Amount = 2

Current

dp[2]=1

Expected

1

Already matches.

No new coin.

Amount = 3

Current

dp[3]=1

Expected

2

Missing one way.

The only explanation is

coin 3 exists

because smaller coins have already been fully processed.

Add coin 3.

Update

for(amt=3; amt<=n; amt++)
    dp[amt]+=dp[amt-3];

Now

dp

1 1 1 2 2

Exactly matches.

Recovered coins

1 3
Why is this greedy approach correct?

Suppose you're processing amount i.

All coins smaller than i have already been considered.

So dp[i] already contains every possible way using those smaller coins.

There are only three cases.

Case 1
dp[i] == numWays[i]

Perfect.

No coin of value i.

Case 2
dp[i] > numWays[i]

Impossible.

You've already generated too many ways.

Adding more coins only increases counts.

So answer is

[]
Case 3
dp[i] < numWays[i]

Can the difference be more than 1?

No.

If coin i exists, it contributes exactly one new way to make amount i:

{i}

since no previously discovered coin can contribute to dp[0] except the empty combination, and the update adds dp[0] = 1 to dp[i].

Therefore:

If the difference is exactly 1, coin i must exist.
If the difference is greater than 1, it's impossible.
Algorithm
dp[0]=1

for i=1 to n

    if dp[i] > numWays[i]
        return {}

    if dp[i] < numWays[i]

        if numWays[i]-dp[i] != 1
            return {}

        answer.push_back(i)

        for amt=i to n
            dp[amt]+=dp[amt-i]
Complexity

Let n = numWays.size().

Outer loop: n
DP update for each discovered coin: up to n

So the total time complexity is:

O(n²)

Space complexity:

O(n)
C++ Implementation
class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> ans;

        for (int coin = 1; coin <= n; coin++) {

            if (dp[coin] > numWays[coin - 1])
                return {};

            if (dp[coin] < numWays[coin - 1]) {

                if (numWays[coin - 1] - dp[coin] != 1)
                    return {};

                ans.push_back(coin);

                for (int amt = coin; amt <= n; amt++) {
                    dp[amt] += dp[amt - coin];
                }
            }
        }

        return ans;
    }
};

The crucial insight is that when processing amount i, every effect of coins smaller than i has already been accounted for. Therefore, the only possible source of any remaining deficit at amount i is the presence of a coin with denomination exactly i. This makes the greedy reconstruction both natural and correct.

not understood 

No problem—this problem is not obvious at all. The trick is to think about how Coin Change II builds the DP. Let's go very slowly.

Step 1: Remember Coin Change II

Suppose the coins are

coins = [1,3]

The DP starts with

dp = [1,0,0,0,0]

where

dp[i] = number of ways to make amount i

Now process coin 1.

dp[1] += dp[0]
dp[2] += dp[1]
dp[3] += dp[2]
dp[4] += dp[3]

Now

dp = [1,1,1,1,1]

Meaning

1 -> {1}

2 -> {1+1}

3 -> {1+1+1}

4 -> {1+1+1+1}

Now process coin 3.

dp[3]+=dp[0]

1+1=2

because

3

and

1+1+1

are two ways.

Then

dp[4]+=dp[1]

1+1=2

because

1+3

1+1+1+1

Now

dp=[1,1,1,2,2]

Now forget the coins.

Suppose someone only gives you

numWays

1 1 2 2

Can we recover the coins?

YES.

Step 2: Start with NO coins

Initially

dp=[1,0,0,0,0]

This means

"I haven't discovered any coin yet."

Look at amount 1

Expected

numWays[1]=1

Current DP

dp[1]=0

Question:

Can I make amount 1 without a coin of value 1?

No.

Because every coin is larger than 1.

Therefore

coin 1 MUST exist.

After discovering coin 1

we simulate exactly what Coin Change II would have done.

Update

dp=[1,1,1,1,1]
Step 3: Look at amount 2

Expected

1

Current

1

Already matches.

So do we need a coin 2?

No.

Because smaller coins already explain everything.

Step 4: Look at amount 3

Expected

2

Current

1

One way is missing.

Question:

Could that missing way come from coin 2?

No.

We already decided coin 2 doesn't exist.

Could it come from coin 1?

Impossible.

Coin 1 has already contributed all its ways.

The ONLY remaining possibility is

coin 3 exists.

Add it.

Update DP.

Now

dp=[1,1,1,2,2]

Everything matches.

Recovered coins

1 3
Why can we safely decide at amount i?

This is the MOST IMPORTANT IDEA.

Suppose we are currently checking

amount = 5

Before reaching 5, we have already decided whether

coin 1 exists

coin 2 exists

coin 3 exists

coin 4 exists

So the DP already contains all combinations made using coins smaller than 5.

Nothing else can suddenly create new ways for amount 5 except:

adding a coin of value 5.

That's why we process amounts from small to large.

Another Example

Suppose

numWays

amount

1 2 3 4

ways

0 1 0 1

Start

dp

1 0 0 0 0

Amount=1

Expected

0

Current

0

Matches.

No coin 1.

Amount=2

Expected

1

Current

0

Missing one way.

Only explanation

coin 2 exists.

Update

dp

1 0 1 0 1

Amount=3

Expected

0

Current

0

Matches.

No coin 3.

Amount=4

Expected

1

Current

1

Matches.

No coin 4.

Recovered coins

2

Correct.

The Greedy Rule

At each amount i:

Current DP = ways explained by the coins we've already discovered.

Now compare it with the required answer.

Case 1
dp[i] == numWays[i]

Everything is already explained.

➡️ No coin i.

Case 2
dp[i] < numWays[i]

Some ways are missing.

The only denomination that can introduce new combinations whose smallest new coin is exactly i is coin i itself.

➡️ Coin i must exist.

Then immediately update the DP, just like in Coin Change II.

Case 3
dp[i] > numWays[i]

You've already created too many ways using smaller coins.

Adding more coins can never decrease the number of ways.

➡️ Impossible → return {}.

One question for you

Suppose you're given:

numWays = [1, 2]

That means:

amount 1 → 1 way
amount 2 → 2 ways

Can you try applying the above process manually and tell me which coins you think exist? We'll walk through it together.
*/