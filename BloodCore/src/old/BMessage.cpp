#include "BMessage.h"

namespace Bloodstone
{
	/*BObject::BObject()
	{
		os << "<html>" << endl;
		os << "<head>" << endl;
		os << "<title>Work log</title>" << endl;
		os << "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">" << endl;
		os << "</head>" << endl;
		os << "<body>" << endl;
		os << "<div class=\"header\"><b>Hailstorm Engine - Work log</b></div>" << endl;
	}*/

	BObject::BObject(const char * name)
	{
		mObjectName = name;
	}

	BObject::~BObject()
	{
		/*os << "</body>" << endl;
		os << "</html>" << endl;

		os.close();*/
	}

	void BObject::DrawLine(ofstream& os, const char* text, MessageTypes type)
	{
		if (os)
		{
			char* _warning;

			switch (type)
			{
			case MT_NORMAL:
				_warning = "normal";
				break;
			case MT_WARNING:
				_warning = "warning";
				break;
			case MT_ERROR:
				_warning = "error";
				break;
			}

			os << "<div class=" << _warning << ">" << mObjectName << "_" << text << "</div>" << endl;
			os.flush();
		}
	}

	char * BObject::GetName()
	{
		return mObjectName;
	}
}