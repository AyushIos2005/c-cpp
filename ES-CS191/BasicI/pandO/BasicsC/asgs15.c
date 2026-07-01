// matrix multipcation with transpose

#include<stdio.h>
int main(){
    int n,m;
    printf("Enter a no. of rows : ");
    scanf("%d",&n);

    printf("Enter a no. of cols : ");
    scanf("%d",&m);

     int arr[n][m];
     printf("Enter a 2-D array : \n");
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
        
    }
    printf("2-D array is : \n");
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int trans[m][n];
    printf("Transpose of Array :\n");
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            trans[i][j] = arr[j][i];
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }

     int result[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += arr[i][k] * trans[k][j];
            }
        }
    }

    printf("Multiplication of array is : \n");
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}