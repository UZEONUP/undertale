#pragma once
#include "gameNode.h"

struct rc_control
{
	RECT rc;
	int x, y;
	int width_max, height_max;
};
struct battle_bar
{
	Image* img;
	RECT rc;
	int x, y;
};
enum TURN_STATE
{
	MENU_SELECT,
	TALK_BUBBLE,
	INGAME,
	TALK_MAIN
};
class battleUI : public gameNode
{
private:
	//메인 렉트
	rc_control _main_rc;
	RECT _fill;

	Image* _menu_off[4];
	Image* _menu_on[4];
	Image* _heart;
	Image* _speechBubble;
	Image* _attack_ground;
	battle_bar _attack_bar;

	int daCount;
	int daCount2;

	//턴 여부(0 == 메뉴 선택, 1 == 말풍선 대화중, 2 == 미니게임중, 3 == 메인 대화중)
	TURN_STATE isTurn;
	//메뉴 선택(공격, 행동, 아이템, 자비)
	int _menu_main_count;
	//메뉴 선택 후 인메뉴
	int _menu_input1_count;

	//_menu_main_count(공격) 일때
	//공격시작과 공격 끝 여부
	bool _isAttack_start;
	bool _isAttack_finish;
	//공격바 카운트
	int _attack_bar_count;

	//적공격 중
	int enemy_attack_count;

	//_menu_main_count(자비) 일때
	bool _isMercy;

	const wchar_t* menu_select;
	const wchar_t* menu_action;

	//==========다이얼로그==============
	//원본 대사 변수
	char* _str_main;
	char* _str_bubble;

	//타이핑 효과를 위해 원본 대사에서 잘라온 변수
	char _word_cut[1024];
	char _word_cut2[1024];

	//ini데이터 Title 순번을 넘기기 위한 변수
	char _title_char[64];
	int _title_int;
	char _title_char2[64];
	int _title_int2;

	//글자 갯수
	int _word_count;
	int _word_count2;

	//글자 속도
	int _word_speed;


public:
	battleUI();
	~battleUI();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void main_rect_control_default(bool expandOrReduce);
	void main_rect_control_customizing(bool expandOrReduce, int speed, int maxSizeWidth, int maxSizeHeight);

	char* ConvertWCtoC(wchar_t* str);
	wchar_t* ConverCtoWC(char* str);

	void talk_bubble_start(const char* subject, int startNum);
	void talk_bubble_end(int endNum);
	void talk_main_start(const char* subject, int startNum);
	bool talk_main_end(int endNum);
};

