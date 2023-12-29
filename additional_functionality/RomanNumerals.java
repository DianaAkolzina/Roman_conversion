import java.util.LinkedHashMap;
import java.util.Map;

public class RomanNumerals {
    private static final LinkedHashMap<Integer, String> intToRomanMap = new LinkedHashMap<>();
    static {
        intToRomanMap.put(1000, "M");
        intToRomanMap.put(900, "CM");
        intToRomanMap.put(500, "D");
        intToRomanMap.put(400, "CD");
        intToRomanMap.put(100, "C");
        intToRomanMap.put(90, "XC");
        intToRomanMap.put(50, "L");
        intToRomanMap.put(40, "XL");
        intToRomanMap.put(10, "X");
        intToRomanMap.put(9, "IX");
        intToRomanMap.put(5, "V");
        intToRomanMap.put(4, "IV");
        intToRomanMap.put(1, "I");
    }

    public static int romanToInt(String s) {
        Map<Character, Integer> romanToIntMap = Map.of('I', 1, 'V', 5, 'X', 10, 'L', 50, 'C', 100, 'D', 500, 'M', 1000);
        int total = 0, prevValue = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int value = romanToIntMap.get(s.charAt(i));
            total = value < prevValue ? total - value : total + value;
            prevValue = value;
        }
        return total;
    }

    public static String intToRoman(int num) {
        StringBuilder roman = new StringBuilder();
        for (Map.Entry<Integer, String> entry : intToRomanMap.entrySet()) {
            while (num >= entry.getKey()) {
                roman.append(entry.getValue());
                num -= entry.getKey();
            }
        }
        return roman.toString();
    }

    // Find GCD of two Roman numerals
    public static String gcdRomanNumerals(String num1, String num2) {
        int a = romanToInt(num1);
        int b = romanToInt(num2);
        return intToRoman(gcd(a, b));
    }

    // Compare two Roman numerals
    public static int compareRomanNumerals(String num1, String num2) {
        int a = romanToInt(num1);
        int b = romanToInt(num2);
        return Integer.compare(a, b);
    }

    // Convert to minimal Roman numeral form
    public static String minimizeRomanNumeral(String num) {
        int value = romanToInt(num);
        return intToRoman(value);
    }

    // Helper method for GCD calculation
    private static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        // Example usage
        String num1 = "MCMXCIV"; // 1994
        String num2 = "XLII";    // 42

        System.out.println("GCD of " + num1 + " and " + num2 + " is: " 
            + gcdRomanNumerals(num1, num2)); // Output: XII (GCD of 1994 and 42)
        System.out.println("Comparison of " + num1 + " and " + num2 + ": " 
            + compareRomanNumerals(num1, num2)); // Output: 1 (num1 is greater than num2)
        System.out.println("Minimized form of 'IIII' is: " 
            + minimizeRomanNumeral("IIII")); // Output: IV
    }
}
