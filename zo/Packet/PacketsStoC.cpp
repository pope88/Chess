#include "PacketsStoC.h"

namespace game {
namespace net {
namespace data {
namespace StoC {

uint8_t * SCUserRegister_0x01::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _result);
  if(HasUserId()) buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _userId);
  return buf;
}

bool SCUserRegister_0x01::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _result)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _userId)) return false;
      _isSetFlag[0] |= 0x01;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCUserRegister_0x01::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_result) + (HasUserId() ? (1 + ::ssu::Utils::SizeUInt32(_userId)) : 0);
}

uint8_t * SCUserLogin_0x02::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _result);
  if(HasUserId()) buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _userId);
  if(HasUserName()) buf = ::ssu::Utils::PackStringTag(buf, 3, _userName);
  if(HasVipLevel()) buf = ::ssu::Utils::PackUInt32Tag(buf, 4, _vipLevel);
  if(HasBanTime()) buf = ::ssu::Utils::PackUInt32Tag(buf, 5, _banTime);
  buf = ::ssu::Utils::PackRepeatedPackedTag(buf, 6, _steps, ::ssu::Utils::PackUInt32, ::ssu::Utils::SizeUInt32);
  return buf;
}

bool SCUserLogin_0x02::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _result)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _userId)) return false;
      _isSetFlag[0] |= 0x01;
      break;
     case 3:
      if(type_ != 2 || !::ssu::Utils::UnpackString(buf, leftSize, _userName)) return false;
      _isSetFlag[0] |= 0x02;
      break;
     case 4:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _vipLevel)) return false;
      _isSetFlag[0] |= 0x04;
      break;
     case 5:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _banTime)) return false;
      _isSetFlag[0] |= 0x08;
      break;
     case 6:
      if(type_ != 2 || !::ssu::Utils::UnpackRepeatedPacked(buf, leftSize, _steps, ::ssu::Utils::UnpackUInt32)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCUserLogin_0x02::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_result) + (HasUserId() ? (1 + ::ssu::Utils::SizeUInt32(_userId)) : 0) + (HasUserName() ? (1 + ::ssu::Utils::SizeString(_userName)) : 0) + (HasVipLevel() ? (1 + ::ssu::Utils::SizeUInt32(_vipLevel)) : 0) + (HasBanTime() ? (1 + ::ssu::Utils::SizeUInt32(_banTime)) : 0) + 1 + ::ssu::Utils::SizeRepeatedPacked(_steps, ::ssu::Utils::SizeUInt32);
}

uint8_t * SCUserInfo_0x03::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _gold);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _totalTopup);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 3, _totalConsume);
  return buf;
}

bool SCUserInfo_0x03::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _gold)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _totalTopup)) return false;
      break;
     case 3:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _totalConsume)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCUserInfo_0x03::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_gold) + 1 + ::ssu::Utils::SizeUInt32(_totalTopup) + 1 + ::ssu::Utils::SizeUInt32(_totalConsume);
}

uint8_t * RoomInfo::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _roomId);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _palyerNum);
  return buf;
}

bool RoomInfo::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _roomId)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _palyerNum)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t RoomInfo::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_roomId) + 1 + ::ssu::Utils::SizeUInt32(_palyerNum);
}

SCUserRoomList_0x04::~SCUserRoomList_0x04() {
  for(::ssu::RepeatedObject<RoomInfo *>::iterator iter = _rmlist.begin(); iter != _rmlist.end(); ++ iter) { delete *iter; } _rmlist.Clear();
}

uint8_t * SCUserRoomList_0x04::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackRepeatedTag(buf, 1, _rmlist, ::ssu::Utils::PackObjectTag<RoomInfo>);
  return buf;
}

bool SCUserRoomList_0x04::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 2 || !::ssu::Utils::UnpackRepeatedPtr(buf, leftSize, _rmlist, ::ssu::Utils::UnpackObjectPtr<RoomInfo>)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCUserRoomList_0x04::Size() const {
  return 1 * _rmlist.Size() + ::ssu::Utils::SizeRepeated(_rmlist, ::ssu::Utils::SizeObject<RoomInfo>);
}

uint8_t * SCUserRoomInfo_0x05::PackBuffer(uint8_t * buf) {
  return buf;
}

bool SCUserRoomInfo_0x05::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  return true;
}

size_t SCUserRoomInfo_0x05::Size() const {
  return 0;
}

uint8_t * SCUserEnterRoom_0x06::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _res);
  return buf;
}

bool SCUserEnterRoom_0x06::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _res)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCUserEnterRoom_0x06::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_res);
}

uint8_t * SCUserEnterTable_0x07::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _res);
  return buf;
}

bool SCUserEnterTable_0x07::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _res)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCUserEnterTable_0x07::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_res);
}

uint8_t * SCUserPlayerNow_0x08::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _res);
  return buf;
}

bool SCUserPlayerNow_0x08::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _res)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCUserPlayerNow_0x08::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_res);
}

uint8_t * PGStatus::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _chairid);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _status);
  return buf;
}

bool PGStatus::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _chairid)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _status)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t PGStatus::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_chairid) + 1 + ::ssu::Utils::SizeUInt32(_status);
}

uint8_t * SCPlayerGameSart_0x09::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _basechips);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _lowestchips);
  return buf;
}

bool SCPlayerGameSart_0x09::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _basechips)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _lowestchips)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCPlayerGameSart_0x09::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_basechips) + 1 + ::ssu::Utils::SizeUInt32(_lowestchips);
}

SCPlayerGameStatus_0x10::~SCPlayerGameStatus_0x10() {
  for(::ssu::RepeatedObject<PGStatus *>::iterator iter = _playerstatus.begin(); iter != _playerstatus.end(); ++ iter) { delete *iter; } _playerstatus.Clear();
}

uint8_t * SCPlayerGameStatus_0x10::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackRepeatedTag(buf, 1, _playerstatus, ::ssu::Utils::PackObjectTag<PGStatus>);
  return buf;
}

bool SCPlayerGameStatus_0x10::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 2 || !::ssu::Utils::UnpackRepeatedPtr(buf, leftSize, _playerstatus, ::ssu::Utils::UnpackObjectPtr<PGStatus>)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCPlayerGameStatus_0x10::Size() const {
  return 1 * _playerstatus.Size() + ::ssu::Utils::SizeRepeated(_playerstatus, ::ssu::Utils::SizeObject<PGStatus>);
}

uint8_t * SCPlayerBlindChips_0x11::blindInfo::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _chairid);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _chips);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 3, _remainchips);
  return buf;
}

bool SCPlayerBlindChips_0x11::blindInfo::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _chairid)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _chips)) return false;
      break;
     case 3:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _remainchips)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCPlayerBlindChips_0x11::blindInfo::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_chairid) + 1 + ::ssu::Utils::SizeUInt32(_chips) + 1 + ::ssu::Utils::SizeUInt32(_remainchips);
}

SCPlayerBlindChips_0x11::~SCPlayerBlindChips_0x11() {
  for(::ssu::RepeatedObject<blindInfo *>::iterator iter = _blindinfos.begin(); iter != _blindinfos.end(); ++ iter) { delete *iter; } _blindinfos.Clear();
}

uint8_t * SCPlayerBlindChips_0x11::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _tableamount);
  buf = ::ssu::Utils::PackRepeatedTag(buf, 2, _blindinfos, ::ssu::Utils::PackObjectTag<blindInfo>);
  return buf;
}

bool SCPlayerBlindChips_0x11::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _tableamount)) return false;
      break;
     case 2:
      if(type_ != 2 || !::ssu::Utils::UnpackRepeatedPtr(buf, leftSize, _blindinfos, ::ssu::Utils::UnpackObjectPtr<blindInfo>)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCPlayerBlindChips_0x11::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_tableamount) + 1 * _blindinfos.Size() + ::ssu::Utils::SizeRepeated(_blindinfos, ::ssu::Utils::SizeObject<blindInfo>);
}

uint8_t * card::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _cardvalue);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _cardcolor);
  return buf;
}

bool card::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _cardvalue)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _cardcolor)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t card::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_cardvalue) + 1 + ::ssu::Utils::SizeUInt32(_cardcolor);
}

SCPlayerHandCards_0x12::~SCPlayerHandCards_0x12() {
  for(::ssu::RepeatedObject<card *>::iterator iter = _cards.begin(); iter != _cards.end(); ++ iter) { delete *iter; } _cards.Clear();
}

uint8_t * SCPlayerHandCards_0x12::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _pos);
  buf = ::ssu::Utils::PackRepeatedTag(buf, 2, _cards, ::ssu::Utils::PackObjectTag<card>);
  return buf;
}

bool SCPlayerHandCards_0x12::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _pos)) return false;
      break;
     case 2:
      if(type_ != 2 || !::ssu::Utils::UnpackRepeatedPtr(buf, leftSize, _cards, ::ssu::Utils::UnpackObjectPtr<card>)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCPlayerHandCards_0x12::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_pos) + 1 * _cards.Size() + ::ssu::Utils::SizeRepeated(_cards, ::ssu::Utils::SizeObject<card>);
}

SCPlayerCommonCards_0x13::~SCPlayerCommonCards_0x13() {
  for(::ssu::RepeatedObject<card *>::iterator iter = _cards.begin(); iter != _cards.end(); ++ iter) { delete *iter; } _cards.Clear();
}

uint8_t * SCPlayerCommonCards_0x13::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _step);
  buf = ::ssu::Utils::PackRepeatedTag(buf, 2, _cards, ::ssu::Utils::PackObjectTag<card>);
  return buf;
}

bool SCPlayerCommonCards_0x13::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _step)) return false;
      break;
     case 2:
      if(type_ != 2 || !::ssu::Utils::UnpackRepeatedPtr(buf, leftSize, _cards, ::ssu::Utils::UnpackObjectPtr<card>)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCPlayerCommonCards_0x13::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_step) + 1 * _cards.Size() + ::ssu::Utils::SizeRepeated(_cards, ::ssu::Utils::SizeObject<card>);
}

uint8_t * SCPlayerOperateReq_0x14::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _opcode);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _chairid);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 3, _basechips);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 4, _currentchips);
  return buf;
}

bool SCPlayerOperateReq_0x14::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _opcode)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _chairid)) return false;
      break;
     case 3:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _basechips)) return false;
      break;
     case 4:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _currentchips)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCPlayerOperateReq_0x14::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_opcode) + 1 + ::ssu::Utils::SizeUInt32(_chairid) + 1 + ::ssu::Utils::SizeUInt32(_basechips) + 1 + ::ssu::Utils::SizeUInt32(_currentchips);
}

uint8_t * SCPlayerOperateNot_0x15::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackUInt32Tag(buf, 1, _opcode);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 2, _chairid);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 3, _currentchips);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 4, _leavechips);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 5, _totalchips);
  return buf;
}

bool SCPlayerOperateNot_0x15::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _opcode)) return false;
      break;
     case 2:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _chairid)) return false;
      break;
     case 3:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _currentchips)) return false;
      break;
     case 4:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _leavechips)) return false;
      break;
     case 5:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _totalchips)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t SCPlayerOperateNot_0x15::Size() const {
  return 1 + ::ssu::Utils::SizeUInt32(_opcode) + 1 + ::ssu::Utils::SizeUInt32(_chairid) + 1 + ::ssu::Utils::SizeUInt32(_currentchips) + 1 + ::ssu::Utils::SizeUInt32(_leavechips) + 1 + ::ssu::Utils::SizeUInt32(_totalchips);
}

}
}
}
}
