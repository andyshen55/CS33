#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include "utils.h"

void work_it_seq(long *old, long *new) {
  int i, j, k;
  int u, v, w;
  long compute_it;
  long aggregate=1.0;

  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1; k++) {
        compute_it = old[i*DIM*DIM+j*DIM+k] * we_need_the_func();
        aggregate+= compute_it / gimmie_the_func();
      }
    }
  }

  printf("AGGR:%ld\n",aggregate);

  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1; k++) {
        new[i*DIM*DIM+j*DIM+k]=0;
        for (u=-1; u<=1; u++) {
          for (v=-1; v<=1; v++) {
            for (w=-1; w<=1; w++) {
               new[i*DIM*DIM+j*DIM+k]+=old[(i+u)*DIM*DIM+(j+v)*DIM+(k+w)];
            }
          }
        }
        new[i*DIM*DIM+j*DIM+k]/=27;
      }
    }
  }

  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1; k++) {
        u=(new[i*DIM*DIM+j*DIM+k]/100);
        if (u<=0) u=0;
        if (u>=9) u=9;
        histogrammy[u]++;
      }
    }
    }

}