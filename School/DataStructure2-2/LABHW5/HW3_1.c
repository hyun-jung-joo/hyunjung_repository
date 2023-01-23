#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 5 

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L)
{
	L->size = 0; // 사이즈 0 
}

int is_empty(ArrayListType* L)
{
	return L->size == 0; //0일때
}

int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE; // max 랑 같으면 !! size 비교여서 
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size) // position 위치 확인 - 0보다 작거나, size 랑 같거나 크면 
		error("위치 오류");

	return L->array[pos];
}

void print_list(ArrayListType* L) 
{
	int i;

	if (!is_empty(L)) { // no empty
		for (i = 0; i < L->size; i++) // size 전 까지 
			printf("%d->", L->array[i]); // array[i]
	}
	printf("리스트끝\n");
}

void insert_last(ArrayListType* L, element item) // 마지막에 넣기 
{
	if (L->size >= MAX_LIST_SIZE) { // size 보다 크거나 같으면 오버
		printf("리스트 오버플로우\n");
		return;
	}
	L->array[L->size++] = item; // size 자리에 item 넣고 , size 를 증가 시킨다 ! 
}

void insert_first(ArrayListType* L, element item) // 맨앞에 insert 
{
	if (is_full(L)) { // 다 차있으면 오버 
		printf("리스트 오버플로우\n");
		return;
	}

	for (int i = (L->size - 1); i >= 0; i--) // size -1 에서 시작해서 0 까지 뒤로 한칸씩 밀기 
		L->array[i + 1] = L->array[i]; // i+1 자리에 i = 뒤로 밀기
	L->array[0] = item; // 맨앞에 집어넣기
	L->size++; // size 늘리기 
}

void insert(ArrayListType* L, int pos, element item) // 포지션 자리에 넣기
{
	if(is_full(L)) { // 다 차면 오버
		printf("리스트 오버플로우\n");
		return;
	}

	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) { // !! -> full 아니고, pos 가 0보다 크거나 같거나, 사이즈보다 작거나 같거나(어차피 insert 하고 사이즈 증가시킬거라서) !!! 
		for (int i = (L->size - 1); i >= pos; i--)  // 사이즈 -1 에서 시작해서 pos 전까지 뒤로 미루기
			L->array[i + 1] = L->array[i]; 
		L->array[pos] = item; // 포지션 자리에 아이템 들어감
		L->size++; // 사이즈 증가 시켜주기 -> 하나가 더 들어왔으니
	}
}

element delete(ArrayListType* L, int pos) // 포지션 자리 삭제
{
	element item; // return 시킬 item
	if (pos < 0 || pos >= L->size) // 포지션이 0보다 작거나, 사이즈 이상이면 오류 -> 삭제라서 size 랑 같으면 안됨 
		error("위치 오류");
	item = L->array[pos]; // 포스 자리꺼 아이템에 저장

	for (int i = pos; i < (L->size - 1); i++) // 포스 부터 size - 1 전까지 !! (size 가 감소 될 것이기 때문)
		L->array[i] = L->array[i + 1]; // i + 1 꺼를 i 로 앞으로 땡기기 ! 
	L->size--; // 사이즈 감소 
	return item; // 아이템 리턴 
}

//리스트의 항목수를 반환한다
int get_length(ArrayListType* L)
{
	return L->size;
}

//pos 번째 항목을 item 으로 바꾼다
void replace(ArrayListType* L, int pos, element item)
{
	if (pos >= 0 && pos < L->size) // pos 로 사이즈 위치 확인 
		L->array[pos] = item;
	else
		printf("위치 오류\n");
}

//– item 이 리스트에 있으면 1 을 아니면 0 을 반환 
int is_in_list(ArrayListType* L, element item)
{
	for (int i = 0; i < L->size; i++)
		if (L->array[i] == item)
			return 1;
	return 0;
}

//리스트에서 key 값을 검색하여 그를 삭제한다.
//여러 개의 key 값이 있을때는 첫번째 key 값을 삭제하는 것으로 한다.key 값이 없는 경우 “없다”고 출력한다.
void delete_by_key(ArrayListType* L, element key)
{
	for (int i = 0; i < L->size; i++)
		if (L->array[i] == key) {
			delete(L, i); // delete 함수를 불러서 i(포스) 로 넘겨준다 ! 
			return;
		}
	printf("삭제하려는 key값 %d은 리스트에 없습니다\n", key);
}

//리스트 비우는 함수
void clear(ArrayListType* L)
{
	L->size = 0;
}

int main(void)
{
	ArrayListType list1;

	init(&list1);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);
	clear(&list1); print_list(&list1);

	insert_last(&list1, 90); print_list(&list1);

	insert(&list1, 0, 30);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);

	delete(&list1, 2); print_list(&list1);

	printf("\n-이 이후는 HW1_1에서 추가한 함수들 테스트-\n");
	insert_first(&list1, 9); print_list(&list1);
	insert_last(&list1, 99); print_list(&list1);

	// 현재 리스트가 꽉 찬(크기 5개) 상태이므로 한 항목을 더 추가하면 "리스트 오버플로우"을 출력한다. 
	insert_first(&list1, 1); print_list(&list1);

	printf("길이는 %d\n", get_length(&list1));
	printf("3번째 데이타는 %d\n", get_entry(&list1, 2));

	replace(&list1, 3, 40); print_list(&list1);
	printf("20은 리스트에 %s\n", is_in_list(&list1, 20) ? "있습니다" : "없습니다");
	printf("22는 리스트에 %s\n", is_in_list(&list1, 22) ? "있습니다" : "없습니다");

	delete_by_key(&list1, 20); print_list(&list1);
	delete_by_key(&list1, 22); print_list(&list1);
	
	return 0;
}