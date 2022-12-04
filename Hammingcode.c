
#include <stdio.h>

int main()
{
 

   
    int data[7]={};
    int datarec[7],c,c1,c2,c3;
    // hamming code for 4 bit data so redudeant bits needed is 2^r>=d+r+1 which is r=3 
    printf("eneter 4 bit data \n");
    //redundant bits are stored at positions 2^r where r=0,1,2 that is  1,2,4,...
    
    // scanf("%d",&data[3]); 
    //  scanf("%d",&data[5]);
    //   scanf("%d",&data[6]);
    //   scanf("%d",&data[7]);
    //as indexing start from 0 
       scanf("%d",&data[2]); 
       scanf("%d",&data[4]);
      scanf("%d",&data[5]);
      scanf("%d",&data[6]);
       
      //     1  2  3  4  5  6  7
     //data [] [] [] [] [] [] []
    //   data[1]=data[1]^data[3]^data[5]^data[7];
    //   data[2]=data[2]^data[3]^data[6]^data[7];
    //   data[4]=data[4]^data[5]^data[6]^data[7];
    // but since array is 0 indexing we write it as  
      
      data[0]=data[0]^data[2]^data[4]^data[6];
      data[1]=data[1]^data[2]^data[5]^data[6];
      data[3]=data[3]^data[4]^data[5]^data[6];
      printf("encoded data is \n");
      int i;
      for(i=0;i<7;i++)
      printf("%d",data[i]);
      
      printf("\n enter data at receiver end one by one \n ");
      for(i=0;i<7;i++)
      scanf("%d",&datarec[i]);
      
      
      c1=datarec[0]^datarec[2]^datarec[4]^datarec[6];
      c2=datarec[1]^datarec[2]^datarec[5]^datarec[6];
      c3=datarec[3]^datarec[4]^datarec[5]^datarec[6];
      c=c3*4+c2*2+c1*1;
      int sizeofarray=sizeof(datarec)/sizeof(datarec[0]);
      if (c==0){
          printf("no error occured in transmitting \n");
      }else{
           printf(" error occured at position %d \t that is ",sizeofarray-c+1);

      }
       for(i=0;i<7;i++)
      printf("%d",datarec[i]);
      
      printf("  \n error corrected data at receiver end:");
      datarec[c-1]=(!c);
      for(i=0;i<7;i++)
      printf("%d",datarec[i]);
      
      
    
    

     return 0;
}
