Problem Explanation:
"Imagine you have 'n' dice, each with 'k' faces numbered from 1 to 'k.' The goal is to find the number of ways to roll these dice so that the sum of the face-up numbers equals a given target. The challenge is to calculate this count, and since the result can be quite large, we're required to return it modulo 10^9 + 7."

Example:
"Let's take an example to illustrate the problem. Suppose you have 2 dice, each with 6 faces (k=6), and you want the sum to be 7. How many ways can you achieve this? The answer is 6! There are 6 different combinations: 1+6, 2+5, 3+4, 4+3, 5+2, and 6+1."

Approach:
"To solve this problem, we'll use dynamic programming. We'll create a 2D array where dp[i][j] represents the number of ways to obtain a sum of 'j' using 'i' dice. We'll iterate through the dice, the target sum, and the possible faces on each die to calculate the count of ways. The base case is when there are no dice (i=0), and the sum is 0, which is 1 way."

Pseudocode:

plaintext
Copy code
dp[0][0] = 1

for i = 1 to n
    for j = 1 to target
        for face = 1 to k
            if (j - face >= 0)
                dp[i][j] += dp[i-1][j-face]

return dp[n][target] % (10^9 + 7)
Code Explanation:
"I've implemented this in C++. We initialize a 2D vector 'dp' to store our results. We iterate through the number of dice, the target sum, and the faces on each die, updating the count. Finally, we return the result modulo 10^9 + 7 to avoid overflow."



#include <vector>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int face = 1; face <= k; ++face) {
                    if (j - face >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                    }
                }
            }
        }

        return dp[n][target];
    }
};


python code - 
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        MOD = 10**9 + 7
        dp = [[0] * (target + 1) for _ in range(n + 1)]

        # Base case: 1 way to get a sum of 0 with 0 dice
        dp[0][0] = 1

        for i in range(1, n + 1):
            for j in range(1, target + 1):
                for face in range(1, k + 1):
                    if j - face >= 0:
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD

        return dp[n][target]

# Example usage
solution = Solution()
result = solution.numRollsToTarget(2, 6, 7)
print(result)



java solution : 

class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        // Define the modulo value to avoid integer overflow
        final int MOD = 1000000007;
        
        // Create a 2D array to store the results
        int[][] dp = new int[n + 1][target + 1];

        // Base case: 1 way to get a sum of 0 with 0 dice
        dp[0][0] = 1;

        // Dynamic Programming: Fill the dp array
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int face = 1; face <= k; ++face) {
                    // Check if the current face is valid for the current target
                    if (j - face >= 0) {
                        // Update the dp array by adding the ways from the previous dice
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                    }
                }
            }
        }

        // The final result is stored in the bottom-right cell of the dp array
        return dp[n][target];
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        int result = solution.numRollsToTarget(2, 6, 7);
        System.out.println(result);
    }
}




