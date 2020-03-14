#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<stdint.h>

static int s[10000000];


void counter(int array[],int k){
               
   FILE *fp;
   char output[]="data.txt";
   int n;
    
   fp=fopen(output,"w");
   for(n=0;n<k;n++) {
   fprintf(fp,"%d\n",array[n]);
   }
    
   fclose(fp);
    
  }


int main()
{
  int i,j,k,n,m,max;
  srand(time(0));
  //n=(rand() % 10 +1)*pow(7,10);
  n = 10000000;
  int maxArray[10000];

  for(k=0;k<10000;k++)
  {
  
    max = 0;
    for(j=0;j<n;j++){
      s[j]=0;

    }

    for(i=0;i<n;i++)
    {
      m=rand()%n;
      s[m] = s[m] + 1;

      if(s[m]>max){
        max = s[m];
      }

    }

    maxArray[k] = max;
    printf("%d,%d\n",k,maxArray[k] );
  }
  counter(maxArray,10000);
return 0;

}

