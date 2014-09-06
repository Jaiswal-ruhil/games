#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"user.h"

int random_matrix(int *arr,int seed);
int get_seed();
void dispmatrix(const int *arr);
int playmatrix(int *arr,int pos);
int testmatrix(const int *arr);

int main()
{
  int arr[16],pos;
  pos=random_matrix(arr,get_seed());
  do
  {
    system("clear");
    dispmatrix(arr);
    pos=playmatrix(arr,pos);
  }while(testmatrix(arr));
  system("clear");
  printf("wonderful u secessfully ended the game\n\n");
  return 0;
}

int testmatrix(const int *arr)
{
  int i;
  for(i=0;i<15;i++)
    if(arr[i]!=(i+1))
      return 1;
  return 0;
}

int playmatrix(int *arr,int pos)
{
  int temp,i;
  i=pos;
  if((temp=getch())==27)
  {
    if(getch()==91)
      switch(getch())
      {// fill the blank not move the blank
        case 'B':
         pos-=(pos/4)?4:0;
         break;
        case 'A':
         pos+=((pos/4)<3)?4:0;
         break;
        case 'C':
         pos-=(pos%4)?1:0;
         break;
        case 'D':
         pos+=((pos%4)<3)?1:0;
         break;
      }
    temp=arr[i];
    arr[i]=arr[pos];
    arr[pos]=temp;
  }
  else if(temp=='\n')
    pos=random_matrix(arr,get_seed());
  else
    exit(0);
  return pos;
}
int random_matrix(int *arr,int seed)
{
	int i,pos,temp,temparr[16]={0};
	srandom(seed);
  for(i=0;i<16;i++)
	{
	  do
     temp=random()%16;
    while((i+1)==temp || temparr[temp]==1);
    temparr[*(arr+i)=temp]=1;
    if(temp==0)
      pos=i;
  }
  return pos;
}

int get_seed()
{
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo=localtime(&rawtime);
  return timeinfo->tm_min+timeinfo->tm_hour+timeinfo->tm_sec;
}

void dispmatrix(const int *arr)
{
  int i,j,k=0;
  for(i=0;i<4;i++)
  {
    printf("\
    *********************************\n\
    *       *       *       *       *\n    ");
    for(j=0;j<4;j++,k++)
    {
      if(arr[k])
        printf("*  %2d   ",arr[k]);
      else
        printf("*       ");
    }
    printf("*\n\
    *       *       *       *       *\n");
  }printf("\
    *********************************\n\n\
  1. play the matrix by the arrow keys, 0 is the empty block\n\
  2. new matrix press enter\n\
     else exit\n\n\n");
}
