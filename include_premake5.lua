
if outputdir == nil then
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
end

project "Mathilda"
	location "Mathilda"

	if runIldaMainTest == nil then
		kind "StaticLib"
	else
		kind "ConsoleApp"
	end

	language "C"
	cdialect "C17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"%{prj.name}/include",
		"%{prj.name}/src"
	}

	defines
	{
		"ILDA_HAVE_INLINE"
	}

	removefiles { "**source.c" }
