#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class RomanNumerals {
private:
    map<char, int> romanToIntMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    vector<pair<int, string>> intToRomanMap = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

public:
    // Convert Roman numeral to integer
    int romanToInt(string s) {
        int total = 0;
        int prev_value = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int value = romanToIntMap[s[i]];
            if (value < prev_value)
                total -= value;
            else
                total += value;
            prev_value = value;
        }
        return total;
    }

    // Convert integer to Roman numeral
    string intToRoman(int num) {
        string roman;
        for (auto& pair : intToRomanMap) {
            while (num >= pair.first) {
                roman += pair.second;
                num -= pair.first;
            }
        }
        return roman;
    }

    // Validate Roman numeral
    bool isValidRomanNumeral(const string& s) {
        regex pattern("^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
        return regex_match(s, pattern);
    }

    // Add two Roman numerals
    string addRomanNumerals(const string& num1, const string& num2) {
        int sum = romanToInt(num1) + romanToInt(num2);
        return intToRoman(sum);
    }

    // Subtract two Roman numerals
    string subtractRomanNumerals(const string& num1, const string& num2) {
        int diff = romanToInt(num1) - romanToInt(num2);
        return diff > 0 ? intToRoman(diff) : "Invalid Operation";
    }

    // Multiply two Roman numerals
    string multiplyRomanNumerals(const string& num1, const string& num2) {
        int product = romanToInt(num1) * romanToInt(num2);
        return intToRoman(product);
    }

    // Divide one Roman numeral by another
    string divideRomanNumerals(const string& num1, const string& num2) {
        int dividend = romanToInt(num1);
        int divisor = romanToInt(num2);
        if (divisor == 0) return "Invalid Operation - Division by Zero";
        int quotient = dividend / divisor;
        return quotient > 0 ? intToRoman(quotient) : "Invalid Operation";
    }
    // Find GCD of two Roman numerals
    string gcdRomanNumerals(const string& num1, const string& num2) {
        int a = romanToInt(num1);
        int b = romanToInt(num2);
        return intToRoman(gcd(a, b));
    }

    // Compare two Roman numerals
    int compareRomanNumerals(const string& num1, const string& num2) {
        int a = romanToInt(num1);
        int b = romanToInt(num2);
        if (a < b) return -1;
        else if (a > b) return 1;
        else return 0;
    }

    // Convert to minimal Roman numeral form
    string minimizeRomanNumeral(const string& num) {
        int value = romanToInt(num);
        return intToRoman(value);
    }
};


int main() {
    RomanNumerals converter;
    string num1 = "MCMXCIV"; // 1994
    string num2 = "XLII";    // 42

    cout << "Sum of " << num1 << " and " << num2 << " is: " 
         << converter.addRomanNumerals(num1, num2) << endl;
    cout << "Difference between " << num1 << " and " << num2 << " is: " 
         << converter.subtractRomanNumerals(num1, num2) << endl;
    cout << "Product of " << num1 << " and " << num2 << " is: " 
         << converter.multiplyRomanNumerals(num1, num2) << endl;
    cout << "Quotient of " << num1 << " divided by " << num2 << " is: " 
         << converter.divideRomanNumerals(num1, num2) << endl;
  
    // GCD of two Roman numerals
    cout << "GCD of " << num1 << " and " << num2 << " is: "
         << converter.gcdRomanNumerals(num1, num2) << endl;

    // Compare two Roman numerals
    int comparisonResult = converter.compareRomanNumerals(num1, num2);
    cout << "Comparison of " << num1 << " and " << num2 << ": "
         << (comparisonResult == 0 ? "Equal" : (comparisonResult < 0 ? "Less" : "Greater")) << endl;

    // Minimize Roman numeral
    string num3 = "IIII"; // Incorrect representation of 4
    cout << "Minimized form of " << num3 << " is: "
         << converter.minimizeRomanNumeral(num3) << endl;

    return 0;
}
