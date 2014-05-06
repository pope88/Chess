project "mongo.zo"
    kind "StaticLib"

    includedirs { "." }

    files {"bson.c", "bson.h", "encoding.c", "encoding.h", "env.c", "env.h", "gridfs.c", "md5.c", "md5.h", "mongo.c", "mongo.h", "numbers.c", "platform.h" }

	configuration "vs*"
	    defines { "MONGO_USE__INT64" }

	configuration "not vs*"
	    defines { "MONGO_HAVE_STDINT" }

	configuration {"linux or freebsd or macosx"}
	    defines { "_USE_LINUX_SYSTEM" }
