#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

static int s[1000000];


void counter(int array[],int k){
               
   FILE *fp;
   char output[]="data3.txt";
   int n;
    
   fp=fopen(output,"w");
   for(n=0;n<k;n++) {
   fprintf(fp,"%d\n",array[n]);
   }
    
   fclose(fp);
    
  }



int rand_lim(int limit) {
/* return a random number between 0 and limit inclusive.
 */

    int divisor = RAND_MAX/(limit+1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}



int fake_calls(int* s,int k,int n)
{
    int i,m,count=0;
    for(i=0;i<k;i++)
    {
        m= rand_lim(n-1);
        //printf("%d\n",m);
        if(s[m]==0){
            s[m] = 1;
            count++;
        }
    }

    return count;
}


int main()
{

 int iteration = 10000;
 int numDays[iteration],i,j,k,k1;
 //long int 0;
 srand(time(0));
 //n=(rand()%10+1))*pow(6,10);
 int n=1000000;
 //int s[n]

 

 for(j=0;j<iteration;j++){
    
    for(i=0;i<n;i++){
        //printf("%d\n",i);
        s[i] = 0;
    }


    i=s[0]=1;
    k=1,k1=0;
    //printf("%d\n",i );
    while(i<=100)
    {   // we can set time limit
        //printf("%d,%d,%d\n",i,k,k1 );
        
        k=k+k1;
        //printf("%d,%d\n",i,k );
        //printf ("%d,%d\n",i,k);
        if(k==n)
            break;
        k1=fake_calls(s,k,n);
        i++;
    }

    numDays[j] = i;
    printf("%d,%d\n",j,numDays[j]);
}
 counter(numDays,iteration);
return 0;
}


