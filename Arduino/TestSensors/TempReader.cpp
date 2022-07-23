#include "TempReader.h";

TempReader::TempReader() {}

TempReader::TempReader(int pinNumber) 
{
    _dataPin = pinNumber;
    // Don't need to initialize anything with the sensor, it should already have power
    // Only need to communicate with sensor to init get data
}


uint8_t* TempReader::GetAllData()
{
    uint *data;

    data = getAllData();

    if(checkSum(data))
    {
        return data;
    }

    return NULL;
}

uint8_t* TempReader::getAllData()
{
    uint8_t dataArray[5];

    // 1. Arduino sends start signal (and pulls down voltage) for at least 18ms
    pinMode((int)pin, OUTPUT);
    digitalWrite((int)_pin, true);
    delay(18);

    //2. Arduino pulls down voltage and waits for a response for 20-40 microseconds
    
    

    //3. DHT sends response signal for 80 microseconds

    //4. DHT pulls up voltage and keeps it for 80 microseconds

    //5. Start data transmission

}

bool TempReader::checkSum(uint8_t* data)
{
    uint8_t sum = 0;

    // Add the first 4 bytes together
    for (int i = 0 i < 4; i++)
    {   
        // If overflow occurs it doesn't matter
        // the lower 8 bits is all I need for check sum
        sum = sum + data[i];
    }

    // Compare with check sum
    if (sum == data[4])
    {
        return true;
    }

    return false;
}

