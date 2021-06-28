#pragma once

#define PI 3.141592f
#define PI2 PI*2

#define RECT_WIDTH(rc) static_cast<float>(rc.right - rc.left)
#define RECT_HEIGHT(rc) static_cast<float>(rc.bottom - rc.top)
#define RECT_CENTER_X(rc) static_cast<float>((rc.left + rc.right) * 0.5f)
#define RECT_CENTER_Y(rc) static_cast<float>((rc.top + rc.bottom) * 0.5f)

namespace UJN_UTIL
{
	//거리가져오는 함수
	float GetDistance(float startX, float startY, float endX, float endY);

	float GetAngle(float x1, float y1, float x2, float y2);

	
	//사각형 구조체
	typedef struct tagENEMYRECT
	{
		float left;
		float top;
		float right;
		float bottom;

		tagENEMYRECT() : left(0.0f), top(0.0f), right(0.0f), bottom(0.0f) {}
		tagENEMYRECT(float _left, float _top, float _right, float _bottom) :
			left(_left), top(_top), right(_right), bottom(_bottom) {}

		void Move(float dx, float dy)
		{
			left += dx;
			right += dx;
			top += dy;
			bottom += dy;
		}

		void Set(float _left, float _top, float _right, float _bottom)
		{
			left = _left;
			top = _top;
			right = _right;
			bottom = _bottom;
		}

		//레프트 탑으로 셋팅
		void SetLeftTopPos(float _left, float _top)
		{
			float width = getWidth();
			float height = getHeight();

			left = _left;
			top = _top;
			right = _left + width;
			bottom = _top + height;
		}

		void SetCenterPos(float centerX, float centerY)
		{
			float halfW = getWidth() * 0.5f;
			float halfH = getHeight() * 0.5f;

			left = centerX - halfW;
			top = centerY - halfH;
			right = centerX + halfW;
			bottom = centerY + halfH;
		}

		float getWidth(void) { return right - left; }
		float getHeight(void) { return bottom - top; }
	}ENEMYRECT, * LPENEMYRECT;

	//사각형이 사각형과 충돌했니?
	bool IsCollision(const RECT& rc1, const ENEMYRECT& rc2);
	bool IsCollision(const RECT& rc1, const RECT& rc2);


}