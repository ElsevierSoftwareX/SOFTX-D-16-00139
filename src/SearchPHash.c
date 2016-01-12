#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "hash.h"
#include "alpha.h"
#include "mem.h"

uint64_t *LoadPrimes(uint32_t n){
  uint64_t  i = 3, count, c, k = 0;
  uint64_t *primes = (uint64_t *) Calloc(n++, sizeof(uint64_t)); 
  primes[0] = 2;
  for(count = 2 ; count < n ; ++i){
    for(c = 2 ; c < i ; c++)
      if(i % c == 0) break;
    if(c == i){
      primes[++k] = i;
      ++count;
      }
    }
  return primes;
  }

int main(int argc, char *argv[]){
  BUF      *B;
  ALPHA    *A;
  HASH     *H;
  uint64_t *primes, nPrimes = 500;
  uint64_t i, k, n, s, baskets;
  
  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.seq > output.param\nIt search for the "
    "best two primes that approximate a hash family function ((p1*seed + p2) "
    "%%#Sequence) on a sequence.\n", argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);
  A = CreateAlphabet();
  LoadAlphabet(A, B);
  primes = LoadPrimes(nPrimes);
  H = CreateHash(0, A->nSym);

  #ifdef SHOW_PRIMES
  printf("Primes: ");
  for(k = 0 ; k < nPrimes ; ++k)
    printf("%"PRIu64" ", primes[k]);
  printf("\n");
  #endif

  baskets = 0;
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){


      H->p1 = H->seed; 
      H->p2 = H->seed + 6;
      H->seed++;
      n = A->numeric[B->buf[i]];
      s = Hash(H);

      if(n == s)
        ++baskets;


      }

  printf("Baskets: %"PRIu64" of %"PRIu64" tries\n", baskets, H->seed);

  //TODO:differentialState
  Free(primes, nPrimes * sizeof(uint64_t));
  DeleteAlphabet(A);
  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

