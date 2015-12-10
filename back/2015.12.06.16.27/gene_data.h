#include<time.h>
#include<stdio.h>
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
	unsigned char pos; // ��ġ 
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
	unsigned char space[space_width][space_height]; // ���ΰ���  (�ð� ������)
	unsigned int space_stat;// ������ ������� 
	
	
}omok_space;


char *all_line; // 2���� �迭�� 1���� �迭���� ���ߴ� ���� 






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

unsigned int score(unsigned char user_input,omok_space * omok);
unsigned int tree_navigator(memory_struct  current_pos);
unsigned int referee(memory_struct  current_pos);
unsigned int fitness_selector(unsigned int mode,unsigned char user_input,omok_space * omok,tree * tree_node,unsigned int counter);
unsigned int learn_fight(gene_header** read_address);




unsigned int tree_navigator(memory_struct  current_pos)// Ʈ���� �̿��� ���� �Լ� 
{
	
}

unsigned int score(unsigned char user_input,omok_space * omok)// �����ڰ� �� ���� ���� ������ ���� ���� ��� 
{
	
	
	
	
	
}

unsigned int referee(memory_struct  current_pos)// ��� ���� ���� Ž����� 
{
	
}

//�۾����� 
unsigned int fitness_selector(unsigned int mode,unsigned char user_input,omok_space * omok,tree *tree_node,unsigned int counter)
{
	
	
	
	gene_body* start;
	unsigned char x;
	unsigned char y;
	unsigned char save;
	
	unsigned int counter2;
	
	
//	start = read_address[counter_gene_head]->neck_node;
	
	int pattern[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
	
	

	
	y= user_input << 4;
	y= y >> 4;	
	x= user_input >> 4;
	
	if( x < 2 || y < 2 || x > 13 || y > 13 )// ���� ó�� 
	{
		return 0;
		// �������� �������� 
	}
	else
	{
		
		if(mode == 0)
		{
			
			for(counter2 =0 ;counter2<8; counter2++ )
			tree_node->next[counter2] = (tree*)malloc(sizeof(tree));
			
			
			for(counter2 =0 ;counter2<8; counter2++ )
			{
				if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 0)
				{
					tree_node->next[counter2]->value = 0;
					tree_node->next[counter2]->pos = user_input +x_in_de_crease*pattern[counter2][0] +y_in_de_crease*pattern[counter2][1];
				}
				else if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 1)
				{
					tree_node->next[counter2]->value = 1;
					tree_node->next[counter2]->pos = user_input +x_in_de_crease*pattern[counter2][0] +y_in_de_crease*pattern[counter2][1];
					
				}
				else if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 2)
				{
					tree_node->next[counter2]->value = 2;
					tree_node->next[counter2]->pos = user_input +x_in_de_crease*pattern[counter2][0] +y_in_de_crease*pattern[counter2][1];
					
				}
			}
			
			
			
			
			
		}
		if(mode == 1)
		{
			
			y= tree_node->pos << 4;
			y= y >> 4;	
			x= tree_node->pos >> 4;
			
			
			if( x < 2 || y < 2 || x > 13 || y > 13 )// ���� ó�� 
			{
				return 0;
				// �������� �������� 
			}
			
			
			for(counter2 =0;counter2<8;counter2++ )
			tree_node->next[counter2] = (tree*)malloc(sizeof(tree));
			
			for(counter2 =0 ;counter2<8; counter2++ )
			{
				if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 0)
				{
					tree_node->next[counter2]->value = 0;
					tree_node->next[counter2]->pos = user_input +x_in_de_crease*pattern[counter2][0] +y_in_de_crease*pattern[counter2][1];
				}
				else if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 1)
				{
					tree_node->next[counter2]->value = 1;
					tree_node->next[counter2]->pos = user_input +x_in_de_crease*pattern[counter2][0] +y_in_de_crease*pattern[counter2][1];
					
				}
				else if( omok->space[x+ pattern[counter2][0]][y+pattern[counter2][1]] == 2)
				{
					tree_node->next[counter2]->value = 2;
					tree_node->next[counter2]->pos = user_input +x_in_de_crease*pattern[counter2][0] +y_in_de_crease*pattern[counter2][1];
					
				}
			}
			
			
			
		}
			
		
		
		
		
	}
	
	return;
	
	for(counter2=0;counter2< 8;counter2++)
	{
		printf("%d ��° ������ ���� %d\n",counter2,tree_node->next[counter2]->value );
		
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
		
		for(counter_x = 0 ;counter_x < space_height; counter_x++)
		{
			for(counter_y = 0 ;counter_y < space_width; counter_y++)
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
			
			
			space.space[x][y] = 1;
			
			
			
			if(start->next_node == NULL)
			{
				return 0;
			} 
			
			
			for(counter_x = 0 ;counter_x < space_height; counter_x++)
			{
				printf("\n");
				for(counter_y = 0 ;counter_y < space_width; counter_y++)
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
	
	unsigned int keyboard_key;
	unsigned int counter=0;
	unsigned char x,y,pos;
	
	x = 7;
	y = 7;
	
	
	
	memset(fight_place.space,0,gene_node_length);
	
	printf("�н��� �����մϴ�.\n");
	
	while(1)
	{
		
		
		keyboard_key = getch();
		
		
		if(keyboard_key == 27)
		{
			break;
		}
		
		if(keyboard_key == 13)
		{
			fight_place.space[x][y] = 1;
			
			make_tree = (tree *)malloc(sizeof(tree));
		
			x = x << 4;
			pos = x+y;
			
			
			printf("�Է�\n");
			fitness_selector(0,pos,&fight_place,make_tree,0);
			
			
			for(counter =0;counter<8;counter++)
			{
				fitness_selector(1,pos,&fight_place,make_tree->next[counter],counter);
			// ������ ���� ��� ���� 
				printf("���\n");
			}
			
			//
			
			//��� �б� 
			for(counter =0;counter<8;counter++)
			printf("%d��ġ %d ��\n",make_tree->next[counter]->pos,make_tree->next[counter]->value );
			
			for(counter =0;counter<8;counter++)
			printf("%d��ġ %d ��\n",make_tree->next[counter]->next[counter]->pos,make_tree->next[counter]->next[counter]->value );
			
			free(make_tree);
			
			x = x >> 4;// x ��ǥ�� ������� �ٲ۴�. 
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
		
		printf("^ %d %d ^\n",x,y);
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
}






#endif



















