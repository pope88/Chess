project "network.zo"
    kind "StaticLib"

    files { "**.cc", "**.cpp", "**.c", "**.h" }
    includedirs { ".." }
    excludes { "Win32/**", "Unix/**" }
    configuration "windows"
        includedirs { "../event/include" }
    configuration { "windows", "not vs *" }
        includedirs {"../event/include"}
    configuration "not vs*"
        buildoptions { "-std=gnu++0x" }

