
if outputdir == nil then
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
end

project "Mathilda"
	location "Mathilda/build"

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

    filter "configurations:Debug"
		defines
		{
			"ILDA_DEBUG",
			"ILDA_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines
		{
			"ILDA_RELEASE",
			"ILDA_ENABLE_ASSERTS"
        }
		runtime "Release"
		optimize "on"
		symbols "on"

    filter "configurations:Dist"
		defines "ILDA_DIST"
		runtime "Release"
		optimize "on"
		symbols "on"
