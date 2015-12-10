#include<time.h>
#include<stdlib.h>
#include<string.h>

#ifndef const_size // ��� ������ 
#define const_size

#define  x_in_de_crease 10000
#define  y_in_de_crease 1


#define gene_node_length 256 // �� �������� ����  (16*16)/2 �̺κ��� �����ϸ� ��ü �������� ũ�⸦ �����Ҽ� �ִ�. 
#define population_size 256 // ����ü���� ���� 
#define space_width 16
#define space_height 16


#define succ_operation 1
#define fail_operation 0

#define Ture 1
#define False 0


#define memory_alloc 1
#define memory_unalloc 0
#define memory_alloc_fail 2
#define memory_unalloc_fail 3

#define three 3
#define two 2
#define one 1

#define left 75 
#define right 77 
#define up 72 
#define down 80 



#endif
///////////////////

void buffer_clear(FILE *);
void sys_diisplay_clean(void);







#ifdef __WIN32__
// ������
// #include<stdio.h> //
#define os 1

#include<stdio.h>
void buffer_clear(FILE *file)
{
	fflush(file);
}

void sys_diisplay_clean()
{
	
	system("cls");
	
	
}

#else
// ������
// #include<linux/include/stdio.h> //
#define os 0


#include<stdio.h>
void buffer_clear(FILE *file)
{
	__fpurge(file);
}

void sys_diisplay_clean()
{
	
	
	system("clean");
	
}


#endif
//////////////////

#ifndef re_define
#define re_define

typedef unsigned int basic_data; // �⺻ �������� ����ȭ 
typedef void* empty_pointer ; // void *�� ����ȭ 


#endif



#ifndef gene_struct
#define gene_struct


typedef struct gene_body
{
	
	
	struct gene_body * prev_node;
	struct gene_body * curr_node;
	struct gene_body * next_node;
	struct gene_body * tail_node;
	
	unsigned char temper; // ���� 
	unsigned int node_num; // ���� ����� ��ȣ 
	
}gene_body;



typedef struct gene_header
{
	
	unsigned int seed; // �õ� �����̴� 
	unsigned int gene_num; // ���� ��ȣ�̴�. 
	struct gene_body * neck_node;// ��ü�� �Ӹ��� �̾��ش�.  
	
}gene_header;



typedef struct plate
{
	
	unsigned int generation_num; //
	struct gene_header* breed_space[population_size]; // �Ӹ�(������)�� ��ġ�� ���� �迭 
	char plate_neme[256]; // ���̺� �̸� 
	
}plate; // ���� ���̺� 


#endif







#ifndef tree_struct
#define tree_struct

typedef struct tree
{
	struct tree * next[8];
	struct tree * head;
	unsigned char posx;
	unsigned char posy;// ��ġ 
	unsigned char value;// ����� �ξ��°�1 ��ǻ�Ͱ� �ξ��°� 2 ����� �ΰ� 0
	
}tree;// ����� �� ���� 




#endif







#ifndef memory_struct_and_func
#define memory_struct_and_func

struct gene_body * gene_maker(struct gene_header * head ,int num,int init ,int ui); // �¾� ���� 
struct gene_body * gene_modifer(struct gene_header ** head ,int num,unsigned char *data,int dest_pos); // ����ü �������� 
struct gene_body * gene_eraser(struct gene_header ** head ,int num, int value,int start_pos,int dest_pos) ; // ���������� �ʱ�ȭ 

unsigned int return_memory_allocation(unsigned int option, void * pointer_target);




typedef struct memory_struct
{
	struct memory_struct * org_address;// ����� �޸𸮰����� �����ּҰ� ����. 
	struct plate *plate_address;// ����� �޸𸮰�����  ���̺� �ּҰ� ����. 
	
}memory_struct;

typedef struct pointer_carrier_box // ����ִ� ������ �ڽ� 
{
	struct pointer_carrier_box * box_address;// �ڽ��� �ּ� 
	empty_pointer obj_address; // �ڽ��� ����Ű�� �ּ� 
	
}pointer_carrier_box;

typedef struct swap_area // ���� ����ü 
{
	struct swap_area * swap_store_address;// ���� ����ü�� �ּ� 
	empty_pointer org_address; // ���� ����� �ּ� 
	empty_pointer dest_address;// ���� ���2�� �ּ�
	unsigned int content_size; // // ���� ����� ũ�� 
	
}swap_area;

gene_body * gene_maker(gene_header * head ,int num,int init,int ui ) // �����ڸ� �����ϴ� �ӽ��Լ�  (�޸��Լ� ������Ÿ��)
{
	
	
	
	int counter=0;
	unsigned int pos[gene_node_length];	

	// start-> ���� ���� �ּ� 
	gene_body * start;
	gene_body * next;
	
	for(counter=0;counter<gene_node_length;counter ++)
	{
		pos[counter]=0;
	}
	counter=0;
	if(init == Ture)// ���������ΰ�? 
	head->neck_node = ( gene_body*)malloc(sizeof(gene_body));
	else
	{
		
	}
	
	start = head->neck_node;
	

	
	while(1)
	{
		if(counter>gene_node_length-1)// ������ ������ �Ѿ��°�? 
		break;
		
		
		
		if(init == Ture)
		{// ���������ΰ�? 
		
			while(1)
			{
				start->temper = rand()%(gene_node_length+1);
				if(pos[start->temper] == 0)
				{
					pos[start->temper] = 1;
					
					
					break;
				}
				
				
			}	
		
			
			
			
		}	
		else
		{
			// ��ü�� ������ �޾ƿ� 
		}
		
		
		start->node_num = counter; // ��� ��ȣ 
		start->curr_node = start; // ���� ��� �ּ� 
		next = ( gene_body* )malloc(sizeof(gene_body)); // ���� ��� �ּ� (���ϵ�) 
		start->next_node = next;
		start->next_node->prev_node = start; // ���� �ּ��� ���� ����� ���� �����ʹ� ���� �����ּ� 
		start = next;
		counter++;
	}
	
	if(num < 80)
	{
		printf("|",counter);
		usleep(5000);
	}
	
}
 

struct gene_body * gene_modifer(struct gene_header ** head ,int num,unsigned char *data,int dest_pos)
{
	
	int counter=0;
	unsigned int pos[gene_node_length];	

	// start-> ���� ���� �ּ� 
	gene_body * start;
	gene_body * next;
	start = head[dest_pos]->neck_node;
	

	
	while(1)
	{
		if(counter>gene_node_length-1)// ������ ������ �Ѿ��°�? 
		break;
		start->temper = *(data+counter); // �ش� �����ͷ� ������. 
		start = start->next_node;
		counter++;
	}
	
	
}//�̹��� 

struct gene_body * gene_eraser(struct gene_header ** head ,int num, int value/* ġȯ�� �� */,int start_pos/* ���� ���� */,int dest_pos/*�� ����*/) 
{
	
	int counter=0;
	int counter_pos =0;
	unsigned int pos[gene_node_length];	

	// start-> ���� ���� �ּ� 
	gene_body * start;
	gene_body * next;
	
	for(counter_pos =start_pos; counter_pos < dest_pos;counter_pos++)
	{
		counter =0; 
		start = head[counter_pos]->neck_node;// ���� ������ 
		

		
		while(1)// ������ ���̸�ŭ ���� 
		{
			
			if(counter>gene_node_length-1)// ������ ������ �Ѿ��°�?  ����  256�̴� 
			break;
			start->temper = value; // �ش� �����ͷ� ������. 
			start = start->next_node; // ���� ������ �� �ǳʶڴ�. 
			counter++;
			
		}
	}
	
	
	
}//�̹��� 

unsigned int return_memory_allocation(unsigned int option, void * pointer_target)
{
	
	free(pointer_target);
	return 0;
	
}






#endif



#ifndef omok_space_struct
#define omok_space_struct

typedef struct omok_space
{
	unsigned char space[space_width+4][space_height+4]; // ���ΰ���  (�ð� ������)
	unsigned int space_stat;// ������ ������� 
	
	
}omok_space;


char *all_line; // 2���� �迭�� 1���� �迭���� ���ߴ� ���� 

typedef struct score_board
{
	unsigned int score;
	unsigned char posx;
	unsigned char posy;
	
}score_board;




#endif

#ifndef _mutate_struct// 
#define _mutate_struct// ���̸� ����Ų�� 

// �����̳� , ���� � ��ȯ���� ����� ã�´�. 

unsigned char * cycle_cross_over(unsigned char * base);
unsigned char * serial_cross_over(unsigned char * A , unsigned char * B);


unsigned char mutate_plate[gene_node_length]; //���̵� �ڼ��� ������ �� 

unsigned char * cycle_cross_over(unsigned char * base)
{
	unsigned int counter,counter2;
	
	
	
	
	
	
	
	
	
}

unsigned char * serial_cross_over(unsigned char *A,	unsigned char *B) 
{

	
	int store[gene_node_length] ;
	srand((unsigned)time(NULL));
	
	int C[gene_node_length];
	
	memset(C,-1,gene_node_length);
	memset(store,-1,gene_node_length);
	
	int a;
	int b;
	
	
	int j;
	int i;
	int k;
	
	int set=0;
	
	scanf("%d",&a);
	fflush(stdin);
	scanf("%d",&b);
	fflush(stdin);
	
	if(a<=0 || a >= 9)
	return 0;
	if(a==b)
	return 0;
	if(a>=b)
	return 0;
	
	
	for(i=0;i<=b-a;i++)
	{
		store[i]=*(A+a+i+1) ;
	
	}
	
	
	for(i=0;i<=b-a;i++)
	{
		C[a+i+1] = store[i];
		
	
	}
	
	
	j= b+1;
	
	
		for(i=0;i<10;i++)
		{
			if(j >= 10 )
			j=0;
			if(j == a+1 )
			break;
			
			set = 0;
			for(k=0;k<b-a;k++)
			{
				
				if(*(B+i) == store[k])
				{
					set ++;
				}
				
				
				if(k == b-a-1 && set ==0)
				{
					set =-1;
					
				}
				
			}
			
			
			
			if(set == -1)
			{
				*(C+j) = *(B+i);
				j++;
				set  =0;
			}
			
			
			
		}
	
	
	for(i=0;i<10;i++)
	printf("%d ",*(C+i));
	
		
	return 0;
}

#endif






#ifndef _excutive_test
#define _excutive_test

/*
	0�� ���� 127 �� ����߿��� 0�� ����� ���յ��� ���� ����ü�� �����Ͽ� �θ�� ��´�. 
	�׸��� 1�� ����߿��� ���յ��� ���� ����ü�� �����Ѵ�. 
	����ü������ ������ �ߺ��� �����ǹǷ� �̹� �����ִ¼��� �ߺ� ����� ���� �Ҽ� �ִ�. 
	�̷������� n�� ��带 �����ϴ� ���ų� �̱�� ����� ������ �� ����ü�� ���Ϸ� �����Ͽ� ���÷� �����Ѵ�. 


*/

score_board * score(tree * tree_node,omok_space * omok,score_board  *score_array);
unsigned int referee(omok_space * omok,unsigned char posx,unsigned char posy );
unsigned int fitness_selector(unsigned int mode,unsigned char posx,unsigned char posy,omok_space * omok,tree * tree_node,unsigned int counter);
unsigned int learn_fight(gene_header** read_address);
unsigned char vote_gene(gene_header** read_address,score_board * score,unsigned int turn,omok_space * omok);

unsigned int exception_handler(unsigned int code,void * data);//



score_board * score(tree * tree_node,omok_space * omok,score_board  *score_array)// �����ڰ� �� ���� ���� ������ ���� ���� ��� 
{
	
	unsigned int score;
	unsigned int counter,counter2 ,header=0;
	unsigned char x2,y2;
	
	
	
	for(counter =0;counter<8;counter++)
	{
		x2 = tree_node->next[counter]->posx ;
		y2 = tree_node->next[counter]->posy ;
		
		if( x2 <= 1 || y2 <= 1 || x2 >= 18 || y2 >= 18 )// �н� (�ʰ���) 
		{
			printf("x\n");
		}
		else// ��� 
		{
			printf("%d %d ��ġ %d ��\n",x2-2,y2-2,tree_node->next[counter]->value );
		}
	
	}
	
	
	for(counter2 =0;counter2<8;counter2++)
	{	
		printf("\n" );
		for(counter =0;counter<8;counter++)
		{
			x2 = tree_node->next[counter]->next[counter2]->posx ;
			y2 = tree_node->next[counter]->next[counter2]->posy ;
		
			if( x2 <= 1 || y2 <= 1 || x2 >= 18 || y2 >= 18 )// �н� (�ʰ���) 
			{
				printf("x\n");
			}
			else// ��� 
			{
				printf("%d %d ��ġ %d ��\n ",x2-2,y2-2,tree_node->next[counter]->value );
				
				if(omok->space[x2][y2] == 0 && tree_node->next[counter]->value == 0) // ��� ���� 
				{
					omok->space[x2][y2] == 1;
					// ���� ī��Ʈ 
					score = referee(omok,x2,y2);
					//��ǥ ���� 
					omok->space[x2][y2] == 0;
					score_array[(counter+1)*(counter2+1)-1].posx = x2-2;
					score_array[(counter+1)*(counter2+1)-1].posy = y2-2;
					score_array[(counter+1)*(counter2+1)-1].score = score;
					printf("%d ����\n",score);
				}

			}
		}
		printf("\n" );
	}
	
	return score_array;
}
	
	
	


unsigned int referee(omok_space * omok,unsigned char posx,unsigned char posy )// ��� ���� ���� Ž����� 
{
	/////////////////////////////////////////// �� �κ��� �����Ͽ� ���յ� ������ �ٲܼ� �ִ�. 
	unsigned char x,y;
	unsigned int score_max;
	unsigned int scoreing=0;
	unsigned int score[4];
	unsigned int counter2,counter=0;
	int pattern[20][2] = {{-2,-2},{-1,-1},{0,0},{1,1},{2,2},
						  {0,2},{0,1},{0,0},{0,-1},{0,-2},
						  {2,0},{1,0},{0,0},{-1,0},{-2,0},
						  {-2,2},{-1,1},{0,0},{1,-1},{2,-2}};
						  
	
	x=posx;
	y=posy;
	
	for(counter2 =0 ;counter2<20; counter2 = counter2 +5 )
	{
		if(omok->space[x+pattern[counter2][0]][y+pattern[counter2][1]] == 1 )
		{
			if(omok->space[x+pattern[counter2+1][0]][y+pattern[counter2+1][1]] == 1 )
			{
				scoreing = scoreing+2;
			}
			 
			
		}
		
		if(omok->space[x+pattern[counter2+1][0]][y+pattern[counter2+1][1]] == 1 )
		{
			scoreing++;
		}
		
	
		
		if(omok->space[x+pattern[counter2+4][0]][y+pattern[counter2+4][1]] == 1 )
		{
			if(omok->space[x+pattern[counter2+3][0]][y+pattern[counter2+3][1]] == 1 )
			{
				scoreing++;
			}
		}
		
		if(omok->space[x+pattern[counter2+3][0]][y+pattern[counter2+3][1]] == 1 )
		{
			scoreing++;
		}
		
		score[counter]= scoreing;
	
		counter ++;
		
		scoreing = 0;
	} 
	
	scoreing =0;
	
	for(counter =0; counter<4;counter ++)
	{
		if(scoreing  <= score[counter])
		{
			scoreing = score[counter];
		}
		
		
	}
	
	
	
	
	////////////////////////////////////////////
	
	
	return scoreing;
	
}

unsigned char vote_gene(gene_header** read_address,score_board * score,unsigned int turn,omok_space * omok)// ����ü ���� 
{
	
	unsigned int counter=0,counter2=0,grade=0,tall=0;
	unsigned char value,x,y;
	score_board final[8];
	
	
	memset(final,0,8*sizeof(score_board));
	
	gene_body* start;
	///////////// ��ǥ�� ������  ��ĥ��� �������� �����Ѵ�. 
	
	
	
	for(counter=0;counter < 81;counter++)
	{
		if(tall <= score[counter].score )
		tall = score[counter].score;
		
	}
	
	for(counter=0;counter < 81;counter++)
	{
		if(tall == score[counter].score )
		{
			final[counter2].posx =  score[counter].posx;
			final[counter2].posy =  score[counter].posy;
			counter2++;
		}
		
	}
	
	tall = 0;
	for(counter =0 ;counter <7;counter++)
	{
		if(final[counter].posx ==  score[counter+1].posx && final[counter].posy == score[counter+1].posy )
		{
			
		}
		else if(final[counter].score !=  0 || final[counter].score != 0)
		{
			tall++;
		}
	}
	
	if(tall == 0)
	{
		value = final[0].posx << 4 ;
		value = final[0].posy + value;
		
		
	}
	else
	{
		tall = rand()%tall;
	}
	
	//////////////
	
	for(counter=0;counter < population_size;counter++)
	{
		start = read_address[counter]->neck_node;
		for(counter2=0;counter2<turn;counter2++)
		{
			start = start->next_node;
			
		}
		
		if(start->temper  == value )// ��ġ�� �Է�  ��ǥ 
		{
			y= start->temper << 4;
			y= y >> 4;
			
			x= start->temper >> 4;
			
			printf("%d %d d\n" ,x,y );
			omok->space[x+2][y+2] =7;
		}
		// ���� ��ǥ���� ���� ����ü�� ã�´�.  
		
	}
	// ���븦 �������� �ѱ��. 
	printf("���� �� ��������");
	printf("���� ����");
	
	// ���� ���� ���� ���� 
	
	
}




//�۾����� 
unsigned int fitness_selector(unsigned int mode,unsigned char posx,unsigned char posy,omok_space * omok,tree *tree_node,unsigned int counter)
{
	
	
	
	gene_body* start;
	unsigned char x;
	unsigned char y;
	unsigned char save;
	
	unsigned int counter2;
	
	x =
	 posx;
	y = posy;
	
	
	
//	start = read_address[counter_gene_head]->neck_node;
	
	int pattern[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
	
	
	
		
		
		if(mode == 0)
		{
			
			for(counter2 =0 ;counter2<8; counter2++ )
			tree_node->next[counter2] = (tree*)malloc(sizeof(tree));
			
			
			for(counter2 =0 ;counter2<8; counter2++ )
			{
				if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 0)
				{
					tree_node->next[counter2]->value = 0;
					tree_node->next[counter2]->posx = x +1*pattern[counter2][0] ;
					tree_node->next[counter2]->posy = y +1*pattern[counter2][1] ;
				}
				else if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 1)
				{
					tree_node->next[counter2]->value = 1;
					tree_node->next[counter2]->posx = x +1*pattern[counter2][0] ;
					tree_node->next[counter2]->posy = y +1*pattern[counter2][1] ;
				}
				else if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 2)
				{
					tree_node->next[counter2]->value = 2;
					tree_node->next[counter2]->posx = x +1*pattern[counter2][0] ;
					tree_node->next[counter2]->posy = y +1*pattern[counter2][1] ;
				}
				
			}
			
			
			
			
			
		}
		if(mode == 1)
		{
			
				for(counter2 =0 ;counter2<8; counter2++ )
			tree_node->next[counter2] = (tree*)malloc(sizeof(tree));
			
			
			for(counter2 =0 ;counter2<8; counter2++ )
			{
				if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 0)
				{
					tree_node->next[counter2]->value = 0;
					tree_node->next[counter2]->posx = x +1*pattern[counter2][0] ;
					tree_node->next[counter2]->posy = y +1*pattern[counter2][1] ;
				}
				else if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 1)
				{
					tree_node->next[counter2]->value = 1;
					tree_node->next[counter2]->posx = x +1*pattern[counter2][0] ;
					tree_node->next[counter2]->posy = y +1*pattern[counter2][1] ;
				}
				else if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 2)
				{
					tree_node->next[counter2]->value = 2;
					tree_node->next[counter2]->posx = x +1*pattern[counter2][0] ;
					tree_node->next[counter2]->posy = y +1*pattern[counter2][1] ;
				}
			}
			
			return 1;
			
		}
			
		return 1;
		
		
		
	
	
	
	

	
}




unsigned int exception_handler(unsigned int code,void * data)
{
	if(code == 0)// �ߺ��Ǵ� ���յ� 
	{
		
	}
	else if(code == 1)// �ش� ����ü ���� 
	{
		
	}
	

	
	
}





#endif









#ifndef api// ���� ������ ����.  api�̱� ������ 
#define api

unsigned int show(unsigned int start_pos ,unsigned int dest_pos, gene_header** read_address); //���� ������� ���� �Լ� 
unsigned int ui_main(memory_struct  current_pos); // ui���� 
unsigned int space_view(gene_header** read_address);
unsigned int learn_fight(gene_header** read_address);





unsigned int show(unsigned int start_pos ,unsigned int dest_pos, gene_header** read_address)
{
	
	gene_body* start;
	unsigned int counter;
	unsigned int counter2;
	
	unsigned char x,y;
	
	
	for(counter = start_pos ;counter <= dest_pos;counter++  )
	{
		
		start = read_address[counter]->neck_node;
 		printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ� %d \n", counter);
		for(counter2=0;counter2<gene_node_length;counter2++)
		{
			
			printf("%d �� ���  \n", start->node_num );
		
			y= start->temper << 4;
			y= y >> 4;
			
			x= start->temper >> 4;
			
			printf("x: %d y:  %d \n", x,y );
			
			
			if(start->next_node == NULL)
			{
				return 0;
			} 
			
			start = start->next_node;
		}
			
	}
	
	
	
}



unsigned int ui_main(memory_struct  current_pos)
{
	void* current_pointer;
	
	current_pointer = current_pos.plate_address->breed_space; // ���� �ּҸ� �Ѱ� ���� ��Ʈ 
	 
	unsigned int select1 , select2 ,select3; 
	unsigned int choose;
	
	unsigned char sample[gene_node_length]; // ������ ���ڿ� 
	memset(sample,65,gene_node_length); // ���ڿ���  ������ ������ �����Ѵ�. ����&����Ǵ� ����ü�� �̿� �ش�ȴ�. 
	
	
	
	while(1)
	{
		printf("���� ���� �˰��� 153337 �����\n");
		printf("\n \t 1.����ü ��ġ������  ���� \n");
		printf("\n \t 2.����ü ��ǥ�󿡼� ���� \n");
		printf("\n \t 3.����ü ġȯ \n");
		printf("\n \t 4.����ü ���� \n");
		printf("\n \t 5.������ �׽�Ʈ \n");
		
		scanf("%d",&choose);
		buffer_clear(stdin);
		if(choose == 1) // ������ ���� 
		{
			while(1)
			{
				printf("�ΰ��� ���� �Է��ϼ��� �� ����  ���ų� ������ �ʰ��Ǹ� �����\n");
				scanf("%d",&select1);
				buffer_clear(stdin);
				scanf("%d",&select2);
				buffer_clear(stdin);
				
				if(select1 == select2)
				{
					break;
				}
				if(select1 >= population_size || select2 >= population_size || select1 <= 0 || select2 <= 0)
				{
					break;
				}
				
				show(select1,select2,current_pointer); // ����ü ���� ��� 
			}
		} 
		else if(choose == 2)//  ��ǥ �˻� 
		{
			space_view(current_pointer);
		}
		else if(choose == 3)// 
		{
			
			while(1)
			{
				
				printf("\n \t ����ü ġȯ \n");
				printf("\n \t ������ �� �� �Է����ּ��� \n");
				
				
				
				scanf("%d",&select1);
				buffer_clear(stdin);
				scanf("%d",&select2);
				buffer_clear(stdin);
				
				if(select1 == select2)
				{
					break;
				}
				if(select1 >= population_size || select2 >= population_size || select1 <= 0 || select2 <= 0)
				{
					break;
				}
				
				
				printf("\n \t ġȯ�� ���� �Է����ּ��� \n");
				scanf("%c",&select3);
				buffer_clear(stdin);
				
				
				
				
				gene_eraser(current_pointer,0, select3,select1,select2) ;
				
				
			}
		}
		else if(choose == 4)// 
		{
			
			while(1)
			{
				
				printf("\n \t ����ü ���� \n");
				printf("\n \t ������ ����ü�� �Է����ּ��� \n");
				
				
				
				scanf("%d",&select1);
				buffer_clear(stdin);
			
				
				if(select1 > population_size)
				{
					break;
				}
				if(select1 >= population_size ||  select1 <= 0 )
				{
					break;
				}
				
				
				printf("\n \t ���Ե� ��  \n");
				printf("\n \t %s  \n",sample);
				buffer_clear(stdin);
				
				
				
				
				gene_modifer(current_pointer,0,sample,select1);
				
				
			}
		}
		else if(choose == 5)//  �н���Ű�� 
		{
			
			learn_fight(current_pointer);
			
			
			
		}
		else
		{
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		
	} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

unsigned int space_view(gene_header** read_address)
{
	
	omok_space space;
	unsigned int counter_x,counter_y;
	unsigned int keyboard_key;
	gene_body* start;
	unsigned int counter_gene_head;
	unsigned int counter2;
	unsigned char x,y;
	
	
	
	// ��ǥ�ʱ�ȭ ��� 
	
	while(1)
	{
		
		for(counter_x = 0 ;counter_x < space_height+4; counter_x++)
		{
			for(counter_y = 0 ;counter_y < space_width+4; counter_y++)
			{
				space.space[counter_x][counter_y] = 0;
			}
			
		}
		
		
		printf("����ü ��ȣ�� �Է��ϼ���\n");
		scanf("%d",&counter_gene_head);
		
		
		if(counter_gene_head >= population_size)
		break;
		
		start = read_address[counter_gene_head]->neck_node;
 		
		for(counter2=0;counter2<gene_node_length;counter2++)
		{
			
			
			
		
			y= start->temper << 4;
			y= y >> 4;
			
			x= start->temper >> 4;
			
			
			space.space[x+2][y+2] = 1;
			
			
			
			if(start->next_node == NULL)
			{
				return 0;
			} 
			
			
			for(counter_x = 2 ;counter_x < space_height+2; counter_x++)
			{
				printf("\n");
				for(counter_y = 2 ;counter_y < space_width+2; counter_y++)
				{
					printf("%d ",space.space[counter_x][counter_y]);
				}
				
			}
			printf("\n");
			
			keyboard_key = getch();
			
			if(keyboard_key == 27)
			{
				break;
			}
			
			
			sys_diisplay_clean();
			
			
			
			start = start->next_node;
		}
			
			
			
		
		

	}
	
	
	
	
	
	
	
}


unsigned int learn_fight(gene_header** read_address) // ���α׷��� �н� ��Ų��. 
{
	
	gene_body * start;
	gene_body * next;
	//start = head[2]->neck_node;
	tree * make_tree;
	omok_space  fight_place;
	score_board * scores;
	score_board score_array[81]; 
	unsigned int turn=0;
	unsigned int keyboard_key;
	unsigned int counter=0,counter2 =0;
	unsigned char x,y,posx,posy,x2,y2;
	
	x = 7;
	y = 7;
	
	
	
	memset(fight_place.space,0,20*20);
	
	printf("�н��� �����մϴ�.\n");
	
	while(1)
	{
		
		
		keyboard_key = getch();
		sys_diisplay_clean();
		
		if(keyboard_key == 27)
		{
			break;
		}
		
		if(keyboard_key == 13 && fight_place.space[x+2][y+2] == 0)
		{
			fight_place.space[x+2][y+2] = 1;
			
			make_tree = (tree *)malloc(sizeof(tree));
		
			turn++;	
			
			make_tree->posx = x+2;
			make_tree->posy = y+2;
			
			printf("�Է�\n");
			fitness_selector(0,make_tree->posx,make_tree->posy,&fight_place,make_tree,0);
			
			
			
			for(counter =0;counter<8;counter++)
			{
				fitness_selector(1,make_tree->next[counter]->posx,make_tree->next[counter]->posy,&fight_place,make_tree->next[counter],counter);
			// ������ ���� ��� ���� 
				printf("���\n");
			}
		
			
			scores = score(make_tree,&fight_place,&score_array[0]); // ���յ��� �����ϰ� ���� �δ� �Լ� 
			printf("%d ��\n",turn);
			vote_gene(read_address,scores,turn,&fight_place);
			memset(score_array,0,81*sizeof(score_board)); 
			free(make_tree); // Ʈ���� �ʱ�ȭ 
			
			
			// x ��ǥ�� ������� �ٲ۴�. 
		}
		else if(fight_place.space[x+2][y+2] != 0)
		{
			printf("�̹� ���� ���ΰ��Դϴ�.\n");
		}
		
		if(keyboard_key == 224)
		{
			keyboard_key = getch();
			printf("%d \n",keyboard_key);
			
			if(keyboard_key == left && (x > 0 && x <= 15  ))
			{
				x--;
			}
		
			if(keyboard_key == right && (x >= 0 && x < 15  ))
			{
				x++;
			}
			
			if(keyboard_key == up && (y > 0 && y <= 15  ))
			{
				y--;
			}
			
			if(keyboard_key == down && (y >= 0 && y < 15  ))
			{
				y++;
			}
		
			
			
		}
		
		for(counter =2;counter < space_height+2 ;counter ++)
		{
			printf("\n");
			for(counter2=2 ;counter2 < space_width+2 ;counter2 ++ )
			{
				if(x+2== counter2 && y+2 == counter)
				{
					printf("x ");
				}
				else
				{
					printf("%d ",fight_place.space[counter2][counter]);
				}
				
			}
		}
		
				
		
		printf("^ %d %d ^\n",x,y);
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
}






#endif




