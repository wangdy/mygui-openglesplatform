/*!
	@file
	@author		George Evmenov
	@date		07/2009
*/

//
//  MyGUI_OpenGLESRenderManager.h
//
//  Created by wangdy on 10/2012.
//
//

#ifndef __MYGUI_OPENGLES_RENDER_MANAGER_H__
#define __MYGUI_OPENGLES_RENDER_MANAGER_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_RenderFormat.h"
#include "MyGUI_IVertexBuffer.h"
#include "MyGUI_RenderManager.h"
#include "MyGUI_OpenGLESImageLoader.h"

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

namespace MyGUI
{

	class OpenGLESRenderManager :
		public RenderManager,
		public IRenderTarget
	{
	public:
		OpenGLESRenderManager();

		void initialise(OpenGLESImageLoader* _loader = 0);
		void shutdown();

		static OpenGLESRenderManager& getInstance()
		{
			return *getInstancePtr();
		}
		static OpenGLESRenderManager* getInstancePtr()
		{
			return static_cast<OpenGLESRenderManager*>(RenderManager::getInstancePtr());
		}

		/** @see OpenGLESRenderManager::getViewSize */
		virtual const IntSize& getViewSize() const;

		/** @see OpenGLESRenderManager::getVertexFormat */
		virtual VertexColourType getVertexFormat();

		/** @see OpenGLESRenderManager::createVertexBuffer */
		virtual IVertexBuffer* createVertexBuffer();
		/** @see OpenGLESRenderManager::destroyVertexBuffer */
		virtual void destroyVertexBuffer(IVertexBuffer* _buffer);

		/** @see OpenGLESRenderManager::createTexture */
		virtual ITexture* createTexture(const std::string& _name);
		/** @see OpenGLESRenderManager::destroyTexture */
		virtual void destroyTexture(ITexture* _texture);
		/** @see OpenGLESRenderManager::getTexture */
		virtual ITexture* getTexture(const std::string& _name);


		/** @see IRenderTarget::begin */
		virtual void begin();
		/** @see IRenderTarget::end */
		virtual void end();
		/** @see IRenderTarget::doRender */
		virtual void doRender(IVertexBuffer* _buffer, ITexture* _texture, size_t _count);
		/** @see IRenderTarget::getInfo */
		virtual const RenderTargetInfo& getInfo();


	/*internal:*/
		void drawOneFrame();
		void setViewSize(int _width, int _height);
		bool isPixelBufferObjectSupported() const;

	private:
		void destroyAllResources();
        GLuint BuildShader(const char* source, GLenum shaderType) const;
        GLuint BuildProgram(const char* vertexShaderSource,
                            const char* fragmentShaderSource) const;

	private:
		IntSize mViewSize;
		bool mUpdate;
		VertexColourType mVertexFormat;
		RenderTargetInfo mInfo;

		typedef std::map<std::string, ITexture*> MapTexture;
		MapTexture mTextures;
		OpenGLESImageLoader* mImageLoader;
		bool mPboIsSupported;

		bool mIsInitialise;
        
        float angle=0.0;
        int step=1;
        void renderScene(void);
        
        GLuint _positionSlot;
        GLuint _colorSlot;
        GLuint _texSlot;
        
        GLuint mProgram;
        GLuint mVertShader;
        GLuint mFragShader;
	};

} // namespace MyGUI

#endif // __MYGUI_OPENGLES_RENDER_MANAGER_H__
