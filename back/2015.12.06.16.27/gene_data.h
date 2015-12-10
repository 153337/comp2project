#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef const_size // 상수 데이터 
#define const_size

#define  x_in_de_crease 10000
#define  y_in_de_crease 1


#define gene_node_length 256 // 한 유전자의 길이  (16*16)/2 이부분을 조작하면 전체 유전자의 크기를 제어할수 있다. 
#define population_size 256 // 염색체수의 설정 
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
// 윈도우
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
// 리눅스
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

typedef unsigned int basic_data; // 기본 데이터의 문서화 
typedef void* empty_pointer ; // void *의 문서화 


#endif



#ifndef gene_struct
#define gene_struct


typedef struct gene_body
{
	
	
	struct gene_body * prev_node;
	struct gene_body * curr_node;
	struct gene_body * next_node;
	struct gene_body * tail_node;
	
	unsigned char temper; // 성질 
	unsigned int node_num; // 현재 노드의 번호 
	
}gene_body;



typedef struct gene_header
{
	
	unsigned int seed; // 시드 정보이다 
	unsigned int gene_num; // 세대 번호이다. 
	struct gene_body * neck_node;// 본체와 머리를 이어준다.  
	
}gene_header;



typedef struct plate
{
	
	unsigned int generation_num; //
	struct gene_header* breed_space[population_size]; // 머리(유전자)의 위치값 들의 배열 
	char plate_neme[256]; // 테이블 이름 
	
}plate; // 실험 테이블 


#endif







#ifndef tree_struct
#define tree_struct

typedef struct tree
{
	struct tree * next[8];
	struct tree * head;
	unsigned char pos; // 위치 
	unsigned char value;// 사람이 두었는가1 컴퓨터가 두었는가 2 빈공간 인가 0
	
}tree;// 경우의 수 계산용 




#endif







#ifndef memory_struct_and_func
#define memory_struct_and_func

struct gene_body * gene_maker(struct gene_header * head ,int num,int init ,int ui); // 셋업 과정 
struct gene_body * gene_modifer(struct gene_header ** head ,int num,unsigned char *data,int dest_pos); // 염색체 단위수정 
struct gene_body * gene_eraser(struct gene_header ** head ,int num, int value,int start_pos,int dest_pos) ; // 일정값으로 초기화 

unsigned int return_memory_allocation(unsigned int option, void * pointer_target);




typedef struct memory_struct
{
	struct memory_struct * org_address;// 사용할 메모리공간의 시작주소가 들어간다. 
	struct plate *plate_address;// 사용할 메모리공간의  테이블 주소가 들어간다. 
	
}memory_struct;

typedef struct pointer_carrier_box // 비어있는 포인터 박스 
{
	struct pointer_carrier_box * box_address;// 박스의 주소 
	empty_pointer obj_address; // 박스가 가르키는 주소 
	
}pointer_carrier_box;

typedef struct swap_area // 스왑 구조체 
{
	struct swap_area * swap_store_address;// 스왑 구조체의 주소 
	empty_pointer org_address; // 스왑 대상의 주소 
	empty_pointer dest_address;// 스왑 대상2의 주소
	unsigned int content_size; // // 스왑 대상의 크기 
	
}swap_area;

gene_body * gene_maker(gene_header * head ,int num,int init,int ui ) // 유전자를 생성하는 임시함수  (메모리함수 프로토타입)
{
	
	
	
	int counter=0;
	unsigned int pos[gene_node_length];	

	// start-> 새로 받은 주소 
	gene_body * start;
	gene_body * next;
	
	for(counter=0;counter<gene_node_length;counter ++)
	{
		pos[counter]=0;
	}
	counter=0;
	if(init == Ture)// 시작지점인가? 
	head->neck_node = ( gene_body*)malloc(sizeof(gene_body));
	else
	{
		
	}
	
	start = head->neck_node;
	

	
	while(1)
	{
		if(counter>gene_node_length-1)// 정해진 개수를 넘었는가? 
		break;
		
		
		
		if(init == Ture)
		{// 시작지점인가? 
		
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
			// 개체군 교차후 받아옴 
		}
		
		
		start->node_num = counter; // 노드 번호 
		start->curr_node = start; // 현재 노드 주소 
		next = ( gene_body* )malloc(sizeof(gene_body)); // 다음 노드 주소 (리턴됨) 
		start->next_node = next;
		start->next_node->prev_node = start; // 시작 주소의 다음 노드의 과거 데이터는 현재 시작주소 
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

	// start-> 새로 받은 주소 
	gene_body * start;
	gene_body * next;
	start = head[dest_pos]->neck_node;
	

	
	while(1)
	{
		if(counter>gene_node_length-1)// 정해진 개수를 넘었는가? 
		break;
		start->temper = *(data+counter); // 해당 데이터로 덮어씌운다. 
		start = start->next_node;
		counter++;
	}
	
	
}//이번주 

struct gene_body * gene_eraser(struct gene_header ** head ,int num, int value/* 치환될 값 */,int start_pos/* 시작 구간 */,int dest_pos/*끝 구간*/) 
{
	
	int counter=0;
	int counter_pos =0;
	unsigned int pos[gene_node_length];	

	// start-> 새로 받은 주소 
	gene_body * start;
	gene_body * next;
	
	for(counter_pos =start_pos; counter_pos < dest_pos;counter_pos++)
	{
		counter =0; 
		start = head[counter_pos]->neck_node;// 시작 유전자 
		

		
		while(1)// 유전자 길이만큼 수행 
		{
			
			if(counter>gene_node_length-1)// 정해진 개수를 넘었는가?  련재  256이다 
			break;
			start->temper = value; // 해당 데이터로 덮어씌운다. 
			start = start->next_node; // 다음 유전자 로 건너뛴다. 
			counter++;
			
		}
	}
	
	
	
}//이번주 

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
	unsigned char space[space_width][space_height]; // 메인공간  (시각 디버깅용)
	unsigned int space_stat;// 게임의 진행상태 
	
	
}omok_space;


char *all_line; // 2차원 배열을 1차원 배열으로 낯추는 역할 






#endif

#ifndef _mutate_struct// 
#define _mutate_struct// 변이를 일으킨다 

// 스왑이나 , 단위 등가 교환등의 방법을 찾는다. 

unsigned char * cycle_cross_over(unsigned char * base);
unsigned char * serial_cross_over(unsigned char * A , unsigned char * B);


unsigned char mutate_plate[gene_node_length]; //변이된 자손이 나오는 곳 

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
	0번 부터 127 번 노드중에서 0번 노드중 적합도가 높은 염색체만 색출하여 부모로 삼는다. 
	그리고 1번 노드중에서 적합도가 높은 염색체를 선발한다. 
	염색체내부의 구조는 중복이 방지되므로 이미 높여있는수의 중복 계산을 방지 할수 있다. 
	이런식으로 n번 노드를 수행하다 지거나 이기는 결과가 나오면 그 염색체를 파일로 저장하여 샠플로 제작한다. 


*/

unsigned int score(unsigned char user_input,omok_space * omok);
unsigned int tree_navigator(memory_struct  current_pos);
unsigned int referee(memory_struct  current_pos);
unsigned int fitness_selector(unsigned int mode,unsigned char user_input,omok_space * omok,tree * tree_node,unsigned int counter);
unsigned int learn_fight(gene_header** read_address);




unsigned int tree_navigator(memory_struct  current_pos)// 트리를 이용한 예측 함수 
{
	
}

unsigned int score(unsigned char user_input,omok_space * omok)// 실험자가 둔 수에 대한 예측된 수의 점수 계산 
{
	
	
	
	
	
}

unsigned int referee(memory_struct  current_pos)// 경기 심판 오목 탐지기능 
{
	
}

//작업일지 
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
	
	if( x < 2 || y < 2 || x > 13 || y > 13 )// 예외 처리 
	{
		return 0;
		// 마지막에 손을보자 
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
			
			
			if( x < 2 || y < 2 || x > 13 || y > 13 )// 예외 처리 
			{
				return 0;
				// 마지막에 손을보자 
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
		printf("%d 번째 가지의 정보 %d\n",counter2,tree_node->next[counter2]->value );
		
	}

	
	
}




#endif









#ifndef api// 가장 마지막 정의.  api이기 때문에 
#define api

unsigned int show(unsigned int start_pos ,unsigned int dest_pos, gene_header** read_address); //추후 디버깅을 위한 함수 
unsigned int ui_main(memory_struct  current_pos); // ui메인 
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
 		printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ %d \n", counter);
		for(counter2=0;counter2<gene_node_length;counter2++)
		{
			
			printf("%d 번 노드  \n", start->node_num );
		
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
	
	current_pointer = current_pos.plate_address->breed_space; // 메인 주소를 넘겨 받음 루트 
	 
	unsigned int select1 , select2 ,select3; 
	unsigned int choose;
	
	unsigned char sample[gene_node_length]; // 대입할 문자열 
	memset(sample,65,gene_node_length); // 문자열을  일정한 값으로 변형한다. 교차&교배되는 염색체가 이에 해당된다. 
	
	
	
	while(1)
	{
		printf("오목 유전 알고리즘 153337 허승재\n");
		printf("\n \t 1.염색체 수치적으로  보기 \n");
		printf("\n \t 2.염색체 좌표상에서 보기 \n");
		printf("\n \t 3.염색체 치환 \n");
		printf("\n \t 4.염색체 대입 \n");
		printf("\n \t 5.적응도 테스트 \n");
		
		scanf("%d",&choose);
		buffer_clear(stdin);
		if(choose == 1) // 유전자 보기 
		{
			while(1)
			{
				printf("두개의 수를 입력하세요 두 수가  같거나 범위가 초과되면 종료됨\n");
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
				
				show(select1,select2,current_pointer); // 염색체 단위 출력 
			}
		} 
		else if(choose == 2)//  좌표 검사 
		{
			space_view(current_pointer);
		}
		else if(choose == 3)// 
		{
			
			while(1)
			{
				
				printf("\n \t 염색체 치환 \n");
				printf("\n \t 범위를 두 곳 입력해주세요 \n");
				
				
				
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
				
				
				printf("\n \t 치환될 값을 입력해주세요 \n");
				scanf("%c",&select3);
				buffer_clear(stdin);
				
				
				
				
				gene_eraser(current_pointer,0, select3,select1,select2) ;
				
				
			}
		}
		else if(choose == 4)// 
		{
			
			while(1)
			{
				
				printf("\n \t 염색체 대입 \n");
				printf("\n \t 대입할 염색체를 입력해주세요 \n");
				
				
				
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
				
				
				printf("\n \t 대입될 값  \n");
				printf("\n \t %s  \n",sample);
				buffer_clear(stdin);
				
				
				
				
				gene_modifer(current_pointer,0,sample,select1);
				
				
			}
		}
		else if(choose == 5)//  학습시키기 
		{
			
			learn_fight(current_pointer);
			
			
			
		}
		else
		{
			printf("프로그램을 종료합니다.\n");
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
	
	
	
	// 좌표초기화 기능 
	
	while(1)
	{
		
		for(counter_x = 0 ;counter_x < space_height; counter_x++)
		{
			for(counter_y = 0 ;counter_y < space_width; counter_y++)
			{
				space.space[counter_x][counter_y] = 0;
			}
			
		}
		
		
		printf("염색체 번호를 입력하세요\n");
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


unsigned int learn_fight(gene_header** read_address) // 프로그램을 학습 시킨다. 
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
	
	printf("학습을 시작합니다.\n");
	
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
			
			
			printf("입력\n");
			fitness_selector(0,pos,&fight_place,make_tree,0);
			
			
			for(counter =0;counter<8;counter++)
			{
				fitness_selector(1,pos,&fight_place,make_tree->next[counter],counter);
			// 유전자 점수 계산 시작 
				printf("노딩\n");
			}
			
			//
			
			//노드 읽기 
			for(counter =0;counter<8;counter++)
			printf("%d위치 %d 값\n",make_tree->next[counter]->pos,make_tree->next[counter]->value );
			
			for(counter =0;counter<8;counter++)
			printf("%d위치 %d 값\n",make_tree->next[counter]->next[counter]->pos,make_tree->next[counter]->next[counter]->value );
			
			free(make_tree);
			
			x = x >> 4;// x 좌표를 원래대로 바꾼다. 
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



















