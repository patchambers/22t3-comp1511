
#include <stdio.h>

int is_lowercase(char c);
int is_uppercase(char c); 
int is_letter(char c); 
char to_lowercase(char c); 
char to_uppercase(char c); 
int is_vowel(char c); 
int count_lowercase(char *string); 
void make_vowels_uppercase(char *string); 
void delete_following_words(char *string); 


int main(void) {


    char string1[] = "COMP1511 Week 5";
    printf("String 1: %s\n", string1);
    printf("Count lowercase letters in string: %d\n", count_lowercase(string1));
    printf("\n");

    char string2[] = "Rainy days :(";
    printf("String 2: %s\n", string2);
    make_vowels_uppercase(string2);
    printf("Making vowels uppercase: \n");
    printf("%s\n", string2);
    printf("\n");
    
    char string3[] = "Look at how many words we have";
    printf("String 3: %s\n", string3);
    delete_following_words(string3);
    printf("Deleting following words: \n");
    printf("%s\n", string3);
    printf("\n");

    return 0;
}



// Returns : 1 if `c` is a lowercase letter
//         : 0 otherwise.
int is_lowercase(char c) {

    return 'a' <= c && c <= 'z';
}

// Returns : 1 if `c` is an uppercase letter
//         : 0 otherwise.
int is_uppercase(char c) {

    return 'A' <= c && c <= 'Z';
}

// Returns : 1 if `c` is a letter
//         : 0 otherwise.
int is_letter(char c) {

    return is_lowercase(c) || is_uppercase(c);
}

// Returns : `c` converted to lowercase, if it was an uppercase letter
//         : `c` unmodified, otherwise
char to_lowercase(char c) {
    if (is_uppercase(c)) {
        return c - 'A' + 'a';
    }

    return c;
}

// Returns : `c` converted to uppercase, if it was a lowercase letter
//         : `c` unmodified, otherwise
char to_uppercase(char c) {
    if (is_lowercase(c)) {
        return c - 'a' + 'A';
    }

    return c;
}

// Returns : 1 if `c` is an uppercase or lowercase vowel
//         : 0 otherwise.
int is_vowel(char c) {
    char lower_c = to_lowercase(c);

    return lower_c == 'a' 
        || lower_c == 'e'
        || lower_c == 'i' 
        || lower_c == 'o' 
        || lower_c == 'u';
}

// Functions to implement:

// 1.
// returns the number of lowercase letters in `char *string`
int count_lowercase(char *string) {
    int num_lowercase = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (is_lowercase(string[i])) {
            num_lowercase++;
        }
    }
    return num_lowercase;
}

// 2.
// modifies `char *string` by converting all its vowels to uppercase
void make_vowels_uppercase(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        // string[i] = 'a'
        if (is_vowel(string[i]) == 1) {
            string[i] = to_uppercase(string[i]);
        }
        i++;
    }
}

// 3..
// shortens a string so that it ends after the first word
// e.g. "This is a sentence" should turn into:
//      "This"
// 
// (hint. what defines when a string ends?)
void delete_following_words(char *string) {
    int i = 0;
    while (string[i] != ' ' && string[i] != '\0') {
        i++;
    }
    string[i] = '\0';
}
