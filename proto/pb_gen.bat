@echo off
SsuPBCpp PacketsCtoS.proto ../zo/Packet/PacketsCtoS.cpp ../zo/Packet/PacketsCtoS.h
SsuPBCpp PacketsStoC.proto ../zo/Packet/PacketsStoC.cpp ../zo/Packet/PacketsStoC.h
protoa PacketsStoC.proto ../zo/Packet/Builder.inl SC PacketsCtoS.proto ../zo/Packet/Handler/ CS

