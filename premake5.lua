include "Dependencies.lua"

workspace "Crono"
        architecture "x86_64"
        startproject "CronoEditor"

        outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

        configurations
        {
            "Debug",
            "Release",
            "Ship"
        }

        flags
	    {
		    "MultiProcessorCompile"
	    }

        group ""

        group "Editor"
            include "CronoEditor"

        group ""

        group "Engine"
            include "CronoEngine"

        group ""