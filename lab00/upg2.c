#include <stdio.h>

int main(int argc, char ** argv)
{
  char str[] = "sihtgubed";
  char *stri = &str[8]; // Point to last element in str
  char *buf[9]; // Create a buffer to hold char
  char **bufi, **bufend; // Create ppointers, start and end
  bufi = buf; // Start of buffer
  bufend = &buf[9]; // End of buffer

  while (bufi != bufend){ // Run through string 
    *bufi = stri;
    bufi++;
    stri--; 
  }

  while (bufi != buf){ // Make all caps
    bufi--; // FIXED. DO NOT TRY TO CAPS NULL CHAR.
    **bufi -= 32; 
  }

  while (bufi != bufend){ // Print decoded msg
    printf("%c", **bufi);
    bufi++;
  }
}

