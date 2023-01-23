#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3 // max = 3 으로 고정 

typedef struct { 
	char name[100]; // 이름 -> 배열로 
	char gender; // 성별 
} element; // element 타입 ! 

typedef struct {
	element queue[MAX_QUEUE_SIZE]; // element 타입 큐 
	int front, rear;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q)
{
	q->front = q->rear = 0; // 원형큐는 0으로 초기화 , 선형은 -1 
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear); // 같으면 empty ! 
}

int is_full(QueueType* q) // 원형은 1개 차이가 날 때 full 
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // rear + 1 한거에 max 나눠 준거 ( 최대 넘어가는거 방지) == 프론트
}

void enqueue(QueueType* q, element item) 
{
	if (is_full(q)) // full 
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // rear 하나 증가 먼저  
	q->queue[q->rear] = item; // item 을 늘린 rear 자리에 넣어준다 
}

element dequeue(QueueType* q)
{
	if (is_empty(q)) // 비어있는지 확인하기 
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // front 를 늘려준다 %max 
	return q->queue[q->front]; // 늘린 front 자리에 있는 것을 return 
}


element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE]; // front + 1 %max 한거에 것을 return 
}

void print_queue(QueueType* q)
{
	if (!is_empty(q)) {
		int i = q->front; // i 를 front 값으로 
		do {
			i = (i + 1) % MAX_QUEUE_SIZE; // i + 1 하면서 대신 max 값으로 나눠진 i 값 
			printf("%s ", q->queue[i].name); // .name ( 얘는 변수임 - 포인터가 아님) 
			//if (i == q->rear)
				//break;
		} while (i != q->rear); // 여기를 rear 로 ! -> rear 까지 읽어줌 do while 이니까 ->  그 다음에 끝내기 (조건 충족) 
	}
	printf("\n");
}

// 이 부분 유의! 
int get_count(QueueType* q) 
{
	if (q->rear < q->front) // front 가 rear 보다 크다면(rear 가 한바퀴 돌음) ! 더 앞에 있을 수도 있음 -> 음수가 나올 수 있음 이를 방지해야함
		return (q->rear + MAX_QUEUE_SIZE - q->front); // rear + max 한거에서 front 를 빼줘야함 -> 음수 방지
	else
		return (q->rear - q->front); // 그게 아니면 rear에서 front를 빼준다 (rear > front) 
}

//함수로 나눠주기 ! 
void check(QueueType* q, QueueType* p, element item) // q 가 들어온 성별의 큐, p는 상대방 큐 
{
	if (is_full(q)) // 꽉 찼음 (현재 성별 큐가) -> 매칭도 안된다. 
		printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용\n");
	else { // 자신 성별 큐에 자리가 있으면 
		if (is_empty(p)) { // 상대방이 empty 이면 -> 대기 : enqueue 된다 
			printf("아직 대상자가 없습니다. 기다려주십시요.\n"); // 대기 
			enqueue(q, item); // enqueue 자신 성별 큐에  
		}
		else { // 상대방이 있으면 -> 매칭 상대가 있음
			enqueue(q, item); // 우선 enqueue 를 하고 ! 자신 성별 큐에 
			printf("커플이 탄생했습니다! %s과 %s\n", dequeue(q).name, dequeue(p).name); //  2 곳에서 dequeue !  - 현재 성별 , 상대방 성별 
		}
	}
}

void main()
{
	QueueType manQ;
	QueueType womanQ;
	element newPerson;
	char key;

	//둘다 초기화 
	init(&manQ);
	init(&womanQ);
	printf("미팅 주선 프로그램입니다.\n");
	//do while 로 우선 시작하게끔
	do {
		printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>:");
		scanf(" %c", &key); // space로 버퍼 비우기

		switch (key) {
		case 'i': // insert
			printf("이름을 입력: ");
			scanf("%s", newPerson.name);
			//while(getchar() != '\n');
			printf("성별을 입력<m or f>: ");
			scanf(" %c", &newPerson.gender); // space로 버퍼 비워주기


			//이렇게 똑같은 부분은 함수로 만드는 것이 좋다 ! -> check 함수로 + 매칭도 넣음
			if (newPerson.gender == 'm') // 남자면
				check(&manQ, &womanQ, newPerson); // manQ먼저 
			else
				check(&womanQ, &manQ, newPerson); // woman
			break;

		case 'c':
			printf("남성 대기자 %d명: ", get_count(&manQ));
			print_queue(&manQ);
			printf("여성 대기자 %d명: ", get_count(&womanQ));
			print_queue(&womanQ);
			break;
		}
		//while(getchar() != '\n');
	} while (key != 'q');
}

