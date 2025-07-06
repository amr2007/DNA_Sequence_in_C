#include <stdio.h>  // for input/output functions like printf and scanf
#include <string.h> // for string functions (not used much but helpful)
#include <ctype.h>  // for toupper() to convert lowercase to uppercase

int main()
{
    char input_dna[100];                 // declare an array to store the DNA sequence (max 99 chars + 1 for '\0')
    printf("Enter the DNA sequence:\n"); // ask user to enter DNA
    scanf("%s", input_dna);              // read DNA string from user

    int valid = 1; // we start by assuming the sequence is valid

    // loop through each character of input_dna until the null character '\0'
    for (int i = 0; input_dna[i] != '\0'; i++)
    {
        input_dna[i] = toupper(input_dna[i]); // convert each character to uppercase

        // check if the current character is NOT one of A, T, G, or C
        if (input_dna[i] != 'A' && input_dna[i] != 'T' && input_dna[i] != 'G' && input_dna[i] != 'C')
        {
            valid = 0; // if invalid character found, set valid to 0 (false)
            break;     // exit the loop early since it's not a valid DNA sequence
        }
    }

    // if valid is still 1, it means all characters were A, T, G, or C
    if (valid)
    {
        printf("Valid DNA Sequence\n"); // print valid
    }
    else
    {
        printf("Invalid DNA sequence\n"); // print invalid
    }

    // declare variables to count each base
    int countA = 0;
    int countT = 0;
    int countG = 0;
    int countC = 0;

    // loop through input_dna again to count each base
    for (int i = 0; input_dna[i] != '\0'; i++)
    {
        if (input_dna[i] == 'A') // if character is A
        {
            countA++; // increase A count
        }
        if (input_dna[i] == 'T') // if character is T
        {
            countT++; // increase T count
        }
        if (input_dna[i] == 'G') // if character is G
        {
            countG++; // increase G count
        }
        if (input_dna[i] == 'C') // if character is C
        {
            countC++; // increase C count
        }
    }

    // print the count of each base
    printf("A: %d\n", countA);
    printf("T: %d\n", countT);
    printf("G: %d\n", countG);
    printf("C: %d\n", countC);

    // calculate total number of valid bases (A + T + G + C)
    int total_ATGC = countA + countT + countG + countC;

    // calculate GC content percentage using float division
    float gc_content = ((countG + countC)) / (float)total_ATGC * 100;

    // print GC content with 2 decimal places
    printf("GC Content: %.2f%%\n", gc_content);

    // now we'll calculate the reverse complement
    char reverse_complement[100]; // array to store the result
    int j = 0;                    // index for reverse_complement

    // loop through the DNA sequence in reverse
    for (int i = total_ATGC - 1; i >= 0; i--)
    {
        // find complement base and store in reverse_complement
        if (input_dna[i] == 'A')
        {
            reverse_complement[j++] = 'T'; // A -> T
        }
        if (input_dna[i] == 'T')
        {
            reverse_complement[j++] = 'A'; // T -> A
        }
        if (input_dna[i] == 'G')
        {
            reverse_complement[j++] = 'C'; // G -> C
        }
        if (input_dna[i] == 'C')
        {
            reverse_complement[j++] = 'G'; // C -> G
        }
    }

    reverse_complement[j] = '\0'; // end the string with null character

    // print the final reverse complement
    printf("Input DNA Sequance :%s\n", input_dna);
    printf("Reverse Complement :%s\n", reverse_complement);

    return 0; // end of program
}
