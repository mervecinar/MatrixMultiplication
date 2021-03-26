#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R  500//matris boyutlarýmýz kare matris  olduðu için satýr ve sütunu da R olarak adlandýrdým
// metotlarýn imzalarý 
float** matrixmatrixMultiply(float** dizi1, float** dizi2);
/*
float** matrixmatrixMultiplyikj(float** dizi1, float** dizi2);
float** matrixmatrixMultiplyjik(float** dizi1, float** dizi2);
float** matrixmatrixMultiplyjki(float** dizi1, float** dizi2);
float** matrixmatrixMultiplykij(float** dizi1, float** dizi2);
float** matrixmatrixMultiplykji(float** dizi1, float** dizi2);
*/

int main(void) {

    srand(time(NULL));
    int i, j;
    //printf("Dizi1\n"); 
    // 2 pointerlý Dizi1 için bellekte yer ayýrma ve random deðer atama
    float** dizi1 = (float**) malloc(sizeof (float*)*R);


    for (i = 0; i < R; i++) {
        dizi1[i] = (float*) malloc(sizeof (float)*R);
    }
    for (i = 0; i < R; i++) {
        for (j = 0; j < R; j++) {
            dizi1[i][j] = ((float) rand() / (float) (RAND_MAX))*6 + 1;


        }
        // printf("\n");
 
    }
    //printf("Dizi2\n"); 
    // 2 pointerlý Dizi2 için bellekte yer ayýrma ve random deðer atama 
    float** dizi2 = (float**) malloc(sizeof (float*)*R);


    for (i = 0; i < R; i++) {
        dizi2[i] = (float*) malloc(sizeof (float)*R);
    }
    for (i = 0; i < R; i++) {
        for (j = 0; j < R; j++) {
            dizi2[i][j] = ((float) rand() / (float) (RAND_MAX))*6 + 1;


        }
         // printf("\n");
    }
    // Sadece çarpým için süre ölçümü saniye cinsinden 
   
    float saniye;
    clock_t basla, bitir;
    basla = clock();
    float** a = matrixmatrixMultiply(dizi1, dizi2);


    bitir = clock();
    saniye = (float) (bitir - basla) / CLOCKS_PER_SEC;
    printf("k-j-i %dx%d sure: %f\n", R, R, saniye);
        // ön bellekte kaplanan yeri geri verme 
    free(dizi1);
    free(dizi2);
    return 0;
}
// her bir algoritma sýralamasý için oluþturulan ayrý ayrý metotlar

float** matrixmatrixMultiply(float** dizi1, float** dizi2) {
	//ijk döngüsü içindir önce  2 pointerlý dzilerin malloctan çarpým için yer ayýrtýlýr daha sonra önceden oluþturulan 
//dizi 1 ve dizi 2 nin  satýr ve sütünun i-j-k sýralmasý ile döngüye girerek tekrar iki pointerlý  çarpým matrisi oluþturulur.
    int i, j, k;
    float** carp = (float**) malloc(sizeof (float*)*R);
    for (i = 0; i < R; i++) {
        carp[i] = (float*) malloc(sizeof (float)*R);
    }
    for (k = 0; k < R; k++) {
        for (j = 0; j < R; j++) {
            for (i = 0; i < R; i++) {
                carp[k][j] += dizi1[k][i] * dizi2[i][j];
            }
        }
            // printf("\n");
    }
    free(carp);

    return carp;
}
/*
float** matrixmatrixMultiplyikj(float** dizi1, float** dizi2) {
		//ikj döngüsü içindir önce malloctan çarpým için yer ayýrtýlýr daha sonra önceden oluþturulan 
	//	dizi 1 ve dizi 2 nin  satýr ve sütünun i-j-k sýralmasý ile döngüye girerek çarpar ve tekrar iki pointerlý  çarpým matrisi oluþturulur.
    int i, j, k;
    float** carp = (float**) malloc(sizeof (float)*R);
    for (i = 0; i < R; i++) {
        carp[i] = (float*) malloc(sizeof (float)*R);
    }
    for (i= 0; i < R; i++) {
        for (k = 0; k < R; k++) {
            for ( j= 0; j < R; j++) {
                carp[i][j] += dizi1[i][k] * dizi2[k][j];
            }
        }
    }
    free(carp);

    return carp;
}
float** matrixmatrixMultiplyjik(float** dizi1, float** dizi2) {
		//jik döngüsü içindir önce malloctan çarpým için yer ayýrtýlýr daha sonra önceden oluþturulan 
//	dizi 1 ve dizi 2 nin  satýr ve sütünun j-i-k sýralmasý ile döngüye girere çarpar ve  tekrar iki pointerlý  çarpým matrisi oluþturulur.
	
    int i, j, k;
    float** carp = (float**) malloc(sizeof (float)*R);
    for (i = 0; i < R; i++) {
        carp[i] = (float*) malloc(sizeof (float)*R);
    }
    for (j = 0; i < R; i++) {
        for (i = 0; i < R; i++) {
            for (k = 0; k < R; k++) {
                carp[i][j] += dizi1[i][k] * dizi2[k][j];
            }
        }
    }
    free(carp);

    return carp;
}
float** matrixmatrixMultiplyjki(float** dizi1, float** dizi2) {
		//jki döngüsü içindir önce malloctan çarpým için yer ayýrtýlýr daha sonra önceden oluþturulan 
		//dizi 1 ve dizi 2 nin  satýr ve sütünun j-k-i sýralmasý ile döngüye girere çarpar ve  tekrar iki pointerlý  çarpým matrisi oluþturulur.
    int i, j, k;
    float** carp = (float**) malloc(sizeof (float)*R);
    for (i = 0; i < R; i++) {
        carp[i] = (float*) malloc(sizeof (float)*R);
    }
    for (j = 0; j < R; j++) {
        for (k = 0; k < R; k++) {
            for (i = 0; i < R; i++) {
                carp[i][j] += dizi1[i][k] * dizi2[k][j];
            }
        }
    }
    free(carp);

    return carp;
}
float** matrixmatrixMultiplykij(float** dizi1, float** dizi2) {
		//kij döngüsü içindir önce malloctan çarpým için yer ayýrtýlýr daha sonra önceden oluþturulan 
//	dizi 1 ve dizi 2 nin  satýr ve sütünun k-i-j sýralmasý ile döngüye girere çarpar ve  tekrar iki pointerlý  çarpým matrisi oluþturulur.
    int i, j, k;
    float** carp = (float**) malloc(sizeof (float)*R);
    for (i = 0; i < R; i++) {
        carp[i] = (float*) malloc(sizeof (float)*R);
    }
    for (k = 0; k < R; k++) {
        for (i = 0; i < R; i++) {
            for (j = 0; j < R; j++) {
                carp[i][j] += dizi1[i][k] * dizi2[k][j];
            }
        }
    }
    free(carp);

    return carp;
}
float** matrixmatrixMultiplykji(float** dizi1, float** dizi2) {
		// kji döngüsü içindir önce malloctan çarpým için yer ayýrtýlýr daha sonra önceden oluþturulan 
//	dizi 1 ve dizi 2 nin  satýr ve sütünun k-j-i sýralmasý ile döngüye girere çarpar ve  tekrar iki pointerlý  çarpým matrisi oluþturulur.
    int i, j, k;
    float** carp = (float**) malloc(sizeof (float)*R);
    for (i = 0; i < R; i++) {
        carp[i] = (float*) malloc(sizeof (float)*R);
    }
    for (k = 0; k < R; k++) {
        for (j = 0; j < R; j++) {
            for (i = 0; i < R; i++) {
                carp[i][j] += dizi1[i][k] * dizi2[k][j];
            }
        }
    }
    free(carp);

    return carp;
}
*/

