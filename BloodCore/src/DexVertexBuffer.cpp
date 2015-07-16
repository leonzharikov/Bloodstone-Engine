#include "DexVertexBuffer.h"

namespace Dex
{
	VertexBuffer::VertexBuffer(_intun nVertexCount)
		: Buffer(nullptr)
	{
		m_nVertexCount = nVertexCount;
		m_nOffset = 0;
	}

	VertexBuffer::~VertexBuffer(void)
	{
	}

	void VertexBuffer::GetVertexSemantics(_lVertexLayout& sl)
	{
		sl = m_lVertexSemantic;
	}

	void VertexBuffer::AddVertexSemantic(VertexLayout eSemantics)
	{
		m_lVertexSemantic.push_back(eSemantics);

		switch (eSemantics)
		{
		case Dex::VL_POSITION:
			m_nOffset += 12;
			break;
		case Dex::VL_NORMAL:
			m_nOffset += 12;
			break;
		case Dex::VL_TEXTURE:
			m_nOffset += 8;
			break;
		}

		m_pBuffer = realloc(m_pBuffer, m_nVertexCount * m_nOffset);
	}

	void VertexBuffer::RemoveVertexSemantic(VertexLayout eSemantics)
	{
		for (auto it = m_lVertexSemantic.begin(); it != m_lVertexSemantic.end(); ++it)
		{
			if (*it == eSemantics) {
				switch (eSemantics)
				{
				case Dex::VL_POSITION:
					m_nOffset -= 12;
					break;
				case Dex::VL_NORMAL:
					m_nOffset -= 12;
					break;
				case Dex::VL_TEXTURE:
					m_nOffset -= 8;
					break;
				}

				m_lVertexSemantic.erase(it);
				break;
			}
		}
	}

	_intun VertexBuffer::GetSizeBuffer(void)
	{
		return m_nVertexCount * m_nOffset;
	}

	_intun VertexBuffer::GetVertexCount(void)
	{
		return m_nVertexCount;
	}

	_intun VertexBuffer::GetOffsetBuffer(void)
	{
		return m_nOffset;
	}
}