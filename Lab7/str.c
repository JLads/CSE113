#include "str.h"
#include <stdio.h>
#include <string.h>


int str_len(char *s)
{    
        int len;
        for (len = 0 ; *s != '\0' ; s++) {
                len++;
        }
        return len;
}

/* array version */
/* concantenate t to the end of s; s must be big enough */
void str_cat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') 	/* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}

/*array version*/
void squeeze(char s[], int c)
{
        int i, j;

        for(i = j = 0; s[i] != '\0'; i++)
                 if (s[i] != c)
                         s[j++] = s[i];

        s[j] = '\0';
}




/* 
 * I turned this into the pointer version.
 *
 *
 *
 * */
void psqueeze(char *s, int c)
{
	int i, j;
	
	for (i = j = 0; *(s+i) != '\0'; i++)
		if (*(s+i) != c)
			*(s + (j++)) = *(s+i);

	*(s + j) = '\0';
}

/*
 * i changed this some 
 *
 *
 * */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = str_len(s) - 1; i < j; i++, j-- ) {
		/* change this so it calls cswap */
        	c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	
}

void preverse(char *s)
{
        int i, j;

        for (i = 0, j = str_len(s) -1; i < j; i++, j--) {
                cswap((s+i), (s+j));
        }
}

/*
 * I did this
 * */
char *pindex(char *s, int c)
{
        int i = 0;
        for (; *(s+i) != '\0'; i++) {
                if (*(s+i) == c) {
                        return (s+i);
                }
        }
        return 0;
}





/*
 * i did this
 *
 *
 * */
void cswap(char *c, char *d)
{
        int tmp;
        tmp = *c;
        *c = *d;
        *d = tmp;
}

/*
 * i did this
 *
 *
 *
 * */
int pstr_ncmp(char *s, char *t, int n)
{
        int i = 0;
        while(n--) {
            if (*(s+i) != *(t+i)) {
                return *s-*t;
            } else {
                i++;
            }
        }
        return 0;
}

/* copy n chars of src into dest 
 * I did this
 *
 *
 *
 *
 *
 * */
void pstr_ncpy(char *dest, char *src, int n)
{
        char *this = dest;

        while(n--) {
            *this++ = *src++;
        }
        *this = '\0';
}

/* concantenate t to the end of s; s must be big enough! 
 * I did this
 *
 *
 *
 *
 * */
void pstr_cat(char *s, char *t)
{
 	int i, j;

	i = j = 0;
	while (*(s+i) != '\0') 	/* find end of s */
		i++;
	while ((*(s+ (i++)) = *(t + (j++))) != '\0') /* copy t */
		;
}
