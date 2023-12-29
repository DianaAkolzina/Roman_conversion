class RomanNumerals:
    # Mapping of Roman numerals to integers
    roman_to_int_mapping = {
        'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000
    }

    # Convert Roman numeral to integer
    def roman_to_int(self, s: str) -> int:
        total = 0
        prev_value = 0
        for char in reversed(s):
            value = self.roman_to_int_mapping[char]
            if value < prev_value:
                total -= value
            else:
                total += value
            prev_value = value
        return total

    # Convert integer to Roman numeral
    def int_to_roman(self, num: int) -> str:
        value_symbols = [
            (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
            (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
            (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
        ]
        roman_numeral = ''
        for value, symbol in value_symbols:
            while num >= value:
                roman_numeral += symbol
                num -= value
        return roman_numeral

    # Find GCD of two Roman numerals
    def gcd_roman_numerals(self, num1: str, num2: str) -> str:
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        a = self.roman_to_int(num1)
        b = self.roman_to_int(num2)
        return self.int_to_roman(gcd(a, b))

    # Compare two Roman numerals
    def compare_roman_numerals(self, num1: str, num2: str) -> int:
        a = self.roman_to_int(num1)
        b = self.roman_to_int(num2)
        return (a > b) - (a < b)  # Returns 1 if a > b, -1 if a < b, 0 if equal

    # Minimize Roman numeral
    def minimize_roman_numeral(self, num: str) -> str:
        value = self.roman_to_int(num)
        return self.int_to_roman(value)


# Example usage
converter = RomanNumerals()
print(converter.roman_to_int("MCMXCIV"))  # Output: 1994
print(converter.int_to_roman(1994))       # Output: MCMXCIV
print(converter.gcd_roman_numerals("LXXII", "XXIV"))  # Output: XII (GCD of 72 and 24)
print(converter.compare_roman_numerals("X", "V"))     # Output: 1 (X is greater than V)
print(converter.minimize_roman_numeral("IIII"))      # Output: IV
