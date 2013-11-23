/*!
	@file
	@author		George Evmenov
	@date		07/2009
*/

#ifndef __MYGUI_OPENGLES_DATA_MANAGER_H__
#define __MYGUI_OPENGLES_DATA_MANAGER_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_DataManager.h"

namespace MyGUI
{

	class OpenGLESDataManager :
		public DataManager
	{
	public:
		OpenGLESDataManager();

		void initialise();
		void shutdown();

		static OpenGLESDataManager& getInstance()
		{
			return *getInstancePtr();
		}
		static OpenGLESDataManager* getInstancePtr()
		{
			return static_cast<OpenGLESDataManager*>(DataManager::getInstancePtr());
		}

		/** @see DataManager::getData(const std::string& _name) */
		virtual IDataStream* getData(const std::string& _name);

		/** @see DataManager::isDataExist(const std::string& _name) */
		virtual bool isDataExist(const std::string& _name);

		/** @see DataManager::getDataListNames(const std::string& _pattern) */
		virtual const VectorString& getDataListNames(const std::string& _pattern);

		/** @see DataManager::getDataPath(const std::string& _name) */
		virtual const std::string& getDataPath(const std::string& _name);

	/*internal:*/
		void addResourceLocation(const std::string& _name, bool _recursive);

	private:
		struct ArhivInfo
		{
			std::wstring name;
			bool recursive;
		};
		typedef std::vector<ArhivInfo> VectorArhivInfo;
		VectorArhivInfo mPaths;

		bool mIsInitialise;
	};

} // namespace MyGUI

#endif // __MYGUI_OPENGLES_DATA_MANAGER_H__
