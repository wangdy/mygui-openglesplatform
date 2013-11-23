/*!
	@file
	@author		George Evmenov
	@date		07/2009
*/

//
//  MyGUI_OpenGLESPlatform.h
//
//  Created by wangdy on 10/2012.
//
//

#ifndef __MYGUI_OPENGLES_PLATFORM_H__
#define __MYGUI_OPENGLES_PLATFORM_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_OpenGLESDiagnostic.h"
#include "MyGUI_OpenGLESRenderManager.h"
#include "MyGUI_OpenGLESDataManager.h"
#include "MyGUI_OpenGLESImageLoader.h"
#include "MyGUI_LogManager.h"

namespace MyGUI
{

	class OpenGLESPlatform
	{
	public:
		OpenGLESPlatform();
		~OpenGLESPlatform();

		void initialise(OpenGLESImageLoader* _loader, const std::string& _logName = MYGUI_PLATFORM_LOG_FILENAME);
		void shutdown();

		OpenGLESRenderManager* getRenderManagerPtr();
		OpenGLESDataManager* getDataManagerPtr();

	private:
		bool mIsInitialise;
		OpenGLESRenderManager* mRenderManager;
		OpenGLESDataManager* mDataManager;
		LogManager* mLogManager;
	};

} // namespace MyGUI

#endif // __MYGUI_OPENGLES_PLATFORM_H__
