//OpenMP version.  Edit and submit only this file.
/* Enter your details below
 * Name : Thant Zin Oo
 * UCLA ID : 705172144
 * Email : andyshen55@ucla.edu
 */

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include "utils.h"

void work_it_par(long *old, long *new) {
  int i, j, k, uu0, uu1, uu2, uu3, uu4, uu5;
  double g_func = gimmie_the_func();
  double w_func = we_need_the_func();
  long aggregate = 1.0;

  #pragma omp parallel for private (i, j, k) reduction (+:aggregate)
  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k = 1; k < (DIM-1); ++k) {
        aggregate += old[i*DIM*DIM+j*DIM+k] * (w_func / g_func);
      }
    }
  }

  printf("AGGR:%ld\n",aggregate);

  long acc;
  #pragma omp parallel private (i, j, k, acc)
#pragma omp for
  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1; k++) {
        acc = 0;
        acc += old[(i-1)*DIM*DIM+(j-1)*DIM+(k-1)];
        acc += old[(i-1)*DIM*DIM+(j-1)*DIM+(k)];
        acc += old[(i-1)*DIM*DIM+(j-1)*DIM+(k+1)];
        acc += old[(i-1)*DIM*DIM+(j)*DIM+(k-1)];
        acc += old[(i-1)*DIM*DIM+(j)*DIM+(k)];
        acc += old[(i-1)*DIM*DIM+(j)*DIM+(k+1)];
        acc += old[(i-1)*DIM*DIM+(j+1)*DIM+(k-1)];
        acc += old[(i-1)*DIM*DIM+(j+1)*DIM+(k)];
        acc += old[(i-1)*DIM*DIM+(j+1)*DIM+(k+1)];
        acc += old[(i)*DIM*DIM+(j-1)*DIM+(k-1)];
        acc += old[(i)*DIM*DIM+(j-1)*DIM+(k)];
        acc += old[(i)*DIM*DIM+(j-1)*DIM+(k+1)];
        acc += old[(i)*DIM*DIM+(j)*DIM+(k-1)];
        acc += old[(i)*DIM*DIM+(j)*DIM+(k)];
        acc += old[(i)*DIM*DIM+(j)*DIM+(k+1)];
        acc += old[(i)*DIM*DIM+(j+1)*DIM+(k-1)];
        acc += old[(i)*DIM*DIM+(j+1)*DIM+(k)];
        acc += old[(i)*DIM*DIM+(j+1)*DIM+(k+1)];
        acc += old[(i+1)*DIM*DIM+(j-1)*DIM+(k-1)];
        acc += old[(i+1)*DIM*DIM+(j-1)*DIM+(k)];
        acc += old[(i+1)*DIM*DIM+(j-1)*DIM+(k+1)];
        acc += old[(i+1)*DIM*DIM+(j)*DIM+(k-1)];
        acc += old[(i+1)*DIM*DIM+(j)*DIM+(k)];
        acc += old[(i+1)*DIM*DIM+(j)*DIM+(k+1)];
        acc += old[(i+1)*DIM*DIM+(j+1)*DIM+(k-1)];
        acc += old[(i+1)*DIM*DIM+(j+1)*DIM+(k)];
        acc += old[(i+1)*DIM*DIM+(j+1)*DIM+(k+1)];
        acc /= 27;
        new[i*DIM*DIM+j*DIM+k] = acc;
      }
    }
  }

  int u0, u1, u2, u3, u4, u5, u6, u7, u8, u9;
  u0 = histogrammy[0];
  u1 = histogrammy[1];
  u2 = histogrammy[2];
  u3 = histogrammy[3];
  u4 = histogrammy[4];
  u5 = histogrammy[5];
  u6 = histogrammy[6];
  u7 = histogrammy[7];
  u8 = histogrammy[8];
  u9 = histogrammy[9];

  #pragma omp parallel private (i, j, k, uu0, uu1, uu2, uu3, uu4, uu5)
#pragma omp for reduction (+:u0, u1, u2, u3, u4, u5, u6, u7, u8, u9)
  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1 - 6; k+= 6) {
        uu0=(new[i*DIM*DIM+j*DIM+k]/100);
        uu1=(new[i*DIM*DIM+j*DIM+k + 1]/100);
        uu2=(new[i*DIM*DIM+j*DIM+k + 2]/100);
        uu3=(new[i*DIM*DIM+j*DIM+k + 3]/100);
        uu4=(new[i*DIM*DIM+j*DIM+k + 4]/100);
        uu5=(new[i*DIM*DIM+j*DIM+k + 5]/100);

        if (uu0<=0) uu0=0;
        if (uu0>=9) uu0=9;
        switch(uu0)
        {
          case(0): ++u0; break;
          case(1): ++u1; break;
          case(2): ++u2; break;
          case(3): ++u3; break;
          case(4): ++u4; break;
          case(5): ++u5; break;
          case(6): ++u6; break;
          case(7): ++u7; break;
          case(8): ++u8; break;
          case(9): ++u9; break;
        }
        if (uu1<=0) uu1=0;
        if (uu1>=9) uu1=9;
        switch(uu1)
        {
          case(0): ++u0; break;
          case(1): ++u1; break;
          case(2): ++u2; break;
          case(3): ++u3; break;
          case(4): ++u4; break;
          case(5): ++u5; break;
          case(6): ++u6; break;
          case(7): ++u7; break;
          case(8): ++u8; break;
          case(9): ++u9; break;
        }
        if (uu2<=0) uu2=0;
        if (uu2>=9) uu2=9;
        switch(uu2)
        {
          case(0): ++u0; break;
          case(1): ++u1; break;
          case(2): ++u2; break;
          case(3): ++u3; break;
          case(4): ++u4; break;
          case(5): ++u5; break;
          case(6): ++u6; break;
          case(7): ++u7; break;
          case(8): ++u8; break;
          case(9): ++u9; break;
        }
        if (uu3<=0) uu3=0;
        if (uu3>=9) uu3=9;
        switch(uu3)
        {
          case(0): ++u0; break;
          case(1): ++u1; break;
          case(2): ++u2; break;
          case(3): ++u3; break;
          case(4): ++u4; break;
          case(5): ++u5; break;
          case(6): ++u6; break;
          case(7): ++u7; break;
          case(8): ++u8; break;
          case(9): ++u9; break;
        }
        if (uu4<=0) uu4=0;
        if (uu4>=9) uu4=9;
        switch(uu4)
        {
          case(0): ++u0; break;
          case(1): ++u1; break;
          case(2): ++u2; break;
          case(3): ++u3; break;
          case(4): ++u4; break;
          case(5): ++u5; break;
          case(6): ++u6; break;
          case(7): ++u7; break;
          case(8): ++u8; break;
          case(9): ++u9; break;
        }
        if (uu5<=0) uu5=0;
        if (uu5>=9) uu5=9;
        switch(uu5)
        {
          case(0): ++u0; break;
          case(1): ++u1; break;
          case(2): ++u2; break;
          case(3): ++u3; break;
          case(4): ++u4; break;
          case(5): ++u5; break;
          case(6): ++u6; break;
          case(7): ++u7; break;
          case(8): ++u8; break;
          case(9): ++u9; break;
        }
      }
      for (; k<DIM-1; k++) {
	    uu0=(new[i*DIM*DIM+j*DIM+k]/100);
	    if (uu0<=0) uu0=0;
	    if (uu0>=9) uu0=9;
	    switch(uu0)
	    {
	      case(0): ++u0; break;
	      case(1): ++u1; break;
	      case(2): ++u2; break;
	      case(3): ++u3; break;
	      case(4): ++u4; break;
	      case(5): ++u5; break;
	      case(6): ++u6; break;
	      case(7): ++u7; break;
	      case(8): ++u8; break;
	      case(9): ++u9; break;
	  	}
	  }
    }
  }
  histogrammy[0] = u0;
  histogrammy[1] = u1;
  histogrammy[2] = u2;
  histogrammy[3] = u3;
  histogrammy[4] = u4;
  histogrammy[5] = u5;
  histogrammy[6] = u6;
  histogrammy[7] = u7;
  histogrammy[8] = u8;
  histogrammy[9] = u9;
}
