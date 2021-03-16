//  Accept file name, from user and return number of capital charcters.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int FileCapitalCount(char *name)
{
  int fd = 0;
  int iRet = 0;
  int iCnt = 0;
  int i = 0;
  
  
  char mug[100];
  
  fd = open(name,O_RDONLY);
  
  if(fd == -1)
  {
     printf("unable to open the file \n");
  }
  
  while((iRet = read(fd,mug,sizeof(mug))) != 0)
  {
	  for(i = 0; i < iRet; i++)
	  {
           if((mug[i] >= 'A') && (mug[i] <= 'Z'))
		   {
			   iCnt++;
		   }
	  }		  
  }
  close(fd);
  return iCnt;
}

int main()
{
  char name[20];
  int iRet = 0;
  
  printf("Enter the file name\n");
  scanf("%s",name);
  
  iRet = FileCapitalCount(name);
  
  printf("No of capital character are : %d\n",iRet);

return 0;
}

/*

output

Enter the file name
Data.txt
No of capital character are : 2

*/