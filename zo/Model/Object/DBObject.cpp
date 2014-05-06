#include "Config.h"
#include "DBObject.h"
#include "Worker/DB.h"
#include "Worker/Base.h"

namespace Object
{

void DBObject::pushAction( Database::MongoAction * ma )
{
	Worker::dbMongo.push(ma);
}

}
