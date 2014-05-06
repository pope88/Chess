#ifndef _ROOMPLAYERMANAGER_H_
#define _ROOMPLAYERMANAGER_H_
class User;
class RoomPlayerManager
{
public:
	RoomPlayerManager() {}
	~RoomPlayerManager() {}
	bool insertPlayer(User *user) { return true; }
	bool removePlayer(User *user) { return true; }
	User* findPlayer(UInt32 pid) { return NULL; }
	//void broadcastRoom(Packet::Builder& builder, User *pExceptPlayer = NULL);
	UInt32 getPlayerNum() { return _roomPlayers.size(); }
private:
	UInt32 _roomId;
	std::unordered_map< UInt32, User* > _roomPlayers; 
};
#endif