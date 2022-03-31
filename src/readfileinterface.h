#ifndef READFILEINTERFACE_H
#define READFILEINTERFACE_H

/**
 * @brief The ReadFileInterface abstract class represents any file reader
 */
class ReadFileInterface {

public:
    /**
     * @brief Virtual destructor
     */
    virtual ~ReadFileInterface(){}

    /**
     * @brief Virtuar read method
     */
    virtual void read() = 0;
};

#endif // READFILEINTERFACE_H