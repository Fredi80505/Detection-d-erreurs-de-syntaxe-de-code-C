#include <stdio.h>

int main() {
    char str[1000];
    int start = 0, end = 0, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[end] != '\0') {
        end++;
    }
    end--;

   
    while (start < end) {
        if (str[start] != str[end]) {
            isPalindrome = 0; 
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
