#include <iostream>
#include <vector>

// Function to find the longest common substring
std::string longestCommonSubstring(const std::string& str1, const std::string& str2) {
    // Get the lengths of the input strings
    size_t len1 = str1.length();
    size_t len2 = str2.length();

    // Initialize a 2D table to store the lengths of common substrings
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

    // Variables to store the length of the longest common substring and its ending position
    int maxLength = 0;
    int endIndex = 0;

    // Populate the table and find the longest common substring
    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    // Extract the longest common substring
    std::string result = str1.substr(endIndex - maxLength + 1, maxLength);

    return result;
}

int main() {
    // Example usage
    std::string str1 = "ABAB";
    std::string str2 = "BABA";

    // Find the longest common substring
    std::string lcs = longestCommonSubstring(str1, str2);

    // Output the result
    std::cout << "Longest Common Substring: " << lcs << std::endl;

    return 0;
}
