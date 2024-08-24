workspace "Mathilda"
	architecture "x64"
	startproject "Mathilda"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Mathilda"
	location "Mathilda"
	kind "ConsoleApp"
	language "C"
	cdialect "C17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"%{prj.name}/src"
	}