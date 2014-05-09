#include "PacketsCtoS.h"

namespace game {
namespace net {
namespace data {
namespace CtoS {

uint8_t * HeadPack::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackFixed32Tag(buf, 1, _cmdtype);
  buf = ::ssu::Utils::PackFixed32Tag(buf, 2, _cmdlen);
  return buf;
}

bool HeadPack::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 5 || !::ssu::Utils::UnpackFixed32(buf, leftSize, _cmdtype)) return false;
      break;
     case 2:
      if(type_ != 5 || !::ssu::Utils::UnpackFixed32(buf, leftSize, _cmdlen)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t HeadPack::Size() const {
  return 1 + ::ssu::Utils::SizeFixed32(_cmdtype) + 1 + ::ssu::Utils::SizeFixed32(_cmdlen);
}

uint8_t * CSUserLogout_0xFFFF::PackBuffer(uint8_t * buf) {
  return buf;
}

bool CSUserLogout_0xFFFF::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  return true;
}

size_t CSUserLogout_0xFFFF::Size() const {
  return 0;
}

uint8_t * CSUserRegister_0x01::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackStringTag(buf, 1, _username);
  buf = ::ssu::Utils::PackStringTag(buf, 2, _pwd);
  return buf;
}

bool CSUserRegister_0x01::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 2 || !::ssu::Utils::UnpackString(buf, leftSize, _username)) return false;
      break;
     case 2:
      if(type_ != 2 || !::ssu::Utils::UnpackString(buf, leftSize, _pwd)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t CSUserRegister_0x01::Size() const {
  return 1 + ::ssu::Utils::SizeString(_username) + 1 + ::ssu::Utils::SizeString(_pwd);
}

uint8_t * CSUserLogin_0x02::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackStringTag(buf, 1, _username);
  if(HasPwd()) buf = ::ssu::Utils::PackStringTag(buf, 2, _pwd);
  if(HasWallow()) buf = ::ssu::Utils::PackUInt32Tag(buf, 3, _wallow);
  return buf;
}

bool CSUserLogin_0x02::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 2 || !::ssu::Utils::UnpackString(buf, leftSize, _username)) return false;
      break;
     case 2:
      if(type_ != 2 || !::ssu::Utils::UnpackString(buf, leftSize, _pwd)) return false;
      _isSetFlag[0] |= 0x01;
      break;
     case 3:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _wallow)) return false;
      _isSetFlag[0] |= 0x02;
      break;
     default: break;
    }
  }
  return true;
}

size_t CSUserLogin_0x02::Size() const {
  return 1 + ::ssu::Utils::SizeString(_username) + (HasPwd() ? (1 + ::ssu::Utils::SizeString(_pwd)) : 0) + (HasWallow() ? (1 + ::ssu::Utils::SizeUInt32(_wallow)) : 0);
}

uint8_t * CSUserInfo_0x03::PackBuffer(uint8_t * buf) {
  return buf;
}

bool CSUserInfo_0x03::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  return true;
}

size_t CSUserInfo_0x03::Size() const {
  return 0;
}

}
}
}
}