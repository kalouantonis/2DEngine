#ifndef XMLRESOURCE_H
#define XMLRESOURCE_H

#include <tinyxml/tinyxml.h>
#include "Engine.h"

namespace SuperEngine
{
    class XMLoader
    {
        public:
            XMLoader();
            virtual ~XMLoader();

            bool LoadContent(const char* filename);

            TiXmlElement* getRoot();

            /** \brief Returns an attribute from an element
            *   Will perform a search on all attributes and if found will return
            *   its value, else, it'll return NULL
            *
            * \param TiXmlElement to search for attributes
            * \return The element string, else NULL
            *
            */
            std::string getAttrFromElem(const std::string& attrName, TiXmlElement* elem);
            std::string getAttrFromElem(const std::string& attrName, const std::string& elemName);

            std::string getTextFromElem(TiXmlElement* elem);
            std::string getTextFromElem(const std::string& eleName);

            TiXmlElement* getNestedElem(const std::string& elemName, TiXmlElement* parent = NULL);

            TiXmlHandle* getHandle() { return m_docHandle; }

            static int StrToInt(const std::string& str);

        private:
            TiXmlElement* m_rootElem;
            TiXmlHandle* m_docHandle;
            TiXmlDocument m_doc;
    };
};

#endif // XMLRESOURCE_H
