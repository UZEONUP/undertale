#include "stdafx.h"
#include "battleUI.h"

battleUI::battleUI()
{
}

battleUI::~battleUI()
{
}

HRESULT battleUI::init()
{
	_menu_off[0] = ImageManager::GetInstance()->AddImage("공격_off", L"UI이미지/UI_공격_비활성화_110_42.png");
	_menu_off[1] = ImageManager::GetInstance()->AddImage("행동_off", L"UI이미지/UI_행동_비활성화_110_42.png");
	_menu_off[2] = ImageManager::GetInstance()->AddImage("아이템_off", L"UI이미지/UI_아이템_비활성화_110_42.png");
	_menu_off[3] = ImageManager::GetInstance()->AddImage("자비_off", L"UI이미지/UI_자비_비활성화_110_42.png");
	_menu_on[0] = ImageManager::GetInstance()->AddImage("공격_on", L"UI이미지/UI_공격_활성화_110_42.png");
	_menu_on[1] = ImageManager::GetInstance()->AddImage("행동_on", L"UI이미지/UI_행동_활성화_110_42.png");
	_menu_on[2] = ImageManager::GetInstance()->AddImage("아이템_on", L"UI이미지/UI_아이템_활성화_110_42.png");
	_menu_on[3] = ImageManager::GetInstance()->AddImage("자비_on", L"UI이미지/UI_자비_활성화_110_42.png");
	_heart = ImageManager::GetInstance()->AddImage("하트", L"UI이미지/UI_하트_20_20.png");
	_speechBubble = ImageManager::GetInstance()->AddImage("말풍선오른쪽", L"UI이미지/UI_말풍선_오른쪽_237_104.png");
	_attack_ground = ImageManager::GetInstance()->AddImage("전투판", L"UI이미지/UI_공격타이밍판_540_132.png");

	ImageManager::GetInstance()->AddImage("전투바_화이트", L"UI이미지/UI_공격타이밍바_10_151.png");
	ImageManager::GetInstance()->AddImage("전투바_블랙", L"UI이미지/UI_공격타이밍바_black_10_151.png");
	_attack_bar.img = ImageManager::GetInstance()->FindImage("전투바_화이트");
	_main_rc.x = WINSIZEX / 2;
	_main_rc.y = WINSIZEY / 2 + 50;
	_main_rc.width_max = 150;
	_main_rc.height_max = 150;
	_main_rc.rc = RectMakeCenter(_main_rc.x, _main_rc.y, _main_rc.width_max, _main_rc.height_max);

	_attack_bar.x = 30;
	_attack_bar.y = WINSIZEY / 2 - 25;
	_attack_bar_count = 0;

	daCount = 1;
	daCount2 = 1;
	_isMercy = false;

	isTurn = TALK_BUBBLE;
	_menu_main_count = 1;
	_menu_input1_count = 0;
	_isAttack_start = false;
	_isAttack_finish = false;
	enemy_attack_count = 0;
	//==========다이얼로그==============

	_title_int = 1;
	_title_int2 = 1;
	_word_count = 0;
	_word_count2 = 0;
	_word_speed = 0;
	talk_main_start("샌즈_메인", 1);
	talk_bubble_start("샌즈_말풍선", 1);
	//폰트추가
	D2DRENDER->AddTextFormat(L"-윤디자인웹돋움");
	return S_OK;
}

void battleUI::release()
{
}

void battleUI::update()
{

	if (isTurn == MENU_SELECT)
	{
		//메뉴 선택 키 왼쪽
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _menu_input1_count == 0)
		{
			_menu_main_count--;
			if (_menu_main_count < 1) _menu_main_count = 1;
		}
		//메뉴 선택 키 오른쪽
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _menu_input1_count == 0)
		{
			_menu_main_count++;
			if (_menu_main_count > 4) _menu_main_count = 4;
		}
	}

	//Z버튼 == 엔터
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		if (isTurn == MENU_SELECT)
		{
			//공격시작 후 공격바 멈추고 싶을떄
			if (_isAttack_start && !_isAttack_finish)
			{
				_isAttack_finish = true;
			}
			//공격창에서 Z버튼 누를 시 공격 시작
			if (_menu_input1_count == 1 && !_isAttack_start)
			{
				_attack_bar.x = 30;
				_isAttack_start = true;
			}
			if (_menu_input1_count == 2)
			{

			}
			if (_menu_input1_count == 4 && !_isMercy)
			{
				_isMercy = true;
				_word_count2 = 0;
			}
		}
		if (isTurn == MENU_SELECT)
		{
			//버튼 누른 메뉴로 이동
			_menu_input1_count = _menu_main_count;
		}
		if (isTurn == TALK_MAIN)
		{
			if (talk_main_end(daCount))
			{
				_menu_main_count = 1;
				_menu_input1_count = 0;
				isTurn = MENU_SELECT;
				daCount++;
			}
			//i가 대사의 길이와 같으면 다음 대사로 넘어감
			if (_word_count == strlen(_word_cut) && _word_count >= 3)
			{
				_word_count = 0;
				_title_int++;
				//이니데이터 title값을 변경해주기위해 int to string 변환
				_title_char[1024] = _itoa_s(_title_int, _title_char, sizeof(_title_char), 10);
				_str_main = INIDATA->loadDataString("28기", "샌즈_메인", _title_char);
			}
		}
		//말풍선 턴
		if (isTurn == TALK_BUBBLE)
		{
			//말풍선에서 인게임으로 넘어가는 타이밍
			talk_bubble_end(4);
			talk_bubble_end(6);
			talk_bubble_end(10);
			talk_bubble_end(12);
			talk_bubble_end(15);
			talk_bubble_end(19);
			talk_bubble_end(22);
			talk_bubble_end(26);
			talk_bubble_end(27);
			talk_bubble_end(32);
			talk_bubble_end(37);
			talk_bubble_end(38);
			talk_bubble_end(40);
			talk_bubble_end(42);
			talk_bubble_end(48);
			talk_bubble_end(50);
			talk_bubble_end(56);
			talk_bubble_end(60);
			talk_bubble_end(63);
			talk_bubble_end(65);
			talk_bubble_end(66);
			talk_bubble_end(68);
			talk_bubble_end(71);
			talk_bubble_end(104);
			//i가 대사의 길이와 같으면 다음 대사로 넘어감
			if (_word_count2 == strlen(_word_cut2) && _word_count2 >= 3 && !_isMercy)
			{
				_title_int2++;
				_word_count2 = 0;
				_title_char2[1024] = _itoa_s(_title_int2, _title_char2, sizeof(_title_char2), 10);
				_str_bubble = INIDATA->loadDataString2("28기", "샌즈_말풍선", _title_char2);
				//이니데이터 title값을 변경해주기위해 int to string 변환
			}
			//자비(살려주기)일때도 대사의 길이가 같으면 다음대사로
			if (_isMercy && _word_count2 == strlen(_word_cut2) && _word_count2 >= 3)
			{
				isTurn = INGAME;
				_isMercy = false;
				_menu_input1_count = 0;
			}
		}
	}
	//X버튼 == 취소
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		if (isTurn == MENU_SELECT)
		{
			//메뉴 선택 취소
			if (_menu_input1_count != 0 && !_isAttack_start)
			{
				_menu_main_count = _menu_input1_count;
				_menu_input1_count = 0;
			}
		}
		if (isTurn == TALK_MAIN)
		{
			//i가 대사의 길이와 같이 않으면 대사를 모두 표시
			if (_word_count != strlen(_str_main))	_word_count = strlen(_str_main);
		}
	}
	//자비(살려주기)
	if (_isMercy)
	{
		isTurn = TALK_BUBBLE;
		talk_bubble_start("샌즈_말풍선", 7);
	}

	//메뉴 카운터2에 따른 텍스트 출력
	if (_menu_input1_count == 1) menu_select = L" * 보스이름";
	if (_menu_input1_count == 2) menu_select = L" * 보스이름";
	if (_menu_input1_count == 3) menu_select = L" * 아이템 목록";
	if (_menu_input1_count == 4 && !_isMercy) menu_select = L" * 살려주기";
	//공격 실행 시 공격바 움직임
	if (_isAttack_start && !_isAttack_finish)
	{
		_attack_bar.x += 5;
		_attack_bar_count = 0;
		if (_attack_bar.x >= 620) _isAttack_finish = true;
	}
	//공격 완료 후
	if (_isAttack_start && _isAttack_finish)
	{
		_attack_bar_count++;
	}
	//공격 완료 후 깜박일때
	if (_attack_bar_count >= 100)
	{
		_isAttack_start = false;
		_isAttack_finish = false;
		isTurn = TALK_BUBBLE;
		_word_count2 = 0;
		_menu_input1_count = 0;
		_attack_bar_count = 0;
	}
	//인게임인 경우
	if (isTurn == INGAME)
	{
		enemy_attack_count++;
	}
	if (enemy_attack_count >= 200)
	{
		enemy_attack_count = 0;
		isTurn = TALK_MAIN;
		_word_count = 0;
	}
	//말풍선 대화중, 미니게임중이면 메인 전투창 크기를 줄임
	if (isTurn == TALK_BUBBLE || isTurn == INGAME)main_rect_control_default(false);
	//말풍선 대화중, 미니게임 중이 아니면 메인 전투창 크기를 늘임
	if (isTurn == MENU_SELECT || isTurn == TALK_MAIN)main_rect_control_default(true);

	//==========다이얼로그==============
	_word_speed++;

	//속도에 따라 타이핑 효과 생성
	if (_word_speed % 4 == 0)
	{
		strncpy_s(_word_cut, sizeof(_word_cut), _str_main, _word_count * 2);
		_word_count++;
		if (_word_count >= strlen(_str_main)) _word_count = strlen(_str_main);

		strncpy_s(_word_cut2, sizeof(_word_cut2), _str_bubble, _word_count2 * 2);
		_word_count2++;
		if (_word_count2 >= strlen(_str_bubble)) _word_count2 = strlen(_str_bubble);

		_word_speed = 0;
	}

}

void battleUI::render()
{
	//선택창 텍스트
	if (_menu_input1_count != 0 && !_isMercy)
	{
		D2DRENDER->RenderText(120, 250, menu_select, 20, D2DRenderer::DefaultBrush::White);
	}
	//공격 시 이미지
	if (_isAttack_start)
	{
		_attack_ground->Render(0, 0, 1, 1, 0, 0, 0, 20, WINSIZEY / 2 - 20);
		_attack_bar.img->Render(0, 0, 1, 1, 0, 0, 0, _attack_bar.x, _attack_bar.y);
		if (_attack_bar_count % 10 < 5) _attack_bar.img = ImageManager::GetInstance()->FindImage("전투바_화이트");
		else _attack_bar.img = ImageManager::GetInstance()->FindImage("전투바_블랙");
	}
	//메인 전투창 렉트
	D2DRENDER->DrawRectangle
	(
		_main_rc.rc,
		D2DRenderer::DefaultBrush::White,
		5.F
	);
	//메뉴 off 이미지
	_menu_off[0]->Render(0, 0, 1, 1, 0, 0, 0, 20, WINSIZEY - 50);
	_menu_off[1]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 150, WINSIZEY - 50);
	_menu_off[2]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 300, WINSIZEY - 50);
	_menu_off[3]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 450, WINSIZEY - 50);
	//말풍선
	if (isTurn == TALK_BUBBLE)	_speechBubble->Render(0, 0, 1, 1, 0, 0, 0, 340, 80);


	//메뉴 선택에 따른 이미지
	if (isTurn == MENU_SELECT)
	{
		if (_menu_main_count == 1 && !_isAttack_start)
		{
			_menu_on[0]->Render(0, 0, 1, 1, 0, 0, 0, 20, WINSIZEY - 50);
			if (_menu_input1_count == 1) _heart->Render(0, 0, 1, 1, 0, 0, 0, 100, WINSIZEY - 225);
			else _heart->Render(0, 0, 1, 1, 0, 0, 0, 30, WINSIZEY - 40);

		}
		if (_menu_main_count == 2 && !_isAttack_start)
		{
			_menu_on[1]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 150, WINSIZEY - 50);
			if (_menu_input1_count == 2) _heart->Render(0, 0, 1, 1, 0, 0, 0, 100, WINSIZEY - 225);
			else _heart->Render(0, 0, 1, 1, 0, 0, 0, 30 + 150, WINSIZEY - 40);
		}
		if (_menu_main_count == 3 && !_isAttack_start)
		{
			_menu_on[2]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 300, WINSIZEY - 50);
			if (_menu_input1_count == 3) _heart->Render(0, 0, 1, 1, 0, 0, 0, 100, WINSIZEY - 225);
			else _heart->Render(0, 0, 1, 1, 0, 0, 0, 30 + 300, WINSIZEY - 40);
		}
		if (_menu_main_count == 4 && !_isAttack_start)
		{
			_menu_on[3]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 450, WINSIZEY - 50);
			if (_menu_input1_count == 4) _heart->Render(0, 0, 1, 1, 0, 0, 0, 100, WINSIZEY - 225);
			else _heart->Render(0, 0, 1, 1, 0, 0, 0, 30 + 450, WINSIZEY - 40);
		}
	}

	//==========다이얼로그==============
	//메인
	if (isTurn == TALK_MAIN)
	{
		/*	D2DRENDER->RenderText(100, 300, ConverCtoWC(_word_cut), 20);*/
		D2DRENDER->RenderTextField(50, 150, ConverCtoWC(_word_cut), D2D1::ColorF::White, 20, 500, 200, 1,
			DWRITE_TEXT_ALIGNMENT_LEADING, L"-윤디자인웹돋움");
	}
	//말풍선
	if (isTurn == TALK_BUBBLE)
	{
		/*	D2DRENDER->RenderText(450, 100, ConverCtoWC(_word_cut2), (0, 0, 0), 1, 20, DWRITE_TEXT_ALIGNMENT_LEADING, L"-윤디자인웹돋움");*/


		D2DRENDER->RenderTextField(380, 80, ConverCtoWC(_word_cut2), D2D1::ColorF::Black, 20, 180, 100, 1,
			DWRITE_TEXT_ALIGNMENT_LEADING, L"-윤디자인웹돋움");


	}
}
//메인 전투 렉트 컨트롤함수 기본값		 (늘리고 싶으면 true, 줄이고 싶으면 false)
void battleUI::main_rect_control_default(bool expandOrReduce)
{
	if (expandOrReduce)
	{
		_main_rc.width_max += 10;
		_main_rc.height_max += 10;
		if (_main_rc.width_max >= 520) _main_rc.width_max = 520;
		if (_main_rc.height_max >= 160) _main_rc.height_max = 160;
	}
	else
	{
		_main_rc.width_max -= 10;
		_main_rc.height_max -= 10;
		if (_main_rc.width_max <= 150) _main_rc.width_max = 150;
		if (_main_rc.height_max <= 150) _main_rc.height_max = 150;
	}
	_main_rc.rc = RectMakeCenter(_main_rc.x, _main_rc.y, _main_rc.width_max, _main_rc.height_max);
}
//메인 전투 렉트 컨트롤함수 커스터마이징			 (늘릴지 줄일지 여부,	 크기변환 속도,	최소 혹은 최대 넓이,	최소 혹은 최대 높이)
void battleUI::main_rect_control_customizing(bool expandOrReduce, int speed, int maxSizeWidth, int maxSizeHeight)
{
	if (expandOrReduce)
	{
		_main_rc.width_max += speed;
		_main_rc.height_max += speed;
		if (_main_rc.width_max >= maxSizeWidth) _main_rc.width_max = maxSizeWidth;
		if (_main_rc.height_max >= maxSizeHeight) _main_rc.height_max = maxSizeHeight;
	}
	else
	{
		_main_rc.width_max -= speed;
		_main_rc.height_max -= speed;
		if (_main_rc.width_max <= maxSizeWidth) _main_rc.width_max = maxSizeWidth;
		if (_main_rc.height_max <= maxSizeHeight) _main_rc.height_max = maxSizeHeight;
	}
	_main_rc.rc = RectMakeCenter(_main_rc.x, _main_rc.y, _main_rc.width_max, _main_rc.height_max);
}

//wchar_t 에서 char 로의 형변환 함수
char * battleUI::ConvertWCtoC(wchar_t * str)
{
	//반환할 char* 변수 선언
	char* pStr;

	//입력받은 wchar_t 변수의 길이를 구함
	int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	//char* 메모리 할당
	pStr = new char[strSize];

	//형 변환 
	WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);
	return pStr;
}
//char 에서 wchar_t 로의 형변환 함수
wchar_t * battleUI::ConverCtoWC(char * str)
{
	//wchar_t형 변수 선언
	wchar_t* pStr;
	//멀티 바이트 크기 계산 길이 반환
	int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);
	//wchar_t 메모리 할당
	pStr = new WCHAR[strSize];
	//형 변환
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, pStr, strSize);
	return pStr;
}

void battleUI::talk_bubble_start(const char * subject, int startNum)
{
	_title_int2 = startNum;
	char title_name[64];
	title_name[32] = _itoa_s(startNum, title_name, sizeof(title_name), 10);
	_str_bubble = INIDATA->loadDataString2("28기", subject, title_name);
}

void battleUI::talk_bubble_end(int endNum)
{
	if (endNum == _title_int2 && _word_count2 == strlen(_word_cut2) && _word_count2 >= 3)
	{
		isTurn = INGAME;

	}
}

void battleUI::talk_main_start(const char * subject, int startNum)
{
	char title_name[64];
	title_name[32] = _itoa_s(startNum, title_name, sizeof(title_name), 10);
	_str_main = INIDATA->loadDataString("28기", subject, title_name);
}

bool battleUI::talk_main_end(int endNum)
{
	if (endNum == _title_int && _word_count == strlen(_word_cut) && _word_count >= 3)
	{
		return true;
	}
	else return false;
}



