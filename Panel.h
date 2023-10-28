#pragma once
#include "Include.h"

// 더블 버퍼 기능을 담당할 클래스 
class Panel
{
private:
	static HANDLE buffer[2]; // 2개의 출력 버퍼(2개를 번갈아가면서 그리고 보여줌)
	// 위의 배열에서 특정 버퍼 접근 시, 사용할 인덱스
	static int bufferIdx;

public:
	void Initialize(); // 버퍼 초기화 작업
	void Clear(); // 버퍼 지우기
	void Flip(); // 버퍼 교체
	void Release(); // 버퍼 파괴 시, 메모리 해제

	// 실질적으로 자주 사용하게 될 더블 버퍼 기능들
	// -> 더블 버퍼 사용 시, 일반적인 콘솔 출력 이용 불가함
	//    따라서, 아래 정의된 출력 관련 기능들을 이용하면 됨
public:
	// 커서의 위치를 파라미터로 넘긴 x, y 좌표로 변경
	static void Goto(int x, int y);
	// 커서를 x, y 좌표로 변경 후, str 문자열을 출력
	static void Print(const char* str, int x, int y);
	// 출력 시, 색상 설정
	// (한 번 설정 시, 다른 색을 설정하기까지 해당 색상이 유지됨)
	static void SetColor(Color color);

public:
	Panel();
	~Panel();
};

