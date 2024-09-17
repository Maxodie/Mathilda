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
runIldaMainTest = true

if outputdir == nil then
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
end


if outputdir == nil then
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
end

include("include_premake5.lua")