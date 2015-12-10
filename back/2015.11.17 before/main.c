#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gene_data.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// 시작 주소값을 주면 노드를 연결하고 노드의 다음 주소를 리턴한다. 
// 구조체 결과를 출력한다. 

////////////////////////////  실행부분 
int main() 
{
	
	unsigned int counter_main; // 셋업용 카운터 
	
	// 구조체 선언 
	memory_struct org; 
	plate table;
	gene_header temp;
	empty_pointer current_pointer;
	int seed;// 시드 
	
	time_t time_set; // 시간변수 

	srand( (unsigned)time(NULL) );  // 형변환 
	

	
	
	org.org_address = (memory_struct*)malloc(sizeof(memory_struct));
	org.plate_address = (plate*)malloc(sizeof(plate));
	
	
	// 공간 할당 (테이블 초기화)
	for(counter_main=0;counter_main<100;counter_main++)
	{
		
		org.plate_address->breed_space[counter_main] = (gene_header*)malloc(sizeof(gene_header)); // 공간 할당 
		
	
	}
	
	// 공간 할당 (염색체 생성)
	for(counter_main=0;counter_main<100;counter_main++)
	{
	
		gene_maker(org.plate_address->breed_space[counter_main] ,counter_main,1 ,counter_main); // 해당염색체만 선택 교체 가능  처음 에는 공간할당 
		
	}
	
	ui_main(org);
	
	
	
	// 셋업과정 
	
	// 프로그램 시작 
/////////////////////////////////////////////////////////////////////////////////////////////////	
	
}





