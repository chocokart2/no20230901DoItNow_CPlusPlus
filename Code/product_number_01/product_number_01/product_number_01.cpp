// product_number_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

// 빛이 있으라.

// 해당 프로그램이 가지고 있는 정보를 담습니다. 메모리 누수가 싫어서 만들었습니다.
// 만약 해당 데이터 조각의 일부를 사용하고 싶으면 이 구조체의 일부를 사용할 수도 있습니다.

// 프로그램에 저장될 모든 정보를 총괄합니다.
typedef struct ProgramData ProgramData;
// 해야 하는 일에 대해 저장합니다.
typedef struct TaskPlan TaskPlan;
// 해당 업무를 완수했는지 여부를 저장합니다.
typedef struct TaskResult TaskResult;

struct TaskPlan
{
public:
	int index;
	int repeatFlag;
	string name;
};

struct TaskResult
{
public:
	bool isTaskFinished;
	int taskPlanIndex;
};

struct ProgramData
{
public:
	int randomNumber = 0;
	int taskCount = 0;
	int plansPtrCount;
	string masterName;
	TaskPlan plansPtr[50];
};

void Greet(ProgramData& progamData);
void InitateProgramData(ProgramData& target);
void Say(string message);
//void ShowTask();
int AskMain();


void Greet(ProgramData& progamData)
{
	time_t timer = time(NULL);
	struct tm formattedTime;
	localtime_s(&formattedTime, &timer);

	std::cout << ">> 반갑습니다, " << progamData.masterName << "." << endl;
	cout << ">> 오늘 할 일은 " << progamData.taskCount << "개 남았습니다." << endl;
	cout << ">> 지금 시간은 " << (formattedTime.tm_hour > 12 ? "오후 " : "오전 ")
		<< (formattedTime.tm_hour > 12 ? formattedTime.tm_hour - 12 : formattedTime.tm_hour)
		<< "시 " << formattedTime.tm_min << "분 입니다." << endl;
}

void InitateProgramData(ProgramData& target)
{
	target.masterName = "Chocokart2";
	target.taskCount = 0;
}

void Say(string message)
{
	cout << ">> " << message << endl;
}

int AskMain()
{
	cout << "<<";
	string recvLine;
	cin >> recvLine;
	return 1;
}



int main()
{
	ProgramData data;
	ProgramData& program = data;
	InitateProgramData(program);

	Greet(program);
	system("pause");
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
