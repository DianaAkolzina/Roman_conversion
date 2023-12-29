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

# Example usage
converter = RomanNumerals()
print(converter.roman_to_int("MCMXCIV"))  # Output: 1994
print(converter.int_to_roman(1994))        # Output: MCMXCIV
