package strings;

import static org.junit.Assert.assertEquals;

import java.util.List;

import org.junit.Test;

public class KmpExerciseTest {
    @Test
    public void testTextWithRepeatedPattern_returnsMultiple() {
        String patternToFind = "onions";
        String text = "anonionionsab";

        List<Integer> result = KmpExercise.matchPattern(patternToFind, text);
        assertEquals(1, result.size());

        int firstStartingIndex = result.get(0);
        assertEquals(2, firstStartingIndex);
    }
}
