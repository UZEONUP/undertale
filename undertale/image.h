#pragma once

class Image final
{
public:
	struct TagLoadedImageInfo
	{
		string key;
		wstring directory;

		TagLoadedImageInfo() {}
		TagLoadedImageInfo(const string& key,const wstring& directory)
			:key(key), directory(directory) {}
	};
	struct FrameRect
	{
		float x;
		float y;
		float width;
		float height;
	};
private:
	ID2D1Bitmap*		mBitmap;
	float				mAlpha;			

	Vector2				mSize;			
	float				mScale;			
	float				mAngle;

	TagLoadedImageInfo	mLoadInfo;		

	vector<Image::FrameRect>	mFrameInfo;
	int							mMaxFrameX;
	int							mMaxFrameY;
private:
	friend class ImageManager;
	Image() = delete;
	Image( ID2D1Bitmap*const bitmap,const TagLoadedImageInfo& loadinfo);
	Image( ID2D1Bitmap*const bitmap,const TagLoadedImageInfo& loadinfo,const int maxFrameX,const int maxFrameY);
	virtual ~Image();
	Image operator = (const Image& image) {}
public:
	void Render(const float X, const float Y, const float scaleW = 1.f, const float scalseH = 1.f,
		const float degreeAngle = 0.f, const float rotateCenterX = 0.f, const float rotateCenterY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	
	void FrameRender(const Vector2& position, const int frameX, const int frameY);

	void ResetRenderOption();

	void SetSize(const Vector2& vec) { this->mSize = vec; }
	void SetAlpha(const float alpha) { this->mAlpha = alpha; }
	void SetScale(const float scale) { this->mScale = scale; }
	void SetAngle(const float angle) { this->mAngle = angle; }

	const int GetMaxFrameX()const{ return mMaxFrameX; }
	const int GetMaxFrameY()const{ return mMaxFrameY; }
	const string GetKey() const { return this->mLoadInfo.key; }
	const UINT GetWidth() const{ return mBitmap->GetPixelSize().width; }
	const UINT GetHeight()const{ return mBitmap->GetPixelSize().height; }
	const Vector2 GetSize()const { return this->mSize; }
	Vector2 GetFrameSize(const int& frame = 0) const { return Vector2(mFrameInfo[frame].width, mFrameInfo[frame].height); }
	const TagLoadedImageInfo& GetLoadInfo() const { return mLoadInfo; }
};

