#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	
	char A[10];	
	char B[10];
	char C[10];
	char find;
	char save;
	int turn;
	int a;
	int i;
	int j=0;
	int k=0;
	int counter=0;
	int switching=0;
	
	
		strcpy(A,"8710634952");//11
		strcpy(B,"0243156789");
		memset(C,65,10);
		
		turn=0;
	 
		save = A[j];
		find = B[j];	
		C[j] = A[j];
		
		
				
				
				while(1)
				{
					if(i==10)
					{
						i==0;
					}
					
					
					if(turn ==0)
					{
							
						//
						
						
						
						for(i=j;i<10;i++)
						{
							if(find == A[i])
							{
							
								C[i] = A[i];
								find = B[i];	
								break;	
							}
							
						}
						
						if(save == find )
						{
							
							turn = 1;
							j++;
							switching=1;
							
							
						}
						
					}
					
					
					if(switching==1)
					{
						if(turn == 1)
						{
							find = A[j];
							C[j] = B[j];
							save = B[j];
							switching =0;
						}
						else
						{
							find = B[j];
							C[j] = A[j];
							save = A[j];
							switching =0;
						}
						
						
					}
					
				
					if(turn ==1)
					{
					
						
						
							
						
						for(i=j;i<10;i++)
						{
							if(find == B[i])
							{
								C[i] = B[i];
								find = A[i];
								break;
							}
							
						}
					
						if(save == find )
						{
							turn = 0;
							j++;
							switching=1;
							
							
						}
						
						
					}
					
						
					if(switching==1)
					{
						if(turn == 1)
						{
							find = A[j];
							C[j] = B[j];
							save = B[j];
							switching =0;
						}
						else
						{
							find = B[j];
							C[j] = A[j];
							save = A[j];
							switching =0;
						}
						
						
						
					}

							///////////
							for(k=0;k<10;k++)
							{
								
								if(C[k] == 'A')
								{
									counter = 0;
									break;
								}
								else
								{
									counter++;
									
								}
								
							}
							////////
							
							if(counter == 10)
							{
								
								break;
								
							}
							
							printf("%s \n",C);
							printf("%d <%d> (%c 저장)  (%c 찾기) %d \n",i,j,save,find);
							system("pause");
							
							
				}
				
						
							
			
	return 0;
}
