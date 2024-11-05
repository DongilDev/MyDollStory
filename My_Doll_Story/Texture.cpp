#include "pch.h"
#include "Texture.h"
#include "Main.h"

Texture::Texture()
	:m_hBit(0)
	, m_dc(0)
	, m_bitInfo{}
{

}

Texture::~Texture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void Texture::Load(const wstring& _strFilePath)
{
	// 파일로부터 로딩한 데이터를 비트맵으로 생성
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0 , 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit != nullptr);

	// 비트맵과 연결할 DC
	m_dc = CreateCompatibleDC(Main::GetInst()->GetMainDC());

	//비트맵과 DC 연결
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	// 비트맵 정보
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}