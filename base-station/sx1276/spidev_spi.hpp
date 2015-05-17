#ifndef SPIDEV_SPI_HPP__
#define SPIDEV_SPI_HPP__

#include "spi.hpp"
#include <string>

class SpidevSPI : public SPI
{
public:
  SpidevSPI();
  ~SpidevSPI();

  bool Open(const char *spidev);
  virtual bool is_open() const { return fd_ < 0; }

  const char *device() const { return spidev_.c_str(); }

  virtual bool ReadRegister(uint8_t reg, uint8_t& result);
  virtual bool WriteRegister(uint8_t reg, uint8_t value);

private:
  bool ConfigureSPI();

  std::string spidev_;
  int fd_;
};

#endif // SPIDEV_SPI_HPP
