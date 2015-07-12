#pragma once

#include "DexPreCompletion.h"
#include "DexCoreFile.h"
#include "DexSerializer.h"

namespace Dex
{
	#define GEOMETRY_VERSION_SERIALIZER 3

	enum GeometryStruct
	{
		// int ( version visual object )
		// bool ( bUseIndex )
		// if ( bUseIndex )
		// {
		//		int ( enum IndexType )
		//		UInt32 ( Index count )
		//		Ptr ( buffer )
		// }
		GEOMETRY_VERTEX_BEGIN,
		// UInt32 ( Vertex count )
		GEOMETRY_VERTEX_ELEMENT_BEGIN,
		// int ( enum VertexSemantics )
		GEOMETRY_VERTEX_ELEMENT_END,
		// Ptr ( buffer )
		GEOMETRY_VERTEX_END
		// ASCII code shader
	};

	class D_EXPORT GeometryFile : public CoreFile, public Serializer
	{
	public:
		GeometryFile(ofstream* logger, Folder* pParent, const string& cPath, const string& cName);
		~GeometryFile()
		{

		}
	};
}