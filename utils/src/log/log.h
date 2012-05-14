/*
 * TurnLeftLib/utils/debug_level.h
 *
 * This base class allows the creation of logs. Logs can be of certain levels,
 * which can be accessed and tested against, and can either log to a file or
 * to stderr.
 * Additionally, the log() method has been made virtual, so that subclasses
 * may implement different logging techniques if necessary.
 *
 * Two publicly accessible enums are made available as separate from the class:
 * TurnLeft::Utils::DEBUG_LEVEL and TurnLeft::Utils::DEBUG_TYPE,
 * where the level can be one of (in order of most to least severe):
 *      CRITICAL -> Severe violations of preconditions
 *      WARN -> Not everything is as it should be, but we can continue
 *      VERBOSE -> Standard messaging
 *      ANNOYING -> All messages sent to the log will in fact be logged.
 *
 * DEBUG_TYPE can either be COUT or FILE, which are pretty self-explanatory.
 */

#ifndef TL_UTILS_DEBUG_LEVEL_H_
#define TL_UTILS_DEBUG_LEVEL_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

#include <TurnLeftLib/Exceptions>

namespace TurnLeft{
namespace Utils{


/*! This enumerated type allows for the easy access of certain log levels.
 * CRITICAL messages are reserved for the most severe messages, which would,
 * for instance, still be applicable in a production environment.
 * WARN messages are those which could be useful in production, and are things
 * that should be monitored to see what side effects they might have.
 * VERBOSE are messages which may be useful in production and development, and
 * ANNOYING messages are those that are probably only useful in the early phase
 * of development.
 */
enum DEBUG_LEVEL
{
    CRITICAL,
    WARN,
    VERBOSE,
    ANNOYING
};

/*! This enumerated type differentiates between logs that send messages to
 * the CLI versus those that are logged to a file.
 * COUT and FILE are both pretty self-explanatory.
 */
enum DEBUG_TYPE
{
    COUT,
    FILE
};

/*! \brief The Log class allows for a dynamic logging system which can be manipulated
 * at will to provide different output for different sections of your program
 * by instantiating only a single log object. Creating a log with no
 * construction parameters will default to CRITICAL messages sent to the CLI.
 */
class Log
{
private:
    /*! The current debug level enum */
    DEBUG_LEVEL level;
    /*! The current method of logging. Though this can change, it
     * isn't erecommended to do so.
     */
    DEBUG_TYPE type;

    /*! If the type is set to FILE, a new output stream will be
     * allocated on the heap. The object has responsibility of
     * this pointer, and will delete it upon destruction.
     */
    std::ofstream output;
public:
    /*! The constructor can take up to three parameters, all of
     * which are optional. However, if DEBUG_TYPE is set to FILE, the
     * filename parameter must be passed.
     *
     * \param _level The DEBUG_LEVEL enum (default is CRITICAL)
     * \param _type The DEBUG_TYPE enum (default is COUT)
     * \param _filename The file which will be written to.
     * \sa level
     * \sa type
     * \sa output
     * \throw MissingParemeterException If filename is not passed, but
     * DEBUG_TYPE is set to FILE.
     *
     */
    Log(DEBUG_LEVEL,DEBUG_TYPE,const char*);

    /*! The default destructor destroys the ofstream pointer!
     * \sa output
     */
    virtual ~Log();

    /*! The log method will test to see if the log message meets the level
     * requirements for the current DEBUG_LEVEL setting. If so, it will log
     * the message in the format specified by DEBUG_TYPE. The second parameter
     * is optional, and defaults to ANNOYING. The reason for this is two-fold:
     * 1) It will make creating trash debug messages easier while developing, and
     * 2) Because the class default is CRITICAL, instantiating objects with
     * clss default settings, and calling the default log() method will not
     * bother logging the message, thereby speeding up the code, meaning you
     * the programmer can afford to be a little lazier.
     * Note that this method IS virtual, so it can take on different behaviour
     * in inherited classes if desired.
     *
     * \param _message The message to be written to the log
     * \param _level The importance of the message (default is ANNOYING)
     */
    virtual void log(const char*, DEBUG_LEVEL);

    /*! Standard accessor which returns the debug level.
     * \sa level
     * \return 0=CRITICAL, 1=WARN, 2=VERBOSE, 3=ANNOYING
     */
    DEBUG_LEVEL getLevel();
    /*! Standard accessor which returns the debug type.
     * \sa type
     * \return 0=COUT, 1=FILE
     */
    DEBUG_TYPE getType();
    /*! Standard setter which alters the debug level of the log.
     * This can be useful if you are working on a trouble spot within your
     * program, and only want to retrieve verbose messages in that section.
     * \sa level
     * \param _level The new DEBUG_LEVEL enum.
     */
    void setLevel(DEBUG_LEVEL);

    /*! Abnormal setter which optionally takes two parameters, the second
     * being the filename if the new debug type is FILE.
     * \sa type
     * \param _type The new DEBUG_TYPE enum
     * \param _filename If the new type is FILE, a filename must be passed.
     */
    void setType (DEBUG_TYPE, const char* filename);
};
}}
#endif
