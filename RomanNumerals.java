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
}
