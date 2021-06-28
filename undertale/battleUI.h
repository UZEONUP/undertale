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
	//���� ��Ʈ
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

	//�� ����(0 == �޴� ����, 1 == ��ǳ�� ��ȭ��, 2 == �̴ϰ�����, 3 == ���� ��ȭ��)
	TURN_STATE isTurn;
	//�޴� ����(����, �ൿ, ������, �ں�)
	int _menu_main_count;
	//�޴� ���� �� �θ޴�
	int _menu_input1_count;

	//_menu_main_count(����) �϶�
	//���ݽ��۰� ���� �� ����
	bool _isAttack_start;
	bool _isAttack_finish;
	//���ݹ� ī��Ʈ
	int _attack_bar_count;

	//������ ��
	int enemy_attack_count;

	//_menu_main_count(�ں�) �϶�
	bool _isMercy;

	const wchar_t* menu_select;
	const wchar_t* menu_action;

	//==========���̾�α�==============
	//���� ��� ����
	char* _str_main;
	char* _str_bubble;

	//Ÿ���� ȿ���� ���� ���� ��翡�� �߶�� ����
	char _word_cut[1024];
	char _word_cut2[1024];

	//ini������ Title ������ �ѱ�� ���� ����
	char _title_char[64];
	int _title_int;
	char _title_char2[64];
	int _title_int2;

	//���� ����
	int _word_count;
	int _word_count2;

	//���� �ӵ�
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

