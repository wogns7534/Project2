#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
	const char* filename = "./text1";

	if (stat(filename, &stat1)) {
		printf("This file does not exist.\n");
	}
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
	const char* filename = "./text2";

	if (stat(filename, &stat2)) {
		printf("This file does not exist.\n");
	}
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
	static struct tm time_1;
	time_1 = *(localtime(&stat1.st_mtime));
	time1 = &time_1;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
	static struct tm time_2;
	time_2 = *(localtime(&stat2.st_mtime));
	time2 = &time_2;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
	printf("3. size compare\n");
	if (stat1.st_size > stat2.st_size)
		printf("text1 is bigger\n");
	else if (stat1.st_size < stat2.st_size)
		printf("text2 is bigger\n");
	else
		printf("sizes are equal\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
	printf("4. Block number comparison\n");
	if (stat1.st_blocks > stat2.st_blocks)
		printf("text1 is bigger\n");
	else if (stat1.st_blocks < stat2.st_blocks)
		printf("text2 is bigger\n");
	else
		printf("numbers are equal\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){

	printf("5. date compare\n");
	if (time1->tm_mon < time2->tm_mon)
		printf("text1 is early\n");
	else if (time1->tm_mon > time2->tm_mon)
		printf("text2 is early\n");
	else {									//같은 달에 수정을 한 경우, 날을 비교
		if (time1->tm_mday < time2->tm_mday)
			printf("text1 is early\n");
		else if (time1->tm_mday > time2->tm_mday)
			printf("text2 is early\n");
		else
			printf("same date\n");

	}
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
	printf("6. time compare\n");

	if (time1->tm_hour < time2->tm_hour)
		printf("text1 is early\n");
	else if (time1->tm_hour > time2->tm_hour)
		printf("text2 is early\n");
	else {	// 만일 '시간'이 같을 경우 '분' 비교
		if (time1->tm_min < time2->tm_min)
			printf("text1 is early\n");
		else if (time1->tm_min > time2->tm_min)
			printf("text2 is early\n");
		else
			printf("same time\n");
	}
}
