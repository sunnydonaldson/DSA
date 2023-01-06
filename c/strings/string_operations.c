#include "string_operations.h"
#include "../helpers/arrayhelper.h"
#include <stdio.h>
#include <assert.h>

static int IsUppercase(char c);
static int IsLowercase(char c);

int length_str(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

void to_uppercase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (IsLowercase(str[i]))
            str[i] = str[i] - 32;
    }
}

void to_lowercase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (IsUppercase(str[i]))
            str[i] = str[i] + 32;
    }
}

void toggle_case(char str[])
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (IsLowercase(str[i]))
            str[i] = str[i] - 32;
        else if (IsUppercase(str[i]))
            str[i] = str[i] + 32;
    }
}

void trim(char str[])
{
    int length = length_str(str);
    int count;
    int right_count;
    int i;
    for (count = 0; str[count] == '\n' || str[count] == ' '; count++);
    for (right_count = 0; str[length - right_count -1] == '\n' || str[length - right_count -1] == ' '; right_count++);
    if  (count > 0 || right_count > 0) {
        for (i = count; i < length - right_count; i++)
            str[i - count] = str[i];
        str[i - count] = '\0';
    }


}

int count_words(char str[])
{
    trim(str);
    int space_count = 0;
    for (int i = 0; i < length_str(str); i++)
        if (str[i] == ' ' && str[i -1] != ' ')
            space_count++;
    return space_count + 1;
}

void reverse(char str[])
{
    char tmp;
    for (int i = 0, j = length_str(str) -1; i < j; i++, j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

/** Returns -1 if the first string is greater than the second, 0 if equal, 1 if greater. */
int compare(char A[], char B[])
{
    int i;
    for (i = 0; A[i] != '\0' && B[i] != '\0'; i++) {
        if (A[i] != B[i]) {
            break;
        }
    }

    if (A[i] == B[i]) {
        return 0;
    } else if (A[i] < B[i]) {
        return -1;
    } else {
        return 1;
    }
}

int IsPallindrome(char arr[])
{
    for (int i = 0, j = length_str(arr) -1; i < j; i++, j--) {
        if (arr[i] != arr[j]) {
            return 0;
        }
    }
    return 1;
}

/** Returns true if the two strings are anagrams. */
int IsAnagram(char A[], char B[])
{
  int i;
  int seenChars[122];
  fillValues(seenChars, 122, 0);
  for (i = 0; A[i] != '\0'; i++) {
    seenChars[A[i]]++;
  }

  for (int j = 0; B[j] != '\0'; j++) {
    if (j > i || --seenChars[B[j]] < 0) {
      return 0;
    } 
  }

  for (int i = 0; i < 122; i++) {
    if (seenChars[i] != 0) {
      return 0;
    }
  }
  return 1;
}

/** Prints the duplicated characters. */
void FindDuplicates(char str[])
{
  trim(str);
  int char_counts[122];
  fillValues(char_counts, 122, 0);

  for (int i = 0; str[i] != '\0'; i++) {
    if (char_counts[str[i]] > 0) {
      printf("%c duplicated at %i\n", str[i], i);
    }
    char_counts[str[i]]++;
  }
}

/** Prints the duplicated characters. */
void FindDuplicatesBitManipulation(char str[])
{
  long int seenValues = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    assert(str[i] >= 97 && str[i] <= 122);
    long int mask = 1;
    mask = mask << (str[i] - 97);
    if (seenValues & mask) {
      printf("%c duplicated at %d\n", str[i], i);
    }
    seenValues = seenValues | mask;
  }
}

static int IsUppercase(char c)
{
    return c >= 65 && c <= 90;
}

static int IsLowercase(char c)
{
    return c >= 97 && c <= 122;
}

static int IsAlphaNumeric(char c)
{
  return IsLowercase(c) || IsUppercase(c);
}
