#define _CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100
#define MAX_CUST 200 // max customer
#define MAX_CHAR 100 // 문자열의 max 문자
#include <stdio.h>
#include <string.h>

typedef struct { // 재고 대장: 현재 보유하고 있는 Video 정보 저장
	char title[MAX_CHAR];
	int qty; // 수량
} VideoInfo;

typedef struct { // 대출 대장: 대출해간 (고객 id와 video id)들이 저장
	int custId; // 고객 id : 1, 2, 3
	char title[MAX_CHAR]; // Video 제목
} RentInfo;

void printAllVideo(VideoInfo videoList[], int videoCount) {
	int i;

	printf("Video제목\t수량\n");
	printf("-----------------------\n");
	for (i = 0; i < videoCount; i++)
		printf("%s\t%d\n", videoList[i].title, videoList[i].qty);
}

void purchaseVideo(VideoInfo videoList[], int* videoCountPtr, char title[], int qty)
{
	strcpy(videoList[*videoCountPtr].title, title);
	videoList[*videoCountPtr].qty = qty;
	(*videoCountPtr)++;
}

int searchVideoByTitle(VideoInfo videoList[], int videoCount, char title[])
{
	int i;

	for (i = 0; i < videoCount; i++)
		if (strcmp(title, videoList[i].title) == 0)
			return i;
	return -1;
}

void rentVideo(VideoInfo videoList[], int videoCount, RentInfo rentList[], int* rentCount, char title[], int custId)
{
	RentInfo rent;
	int index = searchVideoByTitle(videoList, videoCount, title);

	rent.custId = custId;
	strcpy(rent.title, videoList[index].title);
	rentList[*rentCount] = rent;

	(*rentCount)++;
	videoList[index].qty--;
}


void printAllRent(RentInfo rentList[], int rentCount) 
{
	int i;
	printf("고객id\tVideo제목\n");
	printf("-----------------------\n");
	for (i = 0; i < rentCount; i++)
		printf("%d\t%s\n", rentList[i].custId, rentList[i].title);
}

void readVideo(VideoInfo videoList[], int* videoCountPtr)
{
	FILE* fp;
	VideoInfo video;

	if ((fp = fopen("video.txt", "r")) == NULL) {
		printf("입력 파일 오픈 실패\n"); exit(1);
	}

	while (fscanf(fp, "%s %d", video.title, &video.qty) != EOF) {
		videoList[*videoCountPtr] = video;
		(*videoCountPtr)++;
	}
	fclose(fp);
}

void writeVideo(VideoInfo videoList[], int videoCount)
{
	FILE* fp;
	int i;

	if ((fp = fopen("video.txt", "w")) == NULL) {
		printf("출력 파일 오픈 실패\n"); exit(1);
	}

	for (i = 0; i < videoCount; i++)
		fprintf(fp, "%s %d\n", videoList[i].title, videoList[i].qty);
	
	fclose(fp);
}

void writeRent(RentInfo rentList[], int rentCount)
{
	FILE* fp;
	int i;

	fp = fopen("rent.txt", "w");
	if (fp == NULL) {
		printf("출력 파일 오픈 실패\n"); exit(1);
	}

	for (i = 0; i < rentCount; i++)
		fprintf(fp, "%d %s\n", rentList[i].custId, rentList[i].title);
	fclose(fp);
}

int main(void)
{
	int videoCount = 0; // videoCount도 0으로 초기화
	VideoInfo videoList[MAX_VIDEO];
	int rentCount = 0; // 현재 대출 건수는 0임
	RentInfo rentList[MAX_CUST];

	char title[MAX_CHAR];
	int qty, custId;
	int choice;
	int indexSearched;

	readVideo(videoList, &videoCount);

	printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
	scanf("%d", &choice);
	while (choice != 6) {
		switch (choice) {
		case 1: printAllVideo(videoList, videoCount); break;

		case 2:
			printf("Enter video 제목: ");
			scanf("%s", title);
			printf("Enter video 수량: ");
			scanf("%d", &qty);
			purchaseVideo(videoList, &videoCount, title, qty); break;

		case 3:
			printf("Enter video 제목: ");
			scanf("%s", title);

			if ((indexSearched = searchVideoByTitle(videoList, videoCount, title)) == -1)
				printf("그런 비디오는 없습니다.\n");
			else if (videoList[indexSearched].qty == 0)
				printf("다 대여중입니다.\n");
			else
				printf("대여 가능합니다.\n"); break;

		case 4:
			printf("Enter video 제목: ");
			scanf("%s", title);
			printf("Enter 고객 id: ");
			scanf("%d", &custId);
			rentVideo(videoList, videoCount, rentList, &rentCount, title, custId); break;

		case 5:
			printAllRent(rentList, rentCount); break;
		}

		printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
		scanf("%d", &choice);
	}

	writeVideo(videoList, videoCount);
	writeRent(rentList, rentCount);
}