#include "Engine.h"

#include <cstdlib>

namespace SuperEngine
{
    XMLoader::XMLoader()
    {
        //ctor
        m_rootElem = NULL;
        m_docHandle = NULL;
    }

    XMLoader::~XMLoader()
    {
        //dtor
        //m_rootElem->Clear();
        delete m_docHandle;
    }

    bool XMLoader::LoadContent(const char* filename)
    {
        if(!m_doc.LoadFile(filename))
        {
            #ifdef _DEBUG
            std::cerr << "XMLoader failed to load file: " << filename << std::endl;
            Logger::getInstance() << ERR << "XMLoader failed to load file: " << filename
                        << "\n\tDebug out: " << m_doc.ErrorDesc() <<std::endl;
            #endif // _DEBUG

            return false;
        }

        #ifdef _DEBUG
        Logger::getInstance() << INFO << "XMLoader loaded " << filename << " successfully" << std::endl;
        #endif // _DEBUG

        m_docHandle = new TiXmlHandle(&m_doc);

        if(!m_docHandle)
            return false;

        return true;
    }

    TiXmlElement* XMLoader::getRoot()
    {
        return m_doc.RootElement();
    }

    std::string XMLoader::getAttrFromElem(const std::string& attrName, TiXmlElement* elem)
    {
        return elem->Attribute(attrName.c_str());
    }

    std::string XMLoader::getAttrFromElem(const std::string& attrName, const std::string& elemName)
    {
        return getNestedElem(elemName)->Attribute(attrName.c_str());
    }

    std::string XMLoader::getTextFromElem(TiXmlElement* elem)
    {
        return elem->GetText();
    }

    std::string XMLoader::getTextFromElem(const std::string& elemName)
    {
        return getNestedElem(elemName)->GetText();
    }

    TiXmlElement* XMLoader::getNestedElem(const std::string& elemName, TiXmlElement* parent)
    {
        if(!parent)
            parent = getRoot();

        for(TiXmlElement* elem = parent->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
        {
            std::string elemVal = elem->Value();

            if(elemVal == elemName)
                return elem;

            // If the element has another child, send it throught a recursive loop
            if((elem->FirstChildElement()) != NULL)
            {
                TiXmlElement* ret = getNestedElem(elemName, elem);
                if(ret)
                    return ret;
            }
        }

        // Nothing was found, return NULL
        return NULL;
    }

    int XMLoader::StrToInt(const std::string& str)
    {
        return atoi(str.c_str());
    }
};
