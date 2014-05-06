#ifndef _PACKETHEAD_H_
#define _PACKETHEAD_H_
#include "SsuObject.h"

class PacketHead : public ::ssu::Object
{
public:
	inline PacketHead(): _op(0), _len(0), _cliid(0), _svrid(0) {}
	virtual ~PacketHead() { }

public:
	virtual unsigned char * PackBuffer(unsigned char * buf)
	{
		buf = ::ssu::Utils::PackFixed32Tag(buf, 1, _op);
		buf = ::ssu::Utils::PackFixed32Tag(buf, 2, _len);
		buf = ::ssu::Utils::PackFixed32Tag(buf, 3, _cliid);
		buf = ::ssu::Utils::PackFixed32Tag(buf, 4, _svrid);
		return buf;
	}
	virtual bool UnpackBuffer(const unsigned char *& buf, size_t& leftSize)
	{
		unsigned int tag_; unsigned char type_;
		while(leftSize > 0)
		{
			if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_))
				return false;
			switch(tag_)
			{
			case 1:
				if(!::ssu::Utils::UnpackFixed32(buf, leftSize, _op))
					return false;
				break;
			case 2:
				if(!::ssu::Utils::UnpackFixed32(buf, leftSize, _len))
					return false;
				break;
			case 3:
				if(!::ssu::Utils::UnpackFixed32(buf, leftSize, _cliid))
					return false;
				break;
			case 4:
				if(!::ssu::Utils::UnpackFixed32(buf, leftSize, _svrid))
					return false;
				break;
			default: break;
			}
		}
		return true;
	}
	virtual size_t Size() const
	{
		return 1 + ::ssu::Utils::SizeFixed32(_op) + 1 + ::ssu::Utils::SizeFixed32(_len) + 1 + ::ssu::Utils::SizeFixed32(_cliid) + 1 + ::ssu::Utils::SizeFixed32(_svrid);
	}

public:
	inline  int Getop() const { return _op; }
	inline void Setop(int op) { _op = op; }

	inline  int Getlen() const { return _len; }
	inline void Setlen(int len) { _len = len; }

	inline  int Getcliid() const { return _cliid; }
	inline void SetCliid(int chiid) { _cliid = chiid; }

	inline  int Getsvrid() const { return _svrid; }
	inline void SetSvrid(int svrid) { _svrid = svrid; }
protected:
	int _op;
	int _len;
	int _cliid;
	int _svrid;
};
static PacketHead packhead;
#endif