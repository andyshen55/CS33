#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

#include "utils.h"

long __attribute__ ((noinline)) gimmie_the_func() {
  return 58113.3;
}

long __attribute__ ((noinline)) we_need_the_func() {
  return 823421.3;
}

int main( int argc, const char* argv[] )
{
  int i,j,k;
  int u;
  struct timespec start, finish;
  double seqDelay, parDelay;

  for (i=0; i<10; i++)
    histogrammy[i]=0;

  for (i=0; i<DIM; i++)
    for (j=0; j<DIM; j++)
      for (k=0; k<DIM; k++)
        {
          original[i*DIM*DIM+j*DIM+k]=(long)(random()%1000);
        }

  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1; k++) {
        u=(original[i*DIM*DIM+j*DIM+k]/100);
        if (u>=9) u=9;
        if (u<=0) u=0;
        histogrammy[u]++;
      }
    }
  }

  for (i=0; i<10; i++)
    printf("HISTO[%d]:%d\n",i,histogrammy[i]);

  for (i=0; i<10; i++)
    histogrammy[i]=0;

  clock_gettime(CLOCK_MONOTONIC, &start);
  work_it_seq(original, new);
  clock_gettime(CLOCK_MONOTONIC, &finish);

  seqDelay = (finish.tv_sec - start.tv_sec);
  seqDelay += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

  for (i=0; i<10; i++)
    printf("NEWHISTO[%d]:%d\n",i,histogrammy[i]);

  printf("Sequential version took %lf time units\n",seqDelay);

  for (i=0; i<10; i++)
    histogrammy[i]=0;

  clock_gettime(CLOCK_MONOTONIC, &start);
  work_it_par(original, new);
  clock_gettime(CLOCK_MONOTONIC, &finish);

  parDelay = (finish.tv_sec - start.tv_sec);
  parDelay += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

  for (i=0; i<10; i++)
    printf("NEWPARHISTO[%d]:%d\n",i,histogrammy[i]);


  printf("Parallel version took %lf time units\n", parDelay);

  printf("This resulted in a %fx speed-up\n", (float)(seqDelay / parDelay));
  printf("Ending the parallelization test\n");

  fprintf(stderr, "%lf", seqDelay / parDelay);

  return 0;

}