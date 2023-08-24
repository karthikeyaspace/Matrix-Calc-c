#include<stdio.h>
#include<math.h>
#define s 4       //s is size of array.

void symm();
void detn();   
void trace();
void add2matrix();
void matrixmultiply();
void matrixsquare();
void matrixcube();
void constantmultiply();
void matrixeigenvalues();

void main(){

    int n,i,j;
    printf("Enter order of the matrix:");         //SQUARE MATRIX.
    scanf("%d",&n);   

    int a[s][s];

    printf("ENTER MATRIX ELEMENTS ROW WISE:\n");
    for(i=1;i<=n;i++){                            //MATRIX INPUT FROM USER.
        for(j=1;j<=n;j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    // FILE *fptr;
    // fptr = fopen("inputmatrix.txt","r");
    
    // for(int i=1;i<=n;i++){  
    //     for(int j=1;j<=n;j++){                       // MATRIX INPUT FROM A FILE.
    //         fscanf(fptr,"%d",&a[i][j]);
    //     }
    // }

    printf("MATRIX(%d) :\n",n);

    for(i=1;i<=n;i++){                            //PRINTING INPUT MATRIX.
        for(j=1;j<=n;j++)
            printf("%d%c",a[i][j],j==n ? '\n' : ' ');
        //printf("\n");
    }
    
    printf("\n");

    // symm (n,a);  
    // detn (n,a);  
    // trace (n,a);
    // add2matrix (n,a);
    // matrixmultiply (n,a);
    // matrixsquare (n,a);
    // matrixcube (n,a);
    // constantmultiply (n,a);
    // matrixeigenvalues (n,a);
        
}           


    void symm(int n,int a[s][s])    {            //SYMMETRIC AND TRANSPOSE OF A MATRIX OF ORDER n.
        
        int a_t[s][s],c=0;
        
        printf("TRANSPOSE(A):\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a_t[i][j]=a[j][i];               //SWAPING ELEMENTS.             
                printf(" %d ",a_t[i][j]);        //TRANSPOSE OF MATRIX A.

                if(a[i][j]!=a_t[i][j])           //TO CHECK WHETHER MATRIX IS SYMMETRIC OR NOT
                   c++;
            }
            printf("\n");
        }
        if(c==0) printf("\nSYMMETRIC MATRIX");
        else printf("\nSKEW-SYMMETRIC MATRIX");
        
    }    


    void detn(int n,int a[s][s])   {             //DETERMINANT FOR MATRIX OF ORDER 2,3.
        int det;

        if(n==2)    
            det = a[1][1]*a[2][2]-a[2][1]*a[1][2];
        else if(n==3)   
            det = a[1][1]*a[2][2]*a[3][3] + a[1][2]*a[3][1]*a[2][3] + a[1][3]*a[2][1]*a[3][2] 
                   - a[1][1]*a[2][3]*a[3][2] - a[1][2]*a[2][1]*a[3][3] - a[1][3]*a[3][1]*a[2][2];
              
        printf("\nDETERMINANT OF A = %d\n",det); 

    }


    void trace(int n,int a[s][s])   {
        int tr=0;
        for(int i=1;i<=n;i++){
            tr+=a[i][i];
        }
        printf("TRACE OF A = %d\n",tr);

    }

    void add2matrix(int n,int a[s][s]){

        int b[s][s],c[s][s];            

        printf("Enter matrix b:\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("b[%d][%d] = ",i,j);
                scanf("%d",&b[i][j]);           //INPUT OF SECOND MATRIX.
                c[i][j]=a[i][j]+b[i][j];        //ADDING A AND B.
            }
        }

        printf("a + b =\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf(" %d ",c[i][j]);         //PRINTING MATRIX C
            }
            printf("\n");
        }
    }

    
    void matrixmultiply(int n,int a[s][s])  {

        int b[s][s],m[s][s],c=0;

        printf("\nEnter second matrix elements row wise:");
        for(int i=1;i<=n;i++){                      //INPUT OF SECOND MATRIX
            for(int j=1;j<=n;j++){
                printf("b[%d][%d] = ",i,j); 
                scanf("%d",&b[i][j]);
            }
        }
        
        for(int i=1;i<=n;i++){                  //MULTIPLICATION OF MATRIX A AND B
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    c+=a[i][k]*b[k][j];         //MULTIPLYING EACH ELEMENT
                }
            m[i][j]=c;
            c=0;
            }
        }
        
        printf("Multiplied matrix is :\n");
        for(int i=1;i<=n;i++){                  //OUTPUT OF MULTIPLYED MATRIX M
            for(int j=1;j<=n;j++){
                printf(" %d ",m[i][j]);
            }
            printf("\n");
        }

    }

    void matrixsquare(int n,int a[s][s]){

        int sq[s][s],c=0;

        printf("MATRIX SQUARE IS :\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    c+=a[i][k]*a[k][j];         //MULTIPLYING MATRIX WITH ITSELF.
                }
            sq[i][j]=c;
            c=0;
            printf(" %d ",sq[i][j]);            //PRINTING THE OUTPUT.
            }
            printf("\n");
        }

    }

    void matrixcube(int n,int a[s][s]){

        int cb[s][s],temp[s][s],c=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    c+=a[i][k]*a[k][j];         //MULTIPLYING MATRIX WITH ITSELF TO GET SQUARE MATRIX.
                }
                temp[i][j]=c;
                c=0;
            }
        }
        printf("MATRIX CUBE IS :\n");
        for(int i=1;i<=n;i++){                  //MULTIPLYING SQUARE MATRIX WITH MAIN MATRIX.
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    c+=temp[i][k]*a[k][j];
                }
                cb[i][j]=c;
                c=0;
                printf(" %d ",cb[i][j]);
            }
            printf("\n");
        }

    }

    void constantmultiply(int n,int a[s][s]){

        float a_c[s][s],c;                        
        printf("Enter number to multiply:");
        scanf("%f",&c);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a_c[i][j]=c*a[i][j];                //MULTIPLYING A CONSTANT WITH EVERY ELEMENT.
                printf(" %.1f ",a_c[i][j]);
            }
        printf("\n");
        }

    } 

    void matrixeigenvalues(int n,int a[s][s]){
    if(n==2){
        int A,B,C,D;               // HERE A,B,C, ARE COEFFICIENTS OF QUADRATIC EQUATION OF CHARECTERISTIC EQUATION.
            float lambda[2];
            A = 1;
            B = -(a[1][1]+a[2][2]);
            C = (a[1][1]*a[2][2]-a[1][2]*a[2][1]);
            D = B*B - 4*A*C;

            printf("Charecteristic equation is = %d %d %d \n\n",A,B,C);       //Ax^2 + Bx + C.
            
            if(D>0){
                lambda[0]= (sqrt(D)-B)/(2*A);       // SOLVING THE QUADRATIC EQUATION.
                lambda[1]=-(sqrt(D)+B)/(2*A);

                printf("Eigen values are : %.3f %.3f ",lambda[0],lambda[1]);  
            }
            else printf("Lambda values are imaginary");
    }

    else if(n==3){
        int A,B,C,D,d;     

            A = 1;          // COEFFICIENTS OF CUBIC EQUATION Ax^3 + Bx^2 + Cx + D
            B = -(a[1][1]+a[2][2]+a[3][3]);
            C = -(-a[1][1]*a[2][2] - a[1][1]*a[3][3] - a[2][2]*a[3][3] + a[3][2]*a[2][3] + a[1][2]*a[2][1] + a[3][1]*a[1][3]);
            D = -(a[1][1]*(a[2][2]*a[3][3] - a[3][2]*a[2][3]) + a[1][2]*(a[3][1]*a[2][3] - a[2][1]*a[3][3]) + 
                a[1][3]*(a[2][1]*a[3][2]-a[3][1]*a[2][2]));
            
            printf("Characteristic equation : %d %d %d %d\n",A,B,C,D);
            
            /* EQUATION REDUCTION METHOD 
                REPEATING OR DISTINCT EIGEN VALUES*/

            int r1,r2,r3;
            for(int i=-50;i<=50;i++){
                d = A*i*i*i + B*i*i + C*i + D;
                if(d==0){
                    r1=i;                    // GETTING FIRST ROOT OF CUBIC EQUATION.
                    break;
                }
            }
            int a=1,b,c;
            
            b=B+A*r1;                        // REDUCING THE MATRIX TO QUADRATIC EQUATION
            c=C+(B+A*r1)*r1;                 // OF FORM ax^2 + bx + c = 0
                                             // SYNTHETIC DIVISION
            d=sqrt(b*b-4*a*c);
            r2 = (-b+d)/2*a;                 // SOLVING QUADRATIC EQUATIONS
            r3 = (-b-d)/2*a;                 

            printf("EIGEN VALUES ARE : %d , %d , %d ",r1,r2,r3);



             /* FINDING ROOT BY LOOPS METHOD 
                    FOR ONLY DISTINCT EIGEN VALUES*/

            // int r[3],z;

            // for(int i=-50;i<=50;i++){
            //     z=A*i*i*i+B*i*i+C*i+D;
            //     if(z==0){
            //         r[0]=i;
            //         break;
            //     }
            // }

            // for(int j=r[0]+1;j<=50;j++){
            //     z=A*j*j*j+B*j*j+C*j+D;
            //     if(z==0){
            //         r[1]=j;
            //         break;
            //     }
            // }
            
            // for(int k=r[1]+1;k<=50;k++){
            //     z=A*k*k*k+B*k*k+C*k+D;
            //     if(z==0){
            //         r[2]=k;
            //         break;
            //     }
            // }

            // printf("Eigen values are %d %d %d ",r[0],r[1],r[2]);

    }
}