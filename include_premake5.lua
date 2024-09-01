

if outputdir == nil then
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
end 

project "Mathilda"
	location "Mathilda"
	kind "ConsoleApp"
	language "C"
	cdialect "C11"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/includes/**.h",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"%{prj.name}/includes",
		"%{prj.name}/src"
	}

	defines 
	{
		"ILDA_HAVE_INLINE"
	}

	filter { "files:**source.c" }
		flags {"ExcludeFromBuild"}