project "server.zo"
    kind "ConsoleApp"

    files { "**.cpp", "**.cc", "**.c", "**.h", "../Config.h", "**.inl" }
    excludes { "Packet/PacketsStoC.*", "Packet/PacketsCtoS.*" }
    includedirs { "..", ".", "../ssu" }
    links { "system.zo", "database.zo", "network.zo", "lua.zo", "mongo.zo" }

    configuration "windows"
        if os.is("windows") then
        debugdir ".."
        end
        includedirs { "../event/include", "../hiredis" }
        links { "hiredis.zo", "event.zo", "ws2_32", "mswsock", "kernel32", "user32" }
    configuration { "vs* or codeblocks" }
        files "../Config.cpp"
        pchsource "../Config.cpp"
        pchheader "Config.h"
    configuration "not vs*"
        buildoptions { "-std=gnu++0x" }
    configuration "not windows"
        links { "hiredis", "curl", "event", "event_pthreads", "pthread" }
    configuration "linux"
        links { "dl" }
