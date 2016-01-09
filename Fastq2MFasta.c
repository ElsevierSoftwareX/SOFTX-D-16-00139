#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"

int main(int argc, char *argv[]){
  uint32_t k, i;
  uint8_t  s, line = 0, pos = 0;
  BUF *B;

  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.fastq > output.mfasta  \n"
    "It converts a FASTQ file format to a pseudo Multi-FASTA file.\n"
    "It does NOT align the sequence.\n"
    "It extracts the sequence and adds each header in a Multi-FASTA format.\n",
    argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      switch(line){ 
        case 0: 
          if(s == '\n') line = 1;
          if(s == '@' && pos++ == 0)
            putchar('>');
          else
            putchar(s);
        break;
        case 1: 
          if(s == '\n') line = 2;
          putchar(s);
        break;
        case 2:
          if(s == '\n') line = 3;
        break;
        case 3:
          if(s == '\n'){ 
            line = 0;
            pos  = 0;
            }
        break;
        } 
      }

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

