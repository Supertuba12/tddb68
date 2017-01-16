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
    *bufi = stri; // make bufi point to last char in str
    bufi++; // move to next ppointer
    stri--; // move backwards in str
  }

  while (bufi != buf){ // Some sort of decoder
    *(*bufi) -= 32; // Change ascii value for each char in str
    bufi--; // ready the second char
  }

  while (bufi != bufend){ // Print decoded msg
    printf("%c", **bufi);
    bufi++;
  }
}

