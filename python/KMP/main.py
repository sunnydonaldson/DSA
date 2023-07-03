def construct_lps_table(pattern):
    lps_table = [0]
    lps_index = 1
    length = 0

    while lps_index < len(pattern):
        if pattern[lps_index] == pattern[length]:
            lps_table.append(length + 1)
            length += 1
            lps_index += 1
        else:
            if length == 0:
                lps_table.append(0)
                lps_index += 1
            else:
                length = lps_table[length - 1]
            
    return lps_table

def kmp(string, pattern):
    lps = construct_lps_table(pattern)
    i, pattern_index = 0, 0    

    while i < len(string) - len(pattern) + 1:
        if string[i] == pattern[pattern_index]:
            i += 1
            pattern_index += 1
        else:
            if pattern_index

pattern = "onion"
print(construct_lps_table(pattern))