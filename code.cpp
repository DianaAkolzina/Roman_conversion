#include <iostream>
#include <map>
#include <vector>
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
};

int main() {
    RomanNumerals converter;
    cout << converter.romanToInt("MCMXCIV") << endl; // Output: 1994
    cout << converter.intToRoman(1994) << endl;      // Output: MCMXCIV
    return 0;
}
