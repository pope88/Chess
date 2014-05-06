project "hiredis.zo"
    kind "StaticLib"

    includedirs { "." }

    files {"**.c", "**.h"}
	
	configuration "windows"
        includedirs { "../event/include" }
