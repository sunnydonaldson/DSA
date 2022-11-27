package strings;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Kmp {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    String text;
    String pattern;
    do {
      System.out.println("Enter a line of text:");
      text = input.nextLine();

      System.out.println("Enter a pattern to look for:");
      pattern = input.nextLine();

    } while (text == null || pattern == null);
    matchPattern(text, pattern);
  }

  public static void matchPattern(String text, String pattern) {
    List<Integer> lps = calculateLps(pattern);
    System.out.println("lps: ");
    System.out.println(lps);

    int textIdx = 0;
    int patternIdx = 0;
    while (textIdx < text.length() - pattern.length() + 1) {
      if (text.charAt(textIdx) == pattern.charAt(patternIdx)) {
        textIdx++;
        patternIdx++;
      } else {
        if (patternIdx == 0) {
          textIdx++;
        } else {
          patternIdx = lps.get(patternIdx -1);
        }
      }
      if (patternIdx == pattern.length()) {
        System.out.println(textIdx - patternIdx);
        patternIdx = lps.get(patternIdx -1);
      }
    }
  }

  private static List<Integer> calculateLps(String pattern) {
    List<Integer> lps = new ArrayList<>();

    // position 0 obviously won't match any prefix, so it's 0
    lps.add(0);
    int length = 0;
    int lpsIndex = 1;

    while (lpsIndex < pattern.length()) {
      if (pattern.charAt(lpsIndex) == pattern.charAt(length)) {
        lps.add(length + 1);
          length++;
        lpsIndex++;
      } else {
        if (length == 0) {
          lps.add(0);
          lpsIndex++;
        } else {
          length = lps.get(length -1);
        }
      }
    }
    return lps;
  }
}
