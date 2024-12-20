project "CronoEditor"
        kind "ConsoleApp"
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
		    "%{wks.location}/%{prj.name}/src",
            "%{wks.location}/CronoEngine/vendor/spdlog/include",
            "%{wks.location}/CronoEngine/src",
        }

        links
        {
            "CronoEngine",
            "glfw3.lib",
            "opengl32.lib"
        }

        filter "system:windows"
		    systemversion "latest"

            defines
		    {
		    }

            links
            {

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