#ifndef TempReaderLib
#define TempReaderLib
#include <Arduino.h>

// Made for the DHT11 Temp & Humidity Sensor
// 
// Makes use of Single-Wire Two-Way scheme

// Note: For a Two-Wire scheme I would use tx and rx lines
// In this case will use a generic digtial line
/*

1. Arduino sends start signal (and pulls down voltage) for at least 18ms

2. Arduino pulls down voltage and waits for a response for 20-40 microseconds

3. DHT sends response signal for 80 microseconds

4. DHT pulls up voltage and keeps it for 80 microseconds

5. Start data transmission


Data consists of decimal and integral parts

One communication process is about 40 ms

A complete data transmission is 40bit and the sensor sends the highest data bit first

Data format is
-   byte integral RH data
-   byte decimal RH data
-   byte integral T data
-   byte decimal T data
-   byte check sum (the last eight bits of the previous bytes summed)
*/


class TempReader 
{
  public:

    TempReader();

    TempReader(uint8_t pinNumber);

    // Should each of these call GetAllData()?
    uint8_t GetTempInt();
    uint8_t GetTempDec();

    uint8_t GetHumidityInt();
    uint8_t GetHumidityDec();

    // 4 bytes
    uint8_t* GetAllData();

  private:
    uint8_t* getAllData();

    bool checkSum(uint8_t* data);
    
    uint8_t _dataPin;
    
    // 5 bytes
    //uint8_t* _data;
};

#endif