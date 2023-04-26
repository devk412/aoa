#include<stdio.h> 
#include<string.h> 
char x[30],y[30]; 
char b[30][30]; 
int c[30][30]; 
int m=0,n=0; 
void LCS() 
{ 
 int i,j; 
 m=strlen(x); 
 n=strlen(y); 
 for(i=0;i<=m;i++){ 
 c[i][0]=0; 
 b[i][0]='-'; 
 } 
 for(j=0;j<=n;j++){ 
 c[0][j]=0; 
 b[0][j]='-'; 
 } 
 for(i=1;i<=m;i++){ 
 for(j=1;j<=n;j++){ 
 if(x[i-1]==y[j-1]){ 
 c[i][j]=c[i-1][j-1]+1; 
 b[i][j]='D'; 
 } 
 else if(c[i][j-1]>=c[i-1][j]){ 
 c[i][j]=c[i][j-1]; 
 b[i][j]='L'; 
 } 
 else{ 
 c[i][j]=c[i-1][j]; 
 b[i][j]='U'; 
 } 
 } 
 } 
 for(i=0;i<=m;i++){ 
 for(j=0;j<=n;j++){ 
 printf("%d%c\t",c[i][j],b[i][j]); 
 } 
 printf("\n"); 
 } 
 } 
void printLCS(int i,int j){ 
 if(i==0 || j==0){ 
 return; 
 } 
 else if(b[i][j]=='D'){ 
 printLCS(i-1,j-1); 
 printf("%c ",x[i-1]); 
 } 
 else if(b[i][j]=='U'){ 
 printLCS(i-1,j); 
} 
else{ 
 printLCS(i,j-1); 
} 
} 
int main(){ 
 printf("Enter the first String: "); 
 scanf("%s",x); 
 printf("Enter the second String: "); 
 scanf("%s",y); 
 printf("The content of string x is:\n"); 
 for(int i=0;i<strlen(x);i++){ 
 printf("%c\n",x[i]); 
 } 
 printf("The content of string y is:\n"); 
 for(int i=0;i<strlen(y);i++){ 
 printf("%c\n",y[i]); 
 } 
 LCS(); 
 printf("Length of LCS is: %d\n",c[m][n]); 
 printLCS(m,n); 
 return 0; 
}