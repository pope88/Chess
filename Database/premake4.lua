project "database.zo"
    kind "StaticLib"

    files { "**.cc", "**.cpp" }
    includedirs { ".." }
    configuration "not vs*"
        buildoptions { "-std=gnu++0x" }
