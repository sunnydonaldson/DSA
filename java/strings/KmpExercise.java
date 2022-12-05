package strings;

import java.util.List;
import java.util.ArrayList;

final class KmpExercise {
    public static final List<Integer> matchPattern(String patternToFind, String text) {
        List<Integer> startingIndecesOfMatches = new ArrayList<>();
        List<Integer> lps = calculateLps(patternToFind);
        
        int patternIndex = 0;
        int currentIndex = 0;
        while (currentIndex < text.length()) {
            if (text.charAt(currentIndex) == patternToFind.charAt(patternIndex)) {
                patternIndex++;
                currentIndex++;
            } else {
                if (patternIndex == 0) {
                    currentIndex++;
                } else {
                    patternIndex = lps.get(patternIndex -1);
                }
            }
            if (patternIndex == patternToFind.length()) {
                startingIndecesOfMatches.add(currentIndex - patternIndex);
                patternIndex = lps.get(patternIndex -1);
            }
        }
        return startingIndecesOfMatches;
    }

    private static final List<Integer> calculateLps(String pattern) {
        int length = 0;
        int currentIndex = 1;

        List<Integer> lps = new ArrayList<>();
        lps.add(length);

        while (currentIndex < pattern.length()) {
            if (pattern.charAt(currentIndex) == pattern.charAt(length)) {
                lps.add(++length);
                currentIndex++;
            } else {
                if (length== 0) {
                    lps.add(0);
                    currentIndex++;
                } else {
                    length = lps.get(length -1);
                }
            }
        }
        return lps;

    }

}