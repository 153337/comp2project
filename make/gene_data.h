#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#ifndef const_size // 상수 데이터 
#define const_size

#define gene_node_length 256 // 한 유전자의 길이  (16*16)/2 이부분을 조작하면 전체 유전자의 크기를 제어할수 있다. 
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



#endif


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
	struct gene_header* breed_space[100]; // 머리(유전자)의 위치값 들의 배열 
	char plate_neme[256]; // 테이블 이름 
	
}plate; // 실험 테이블 


#endif


#ifndef memory_struct_and_func
#define memory_struct_and_func

struct gene_body * gene_maker(struct gene_header * head ,int num,int init ,int ui); // 셋업 과정 
struct gene_body * gene_modifer(struct gene_header * head ,int num); // 염색체 단위수정 
struct gene_body * gene_eraser(struct gene_header * head ,int num, int value) ; // 일정값으로 초기화 

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
		usleep(50000);
	}
	
}
 

struct gene_body * gene_modifer(struct gene_header * head ,int num)
{
	
	head->neck_node;
	
}

struct gene_body * gene_eraser(struct gene_header * head ,int num, int value) 
{
	
}

unsigned int return_memory_allocation(unsigned int option, void * pointer_target)
{
	
	free(pointer_target);
	return 0;
	
}






#endif



#ifndef omok_space_struct
#define omok_space_struct

unsigned int referee();


typedef struct omok_space
{
	unsigned char space[space_width][space_height]; // 메인공간  (시각 디버깅용)
	unsigned int space_stat;// 게임의 진행상태 
	
	
}omok_space;


char *all_line; // 2차원 배열을 1차원 배열으로 낯추는 역할 

unsigned int referee()
{
	
}





#endif




#ifndef api
#define api

unsigned int show(unsigned int start_pos ,unsigned int dest_pos, gene_header** read_address); //추후 디버깅을 위한 함수 
unsigned int ui_main(memory_struct  current_pos); // ui메인 
unsigned int space_view(gene_header** read_address);





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
	 
	unsigned int select1 , select2; 
	unsigned int choose;
	
	while(1)
	{
		printf("오목 유전 알고리즘 153337 허승재\n");
		printf("\n \t 1.염색체 수치적으로  보기 \n");
		printf("\n \t 2.염색체 좌표상에서 보기 \n");
		printf("\n \t 3.환경 설정 \n");
		
		scanf("%d",&choose);
		fflush(stdin);
		if(choose == 1) // 유전자 보기 
		{
			while(1)
			{
				printf("두개의 수를 입력하세요 두 수가  같거나 범위가 초가되면 종료됨\n");
				scanf("%d",&select1);
				fflush(stdin);
				scanf("%d",&select2);
				fflush(stdin);
				
				if(select1 == select2)
				{
					break;
				}
				if(select1 >= 100 || select2 >= 100 || select1 <= 0 || select2 <= 0)
				{
					break;
				}
				
				show(select1,select2,current_pointer); // 염색체 단위 출력 
			}
		} 
		else if(choose == 2)// 실험 시작 
		{
			space_view(current_pointer);
		}
		else if(choose == 3)// 좌표 대응 검사 
		{
			
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
	gene_body* start;
	unsigned int counter_gene_head;
	unsigned int counter2;
	unsigned char x,y;
	
	
	for(counter_x = 0 ;counter_x < space_height; counter_x++)
	{
		for(counter_y = 0 ;counter_y < space_width; counter_y++)
		{
			space.space[counter_x][counter_y] = 0;
		}
		
	}
	// 좌표초기화 기능 
	
	while(1)
	{
		printf("염색체 번호를 입력하세요\n");
		scanf("%d",&counter_gene_head);
		
		
		if(counter_gene_head >= 100)
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
			printf("\n");-
			system("pause");
			system("cls");
			
			
			
			start = start->next_node;
		}
			
			
			
		
		

	}
	
	
	
	
	
	
	
}


#endif


