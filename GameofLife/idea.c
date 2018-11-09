

#define ROWS 10
#define COL 10

a=malloc(rows * sizeof(int));
if (!a){
        return NULL;
}

array index of rows a


COLUMNS:
for (i=0; i<ROWS; i++) {
        a(i) = malloc(col*sizeof(int));

        if (!*(a+i)) {
                for (j = 0 ; j < i : j++) {
                        free(*(a+j));
                }       
                free (a);

        return NULL;
        }
}

in functions pass in **a, **b, **c, etc

matrix notation

a[ROW][Column]

testlive

for (i=0; i<ROWS; i++) {
        for (j=0; j<COL; j++){
                sum_neighbor(a[i][j]);
        }

        then implement rules setting live = 1 dead = 0;
}


then fucking edges
figure it out
