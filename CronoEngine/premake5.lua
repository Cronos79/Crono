project "CronoEngine"
        kind "StaticLib"
        language "C++"
        cppdialect "C++20"
        staticruntime "off"

        targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "src/**.h",
            "src/**.cpp"
        }

        defines
        {
            "_CRT_SECURE_NO_WARNINGS"
        }

        includedirs
	    {
		    "src",
            "%{wks.location}/CronoEngine/vendor/spdlog/include"
        }

        links
        {

        }

        filter "system:windows"
		    systemversion "latest"

            defines
		    {
		    }

            links
            {
            }

            postbuildcommands
            {
                ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/CronoEditor")
            }

            filter "configurations:Debug"            
            runtime "Debug"
            symbols "on"

            defines
		    {
                "_DEBUG",
                "CR_DEBUG"
		    }

            links
            {

            }

            filter "configurations:Release"            
            runtime "Release"
            optimize "on"

            defines
		    {
                "CR_RELEASE"
		    }

            links
            {

            }

            filter "configurations:Ship"            
            runtime "Release"
            optimize "on"

            defines
		    {
                "CR_SHIP"
		    }

            links
            {

            }