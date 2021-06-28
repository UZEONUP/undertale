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
	_menu_off[0] = ImageManager::GetInstance()->AddImage("����_off", L"UI�̹���/UI_����_��Ȱ��ȭ_110_42.png");
	_menu_off[1] = ImageManager::GetInstance()->AddImage("�ൿ_off", L"UI�̹���/UI_�ൿ_��Ȱ��ȭ_110_42.png");
	_menu_off[2] = ImageManager::GetInstance()->AddImage("������_off", L"UI�̹���/UI_������_��Ȱ��ȭ_110_42.png");
	_menu_off[3] = ImageManager::GetInstance()->AddImage("�ں�_off", L"UI�̹���/UI_�ں�_��Ȱ��ȭ_110_42.png");
	_menu_on[0] = ImageManager::GetInstance()->AddImage("����_on", L"UI�̹���/UI_����_Ȱ��ȭ_110_42.png");
	_menu_on[1] = ImageManager::GetInstance()->AddImage("�ൿ_on", L"UI�̹���/UI_�ൿ_Ȱ��ȭ_110_42.png");
	_menu_on[2] = ImageManager::GetInstance()->AddImage("������_on", L"UI�̹���/UI_������_Ȱ��ȭ_110_42.png");
	_menu_on[3] = ImageManager::GetInstance()->AddImage("�ں�_on", L"UI�̹���/UI_�ں�_Ȱ��ȭ_110_42.png");
	_heart = ImageManager::GetInstance()->AddImage("��Ʈ", L"UI�̹���/UI_��Ʈ_20_20.png");
	_speechBubble = ImageManager::GetInstance()->AddImage("��ǳ��������", L"UI�̹���/UI_��ǳ��_������_237_104.png");
	_attack_ground = ImageManager::GetInstance()->AddImage("������", L"UI�̹���/UI_����Ÿ�̹���_540_132.png");

	ImageManager::GetInstance()->AddImage("������_ȭ��Ʈ", L"UI�̹���/UI_����Ÿ�ֹ̹�_10_151.png");
	ImageManager::GetInstance()->AddImage("������_��", L"UI�̹���/UI_����Ÿ�ֹ̹�_black_10_151.png");
	_attack_bar.img = ImageManager::GetInstance()->FindImage("������_ȭ��Ʈ");
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
	//==========���̾�α�==============

	_title_int = 1;
	_title_int2 = 1;
	_word_count = 0;
	_word_count2 = 0;
	_word_speed = 0;
	talk_main_start("����_����", 1);
	talk_bubble_start("����_��ǳ��", 1);
	//��Ʈ�߰�
	D2DRENDER->AddTextFormat(L"-��������������");
	return S_OK;
}

void battleUI::release()
{
}

void battleUI::update()
{

	if (isTurn == MENU_SELECT)
	{
		//�޴� ���� Ű ����
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _menu_input1_count == 0)
		{
			_menu_main_count--;
			if (_menu_main_count < 1) _menu_main_count = 1;
		}
		//�޴� ���� Ű ������
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _menu_input1_count == 0)
		{
			_menu_main_count++;
			if (_menu_main_count > 4) _menu_main_count = 4;
		}
	}

	//Z��ư == ����
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		if (isTurn == MENU_SELECT)
		{
			//���ݽ��� �� ���ݹ� ���߰� ������
			if (_isAttack_start && !_isAttack_finish)
			{
				_isAttack_finish = true;
			}
			//����â���� Z��ư ���� �� ���� ����
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
			//��ư ���� �޴��� �̵�
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
			//i�� ����� ���̿� ������ ���� ���� �Ѿ
			if (_word_count == strlen(_word_cut) && _word_count >= 3)
			{
				_word_count = 0;
				_title_int++;
				//�̴ϵ����� title���� �������ֱ����� int to string ��ȯ
				_title_char[1024] = _itoa_s(_title_int, _title_char, sizeof(_title_char), 10);
				_str_main = INIDATA->loadDataString("28��", "����_����", _title_char);
			}
		}
		//��ǳ�� ��
		if (isTurn == TALK_BUBBLE)
		{
			//��ǳ������ �ΰ������� �Ѿ�� Ÿ�̹�
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
			//i�� ����� ���̿� ������ ���� ���� �Ѿ
			if (_word_count2 == strlen(_word_cut2) && _word_count2 >= 3 && !_isMercy)
			{
				_title_int2++;
				_word_count2 = 0;
				_title_char2[1024] = _itoa_s(_title_int2, _title_char2, sizeof(_title_char2), 10);
				_str_bubble = INIDATA->loadDataString2("28��", "����_��ǳ��", _title_char2);
				//�̴ϵ����� title���� �������ֱ����� int to string ��ȯ
			}
			//�ں�(����ֱ�)�϶��� ����� ���̰� ������ ��������
			if (_isMercy && _word_count2 == strlen(_word_cut2) && _word_count2 >= 3)
			{
				isTurn = INGAME;
				_isMercy = false;
				_menu_input1_count = 0;
			}
		}
	}
	//X��ư == ���
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		if (isTurn == MENU_SELECT)
		{
			//�޴� ���� ���
			if (_menu_input1_count != 0 && !_isAttack_start)
			{
				_menu_main_count = _menu_input1_count;
				_menu_input1_count = 0;
			}
		}
		if (isTurn == TALK_MAIN)
		{
			//i�� ����� ���̿� ���� ������ ��縦 ��� ǥ��
			if (_word_count != strlen(_str_main))	_word_count = strlen(_str_main);
		}
	}
	//�ں�(����ֱ�)
	if (_isMercy)
	{
		isTurn = TALK_BUBBLE;
		talk_bubble_start("����_��ǳ��", 7);
	}

	//�޴� ī����2�� ���� �ؽ�Ʈ ���
	if (_menu_input1_count == 1) menu_select = L" * �����̸�";
	if (_menu_input1_count == 2) menu_select = L" * �����̸�";
	if (_menu_input1_count == 3) menu_select = L" * ������ ���";
	if (_menu_input1_count == 4 && !_isMercy) menu_select = L" * ����ֱ�";
	//���� ���� �� ���ݹ� ������
	if (_isAttack_start && !_isAttack_finish)
	{
		_attack_bar.x += 5;
		_attack_bar_count = 0;
		if (_attack_bar.x >= 620) _isAttack_finish = true;
	}
	//���� �Ϸ� ��
	if (_isAttack_start && _isAttack_finish)
	{
		_attack_bar_count++;
	}
	//���� �Ϸ� �� �����϶�
	if (_attack_bar_count >= 100)
	{
		_isAttack_start = false;
		_isAttack_finish = false;
		isTurn = TALK_BUBBLE;
		_word_count2 = 0;
		_menu_input1_count = 0;
		_attack_bar_count = 0;
	}
	//�ΰ����� ���
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
	//��ǳ�� ��ȭ��, �̴ϰ������̸� ���� ����â ũ�⸦ ����
	if (isTurn == TALK_BUBBLE || isTurn == INGAME)main_rect_control_default(false);
	//��ǳ�� ��ȭ��, �̴ϰ��� ���� �ƴϸ� ���� ����â ũ�⸦ ����
	if (isTurn == MENU_SELECT || isTurn == TALK_MAIN)main_rect_control_default(true);

	//==========���̾�α�==============
	_word_speed++;

	//�ӵ��� ���� Ÿ���� ȿ�� ����
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
	//����â �ؽ�Ʈ
	if (_menu_input1_count != 0 && !_isMercy)
	{
		D2DRENDER->RenderText(120, 250, menu_select, 20, D2DRenderer::DefaultBrush::White);
	}
	//���� �� �̹���
	if (_isAttack_start)
	{
		_attack_ground->Render(0, 0, 1, 1, 0, 0, 0, 20, WINSIZEY / 2 - 20);
		_attack_bar.img->Render(0, 0, 1, 1, 0, 0, 0, _attack_bar.x, _attack_bar.y);
		if (_attack_bar_count % 10 < 5) _attack_bar.img = ImageManager::GetInstance()->FindImage("������_ȭ��Ʈ");
		else _attack_bar.img = ImageManager::GetInstance()->FindImage("������_��");
	}
	//���� ����â ��Ʈ
	D2DRENDER->DrawRectangle
	(
		_main_rc.rc,
		D2DRenderer::DefaultBrush::White,
		5.F
	);
	//�޴� off �̹���
	_menu_off[0]->Render(0, 0, 1, 1, 0, 0, 0, 20, WINSIZEY - 50);
	_menu_off[1]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 150, WINSIZEY - 50);
	_menu_off[2]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 300, WINSIZEY - 50);
	_menu_off[3]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 450, WINSIZEY - 50);
	//��ǳ��
	if (isTurn == TALK_BUBBLE)	_speechBubble->Render(0, 0, 1, 1, 0, 0, 0, 340, 80);


	//�޴� ���ÿ� ���� �̹���
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

	//==========���̾�α�==============
	//����
	if (isTurn == TALK_MAIN)
	{
		/*	D2DRENDER->RenderText(100, 300, ConverCtoWC(_word_cut), 20);*/
		D2DRENDER->RenderTextField(50, 150, ConverCtoWC(_word_cut), D2D1::ColorF::White, 20, 500, 200, 1,
			DWRITE_TEXT_ALIGNMENT_LEADING, L"-��������������");
	}
	//��ǳ��
	if (isTurn == TALK_BUBBLE)
	{
		/*	D2DRENDER->RenderText(450, 100, ConverCtoWC(_word_cut2), (0, 0, 0), 1, 20, DWRITE_TEXT_ALIGNMENT_LEADING, L"-��������������");*/


		D2DRENDER->RenderTextField(380, 80, ConverCtoWC(_word_cut2), D2D1::ColorF::Black, 20, 180, 100, 1,
			DWRITE_TEXT_ALIGNMENT_LEADING, L"-��������������");


	}
}
//���� ���� ��Ʈ ��Ʈ���Լ� �⺻��		 (�ø��� ������ true, ���̰� ������ false)
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
//���� ���� ��Ʈ ��Ʈ���Լ� Ŀ���͸���¡			 (�ø��� ������ ����,	 ũ�⺯ȯ �ӵ�,	�ּ� Ȥ�� �ִ� ����,	�ּ� Ȥ�� �ִ� ����)
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

//wchar_t ���� char ���� ����ȯ �Լ�
char * battleUI::ConvertWCtoC(wchar_t * str)
{
	//��ȯ�� char* ���� ����
	char* pStr;

	//�Է¹��� wchar_t ������ ���̸� ����
	int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	//char* �޸� �Ҵ�
	pStr = new char[strSize];

	//�� ��ȯ 
	WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);
	return pStr;
}
//char ���� wchar_t ���� ����ȯ �Լ�
wchar_t * battleUI::ConverCtoWC(char * str)
{
	//wchar_t�� ���� ����
	wchar_t* pStr;
	//��Ƽ ����Ʈ ũ�� ��� ���� ��ȯ
	int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);
	//wchar_t �޸� �Ҵ�
	pStr = new WCHAR[strSize];
	//�� ��ȯ
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, pStr, strSize);
	return pStr;
}

void battleUI::talk_bubble_start(const char * subject, int startNum)
{
	_title_int2 = startNum;
	char title_name[64];
	title_name[32] = _itoa_s(startNum, title_name, sizeof(title_name), 10);
	_str_bubble = INIDATA->loadDataString2("28��", subject, title_name);
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
	_str_main = INIDATA->loadDataString("28��", subject, title_name);
}

bool battleUI::talk_main_end(int endNum)
{
	if (endNum == _title_int && _word_count == strlen(_word_cut) && _word_count >= 3)
	{
		return true;
	}
	else return false;
}



