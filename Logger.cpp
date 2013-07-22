#include "Logger.h"

// For time logging
#include <ctime>

// For int to string conversion
#include <sstream>

namespace SuperEngine
{
    bool Logger::Init(const std::string& filename)
    {
        // Logger won't append, i dont know, might implement this later
        m_out.open(filename.c_str(), std::ios::out);

        //m_writeTime = true;

        return m_out.is_open();
    }

    void Logger::writeTime()
    {
        if(m_writeTime)
        {
            time_t now = time(0);

            char timeStr[80];
            strftime(timeStr, 80, "%d-%b-%Y %R:%S", localtime(&now));

            m_out << timeStr << " : ";
            m_writeTime = false;
        }
    }

    void Logger::flush()
    {
        m_writeTime = true;
        m_out.flush();
        m_out.close();
    }

    Logger& operator<<(Logger& os, std::ostream& (*fun)(std::ostream&))
    {
        os.setWriteTime(true);

        os.stream() << fun;
        return os;
    }
};
