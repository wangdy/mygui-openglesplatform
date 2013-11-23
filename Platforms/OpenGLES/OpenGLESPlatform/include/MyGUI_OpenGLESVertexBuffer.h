/*!
	@file
	@author		George Evmenov
	@date		07/2009
*/

//
//  MyGUI_OpenGLESVertexBuffer.h
//
//  Created by wangdy on 10/2012.
//
//

#ifndef __MYGUI_OPENGLES_VERTEX_BUFFER_H__
#define __MYGUI_OPENGLES_VERTEX_BUFFER_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_IVertexBuffer.h"
//#include "MyGUI_OpenGLESRenderManager.h"

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

namespace MyGUI
{

	class OpenGLESVertexBuffer : public IVertexBuffer
	{
	public:
		OpenGLESVertexBuffer();
		virtual ~OpenGLESVertexBuffer();

		virtual void setVertexCount(size_t _count);
		virtual size_t getVertexCount();

		virtual Vertex* lock();
		virtual void unlock();

	/*internal:*/
		void destroy();
		void create();

		unsigned int getBufferID() const
		{
			return mBufferID;
		}

	private:
		unsigned int mBufferID;
		size_t mVertexCount;
		size_t mNeedVertexCount;
		size_t mSizeInBytes;
	};

} // namespace MyGUI

#endif // __MYGUI_OPENGLES_VERTEX_BUFFER_H__
