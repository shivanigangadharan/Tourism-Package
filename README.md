# Matrix-Convolution
#include <iostream>

using namespace std;

int main(){
    //PRODUCT
    int i,j,k,l,m,n,c, d,sum = 0;
    int A[10][10], K[10][10], multiply[10][10];

    cout<<"Enter dimension of matrix: ";
    cin>>n;

    cout<<"Enter matrix 1: ";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>>A[i][j];
        }
    }

    cout<<"Enter matrix 2: ";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>>K[i][j];
        }
    }

    cout<<"\nmatrix 1:\n ";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<A[i][j]<<'\t';
        } cout<<"\n";
    }
    cout<<"matrix 2:\n ";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<K[i][j]<<'\t';
        } cout<<"\n";
    }

    /***********************/
    for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++) {
        for (k = 0; k < n; k++) {
          sum = sum + A[c][k]*K[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }

    cout<<"Product of the matrices:\n";

    for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++)
        cout<<multiply[c][d]<<'\t';

      cout<<"\n";
    }

    //CONVOLUTION
    int acc,mid,result;
    acc=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(l=0; l<n; l++){
               for(m=0; m<n; m++){
                   if(i==l && j==m){
                       result=A[i][j]*K[l][m];
                       acc=acc+result;
                   }
               }
            }
        }
    }
    mid= (n/2);
    A[mid][mid]=acc;
    cout<<"\nConvolution :- \n";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<A[i][j]<<'\t';
        } cout<<'\n';
    }
  return 0;

}
