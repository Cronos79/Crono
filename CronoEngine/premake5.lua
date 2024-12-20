project "CronoEngine"
        kind "StaticLib"
        language "C++"
        cppdialect "C++20"
        staticruntime "off"

        targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader "crpch.h"
	    pchsource "src/crpch.cpp"

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
		    "%{wks.location}/%{prj.name}/src",
            "%{wks.location}/CronoEngine/vendor/spdlog/include",
            "%{IncludeDir.GLFW}",
            "%{IncludeDir.Glad}",
        }

        links
        {
            "glfw3.lib",
            "opengl32.lib",
            "Glad",
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
            buildoptions 
            {
                "/MDd",
                "/utf-8"
            }
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
            buildoptions 
            {
                "/MD",
                "/utf-8"
            }
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
            buildoptions 
            {
                "/MD",
                "/utf-8"
            }
            optimize "on"

            defines
		    {
                "CR_SHIP"
		    }

            links
            {

            }