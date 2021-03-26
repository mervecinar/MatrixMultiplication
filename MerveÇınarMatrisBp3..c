#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R  500//matris boyutlar�m�z kare matris  oldu�u i�in sat�r ve s�tunu da R olarak adland�rd�m
// metotlar�n imzalar� 
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
    // 2 pointerl� Dizi1 i�in bellekte yer ay�rma ve random de�er atama
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
    // 2 pointerl� Dizi2 i�in bellekte yer ay�rma ve random de�er atama 
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
    // Sadece �arp�m i�in s�re �l��m� saniye cinsinden 
   
    float saniye;
    clock_t basla, bitir;
    basla = clock();
    float** a = matrixmatrixMultiply(dizi1, dizi2);


    bitir = clock();
    saniye = (float) (bitir - basla) / CLOCKS_PER_SEC;
    printf("k-j-i %dx%d sure: %f\n", R, R, saniye);
        // �n bellekte kaplanan yeri geri verme 
    free(dizi1);
    free(dizi2);
    return 0;
}
// her bir algoritma s�ralamas� i�in olu�turulan ayr� ayr� metotlar

float** matrixmatrixMultiply(float** dizi1, float** dizi2) {
	//ijk d�ng�s� i�indir �nce  2 pointerl� dzilerin malloctan �arp�m i�in yer ay�rt�l�r daha sonra �nceden olu�turulan 
//dizi 1 ve dizi 2 nin  sat�r ve s�t�nun i-j-k s�ralmas� ile d�ng�ye girerek tekrar iki pointerl�  �arp�m matrisi olu�turulur.
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
		//ikj d�ng�s� i�indir �nce malloctan �arp�m i�in yer ay�rt�l�r daha sonra �nceden olu�turulan 
	//	dizi 1 ve dizi 2 nin  sat�r ve s�t�nun i-j-k s�ralmas� ile d�ng�ye girerek �arpar ve tekrar iki pointerl�  �arp�m matrisi olu�turulur.
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
		//jik d�ng�s� i�indir �nce malloctan �arp�m i�in yer ay�rt�l�r daha sonra �nceden olu�turulan 
//	dizi 1 ve dizi 2 nin  sat�r ve s�t�nun j-i-k s�ralmas� ile d�ng�ye girere �arpar ve  tekrar iki pointerl�  �arp�m matrisi olu�turulur.
	
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
		//jki d�ng�s� i�indir �nce malloctan �arp�m i�in yer ay�rt�l�r daha sonra �nceden olu�turulan 
		//dizi 1 ve dizi 2 nin  sat�r ve s�t�nun j-k-i s�ralmas� ile d�ng�ye girere �arpar ve  tekrar iki pointerl�  �arp�m matrisi olu�turulur.
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
		//kij d�ng�s� i�indir �nce malloctan �arp�m i�in yer ay�rt�l�r daha sonra �nceden olu�turulan 
//	dizi 1 ve dizi 2 nin  sat�r ve s�t�nun k-i-j s�ralmas� ile d�ng�ye girere �arpar ve  tekrar iki pointerl�  �arp�m matrisi olu�turulur.
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
		// kji d�ng�s� i�indir �nce malloctan �arp�m i�in yer ay�rt�l�r daha sonra �nceden olu�turulan 
//	dizi 1 ve dizi 2 nin  sat�r ve s�t�nun k-j-i s�ralmas� ile d�ng�ye girere �arpar ve  tekrar iki pointerl�  �arp�m matrisi olu�turulur.
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

