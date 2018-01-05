#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUNCTION: strMerge
// Merge two strings (str1 & str2) into one (strDest) by taking the 1st character of str1, 
// then 1st char from str2, 2nd char from str1, 2nd char from str2, … etc, until the end of
// one string, then append the rest of the other string. For example, two strings "abcd" and
// "pqrstuv" will give you "apbqcrdstuv" as the result.
//
// ccDest is the size of the destination buffer, in character count.
//
void strMerge(const char *str1, const char *str2, char *strDest, unsigned int ccDest)
{
    // print out input strings
    printf("string1 is %s\n", str1);
    printf("string2 is %s\n", str2);
	//Get length of both input strings
	int size1 = strlen(str1);
	int size2 = strlen(str2);

	//size represents the index of where we are inserting the next value in strDest, size of current result string
	int size = 0;
	//Placeholder represents the index of the input array
	int placeholder = 0;

	//Insert a letter from each array for as long as the shortest's length
	while (size1 > placeholder && size2 > placeholder) {
                strDest[size] = *str1++;
		size += 1;
                strDest[size] = *str2++;
		size += 1;
		placeholder += 1;
	}

	//finish off str1 if it is larger than str2
	while (size1 > placeholder) {
		strDest[size] =  *str1++;
		size += 1;
		placeholder += 1;
	}

	//finish off str2 if it is larger than str1
	while (size2 > placeholder) {
                strDest[size] = *str2++;
		size += 1;
		placeholder += 1;
        }
	strDest[size] = '\0';
	printf("merged string is %s\n", strDest);
    // TODO: merge the two strings into strDest, make sure it's NULL terminated
}

// FUNCTION: main
//
int main (int argc, char* argv[])
{
    char *str1;
    char *str2;

    char strNew[128];

    if (argc == 3)
    {
        // if strings are provided via command line arguments
        str1 = argv[1];
        str2 = argv[2];
        strMerge(str1, str2, strNew, sizeof(strNew));
    }
    else
    {
        // no string provided, do the default tests
        str1 = "1234";
        str2 = "567890";
        strMerge(str1, str2, strNew, sizeof(strNew));
        printf("should be        1526374890\n\n");

        str1 = "information";
        str2 = "tech";
        strMerge(str1, str2, strNew, sizeof(strNew));
        printf("should be        itnefcohrmation\n\n");
    }

    return 0;
}
