#include <EEPROM.h>
#include <Arduino.h>  // for type definitions

template <class T> int EEPROM_writeUniform(int block, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;

    unsigned int size = sizeof(value);
    
    unsigned int index = size*block;

    unsigned int i;
    
    for (i = index; i < index+size; i++)
          EEPROM.write(ee++, *p++);

    return i;
}

template <class T> int EEPROM_readUniform(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;

    unsigned int size = sizeof(value);
    
    unsigned int index = size*block;

    unsigned int i;

    for (i = index; i < index+size; i++)
          *p++ = EEPROM.read(ee++);

    return i;
}

template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
    return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}
