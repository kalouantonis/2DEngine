#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <fstream>
#include <ios>

#define ERR "[!!] "
#define WARN "[W] "
#define INFO "[#] "
#define DEBUG "[D] "


#include <tr1/memory>

namespace SuperEngine
{

    class Logger
    {
    private:
        std::ofstream m_out;

        bool m_writeTime;

        Logger() { } // remove constructor
        Logger(Logger const&) {} // copy constructor
        void operator=(Logger const&) {} // assignment op
    public:
        static Logger& getInstance();
        ~Logger() { }

        bool Init(const std::string& filename);

        std::ostream& stream() { return m_out; }

        void writeTime();

        bool getWriteTime() { return m_writeTime; }
        void setWriteTime(bool val) { m_writeTime = val; }

        void flush();

    };

    template<typename T>
    Logger& operator<<(Logger& os, T val)
    {
        os.writeTime();
        os.stream() << val;
        return os;
    }

    // Use function pointer that uses ostream references as parameters and returns
    // and execute it. So anything like std::endl will work.
    Logger& operator<<(Logger& os, std::ostream& (*fun)(std::ostream&));
};


#endif // _LOGGER_H_
